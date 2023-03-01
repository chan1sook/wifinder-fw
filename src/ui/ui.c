// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

extern void setLoadingScreen();

///////////////////// VARIABLES ////////////////////
void ui_event_SceneHome(lv_event_t *e);
lv_obj_t *ui_SceneHome;
#if SCRENE_INFO_INCLUDE
void ui_event_ImgButtonInfoPage(lv_event_t *e);
#endif
lv_obj_t *ui_ImgButtonInfoPage;
lv_obj_t *ui_LabelImgButtonInfoPage;
void ui_event_ImgButtonScanPage(lv_event_t *e);
lv_obj_t *ui_ImgButtonScanPage;
lv_obj_t *ui_LabelImgButtonScanPage;
lv_obj_t *ui_WifinderHomeLogo;
lv_obj_t *ui_ImageSponser1;
lv_obj_t *ui_ImageSponser2;
void ui_event_ImageSponser3(lv_event_t *e);
lv_obj_t *ui_ImageSponser3;
lv_obj_t *ui_ImageTextHome1;
lv_obj_t *ui_ImageTextHome2;
lv_obj_t *ui_ImageTextHome3;
lv_obj_t *ui_LabelVersion;
lv_obj_t *ui_LabelMac;

#if SCRENE_INFO_INCLUDE
lv_obj_t *ui_SceneInfo;
void ui_event_ImgButtonHomePage1(lv_event_t *e);
lv_obj_t *ui_ImgButtonHomePage1;
lv_obj_t *ui_ImageHome1;
lv_obj_t *ui_ImageTextInfo1;
lv_obj_t *ui_ImageTextInfo2;
lv_obj_t *ui_WifinderInfoLogo;
lv_obj_t *ui_ImageTextInfo3;
lv_obj_t *ui_ImageTextInfo4;
lv_obj_t *ui_ImageTextInfo5;
lv_obj_t *ui_ImageTextInfo6;
lv_obj_t *ui_ImageTextInfo7;
lv_obj_t *ui_ImageTextInfo8;
lv_obj_t *ui_ImageTextInfo9;
#endif

void ui_event_SceneScan(lv_event_t *e);
lv_obj_t *ui_SceneScan;
lv_obj_t *ui_RollerWifi;
void ui_event_ImgButtonHomePage2(lv_event_t *e);
lv_obj_t *ui_ImgButtonHomePage2;
lv_obj_t *ui_ImageHome2;
void ui_event_ImgButtonScan(lv_event_t *e);
lv_obj_t *ui_ImgButtonScan;
lv_obj_t *ui_LabelImgButtonScan;
void ui_event_ImgButtonSelect(lv_event_t *e);
lv_obj_t *ui_ImgButtonSelect;
lv_obj_t *ui_LabelImgButtonSelect;
lv_obj_t *ui_PanelScanSide;
lv_obj_t *ui_ArcRssi;
lv_obj_t *ui_LabelRssiValue;
lv_obj_t *ui_ImageGaugeArm;
lv_obj_t *ui_PanelCompass;
lv_obj_t *ui_LabelCompass1;
lv_obj_t *ui_LabelCompassValue;
lv_obj_t *ui_ImageWifi;
lv_obj_t *ui_SceneOta;
void ui_event_ImgButtonOTA(lv_event_t *e);
lv_obj_t *ui_ImgButtonOTA;
lv_obj_t *ui_LabelImgButtonOTA;
void ui_event_ImgButtonHomePage3(lv_event_t *e);
lv_obj_t *ui_ImgButtonHomePage3;
lv_obj_t *ui_ImageHome3;
void ui_event_TextAreaSSID(lv_event_t *e);
lv_obj_t *ui_TextAreaSSID;
void ui_event_TextAreaPassword(lv_event_t *e);
lv_obj_t *ui_TextAreaPassword;
lv_obj_t *ui_LabelWifiSSID;
lv_obj_t *ui_LabelWifiPassword;
lv_obj_t *ui_Keyboard2;
void ui_event_ImgButtonPwReveal(lv_event_t *e);
lv_obj_t *ui_ImgButtonPwReveal;
lv_obj_t *ui_ImageEye;
void ui_event_SceneOtaProgress(lv_event_t *e);
lv_obj_t *ui_SceneOtaProgress;
lv_obj_t *ui_LabelOTAProcess;
void ui_event_ImgButtonBackToOTA(lv_event_t *e);
lv_obj_t *ui_ImgButtonBackToOTA;
lv_obj_t *ui_LabelBackToOTA;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_SceneHome(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_SCREEN_LOADED)
	{
		onHomePageLoad(e);
	}
	if (event_code == LV_EVENT_SCREEN_UNLOADED)
	{
		onHomePageUnload(e);
	}
}
#if SCRENE_INFO_INCLUDE
void ui_event_ImgButtonInfoPage(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		swapScreenWithPrepare(INFO_SCREEN);
	}
}
#endif
void ui_event_ImgButtonScanPage(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		swapScreenWithPrepare(SCAN_SCREEN);
	}
}
void ui_event_ImageSponser3(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		triggerSecretOTA(e);
	}
}
#if SCRENE_INFO_INCLUDE
void ui_event_ImgButtonHomePage1(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		swapScreenWithPrepare(HOME_SCREEN);
	}
}
#endif
void ui_event_SceneScan(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_SCREEN_LOADED)
	{
		onScanPageLoaded(e);
	}
	if (event_code == LV_EVENT_SCREEN_UNLOADED)
	{
		onScanPageUnloaded(e);
	}
}
void ui_event_ImgButtonHomePage2(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		swapScreenWithPrepare(HOME_SCREEN);
	}
}
void ui_event_ImgButtonScan(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		toScanAction(e);
	}
}
void ui_event_ImgButtonSelect(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		toSelectWifiAction(e);
	}
}
void ui_event_ImgButtonOTA(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		swapScreenWithPrepare(OTA_PROGRESS_SCREEN);
	}
}
void ui_event_ImgButtonHomePage3(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		swapScreenWithPrepare(HOME_SCREEN);
	}
}
void ui_event_TextAreaSSID(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		onTextAreaSSIDFocus(e);
	}
}
void ui_event_TextAreaPassword(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		onTextAreaPasswordFocus(e);
	}
}
void ui_event_ImgButtonPwReveal(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		toggleOtaPwReveal(e);
	}
}
void ui_event_SceneOtaProgress(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_SCREEN_LOADED)
	{
		onOTAProgressPageLoaded(e);
	}
	if (event_code == LV_EVENT_SCREEN_UNLOADED)
	{
		onOTAProgressPageUnloaded(e);
	}
}
void ui_event_ImgButtonBackToOTA(lv_event_t *e)
{
	lv_event_code_t event_code = lv_event_get_code(e);
	lv_obj_t *target = lv_event_get_target(e);
	if (event_code == LV_EVENT_CLICKED)
	{
		swapScreenWithPrepare(OTA_SCREEN);
	}
}

