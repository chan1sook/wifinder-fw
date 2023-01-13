#define WIFINDER_VERSION (8UL)
const char *wifinderVersionStr = "1.4.1";

#include <Arduino.h>
#include <Wire.h>
#include <HTTPClient.h>

#include <ESP32httpUpdate.h>

#include <SPI.h>
#include <TFT_eSPI.h>
#include "FT62XXTouchScreen.h"

#include <QMC5883LCompass.h>

#include <WiFi.h>
#include <EEPROM.h>

TFT_eSPI tft = TFT_eSPI();
FT62XXTouchScreen touchScreen = FT62XXTouchScreen(TFT_WIDTH, PIN_SDA, PIN_SCL);

// Find yours here: http://www.magnetic-declination.com/
// Mine is: -0* 50' W, which is ~5/6 Degrees, or (which we need) 0.01454 radians
#define DECLINATION_ANGLE 0.01454

QMC5883LCompass compass;

#include "esp_freertos_hooks.h"
#include "ui/ui.h"

static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t disp_buf;
static lv_color_t buf[screenWidth * 10];

#define PAGE_HOME_LOADED 0b1
#define PAGE_WIFISCAN_LOADED 0b10
#define PAGE_OTAPROGRESS_LOADED 0b100

uint8_t pageLoadedFlag = 0b000;
uint8_t otaClickCount = 0;

#define LABEL_LIST_LENGTH 5
#define WIFI_SCANNING_LIST 0b1
#define WIFI_SCAN_SELECTED 0b10
#define WIFI_SCANNING_RSSI 0b100
#define MAX_RSSI_TIMEOUT 5

uint8_t wifiScaningFlag = 0b000;
bool wifiIconDisplay = false;
int wifiOptionLength = WIFI_SCAN_RUNNING;
String wifiOptions[LABEL_LIST_LENGTH];
String wifiScanSelectedSSID;

uint8_t rssiTimeout = MAX_RSSI_TIMEOUT;
int wifiRssiValue, animatedWifiRssiValue;
int compassDegValue = -1, animatedCompassDegValue = -1;
String compassDir = "?";

// EEPROM format 8|4|8 = 24 bytes

// 0-7: Header valid if = LOG_EEPROM_HEADER
// 8-11: version valid if match WIFINDER_VERSION
// 12-23: minutes usage

#define LOG_EEPROM_HEADER (0b1001111001101011010010001011001110100001101011010111110011000111ULL)
#define LOG_EEPROM_HEADER_ADDR (0U)
#define LOG_EEPROM_VERSION_ADDR (8U)
#define LOG_EEPROM_MINUTES_ADDR (12U)

#define WIFI_UI_UPDATE_RATE 50
#define WIFI_BLINK_RATE 250
#define LOG_USAGE_UPDATE_RATE 60000
#define COMPASS_UPDATE_RATE 2500
#define BUZZER_UPDATE_DURATION 100

unsigned long wifiUiUpdateTime = 0;
unsigned long wifiIconBlinkTime = 0;
unsigned long compassTime = 0;
unsigned long buzzerUpdateRate = 5000;
unsigned long buzzerTime = 0;
unsigned long logRecordTime = 0;
unsigned long otaFadeTime = 0;

#define BUZZER_GPIO 33
bool buzzerAlarm = false;

const char *fwVersionUri = "http://ota.sensesiot.net:10006/fwversion";
const char *telemetryUri = "http://ota.sensesiot.net:10006/telemetry";
const char *otaBinUri = "http://ota.sensesiot.net:10006/getfw";
bool otaBegin = false;
bool hasEeprom = false;

EventGroupHandle_t systemEventGroup = xEventGroupCreate();

static void lv_tick_task(void *arg);
static void ui_update_task(void *arg);

esp_timer_handle_t ticker_timer;
esp_timer_handle_t update_timer;
const esp_timer_create_args_t ticker_timer_args = {
    .callback = &lv_tick_task,
    .name = "lv_tick_task"};
