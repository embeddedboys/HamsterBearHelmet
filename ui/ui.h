// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: HamsterBearDesktop

#ifndef _HAMSTERBEARDESKTOP_UI_H
#define _HAMSTERBEARDESKTOP_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

extern lv_obj_t * ui_ScreenHome;
extern lv_obj_t * ui_StatusBar;
extern lv_obj_t * ui_LabelTime;
extern lv_obj_t * ui_ImageWifi;
extern lv_obj_t * ui_PanelApps;
extern lv_obj_t * ui_ButtonMoviePlayer;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_LabelMusic;
extern lv_obj_t * ui_ButtonSetting;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_LabelSetting;
extern lv_obj_t * ui_ButtonSensors;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_LabelSensors;
extern lv_obj_t * ui_ButtonSystemInfo;
extern lv_obj_t * ui_Image8;
extern lv_obj_t * ui_LabelSystemInfo;
extern lv_obj_t * ui_ButtonNext;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_ButtonPre;
extern lv_obj_t * ui_Image6;
extern lv_obj_t * ui_ButtonPower;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_LabelHint;
extern lv_obj_t * ui_ImageLine;
extern lv_obj_t * ui_ScreenSensors;
extern lv_obj_t * ui_StatusBar1;
extern lv_obj_t * ui_LabelTime1;
extern lv_obj_t * ui_ImageWifi1;
extern lv_obj_t * ui_ChartSensorValue;
extern lv_obj_t * ui_RollerSensors;
extern lv_obj_t * ui_ButtonNext1;
extern lv_obj_t * ui_Image7;
extern lv_obj_t * ui_ButtonPre2;
extern lv_obj_t * ui_Image9;
extern lv_obj_t * ui_ButtonSensorPower;
extern lv_obj_t * ui_Image13;
extern lv_obj_t * ui_ScreenSettings;
extern lv_obj_t * ui_StatusBar2;
extern lv_obj_t * ui_LabelTime2;
extern lv_obj_t * ui_ImageWifi2;
extern lv_obj_t * ui_ButtonWLAN;
extern lv_obj_t * ui_ImageWLAN;
extern lv_obj_t * ui_LabelWLAN;
extern lv_obj_t * ui_ImageLine1;
extern lv_obj_t * ui_TextAreaWLANInfo;
extern lv_obj_t * ui_SliderWLAN;
extern lv_obj_t * ui_ButtonPre1;
extern lv_obj_t * ui_Image10;
extern lv_obj_t * ui_ButtonWLANexpand;
extern lv_obj_t * ui_Image11;
extern lv_obj_t * ui_ButtonWLANSwitch;
extern lv_obj_t * ui_Image12;

void native_invert_state_screen(lv_event_t * e);

LV_IMG_DECLARE(ui_img_269584065);    // assets\wifi-slash.png
LV_IMG_DECLARE(ui_img_display_png);    // assets\display.png
LV_IMG_DECLARE(ui_img_settings2_png);    // assets\settings2.png
LV_IMG_DECLARE(ui_img_sensor2_png);    // assets\sensor2.png
LV_IMG_DECLARE(ui_img_monitor2_png);    // assets\monitor2.png
LV_IMG_DECLARE(ui_img_239678910);    // assets\chevron-right.png
LV_IMG_DECLARE(ui_img_669867669);    // assets\chevron-left.png
LV_IMG_DECLARE(ui_img_power_png);    // assets\power.png
LV_IMG_DECLARE(ui_img_line_png);    // assets\line.png
LV_IMG_DECLARE(ui_img_1840458530);    // assets\chevron-down.png
LV_IMG_DECLARE(ui_img_wlan_big2_png);    // assets\WLAN_big2.png


LV_FONT_DECLARE(ui_font_NeverMindDemiBold);
LV_FONT_DECLARE(ui_font_NeverMindHand);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
