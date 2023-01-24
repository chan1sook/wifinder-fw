// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

  void ui_event_SceneHome(lv_event_t *e);
  extern lv_obj_t *ui_SceneHome;
#if SCRENE_INFO_INCLUDE
  void ui_event_ImgButtonInfoPage(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonInfoPage;
  extern lv_obj_t *ui_LabelImgButtonInfoPage;
#endif
  void ui_event_ImgButtonScanPage(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonScanPage;
  extern lv_obj_t *ui_LabelImgButtonScanPage;
  extern lv_obj_t *ui_WifinderHomeLogo;
  extern lv_obj_t *ui_ImageSponser1;
  extern lv_obj_t *ui_ImageSponser2;
  void ui_event_ImageSponser3(lv_event_t *e);
  extern lv_obj_t *ui_ImageSponser3;
  extern lv_obj_t *ui_ImageTextHome1;
  extern lv_obj_t *ui_ImageTextHome2;
  extern lv_obj_t *ui_ImageTextHome3;
  extern lv_obj_t *ui_LabelVersion;
#if SCRENE_INFO_INCLUDE
  extern lv_obj_t *ui_SceneInfo;
  void ui_event_ImgButtonHomePage1(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonHomePage1;
  extern lv_obj_t *ui_ImageHome1;
  extern lv_obj_t *ui_ImageTextInfo1;
  extern lv_obj_t *ui_ImageTextInfo2;
  extern lv_obj_t *ui_WifinderInfoLogo;
  extern lv_obj_t *ui_ImageTextInfo3;
  extern lv_obj_t *ui_ImageTextInfo4;
  extern lv_obj_t *ui_ImageTextInfo5;
  extern lv_obj_t *ui_ImageTextInfo6;
  extern lv_obj_t *ui_ImageTextInfo7;
  extern lv_obj_t *ui_ImageTextInfo8;
  extern lv_obj_t *ui_ImageTextInfo9;
#endif
  void ui_event_SceneScan(lv_event_t *e);
  extern lv_obj_t *ui_SceneScan;
  extern lv_obj_t *ui_RollerWifi;
  void ui_event_ImgButtonHomePage2(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonHomePage2;
  extern lv_obj_t *ui_ImageHome2;
  void ui_event_ImgButtonScan(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonScan;
  extern lv_obj_t *ui_LabelImgButtonScan;
  void ui_event_ImgButtonSelect(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonSelect;
  extern lv_obj_t *ui_LabelImgButtonSelect;
  extern lv_obj_t *ui_PanelScanSide;
  extern lv_obj_t *ui_ArcRssi;
  extern lv_obj_t *ui_LabelRssiValue;
  extern lv_obj_t *ui_ImageGaugeArm;
  extern lv_obj_t *ui_PanelCompass;
  extern lv_obj_t *ui_LabelCompass1;
  extern lv_obj_t *ui_LabelCompassValue;
  extern lv_obj_t *ui_ImageWifi;
  extern lv_obj_t *ui_SceneOta;
  void ui_event_ImgButtonOTA(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonOTA;
  extern lv_obj_t *ui_LabelImgButtonOTA;
  void ui_event_ImgButtonHomePage3(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonHomePage3;
  extern lv_obj_t *ui_ImageHome3;
  void ui_event_TextAreaSSID(lv_event_t *e);
  extern lv_obj_t *ui_TextAreaSSID;
  void ui_event_TextAreaPassword(lv_event_t *e);
  extern lv_obj_t *ui_TextAreaPassword;
  extern lv_obj_t *ui_LabelWifiSSID;
  extern lv_obj_t *ui_LabelWifiPassword;
  extern lv_obj_t *ui_Keyboard2;
  void ui_event_ImgButtonPwReveal(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonPwReveal;
  extern lv_obj_t *ui_ImageEye;
  void ui_event_SceneOtaProgress(lv_event_t *e);
  extern lv_obj_t *ui_SceneOtaProgress;
  extern lv_obj_t *ui_LabelOTAProcess;
  void ui_event_ImgButtonBackToOTA(lv_event_t *e);
  extern lv_obj_t *ui_ImgButtonBackToOTA;
  extern lv_obj_t *ui_LabelBackToOTA;

  void onHomePageLoad(lv_event_t *e);
  void onHomePageUnload(lv_event_t *e);
  void triggerSecretOTA(lv_event_t *e);
  void onScanPageLoaded(lv_event_t *e);
  void onScanPageUnloaded(lv_event_t *e);
  void toScanAction(lv_event_t *e);
  void toSelectWifiAction(lv_event_t *e);
  void onTextAreaSSIDFocus(lv_event_t *e);
  void onTextAreaPasswordFocus(lv_event_t *e);
  void toggleOtaPwReveal(lv_event_t *e);
  void onOTAProgressPageLoaded(lv_event_t *e);
  void onOTAProgressPageUnloaded(lv_event_t *e);

  LV_IMG_DECLARE(ui_img_wifinderlogo_png);   // assets\WiFinderLogo.png
  LV_IMG_DECLARE(ui_img_sponserlogo1_c_png); // assets\sponserLogo1_c.png
  LV_IMG_DECLARE(ui_img_sponserlogo2_c_png); // assets\sponserLogo2_c.png
  LV_IMG_DECLARE(ui_img_sponserlogo3_c_png); // assets\sponserLogo3_c.png
  LV_IMG_DECLARE(ui_img_texthome1_c_png);    // assets\textHome1_c.png
  LV_IMG_DECLARE(ui_img_texthome2_c_png);    // assets\textHome2_c.png
  LV_IMG_DECLARE(ui_img_texthome3_c_png);    // assets\textHome3_c.png
  LV_IMG_DECLARE(ui_img_home_png);           // assets\home.png
#if SCRENE_INFO_INCLUDE
  LV_IMG_DECLARE(ui_img_textinfo1_c_png); // assets\textInfo1_c.png
  LV_IMG_DECLARE(ui_img_textinfo2_c_png); // assets\textInfo2_c.png
  LV_IMG_DECLARE(ui_img_textinfo3_c_png); // assets\textInfo3_c.png
  LV_IMG_DECLARE(ui_img_textinfo4_c_png); // assets\textInfo4_c.png
  LV_IMG_DECLARE(ui_img_textinfo5_c_png); // assets\textInfo5_c.png
  LV_IMG_DECLARE(ui_img_textinfo6_c_png); // assets\textInfo6_c.png
  LV_IMG_DECLARE(ui_img_textinfo7_c_png); // assets\textInfo7_c.png
  LV_IMG_DECLARE(ui_img_textinfo8_c_png); // assets\textInfo8_c.png
  LV_IMG_DECLARE(ui_img_textinfo9_c_png); // assets\textInfo9_c.png
#endif
  LV_IMG_DECLARE(ui_img_gaugearm_png); // assets\gaugeArm.png
  LV_IMG_DECLARE(ui_img_498619720);    // assets\wifi-logo-13682.png
  LV_IMG_DECLARE(ui_img_eye_png);      // assets\eye.png

  typedef enum
  {
    HOME_SCREEN,
#if SCRENE_INFO_INCLUDE
    INFO_SCREEN,
#endif
    SCAN_SCREEN,
    OTA_SCREEN,
    OTA_PROGRESS_SCREEN,
    SCREEN_BLANK,
  } screen_id;

  extern screen_id loaded_screen[2];
  void load_screen(screen_id screen);
  void unload_screen(screen_id screen);
  void swap_screen_ani(lv_obj_t *newScreen);

  void prepareScreen(screen_id target);
  void swapScreenTo(screen_id target);
  void swapScreenWithPrepare(screen_id target);

  void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