const esp_timer_create_args_t ticker_update_args = {
    .callback = &ui_update_task,
    .name = "update_timer"};

static void updateScanUiOptions()
{
  if (!(pageLoadedFlag & PAGE_WIFISCAN_LOADED))
  {
    return;
  }

  if (wifiOptionLength > 0)
  {
    String options = "";
    for (int i = 0; i < wifiOptionLength; i++)
    {
      if (i > 0)
      {
        options.concat('\n');
      }
      options.concat(wifiOptions[i]);
    }

    // Serial.println(options);

    lv_roller_set_selected(ui_RollerWifi, 0, LV_ANIM_OFF);
    lv_roller_set_options(ui_RollerWifi, options.c_str(), LV_ROLLER_MODE_NORMAL);
  }
  else if (wifiOptionLength == 0)
  {
    lv_roller_set_selected(ui_RollerWifi, 0, LV_ANIM_OFF);
    lv_roller_set_options(ui_RollerWifi, "No Wifi", LV_ROLLER_MODE_NORMAL);
  }
  else
  {
    lv_roller_set_selected(ui_RollerWifi, 0, LV_ANIM_OFF);
    lv_roller_set_options(ui_RollerWifi, "Scan Error", LV_ROLLER_MODE_NORMAL);
  }
}

static bool isWifinderSSID(String ssid)
{
  return ssid.startsWith("WiFinder");
}

static void sortWifiOptions()
{
  int wifiSortedIndex[LABEL_LIST_LENGTH] = {-1, -1, -1, -1, -1};

  // Sort rssi
  int temp, insert_pos;
  for (int i = 0; i < wifiOptionLength; i++)
  {
    insert_pos = i;
    for (int j = 0; j < LABEL_LIST_LENGTH; j++)
    {
      if (wifiSortedIndex[j] == -1)
      {
        wifiSortedIndex[j] = insert_pos;
        break; // Skip to next
      }

      bool val_ssidA = isWifinderSSID(WiFi.SSID(wifiSortedIndex[j]));
      bool val_ssidB = isWifinderSSID(WiFi.SSID(insert_pos));

      // Priority WiFinder SSID check
      if (val_ssidB && !val_ssidA)
      {
        temp = wifiSortedIndex[j];
        wifiSortedIndex[j] = insert_pos;
        insert_pos = temp;
        break;
      }

      int val_a = WiFi.RSSI(wifiSortedIndex[j]);
      int val_b = WiFi.RSSI(insert_pos);
      if (val_b > val_a)
      {
        temp = wifiSortedIndex[j];
        wifiSortedIndex[j] = insert_pos;
        insert_pos = temp;
      }
    }
  }

  wifiOptionLength = wifiOptionLength > LABEL_LIST_LENGTH ? LABEL_LIST_LENGTH : wifiOptionLength;

  for (int i = 0; i < wifiOptionLength; i++)
  {
    wifiOptions[i] = WiFi.SSID(wifiSortedIndex[i]);
  }
}

static void scanWifiForOptions()
{
  if (!(wifiScaningFlag & WIFI_SCANNING_LIST))
  {
    wifiOptionLength = WiFi.scanNetworks(true);
    wifiScaningFlag = wifiScaningFlag | WIFI_SCANNING_LIST;
    wifiIconBlinkTime = millis();
  }

  wifiOptionLength = WiFi.scanComplete();

  if (wifiOptionLength != WIFI_SCAN_RUNNING)
  {
    Serial.print("Scan Result: ");
    Serial.println(wifiOptionLength);

    wifiScaningFlag = wifiScaningFlag & ~WIFI_SCANNING_LIST;

    if (wifiOptionLength > 0)
    {
      sortWifiOptions();
    }

    updateScanUiOptions();
  }
}