///////////////////// SCREENS ////////////////////
void ui_SceneHome_screen_init(void)
{
	ui_SceneHome = lv_obj_create(NULL);
	lv_obj_clear_flag(ui_SceneHome, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_SceneHome, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_SceneHome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

#if SCRENE_INFO_INCLUDE
	ui_ImgButtonInfoPage = lv_btn_create(ui_SceneHome);
	lv_obj_set_width(ui_ImgButtonInfoPage, 80);
	lv_obj_set_height(ui_ImgButtonInfoPage, 36);
	lv_obj_set_x(ui_ImgButtonInfoPage, 64);
	lv_obj_set_y(ui_ImgButtonInfoPage, 128);
	lv_obj_set_align(ui_ImgButtonInfoPage, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonInfoPage, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonInfoPage, LV_OBJ_FLAG_SCROLLABLE);	/// Flags
	lv_obj_set_style_radius(ui_ImgButtonInfoPage, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonInfoPage, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonInfoPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonInfoPage, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonInfoPage, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelImgButtonInfoPage = lv_label_create(ui_ImgButtonInfoPage);
	lv_obj_set_width(ui_LabelImgButtonInfoPage, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelImgButtonInfoPage, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelImgButtonInfoPage, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelImgButtonInfoPage, "Info");
	lv_obj_set_style_text_color(ui_LabelImgButtonInfoPage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelImgButtonInfoPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
#endif

	ui_ImgButtonScanPage = lv_btn_create(ui_SceneHome);
	lv_obj_set_width(ui_ImgButtonScanPage, 80);
	lv_obj_set_height(ui_ImgButtonScanPage, 36);
#if SCRENE_INFO_INCLUDE
	lv_obj_set_x(ui_ImgButtonScanPage, -64);
#else
	lv_obj_set_x(ui_ImgButtonScanPage, 0);
#endif
	lv_obj_set_y(ui_ImgButtonScanPage, 128);
	lv_obj_set_align(ui_ImgButtonScanPage, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonScanPage, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonScanPage, LV_OBJ_FLAG_SCROLLABLE);	/// Flags
	lv_obj_set_style_radius(ui_ImgButtonScanPage, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonScanPage, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonScanPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonScanPage, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonScanPage, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelImgButtonScanPage = lv_label_create(ui_ImgButtonScanPage);
	lv_obj_set_width(ui_LabelImgButtonScanPage, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelImgButtonScanPage, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelImgButtonScanPage, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelImgButtonScanPage, "Scan");
	lv_obj_set_style_text_color(ui_LabelImgButtonScanPage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelImgButtonScanPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_WifinderHomeLogo = lv_img_create(ui_SceneHome);
	lv_img_set_src(ui_WifinderHomeLogo, &ui_img_wifinderlogo_png);
	lv_obj_set_width(ui_WifinderHomeLogo, LV_SIZE_CONTENT);	 /// 1
	lv_obj_set_height(ui_WifinderHomeLogo, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_WifinderHomeLogo, 0);
	lv_obj_set_y(ui_WifinderHomeLogo, -100);
	lv_obj_set_align(ui_WifinderHomeLogo, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_WifinderHomeLogo, LV_OBJ_FLAG_ADV_HITTEST);	/// Flags
	lv_obj_clear_flag(ui_WifinderHomeLogo, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_img_set_zoom(ui_WifinderHomeLogo, 512);

	ui_ImageSponser1 = lv_img_create(ui_SceneHome);
	lv_img_set_src(ui_ImageSponser1, &ui_img_sponserlogo1_c_png);
	lv_obj_set_width(ui_ImageSponser1, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageSponser1, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageSponser1, -72);
	lv_obj_set_y(ui_ImageSponser1, 64);
	lv_obj_set_align(ui_ImageSponser1, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageSponser1, LV_OBJ_FLAG_ADV_HITTEST);	 /// Flags
	lv_obj_clear_flag(ui_ImageSponser1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageSponser2 = lv_img_create(ui_SceneHome);
	lv_img_set_src(ui_ImageSponser2, &ui_img_sponserlogo2_c_png);
	lv_obj_set_width(ui_ImageSponser2, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageSponser2, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageSponser2, 0);
	lv_obj_set_y(ui_ImageSponser2, 64);
	lv_obj_set_align(ui_ImageSponser2, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageSponser2, LV_OBJ_FLAG_ADV_HITTEST);	 /// Flags
	lv_obj_clear_flag(ui_ImageSponser2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageSponser3 = lv_img_create(ui_SceneHome);
	lv_img_set_src(ui_ImageSponser3, &ui_img_sponserlogo3_c_png);
	lv_obj_set_width(ui_ImageSponser3, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageSponser3, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageSponser3, 72);
	lv_obj_set_y(ui_ImageSponser3, 64);
	lv_obj_set_align(ui_ImageSponser3, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageSponser3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST); /// Flags
	lv_obj_clear_flag(ui_ImageSponser3, LV_OBJ_FLAG_SCROLLABLE);						/// Flags

	ui_ImageTextHome1 = lv_img_create(ui_SceneHome);
	lv_img_set_src(ui_ImageTextHome1, &ui_img_texthome1_c_png);
	lv_obj_set_width(ui_ImageTextHome1, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextHome1, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextHome1, 0);
	lv_obj_set_y(ui_ImageTextHome1, -40);
	lv_obj_set_align(ui_ImageTextHome1, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageTextHome1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextHome1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextHome2 = lv_img_create(ui_SceneHome);
	lv_img_set_src(ui_ImageTextHome2, &ui_img_texthome2_c_png);
	lv_obj_set_width(ui_ImageTextHome2, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextHome2, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextHome2, 0);
	lv_obj_set_y(ui_ImageTextHome2, -24);
	lv_obj_set_align(ui_ImageTextHome2, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageTextHome2, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextHome2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextHome3 = lv_img_create(ui_SceneHome);
	lv_img_set_src(ui_ImageTextHome3, &ui_img_texthome3_c_png);
	lv_obj_set_width(ui_ImageTextHome3, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextHome3, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextHome3, 0);
	lv_obj_set_y(ui_ImageTextHome3, 16);
	lv_obj_set_align(ui_ImageTextHome3, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageTextHome3, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextHome3, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_LabelVersion = lv_label_create(ui_SceneHome);
	lv_obj_set_width(ui_LabelVersion, LV_SIZE_CONTENT);	 /// 1
	lv_obj_set_height(ui_LabelVersion, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_LabelVersion, -10);
	lv_obj_set_y(ui_LabelVersion, 147);
	lv_obj_set_align(ui_LabelVersion, LV_ALIGN_RIGHT_MID);
	lv_label_set_text(ui_LabelVersion, "Prerelease");
	lv_obj_set_style_text_color(ui_LabelVersion, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelVersion, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_LabelVersion, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelMac = lv_label_create(ui_SceneHome);
	lv_obj_set_width(ui_LabelMac, LV_SIZE_CONTENT);	 /// 1
	lv_obj_set_height(ui_LabelMac, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_LabelMac, 10);
	lv_obj_set_y(ui_LabelMac, 147);
	lv_obj_set_align(ui_LabelMac, LV_ALIGN_LEFT_MID);
	lv_label_set_text(ui_LabelMac, "MAC");
	lv_obj_set_style_text_color(ui_LabelMac, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelMac, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_LabelMac, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

#if SCRENE_INFO_INCLUDE
	lv_obj_add_event_cb(ui_ImgButtonInfoPage, ui_event_ImgButtonInfoPage, LV_EVENT_ALL, NULL);
#endif
	lv_obj_add_event_cb(ui_ImgButtonScanPage, ui_event_ImgButtonScanPage, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_ImageSponser3, ui_event_ImageSponser3, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_SceneHome, ui_event_SceneHome, LV_EVENT_ALL, NULL);
}
#if SCRENE_INFO_INCLUDE
void ui_SceneInfo_screen_init(void)
{
	ui_SceneInfo = lv_obj_create(NULL);
	lv_obj_clear_flag(ui_SceneInfo, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_SceneInfo, lv_color_hex(0x1B1F31), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_SceneInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImgButtonHomePage1 = lv_btn_create(ui_SceneInfo);
	lv_obj_set_width(ui_ImgButtonHomePage1, 80);
	lv_obj_set_height(ui_ImgButtonHomePage1, 36);
	lv_obj_set_x(ui_ImgButtonHomePage1, 195);
	lv_obj_set_y(ui_ImgButtonHomePage1, 135);
	lv_obj_set_align(ui_ImgButtonHomePage1, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonHomePage1, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonHomePage1, LV_OBJ_FLAG_SCROLLABLE);	 /// Flags
	lv_obj_set_style_radius(ui_ImgButtonHomePage1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonHomePage1, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonHomePage1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonHomePage1, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonHomePage1, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImageHome1 = lv_img_create(ui_ImgButtonHomePage1);
	lv_img_set_src(ui_ImageHome1, &ui_img_home_png);
	lv_obj_set_width(ui_ImageHome1, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageHome1, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_ImageHome1, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageHome1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageHome1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo1 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo1, &ui_img_textinfo1_c_png);
	lv_obj_set_width(ui_ImageTextInfo1, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo1, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo1, 130);
	lv_obj_set_y(ui_ImageTextInfo1, -120);
	lv_obj_set_align(ui_ImageTextInfo1, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo2 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo2, &ui_img_textinfo2_c_png);
	lv_obj_set_width(ui_ImageTextInfo2, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo2, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo2, 130);
	lv_obj_set_y(ui_ImageTextInfo2, -100);
	lv_obj_set_align(ui_ImageTextInfo2, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo2, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_WifinderInfoLogo = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_WifinderInfoLogo, &ui_img_wifinderlogo_png);
	lv_obj_set_width(ui_WifinderInfoLogo, LV_SIZE_CONTENT);	 /// 142
	lv_obj_set_height(ui_WifinderInfoLogo, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_WifinderInfoLogo, -5);
	lv_obj_set_y(ui_WifinderInfoLogo, -122);
	lv_obj_set_align(ui_WifinderInfoLogo, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_WifinderInfoLogo, LV_OBJ_FLAG_ADV_HITTEST);	/// Flags
	lv_obj_clear_flag(ui_WifinderInfoLogo, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_img_set_zoom(ui_WifinderInfoLogo, 128);

	ui_ImageTextInfo3 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo3, &ui_img_textinfo3_c_png);
	lv_obj_set_width(ui_ImageTextInfo3, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo3, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo3, 35);
	lv_obj_set_y(ui_ImageTextInfo3, -58);
	lv_obj_set_align(ui_ImageTextInfo3, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo3, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo3, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo4 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo4, &ui_img_textinfo4_c_png);
	lv_obj_set_width(ui_ImageTextInfo4, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo4, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo4, 130);
	lv_obj_set_y(ui_ImageTextInfo4, -60);
	lv_obj_set_align(ui_ImageTextInfo4, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo4, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo4, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo5 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo5, &ui_img_textinfo5_c_png);
	lv_obj_set_width(ui_ImageTextInfo5, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo5, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo5, 130);
	lv_obj_set_y(ui_ImageTextInfo5, -36);
	lv_obj_set_align(ui_ImageTextInfo5, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo5, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo5, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo6 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo6, &ui_img_textinfo6_c_png);
	lv_obj_set_width(ui_ImageTextInfo6, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo6, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo6, 130);
	lv_obj_set_y(ui_ImageTextInfo6, 0);
	lv_obj_set_align(ui_ImageTextInfo6, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo6, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo6, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo7 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo7, &ui_img_textinfo7_c_png);
	lv_obj_set_width(ui_ImageTextInfo7, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo7, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo7, 130);
	lv_obj_set_y(ui_ImageTextInfo7, 22);
	lv_obj_set_align(ui_ImageTextInfo7, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo7, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo7, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo8 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo8, &ui_img_textinfo8_c_png);
	lv_obj_set_width(ui_ImageTextInfo8, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo8, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo8, 130);
	lv_obj_set_y(ui_ImageTextInfo8, 44);
	lv_obj_set_align(ui_ImageTextInfo8, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo8, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo8, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImageTextInfo9 = lv_img_create(ui_SceneInfo);
	lv_img_set_src(ui_ImageTextInfo9, &ui_img_textinfo9_c_png);
	lv_obj_set_width(ui_ImageTextInfo9, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageTextInfo9, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageTextInfo9, 130);
	lv_obj_set_y(ui_ImageTextInfo9, 80);
	lv_obj_set_align(ui_ImageTextInfo9, LV_ALIGN_LEFT_MID);
	lv_obj_add_flag(ui_ImageTextInfo9, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageTextInfo9, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	lv_obj_add_event_cb(ui_ImgButtonHomePage1, ui_event_ImgButtonHomePage1, LV_EVENT_ALL, NULL);
}
#endif
void ui_SceneScan_screen_init(void)
{
	ui_SceneScan = lv_obj_create(NULL);
	lv_obj_clear_flag(ui_SceneScan, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_SceneScan, lv_color_hex(0x1B1F31), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_SceneScan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_RollerWifi = lv_roller_create(ui_SceneScan);
	lv_roller_set_options(ui_RollerWifi, " ", LV_ROLLER_MODE_NORMAL);
	lv_obj_set_width(ui_RollerWifi, 153);
	lv_obj_set_height(ui_RollerWifi, 193);
	lv_obj_set_x(ui_RollerWifi, 152);
	lv_obj_set_y(ui_RollerWifi, 2);
	lv_obj_set_align(ui_RollerWifi, LV_ALIGN_CENTER);
	lv_obj_set_style_text_color(ui_RollerWifi, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_RollerWifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_RollerWifi, lv_color_hex(0x20293A), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_RollerWifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui_RollerWifi, lv_color_hex(0x31415E), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui_RollerWifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImgButtonHomePage2 = lv_btn_create(ui_SceneScan);
	lv_obj_set_width(ui_ImgButtonHomePage2, 80);
	lv_obj_set_height(ui_ImgButtonHomePage2, 36);
	lv_obj_set_x(ui_ImgButtonHomePage2, 195);
	lv_obj_set_y(ui_ImgButtonHomePage2, 135);
	lv_obj_set_align(ui_ImgButtonHomePage2, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonHomePage2, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonHomePage2, LV_OBJ_FLAG_SCROLLABLE);	 /// Flags
	lv_obj_set_style_radius(ui_ImgButtonHomePage2, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonHomePage2, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonHomePage2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonHomePage2, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonHomePage2, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImageHome2 = lv_img_create(ui_ImgButtonHomePage2);
	lv_img_set_src(ui_ImageHome2, &ui_img_home_png);
	lv_obj_set_width(ui_ImageHome2, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageHome2, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_ImageHome2, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageHome2, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageHome2, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_ImgButtonScan = lv_btn_create(ui_SceneScan);
	lv_obj_set_width(ui_ImgButtonScan, 80);
	lv_obj_set_height(ui_ImgButtonScan, 36);
	lv_obj_set_x(ui_ImgButtonScan, -190);
	lv_obj_set_y(ui_ImgButtonScan, 135);
	lv_obj_set_align(ui_ImgButtonScan, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonScan, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonScan, LV_OBJ_FLAG_SCROLLABLE);	/// Flags
	lv_obj_set_style_radius(ui_ImgButtonScan, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonScan, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonScan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonScan, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonScan, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelImgButtonScan = lv_label_create(ui_ImgButtonScan);
	lv_obj_set_width(ui_LabelImgButtonScan, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelImgButtonScan, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelImgButtonScan, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelImgButtonScan, "Rescan");
	lv_obj_set_style_text_color(ui_LabelImgButtonScan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelImgButtonScan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImgButtonSelect = lv_btn_create(ui_SceneScan);
	lv_obj_set_width(ui_ImgButtonSelect, 80);
	lv_obj_set_height(ui_ImgButtonSelect, 36);
	lv_obj_set_x(ui_ImgButtonSelect, 105);
	lv_obj_set_y(ui_ImgButtonSelect, 135);
	lv_obj_set_align(ui_ImgButtonSelect, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonSelect, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonSelect, LV_OBJ_FLAG_SCROLLABLE);	  /// Flags
	lv_obj_set_style_radius(ui_ImgButtonSelect, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonSelect, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonSelect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonSelect, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonSelect, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelImgButtonSelect = lv_label_create(ui_ImgButtonSelect);
	lv_obj_set_width(ui_LabelImgButtonSelect, LV_SIZE_CONTENT);	 /// 1
	lv_obj_set_height(ui_LabelImgButtonSelect, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelImgButtonSelect, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelImgButtonSelect, "Select");
	lv_obj_set_style_text_color(ui_LabelImgButtonSelect, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelImgButtonSelect, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_PanelScanSide = lv_obj_create(ui_SceneScan);
	lv_obj_set_width(ui_PanelScanSide, 293);
	lv_obj_set_height(ui_PanelScanSide, 246);
	lv_obj_set_x(ui_PanelScanSide, -81);
	lv_obj_set_y(ui_PanelScanSide, -20);
	lv_obj_set_align(ui_PanelScanSide, LV_ALIGN_CENTER);
	lv_obj_clear_flag(ui_PanelScanSide, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_PanelScanSide, lv_color_hex(0x20293A), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_PanelScanSide, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui_PanelScanSide, lv_color_hex(0x31415E), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui_PanelScanSide, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ArcRssi = lv_arc_create(ui_PanelScanSide);
	lv_obj_set_width(ui_ArcRssi, 200);
	lv_obj_set_height(ui_ArcRssi, 200);
	lv_obj_set_align(ui_ArcRssi, LV_ALIGN_CENTER);
	lv_obj_clear_flag(ui_ArcRssi, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_arc_set_range(ui_ArcRssi, -100, 0);
	lv_arc_set_value(ui_ArcRssi, -100);

	ui_LabelRssiValue = lv_label_create(ui_PanelScanSide);
	lv_obj_set_width(ui_LabelRssiValue, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelRssiValue, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_LabelRssiValue, 2);
	lv_obj_set_y(ui_LabelRssiValue, 75);
	lv_obj_set_align(ui_LabelRssiValue, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelRssiValue, "-");
	lv_obj_set_style_text_color(ui_LabelRssiValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelRssiValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_LabelRssiValue, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImageGaugeArm = lv_img_create(ui_PanelScanSide);
	lv_img_set_src(ui_ImageGaugeArm, &ui_img_gaugearm_png);
	lv_obj_set_width(ui_ImageGaugeArm, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageGaugeArm, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageGaugeArm, 0);
	lv_obj_set_y(ui_ImageGaugeArm, -20);
	lv_obj_set_align(ui_ImageGaugeArm, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageGaugeArm, LV_OBJ_FLAG_ADV_HITTEST);	 /// Flags
	lv_obj_clear_flag(ui_ImageGaugeArm, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_img_set_pivot(ui_ImageGaugeArm, 9, 62);
	lv_img_set_angle(ui_ImageGaugeArm, -1350);

	ui_PanelCompass = lv_obj_create(ui_SceneScan);
	lv_obj_set_width(ui_PanelCompass, 147);
	lv_obj_set_height(ui_PanelCompass, 40);
	lv_obj_set_x(ui_PanelCompass, 150);
	lv_obj_set_y(ui_PanelCompass, -123);
	lv_obj_set_align(ui_PanelCompass, LV_ALIGN_CENTER);
	lv_obj_clear_flag(ui_PanelCompass, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_PanelCompass, lv_color_hex(0x20293A), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_PanelCompass, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui_PanelCompass, lv_color_hex(0x31415E), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui_PanelCompass, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelCompass1 = lv_label_create(ui_PanelCompass);
	lv_obj_set_width(ui_LabelCompass1, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelCompass1, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelCompass1, LV_ALIGN_LEFT_MID);
	lv_label_set_text(ui_LabelCompass1, "N");
	lv_obj_set_style_text_color(ui_LabelCompass1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelCompass1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelCompassValue = lv_label_create(ui_PanelCompass);
	lv_obj_set_width(ui_LabelCompassValue, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelCompassValue, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelCompassValue, LV_ALIGN_RIGHT_MID);
	lv_label_set_text(ui_LabelCompassValue, "-");
	lv_obj_set_style_text_color(ui_LabelCompassValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelCompassValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImageWifi = lv_img_create(ui_SceneScan);
	lv_img_set_src(ui_ImageWifi, &ui_img_498619720);
	lv_obj_set_width(ui_ImageWifi, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageWifi, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_ImageWifi, -123);
	lv_obj_set_y(ui_ImageWifi, 135);
	lv_obj_set_align(ui_ImageWifi, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageWifi, LV_OBJ_FLAG_ADV_HITTEST);	 /// Flags
	lv_obj_clear_flag(ui_ImageWifi, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	lv_obj_add_event_cb(ui_ImgButtonHomePage2, ui_event_ImgButtonHomePage2, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_ImgButtonScan, ui_event_ImgButtonScan, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_ImgButtonSelect, ui_event_ImgButtonSelect, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_SceneScan, ui_event_SceneScan, LV_EVENT_ALL, NULL);
}
void ui_SceneOta_screen_init(void)
{
	ui_SceneOta = lv_obj_create(NULL);
	lv_obj_clear_flag(ui_SceneOta, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_SceneOta, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_SceneOta, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImgButtonOTA = lv_btn_create(ui_SceneOta);
	lv_obj_set_width(ui_ImgButtonOTA, 120);
	lv_obj_set_height(ui_ImgButtonOTA, 36);
	lv_obj_set_x(ui_ImgButtonOTA, -64);
	lv_obj_set_y(ui_ImgButtonOTA, 136);
	lv_obj_set_align(ui_ImgButtonOTA, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonOTA, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonOTA, LV_OBJ_FLAG_SCROLLABLE);	   /// Flags
	lv_obj_set_style_radius(ui_ImgButtonOTA, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonOTA, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonOTA, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonOTA, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonOTA, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelImgButtonOTA = lv_label_create(ui_ImgButtonOTA);
	lv_obj_set_width(ui_LabelImgButtonOTA, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelImgButtonOTA, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelImgButtonOTA, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelImgButtonOTA, "Start OTA");
	lv_obj_set_style_text_color(ui_LabelImgButtonOTA, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelImgButtonOTA, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImgButtonHomePage3 = lv_btn_create(ui_SceneOta);
	lv_obj_set_width(ui_ImgButtonHomePage3, 80);
	lv_obj_set_height(ui_ImgButtonHomePage3, 36);
	lv_obj_set_x(ui_ImgButtonHomePage3, 64);
	lv_obj_set_y(ui_ImgButtonHomePage3, 136);
	lv_obj_set_align(ui_ImgButtonHomePage3, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonHomePage3, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonHomePage3, LV_OBJ_FLAG_SCROLLABLE);	 /// Flags
	lv_obj_set_style_radius(ui_ImgButtonHomePage3, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonHomePage3, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonHomePage3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonHomePage3, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonHomePage3, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImageHome3 = lv_img_create(ui_ImgButtonHomePage3);
	lv_img_set_src(ui_ImageHome3, &ui_img_home_png);
	lv_obj_set_width(ui_ImageHome3, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_ImageHome3, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_ImageHome3, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageHome3, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
	lv_obj_clear_flag(ui_ImageHome3, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	ui_TextAreaSSID = lv_textarea_create(ui_SceneOta);
	lv_obj_set_width(ui_TextAreaSSID, 317);
	lv_obj_set_height(ui_TextAreaSSID, LV_SIZE_CONTENT); /// 40
	lv_obj_set_x(ui_TextAreaSSID, 130);
	lv_obj_set_y(ui_TextAreaSSID, -115);
	lv_obj_set_align(ui_TextAreaSSID, LV_ALIGN_LEFT_MID);
	lv_textarea_set_max_length(ui_TextAreaSSID, 32);
	lv_textarea_set_placeholder_text(ui_TextAreaSSID, "Wifi SSID");
	lv_textarea_set_one_line(ui_TextAreaSSID, true);

	ui_TextAreaPassword = lv_textarea_create(ui_SceneOta);
	lv_obj_set_width(ui_TextAreaPassword, 275);
	lv_obj_set_height(ui_TextAreaPassword, LV_SIZE_CONTENT); /// 40
	lv_obj_set_x(ui_TextAreaPassword, 130);
	lv_obj_set_y(ui_TextAreaPassword, -70);
	lv_obj_set_align(ui_TextAreaPassword, LV_ALIGN_LEFT_MID);
	lv_textarea_set_max_length(ui_TextAreaPassword, 32);
	lv_textarea_set_placeholder_text(ui_TextAreaPassword, "Wifi Password");
	lv_textarea_set_one_line(ui_TextAreaPassword, true);
	lv_textarea_set_password_mode(ui_TextAreaPassword, true);

	ui_LabelWifiSSID = lv_label_create(ui_SceneOta);
	lv_obj_set_width(ui_LabelWifiSSID, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelWifiSSID, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_LabelWifiSSID, -367);
	lv_obj_set_y(ui_LabelWifiSSID, -115);
	lv_obj_set_align(ui_LabelWifiSSID, LV_ALIGN_RIGHT_MID);
	lv_label_set_text(ui_LabelWifiSSID, "Wifi SSID");
	lv_obj_set_style_text_color(ui_LabelWifiSSID, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelWifiSSID, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelWifiPassword = lv_label_create(ui_SceneOta);
	lv_obj_set_width(ui_LabelWifiPassword, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelWifiPassword, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_LabelWifiPassword, -366);
	lv_obj_set_y(ui_LabelWifiPassword, -70);
	lv_obj_set_align(ui_LabelWifiPassword, LV_ALIGN_RIGHT_MID);
	lv_label_set_text(ui_LabelWifiPassword, "Wifi\nPassword");
	lv_obj_set_style_text_color(ui_LabelWifiPassword, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelWifiPassword, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui_LabelWifiPassword, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_Keyboard2 = lv_keyboard_create(ui_SceneOta);
	lv_obj_set_width(ui_Keyboard2, 445);
	lv_obj_set_height(ui_Keyboard2, 160);
	lv_obj_set_x(ui_Keyboard2, 0);
	lv_obj_set_y(ui_Keyboard2, 35);
	lv_obj_set_align(ui_Keyboard2, LV_ALIGN_CENTER);
	lv_obj_set_style_radius(ui_Keyboard2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_Keyboard2, lv_color_hex(0x202839), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_Keyboard2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui_Keyboard2, lv_color_hex(0x31415E), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui_Keyboard2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui_Keyboard2, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImgButtonPwReveal = lv_btn_create(ui_SceneOta);
	lv_obj_set_width(ui_ImgButtonPwReveal, 40);
	lv_obj_set_height(ui_ImgButtonPwReveal, 36);
	lv_obj_set_x(ui_ImgButtonPwReveal, 190);
	lv_obj_set_y(ui_ImgButtonPwReveal, -70);
	lv_obj_set_align(ui_ImgButtonPwReveal, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonPwReveal, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonPwReveal, LV_OBJ_FLAG_SCROLLABLE);	/// Flags
	lv_obj_set_style_radius(ui_ImgButtonPwReveal, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonPwReveal, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonPwReveal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonPwReveal, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonPwReveal, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImageEye = lv_img_create(ui_ImgButtonPwReveal);
	lv_img_set_src(ui_ImageEye, &ui_img_eye_png);
	lv_obj_set_width(ui_ImageEye, LV_SIZE_CONTENT);	 /// 1
	lv_obj_set_height(ui_ImageEye, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_ImageEye, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImageEye, LV_OBJ_FLAG_ADV_HITTEST);	/// Flags
	lv_obj_clear_flag(ui_ImageEye, LV_OBJ_FLAG_SCROLLABLE); /// Flags

	lv_obj_add_event_cb(ui_ImgButtonOTA, ui_event_ImgButtonOTA, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_ImgButtonHomePage3, ui_event_ImgButtonHomePage3, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_TextAreaSSID, ui_event_TextAreaSSID, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_TextAreaPassword, ui_event_TextAreaPassword, LV_EVENT_ALL, NULL);
	lv_keyboard_set_textarea(ui_Keyboard2, ui_TextAreaSSID);
	lv_obj_add_event_cb(ui_ImgButtonPwReveal, ui_event_ImgButtonPwReveal, LV_EVENT_ALL, NULL);
}
void ui_SceneOtaProgress_screen_init(void)
{
	ui_SceneOtaProgress = lv_obj_create(NULL);
	lv_obj_clear_flag(ui_SceneOtaProgress, LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_bg_color(ui_SceneOtaProgress, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_SceneOtaProgress, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelOTAProcess = lv_label_create(ui_SceneOtaProgress);
	lv_obj_set_width(ui_LabelOTAProcess, LV_SIZE_CONTENT);	/// 1
	lv_obj_set_height(ui_LabelOTAProcess, LV_SIZE_CONTENT); /// 1
	lv_obj_set_x(ui_LabelOTAProcess, 0);
	lv_obj_set_y(ui_LabelOTAProcess, -15);
	lv_obj_set_align(ui_LabelOTAProcess, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelOTAProcess, "Starting OTA");
	lv_obj_set_style_text_color(ui_LabelOTAProcess, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelOTAProcess, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_LabelOTAProcess, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_ImgButtonBackToOTA = lv_btn_create(ui_SceneOtaProgress);
	lv_obj_set_width(ui_ImgButtonBackToOTA, 80);
	lv_obj_set_height(ui_ImgButtonBackToOTA, 36);
	lv_obj_set_x(ui_ImgButtonBackToOTA, 0);
	lv_obj_set_y(ui_ImgButtonBackToOTA, 50);
	lv_obj_set_align(ui_ImgButtonBackToOTA, LV_ALIGN_CENTER);
	lv_obj_add_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
	lv_obj_clear_flag(ui_ImgButtonBackToOTA, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE); /// Flags
	lv_obj_set_style_radius(ui_ImgButtonBackToOTA, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui_ImgButtonBackToOTA, lv_color_hex(0x34276B), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_ImgButtonBackToOTA, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui_ImgButtonBackToOTA, lv_color_hex(0x3E69B0), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui_ImgButtonBackToOTA, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

	ui_LabelBackToOTA = lv_label_create(ui_ImgButtonBackToOTA);
	lv_obj_set_width(ui_LabelBackToOTA, LV_SIZE_CONTENT);  /// 1
	lv_obj_set_height(ui_LabelBackToOTA, LV_SIZE_CONTENT); /// 1
	lv_obj_set_align(ui_LabelBackToOTA, LV_ALIGN_CENTER);
	lv_label_set_text(ui_LabelBackToOTA, "Back");
	lv_obj_set_style_text_color(ui_LabelBackToOTA, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_LabelBackToOTA, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_add_event_cb(ui_ImgButtonBackToOTA, ui_event_ImgButtonBackToOTA, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui_SceneOtaProgress, ui_event_SceneOtaProgress, LV_EVENT_ALL, NULL);
}

screen_id loaded_screen[2] = {SCREEN_BLANK, SCREEN_BLANK};
extern const char *wifinderVersionStr;

void load_screen(screen_id screen)
{
	switch (screen)
	{
	case HOME_SCREEN:
		if (!ui_SceneHome)
		{
			ui_SceneHome_screen_init();
			setLoadingScreen();
		}
		break;
#if SCRENE_INFO_INCLUDE
	case INFO_SCREEN:
		if (!ui_SceneInfo)
		{
			ui_SceneInfo_screen_init();
		}
		break;
#endif
	case SCAN_SCREEN:
		if (!ui_SceneScan)
		{
			ui_SceneScan_screen_init();
		}
		break;
	case OTA_SCREEN:
		if (!ui_SceneOta)
		{
			ui_SceneOta_screen_init();
		}
		break;
	case OTA_PROGRESS_SCREEN:
		if (!ui_SceneOtaProgress)
		{
			ui_SceneOtaProgress_screen_init();
		}
		break;
	}
}
void unload_screen(screen_id screen)
{
	switch (screen)
	{
	case HOME_SCREEN:
		if (ui_SceneHome)
		{
			lv_obj_del(ui_SceneHome);
			ui_SceneHome = NULL;
		}
		break;
#if SCRENE_INFO_INCLUDE
	case INFO_SCREEN:
		if (ui_SceneInfo)
		{
			lv_obj_del(ui_SceneInfo);
			ui_SceneInfo = NULL;
		}
		break;
#endif
	case SCAN_SCREEN:
		if (ui_SceneScan)
		{
			lv_obj_del(ui_SceneScan);
			ui_SceneScan = NULL;
		}
		break;
	case OTA_SCREEN:
		if (ui_SceneOta)
		{
			lv_obj_del(ui_SceneOta);
			ui_SceneOta = NULL;
		}
		break;
	case OTA_PROGRESS_SCREEN:
		if (ui_SceneOtaProgress)
		{
			lv_obj_del(ui_SceneOtaProgress);
			ui_SceneOtaProgress = NULL;
		}
		break;
	}
}
void swap_screen_ani(lv_obj_t *newScreen)
{
	if (!newScreen || lv_scr_act() == newScreen)
	{
		return;
	}

	// lv_scr_load_anim(newScreen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false);
	lv_disp_load_scr(newScreen);
}

void prepareScreen(screen_id target)
{
	if (target == loaded_screen[1])
	{
		return;
	}

	if (target == loaded_screen[0])
	{
		loaded_screen[0] = loaded_screen[1];
		loaded_screen[1] = target;
	}
	else
	{
		// unload first scene
		unload_screen(loaded_screen[0]);
		loaded_screen[0] = loaded_screen[1];
		loaded_screen[1] = target;
		load_screen(target);
	}
}
void swapScreenTo(screen_id target)
{
	switch (target)
	{
	case HOME_SCREEN:
		swap_screen_ani(ui_SceneHome);
		break;
#if SCRENE_INFO_INCLUDE
	case INFO_SCREEN:
		swap_screen_ani(ui_SceneInfo);
		break;
#endif
	case SCAN_SCREEN:
		swap_screen_ani(ui_SceneScan);
		break;
	case OTA_SCREEN:
		swap_screen_ani(ui_SceneOta);
		break;
	case OTA_PROGRESS_SCREEN:
		swap_screen_ani(ui_SceneOtaProgress);
		break;
	}
}
void swapScreenWithPrepare(screen_id target)
{
	prepareScreen(target);
	swapScreenTo(target);
}

void ui_init(void)
{
	lv_disp_t *dispp = lv_disp_get_default();
	lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
											  false, LV_FONT_DEFAULT);
	lv_disp_set_theme(dispp, theme);

	prepareScreen(HOME_SCREEN);

	lv_disp_load_scr(ui_SceneHome);
}