static void resetWifiPageState()
{
  // Serial.println("Reset State Trigger");
  wifiRssiValue = animatedWifiRssiValue = -100;
  wifiScaningFlag = 0b0000;
  wifiIconDisplay = false;
  wifiOptionLength = WIFI_SCAN_RUNNING;
  compassTime = 0;
  buzzerUpdateRate = 5000;
  buzzerTime = 0;
  buzzerAlarm = false;
  logRecordTime = millis();
}

static void updateCompass()
{
  compass.read();

  // Return Azimuth reading
  compassDegValue = compass.getAzimuth();
  char dirArr[3];
  compass.getDirection(dirArr, compassDegValue);
  compassDir = String(dirArr).substring(1);
  compassDir.trim();

  int x, y, z, b;
  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  b = compass.getBearing(compassDegValue);

  // Serial.print("Heading: ");
  // Serial.println(compassDegValue);
}

static void stopBuzzer()
{
  digitalWrite(BUZZER_GPIO, LOW);
  buzzerAlarm = false;
}

static void alarmBuzzer()
{
  if (!(wifiScaningFlag & WIFI_SCAN_SELECTED))
  {
    return;
  }

  digitalWrite(BUZZER_GPIO, HIGH);
  buzzerAlarm = true;
}

static void adjustBuzzerRate()
{
  // Rate computed by rssi value
  if (wifiRssiValue >= -60)
  {
    buzzerUpdateRate = 300;
  }
  else if (wifiRssiValue >= -70)
  {
    buzzerUpdateRate = 500;
  }
  else if (wifiRssiValue >= -80)
  {
    buzzerUpdateRate = 1000;
  }
  else if (wifiRssiValue >= -90)
  {
    buzzerUpdateRate = 2000;
  }
  else
  {
    buzzerUpdateRate = 5000;
  }
}

static void updateRssi()
{
  int scanResult = WIFI_SCAN_RUNNING;

  if (!(wifiScaningFlag & WIFI_SCANNING_RSSI))
  {
    scanResult = WiFi.scanNetworks(true);
    wifiScaningFlag = wifiScaningFlag | WIFI_SCANNING_RSSI;
  }

  scanResult = WiFi.scanComplete();

  if (scanResult > 0)
  {
    wifiScaningFlag = wifiScaningFlag & ~WIFI_SCANNING_RSSI;

    bool hasValue = false;
    for (int i = 0; i < scanResult; i++)
    {
      if (WiFi.SSID(i).equals(wifiScanSelectedSSID))
      {
        hasValue = true;
        Serial.print("RSSI => ");
        Serial.println(WiFi.RSSI(i));
        wifiRssiValue = WiFi.RSSI(i);
        break;
      }
    }

    if (hasValue)
    {
      rssiTimeout = 0;
    }
    else if (rssiTimeout < MAX_RSSI_TIMEOUT)
    {
      rssiTimeout += 1;
      if (rssiTimeout >= MAX_RSSI_TIMEOUT)
      {
        stopBuzzer();
      }
    }
  }
}

static void updateWifiScanUi()
{
  if (!(pageLoadedFlag & PAGE_WIFISCAN_LOADED) || !ui_SceneScan)
  {
    return;
  }

  if (animatedWifiRssiValue != wifiRssiValue)
  {
    int rssiDiff = wifiRssiValue - animatedWifiRssiValue;
    if (rssiDiff >= -1 && rssiDiff <= 1)
    {
      animatedWifiRssiValue = wifiRssiValue;
    }
    else
    {
      animatedWifiRssiValue = animatedWifiRssiValue + rssiDiff / 2;
    }
  }

  // Scan Btn
  if (wifiScaningFlag & (WIFI_SCANNING_LIST | WIFI_SCAN_SELECTED))
  {
    lv_obj_set_style_text_color(ui_LabelImgButtonScan, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else
  {
    lv_obj_set_style_text_color(ui_LabelImgButtonScan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  // Select Btn
  if (!(wifiScaningFlag & WIFI_SCAN_SELECTED) && ((wifiScaningFlag & WIFI_SCANNING_LIST) || wifiOptionLength < 0))
  {
    lv_obj_set_style_text_color(ui_LabelImgButtonSelect, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else
  {
    lv_obj_set_style_text_color(ui_LabelImgButtonSelect, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  if (wifiScaningFlag & WIFI_SCAN_SELECTED)
  {
    lv_label_set_text(ui_LabelImgButtonSelect, "Deselect");
  }
  else
  {
    lv_label_set_text(ui_LabelImgButtonSelect, "Select");
  }

  // Roller Scroll
  if (!(wifiScaningFlag & (WIFI_SCANNING_LIST | WIFI_SCAN_SELECTED)) && wifiOptionLength > 0)
  { // Can Scroll
    lv_obj_add_flag(ui_RollerWifi, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_text_color(ui_RollerWifi, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  }
  else
  { // Can't
    lv_obj_clear_flag(ui_RollerWifi, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_text_color(ui_RollerWifi, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
  }

  // Rssi Label
  if (wifiScaningFlag & WIFI_SCAN_SELECTED && rssiTimeout < MAX_RSSI_TIMEOUT)
  {
    lv_label_set_text(ui_LabelRssiValue, String(animatedWifiRssiValue).c_str());
  }
  else if (wifiScaningFlag & WIFI_SCAN_SELECTED)
  {
    lv_label_set_text(ui_LabelRssiValue, "?");
  }
  else
  {
    lv_label_set_text(ui_LabelRssiValue, "-");
  }

  // Arc
  if (wifiScaningFlag & WIFI_SCAN_SELECTED && rssiTimeout < MAX_RSSI_TIMEOUT)
  {
    if (animatedWifiRssiValue > 0)
    {
      lv_arc_set_value(ui_ArcRssi, 0);
    }
    else if (animatedWifiRssiValue < -100)
    {
      lv_arc_set_value(ui_ArcRssi, -100);
    }
    else
    {
      lv_arc_set_value(ui_ArcRssi, animatedWifiRssiValue);
    }
  }

  // Arm
  if (wifiScaningFlag & WIFI_SCAN_SELECTED && rssiTimeout < MAX_RSSI_TIMEOUT)
  {
    if (animatedWifiRssiValue > 0)
    {
      lv_img_set_angle(ui_ImageGaugeArm, 1350);
    }
    else if (animatedWifiRssiValue < -100)
    {
      lv_img_set_angle(ui_ImageGaugeArm, -1350);
    }
    else
    {
      int deg = (animatedWifiRssiValue + 100) * 27 - 1350; // 0 : 100
      lv_img_set_angle(ui_ImageGaugeArm, deg);
    }
  }

  if (animatedCompassDegValue != compassDegValue)
  {
    int compassDiff = compassDegValue - animatedCompassDegValue;
    if (compassDiff >= -1 && compassDiff <= 1)
    {
      animatedCompassDegValue = compassDegValue;
    }
    else
    {
      animatedCompassDegValue = animatedCompassDegValue + compassDiff / 2;
    }
  }

  // Compass Label
  if (compassDegValue >= 0)
  {
    lv_label_set_text(ui_LabelCompassValue, String(animatedCompassDegValue).c_str());

    lv_label_set_text(ui_LabelCompass1, compassDir.c_str());
  }
  else
  {
    lv_label_set_text(ui_LabelCompassValue, "-");
  }

  // WifIcon
  if (wifiIconDisplay)
  {
    lv_obj_clear_flag(ui_ImageWifi, LV_OBJ_FLAG_HIDDEN);
  }
  else
  {
    lv_obj_add_flag(ui_ImageWifi, LV_OBJ_FLAG_HIDDEN);
  }
}

void onHomePageLoad(lv_event_t *e)
{
  pageLoadedFlag = pageLoadedFlag | PAGE_HOME_LOADED;
  otaClickCount = 0;
}

void onHomePageUnload(lv_event_t *e)
{
  pageLoadedFlag = pageLoadedFlag & ~PAGE_HOME_LOADED;
  otaClickCount = 0;
}

void triggerSecretOTA(lv_event_t *e)
{
  if (!(pageLoadedFlag & PAGE_HOME_LOADED))
  {
    return;
  }

  otaClickCount += 1;
  if (otaClickCount >= 5)
  {
    prepareScreen(OTA_SCREEN);
    lv_textarea_set_text(ui_TextAreaSSID, "");
    lv_textarea_set_text(ui_TextAreaPassword, "");
    swapScreenTo(OTA_SCREEN);
  }
}

void onTextAreaSSIDFocus(lv_event_t *e)
{
  lv_keyboard_set_textarea(ui_Keyboard2, ui_TextAreaSSID);
}

void onTextAreaPasswordFocus(lv_event_t *e)
{
  lv_keyboard_set_textarea(ui_Keyboard2, ui_TextAreaPassword);
}

static void actualOTAAction()
{
  const char *ssid = lv_textarea_get_text(ui_TextAreaSSID);
  const char *pw = lv_textarea_get_text(ui_TextAreaPassword);

  lv_label_set_text(ui_LabelOTAProcess, "Connecting to Server");

  Serial.println("OTA Inputs");
  Serial.print("SSID: ");
  Serial.println(ssid);
  if (strlen(pw) > 0)
  {
    Serial.println("With Password");
    WiFi.begin(ssid, pw);
  }
  else
  {
    Serial.println("No Password");
    WiFi.begin(ssid);
  }

  WiFi.waitForConnectResult(30000);

  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Can't Connect to Server");
    lv_label_set_text(ui_LabelOTAProcess, "Can't Connect to Server");
    lv_obj_clear_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_CLICKABLE);
    return;
  }

  Serial.println("Connected");
  HTTPClient http;

  if (hasEeprom)
  {
    // lv_label_set_text(ui_LabelOTAProcess, "Send Telemetry");

    String params = String("mac=");
    String mac = WiFi.macAddress();
    mac.replace(":", "");
    params.concat(mac);
    params.concat("&ver=");
    params.concat(String(WIFINDER_VERSION));
    params.concat("&m=");

    uint64_t minutes = 0;
    uint64_t header = EEPROM.readULong64(LOG_EEPROM_HEADER_ADDR);
    uint32_t version = EEPROM.readULong(LOG_EEPROM_VERSION_ADDR);

    if (header == LOG_EEPROM_HEADER && version == WIFINDER_VERSION)
    {
      minutes = EEPROM.readULong64(LOG_EEPROM_MINUTES_ADDR);
    }

    params.concat(String(minutes));
    http.begin(telemetryUri);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    Serial.print("Tel HTTP Response code: ");
    Serial.println(http.POST(params));
    http.end();
  }

  lv_label_set_text(ui_LabelOTAProcess, "Get Firmware Info from Server");
  http.begin(fwVersionUri);

  // Send HTTP GET request
  int httpResponseCode = http.GET();
  if (httpResponseCode != 200)
  {
    http.end();

    Serial.print("Error code: ");
    Serial.println(httpResponseCode);

    lv_label_set_text(ui_LabelOTAProcess, "Can't Get Info from Server");
    lv_obj_clear_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_CLICKABLE);
    return;
  }

  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  String version = http.getString();
  Serial.print("VERSION: ");
  Serial.println(version);

  // Free resources
  http.end();

  if (atoi(version.c_str()) <= WIFINDER_VERSION)
  {
    lv_label_set_text(ui_LabelOTAProcess, "Up to date");
    lv_obj_clear_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_CLICKABLE);
    return;
  }

  lv_label_set_text(ui_LabelOTAProcess, "Download OTA File");

  t_httpUpdate_return ret = ESPhttpUpdate.update(otaBinUri);
  switch (ret)
  {
  case HTTP_UPDATE_FAILED:
    Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
    lv_label_set_text(ui_LabelOTAProcess, ESPhttpUpdate.getLastErrorString().c_str());
    break;
  case HTTP_UPDATE_NO_UPDATES:
    Serial.println("HTTP_UPDATE_NO_UPDATES");
    lv_label_set_text(ui_LabelOTAProcess, "No update");
    break;
  case HTTP_UPDATE_OK:
    Serial.println("HTTP_UPDATE_OK");
    ESP.restart();
    return;
  }

  lv_obj_clear_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_CLICKABLE);
}

void onOTAProgressPageLoaded(lv_event_t *e)
{
  lv_obj_clear_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_add_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_HIDDEN);
  lv_label_set_text(ui_LabelOTAProcess, "Starting OTA");

  otaFadeTime = millis();
  otaBegin = false;
  pageLoadedFlag = pageLoadedFlag | PAGE_OTAPROGRESS_LOADED;
}

void onOTAProgressPageUnloaded(lv_event_t *e)
{
  ESP.restart();
  // pageLoadedFlag = pageLoadedFlag & ~PAGE_OTAPROGRESS_LOADED;
}

void onScanPageLoaded(lv_event_t *e)
{
  resetWifiPageState();
  pageLoadedFlag = pageLoadedFlag | PAGE_WIFISCAN_LOADED;

  lv_roller_set_selected(ui_RollerWifi, 0, LV_ANIM_OFF);
  lv_roller_set_options(ui_RollerWifi, " ", LV_ROLLER_MODE_NORMAL);

  scanWifiForOptions();
  updateWifiScanUi();
}

void onScanPageUnloaded(lv_event_t *e)
{
  pageLoadedFlag = pageLoadedFlag & ~PAGE_WIFISCAN_LOADED;
  stopBuzzer();
}

void toScanAction(lv_event_t *e)
{
  if ((pageLoadedFlag & PAGE_WIFISCAN_LOADED) && !(wifiScaningFlag & (WIFI_SCANNING_LIST | WIFI_SCAN_SELECTED)))
  {
    scanWifiForOptions();
    updateWifiScanUi();
  }
}

void toSelectWifiAction(lv_event_t *e)
{
  if (!(pageLoadedFlag & PAGE_WIFISCAN_LOADED) || (wifiScaningFlag & WIFI_SCANNING_LIST) || wifiOptionLength < 0)
  {
    return;
  }

  uint16_t selectedId = lv_roller_get_selected(ui_RollerWifi);

  if (!(wifiScaningFlag & WIFI_SCAN_SELECTED))
  {
    wifiScanSelectedSSID = wifiOptions[selectedId];
    wifiScaningFlag = wifiScaningFlag | WIFI_SCAN_SELECTED;
    wifiScaningFlag = wifiScaningFlag & ~WIFI_SCANNING_RSSI;
    rssiTimeout = MAX_RSSI_TIMEOUT;
    wifiIconBlinkTime = millis();
  }
  else
  {
    wifiScaningFlag = wifiScaningFlag & ~WIFI_SCAN_SELECTED;
  }

  buzzerUpdateRate = 5000;
  buzzerTime = 0;
  buzzerAlarm = false;
  stopBuzzer();

  updateWifiScanUi();
}

static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors(&color_p->full, w * h, true);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

static void touchpad_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
  TouchPoint touchPos = touchScreen.read();
  if (touchPos.touched)
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touchPos.xPos;
    data->point.y = touchPos.yPos;
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}

static void recordUsageLog()
{
  uint64_t logKey = EEPROM.readULong64(LOG_EEPROM_HEADER_ADDR);
  uint32_t version = EEPROM.readUInt(LOG_EEPROM_VERSION_ADDR);

  if (logKey != LOG_EEPROM_HEADER || version != WIFINDER_VERSION)
  {
    // format and save time start 0
    Serial.println("Init EEPROM Format");
    EEPROM.writeULong64(LOG_EEPROM_HEADER_ADDR, LOG_EEPROM_HEADER);
    EEPROM.writeULong(LOG_EEPROM_VERSION_ADDR, WIFINDER_VERSION);
    EEPROM.writeULong64(LOG_EEPROM_MINUTES_ADDR, 1);
  }
  else
  {
    uint64_t minutes = EEPROM.readULong64(LOG_EEPROM_MINUTES_ADDR);
    if (minutes < ULONG_MAX)
    {
      EEPROM.writeULong64(LOG_EEPROM_MINUTES_ADDR, minutes + 1);
    }
  }

  Serial.print("Minutes: ");
  Serial.println(EEPROM.readULong64(LOG_EEPROM_MINUTES_ADDR));

  if (EEPROM.commit())
  {
    Serial.println("EEPROM Saved");
  }
  else
  {
    Serial.println("Can't Save EEPROM");
  }
}

static void lv_tick_task(void *arg)
{
  lv_tick_inc(portTICK_RATE_MS);
}

static void ui_update_task(void *arg)
{
  lv_task_handler();
}

void setup()
{
  pinMode(BUZZER_GPIO, OUTPUT);
  Serial.begin(115200);

  hasEeprom = EEPROM.begin(20);
  if (!hasEeprom)
  {
    Serial.println("Can't Init EEPROM");
  }

  WiFi.mode(WIFI_STA);
  Wire.setPins(PIN_SDA, PIN_SCL);

  compass.init();

  lv_init();
  ESP_ERROR_CHECK(esp_timer_create(&ticker_timer_args, &ticker_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(ticker_timer, portTICK_RATE_MS * 1000));

  // Enable TFT
  tft.begin();
  tft.setRotation(1);

  // Enable Backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, 1);

  // Start TouchScreen
  touchScreen.begin();

  // Display Buffer
  lv_disp_draw_buf_init(&disp_buf, buf, NULL, screenWidth * 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  // Init Touchscreen
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();

  ESP_ERROR_CHECK(esp_timer_create(&ticker_update_args, &update_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(update_timer, 50 * portTICK_RATE_MS * 1000));
}

void loop()
{
  if (pageLoadedFlag & PAGE_WIFISCAN_LOADED)
  {
    if (hasEeprom && millis() - logRecordTime > LOG_USAGE_UPDATE_RATE)
    {
      logRecordTime = millis();
      recordUsageLog();
    }

    if (millis() - compassTime > COMPASS_UPDATE_RATE)
    {
      compassTime = millis();
      updateCompass();
    }

    if (wifiScaningFlag & WIFI_SCANNING_LIST)
    {
      scanWifiForOptions();
    }

    if (wifiScaningFlag & WIFI_SCAN_SELECTED)
    {
      updateRssi();

      if (rssiTimeout < MAX_RSSI_TIMEOUT)
      {
        if (millis() - buzzerTime > buzzerUpdateRate)
        {
          buzzerTime = millis();
          alarmBuzzer();
        }
        else if (buzzerAlarm && millis() - buzzerTime > BUZZER_UPDATE_DURATION)
        {
          stopBuzzer();
        }
      }

      adjustBuzzerRate();
    }

    if (wifiScaningFlag & WIFI_SCANNING_LIST || wifiScaningFlag & WIFI_SCAN_SELECTED)
    {
      if (millis() - wifiIconBlinkTime > WIFI_BLINK_RATE)
      {
        wifiIconBlinkTime = millis();
        wifiIconDisplay = !wifiIconDisplay;
      }
    }
    else
    {
      wifiIconDisplay = false;
    }

    if (millis() - wifiUiUpdateTime > WIFI_UI_UPDATE_RATE)
    {
      updateWifiScanUi();
    }
  }

  if (pageLoadedFlag & PAGE_OTAPROGRESS_LOADED)
  {
    if (!otaBegin && millis() - otaFadeTime > 2000)
    {
      otaBegin = true;
      actualOTAAction();
    }
  }

  delay(5);
}
