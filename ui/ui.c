// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: HamsterBearDesktop

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScreenHome;
lv_obj_t * ui_StatusBar;
lv_obj_t * ui_LabelTime;
lv_obj_t * ui_ImageWifi;
lv_obj_t * ui_PanelApps;
lv_obj_t * ui_ButtonMoviePlayer;
lv_obj_t * ui_Image3;
lv_obj_t * ui_LabelMusic;
lv_obj_t * ui_ButtonSetting;
lv_obj_t * ui_Image2;
lv_obj_t * ui_LabelSetting;
lv_obj_t * ui_ButtonSensors;
lv_obj_t * ui_Image1;
lv_obj_t * ui_LabelSensors;
lv_obj_t * ui_ButtonSystemInfo;
lv_obj_t * ui_Image8;
lv_obj_t * ui_LabelSystemInfo;
lv_obj_t * ui_ButtonNext;
lv_obj_t * ui_Image5;
lv_obj_t * ui_ButtonPre;
lv_obj_t * ui_Image6;
lv_obj_t * ui_ButtonPower;
lv_obj_t * ui_Image4;
lv_obj_t * ui_LabelHint;
lv_obj_t * ui_ImageLine;
lv_obj_t * ui_ScreenSensors;
lv_obj_t * ui_StatusBar1;
lv_obj_t * ui_LabelTime1;
lv_obj_t * ui_ImageWifi1;
lv_obj_t * ui_ChartSensorValue;
lv_obj_t * ui_RollerSensors;
lv_obj_t * ui_ButtonNext1;
lv_obj_t * ui_Image7;
lv_obj_t * ui_ButtonPre2;
lv_obj_t * ui_Image9;
lv_obj_t * ui_ButtonSensorPower;
lv_obj_t * ui_Image13;
lv_obj_t * ui_ScreenSettings;
lv_obj_t * ui_StatusBar2;
lv_obj_t * ui_LabelTime2;
lv_obj_t * ui_ImageWifi2;
lv_obj_t * ui_ButtonWLAN;
lv_obj_t * ui_ImageWLAN;
lv_obj_t * ui_LabelWLAN;
lv_obj_t * ui_ImageLine1;
lv_obj_t * ui_TextAreaWLANInfo;
lv_obj_t * ui_SliderWLAN;
lv_obj_t * ui_ButtonPre1;
lv_obj_t * ui_Image10;
lv_obj_t * ui_ButtonWLANexpand;
lv_obj_t * ui_Image11;
lv_obj_t * ui_ButtonWLANSwitch;
lv_obj_t * ui_Image12;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

//
// FUNCTION HEADER
void slide_left_out_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void slide_left_out_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 150);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, -88);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}

//
// FUNCTION HEADER
void slide_right_out_Animation(lv_obj_t * TargetObject, int delay);

// FUNCTION
void slide_right_out_Animation(lv_obj_t * TargetObject, int delay)
{

    //
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 150);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, 88);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
static void ui_event_ButtonSetting(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_OVER_LEFT, 150, 0);
    }
}
static void ui_event_ButtonSensors(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenSensors, LV_SCR_LOAD_ANIM_OVER_LEFT, 150, 0);
    }
}
static void ui_event_ButtonNext(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        slide_right_out_Animation(ui_ButtonSetting, 0);
        slide_right_out_Animation(ui_ButtonMoviePlayer, 0);
        slide_right_out_Animation(ui_ButtonSensors, 0);
        slide_right_out_Animation(ui_ButtonSystemInfo, 0);
    }
}
static void ui_event_ButtonPre(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        slide_left_out_Animation(ui_ButtonMoviePlayer, 0);
        slide_left_out_Animation(ui_ButtonSetting, 0);
        slide_left_out_Animation(ui_ButtonSensors, 0);
        slide_left_out_Animation(ui_ButtonSystemInfo, 0);
    }
}
static void ui_event_ButtonPower(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        native_invert_state_screen(e);
    }
}
static void ui_event_ButtonNext1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_roller_set_property(ui_RollerSensors, _UI_ROLLER_PROPERTY_SELECTED_WITH_ANIM, 1);
    }
}
static void ui_event_ButtonPre2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenHome, LV_SCR_LOAD_ANIM_OVER_LEFT, 150, 0);
    }
}
static void ui_event_ButtonWLAN(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_basic_set_property(ui_ButtonWLAN, _UI_BASIC_PROPERTY_HEIGHT,  145);
        _ui_basic_set_property(ui_ButtonWLAN, _UI_BASIC_PROPERTY_POSITION_Y,  -4);
        _ui_basic_set_property(ui_ImageWLAN, _UI_BASIC_PROPERTY_POSITION_Y,  -47);
        _ui_basic_set_property(ui_LabelWLAN, _UI_BASIC_PROPERTY_POSITION_Y,  -47);
        _ui_basic_set_property(ui_ScreenHome, _UI_BASIC_PROPERTY_POSITION_Y,  -46);
    }
}
static void ui_event_ButtonPre1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_ScreenHome, LV_SCR_LOAD_ANIM_OVER_LEFT, 150, 0);
    }
}
static void ui_event_ButtonWLANexpand(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_basic_set_property(ui_ButtonWLAN, _UI_BASIC_PROPERTY_HEIGHT,  145);
        _ui_basic_set_property(ui_ButtonWLAN, _UI_BASIC_PROPERTY_POSITION_Y,  -4);
        _ui_basic_set_property(ui_ImageWLAN, _UI_BASIC_PROPERTY_POSITION_Y,  -47);
        _ui_basic_set_property(ui_LabelWLAN, _UI_BASIC_PROPERTY_POSITION_Y,  -47);
        _ui_basic_set_property(ui_SliderWLAN, _UI_BASIC_PROPERTY_POSITION_Y,  -47);
    }
}
static void ui_event_ButtonWLANSwitch(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_slider_set_property(ui_SliderWLAN, _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM, 1);
        _ui_image_set_property(ui_ImageWifi2, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wifi_png);
        _ui_image_set_property(ui_ImageWifi1, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wifi_png);
        _ui_image_set_property(ui_ImageWifi, _UI_IMAGE_PROPERTY_IMAGE, & ui_img_wifi_png);
    }
}

///////////////////// SCREENS ////////////////////
void ui_ScreenHome_screen_init(void)
{

    // ui_ScreenHome

    ui_ScreenHome = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ScreenHome, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ScreenHome, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHome, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StatusBar

    ui_StatusBar = lv_obj_create(ui_ScreenHome);

    lv_obj_set_width(ui_StatusBar, 278);
    lv_obj_set_height(ui_StatusBar, 39);

    lv_obj_set_x(ui_StatusBar, 0);
    lv_obj_set_y(ui_StatusBar, 0);

    lv_obj_clear_flag(ui_StatusBar, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_StatusBar, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatusBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTime

    ui_LabelTime = lv_label_create(ui_StatusBar);

    lv_obj_set_width(ui_LabelTime, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTime, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTime, -113);
    lv_obj_set_y(ui_LabelTime, 0);

    lv_obj_set_align(ui_LabelTime, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTime, "6:37");

    lv_obj_set_style_text_color(ui_LabelTime, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageWifi

    ui_ImageWifi = lv_img_create(ui_StatusBar);
    lv_img_set_src(ui_ImageWifi, &ui_img_269584065);

    lv_obj_set_width(ui_ImageWifi, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageWifi, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageWifi, 3);
    lv_obj_set_y(ui_ImageWifi, -3);

    lv_obj_set_align(ui_ImageWifi, LV_ALIGN_TOP_RIGHT);

    lv_obj_add_flag(ui_ImageWifi, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageWifi, LV_OBJ_FLAG_SCROLLABLE);

    // ui_PanelApps

    ui_PanelApps = lv_obj_create(ui_ScreenHome);

    lv_obj_set_width(ui_PanelApps, 278);
    lv_obj_set_height(ui_PanelApps, 173);

    lv_obj_set_x(ui_PanelApps, 0);
    lv_obj_set_y(ui_PanelApps, 30);

    lv_obj_set_align(ui_PanelApps, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_PanelApps, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonMoviePlayer

    ui_ButtonMoviePlayer = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonMoviePlayer, 80);
    lv_obj_set_height(ui_ButtonMoviePlayer, 80);

    lv_obj_set_x(ui_ButtonMoviePlayer, -88);
    lv_obj_set_y(ui_ButtonMoviePlayer, 0);

    lv_obj_set_align(ui_ButtonMoviePlayer, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_ButtonMoviePlayer, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonMoviePlayer, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonMoviePlayer, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMoviePlayer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image3

    ui_Image3 = lv_img_create(ui_ButtonMoviePlayer);
    lv_img_set_src(ui_Image3, &ui_img_display_png);

    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image3, 0);
    lv_obj_set_y(ui_Image3, -10);

    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelMusic

    ui_LabelMusic = lv_label_create(ui_ButtonMoviePlayer);

    lv_obj_set_width(ui_LabelMusic, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelMusic, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelMusic, 0);
    lv_obj_set_y(ui_LabelMusic, 30);

    lv_obj_set_align(ui_LabelMusic, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelMusic, "Movies");

    lv_obj_set_style_text_color(ui_LabelMusic, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMusic, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonSetting

    ui_ButtonSetting = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonSetting, 80);
    lv_obj_set_height(ui_ButtonSetting, 80);

    lv_obj_set_x(ui_ButtonSetting, 0);
    lv_obj_set_y(ui_ButtonSetting, 0);

    lv_obj_set_align(ui_ButtonSetting, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_ButtonSetting, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonSetting, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonSetting, ui_event_ButtonSetting, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonSetting, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSetting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image2

    ui_Image2 = lv_img_create(ui_ButtonSetting);
    lv_img_set_src(ui_Image2, &ui_img_settings2_png);

    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image2, 0);
    lv_obj_set_y(ui_Image2, -10);

    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelSetting

    ui_LabelSetting = lv_label_create(ui_ButtonSetting);

    lv_obj_set_width(ui_LabelSetting, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSetting, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSetting, 0);
    lv_obj_set_y(ui_LabelSetting, 30);

    lv_obj_set_align(ui_LabelSetting, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSetting, "Setting");

    lv_obj_set_style_text_color(ui_LabelSetting, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSetting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonSensors

    ui_ButtonSensors = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonSensors, 80);
    lv_obj_set_height(ui_ButtonSensors, 80);

    lv_obj_set_x(ui_ButtonSensors, 88);
    lv_obj_set_y(ui_ButtonSensors, 0);

    lv_obj_set_align(ui_ButtonSensors, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_ButtonSensors, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonSensors, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonSensors, ui_event_ButtonSensors, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonSensors, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSensors, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image1

    ui_Image1 = lv_img_create(ui_ButtonSensors);
    lv_img_set_src(ui_Image1, &ui_img_sensor2_png);

    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image1, 0);
    lv_obj_set_y(ui_Image1, -8);

    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelSensors

    ui_LabelSensors = lv_label_create(ui_ButtonSensors);

    lv_obj_set_width(ui_LabelSensors, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSensors, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSensors, 0);
    lv_obj_set_y(ui_LabelSensors, 30);

    lv_obj_set_align(ui_LabelSensors, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSensors, "Sensors");

    lv_obj_set_style_text_color(ui_LabelSensors, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSensors, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonSystemInfo

    ui_ButtonSystemInfo = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonSystemInfo, 80);
    lv_obj_set_height(ui_ButtonSystemInfo, 80);

    lv_obj_set_x(ui_ButtonSystemInfo, 176);
    lv_obj_set_y(ui_ButtonSystemInfo, 0);

    lv_obj_set_align(ui_ButtonSystemInfo, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_ButtonSystemInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonSystemInfo, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonSystemInfo, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSystemInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image8

    ui_Image8 = lv_img_create(ui_ButtonSystemInfo);
    lv_img_set_src(ui_Image8, &ui_img_monitor2_png);

    lv_obj_set_width(ui_Image8, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image8, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image8, 0);
    lv_obj_set_y(ui_Image8, -5);

    lv_obj_set_align(ui_Image8, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image8, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image8, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelSystemInfo

    ui_LabelSystemInfo = lv_label_create(ui_ButtonSystemInfo);

    lv_obj_set_width(ui_LabelSystemInfo, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSystemInfo, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSystemInfo, 0);
    lv_obj_set_y(ui_LabelSystemInfo, 30);

    lv_obj_set_align(ui_LabelSystemInfo, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSystemInfo, "Monitor");

    lv_obj_set_style_text_color(ui_LabelSystemInfo, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSystemInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonNext

    ui_ButtonNext = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonNext, 30);
    lv_obj_set_height(ui_ButtonNext, 30);

    lv_obj_set_x(ui_ButtonNext, 36);
    lv_obj_set_y(ui_ButtonNext, 7);

    lv_obj_set_align(ui_ButtonNext, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonNext, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonNext, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonNext, ui_event_ButtonNext, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonNext, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonNext, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image5

    ui_Image5 = lv_img_create(ui_ButtonNext);
    lv_img_set_src(ui_Image5, &ui_img_239678910);

    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image5, 1);
    lv_obj_set_y(ui_Image5, 1);

    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonPre

    ui_ButtonPre = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonPre, 30);
    lv_obj_set_height(ui_ButtonPre, 30);

    lv_obj_set_x(ui_ButtonPre, -36);
    lv_obj_set_y(ui_ButtonPre, 7);

    lv_obj_set_align(ui_ButtonPre, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonPre, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonPre, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonPre, ui_event_ButtonPre, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonPre, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPre, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image6

    ui_Image6 = lv_img_create(ui_ButtonPre);
    lv_img_set_src(ui_Image6, &ui_img_669867669);

    lv_obj_set_width(ui_Image6, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image6, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image6, -1);
    lv_obj_set_y(ui_Image6, 1);

    lv_obj_set_align(ui_Image6, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image6, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image6, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonPower

    ui_ButtonPower = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonPower, 30);
    lv_obj_set_height(ui_ButtonPower, 30);

    lv_obj_set_x(ui_ButtonPower, 0);
    lv_obj_set_y(ui_ButtonPower, 7);

    lv_obj_set_align(ui_ButtonPower, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonPower, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonPower, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonPower, ui_event_ButtonPower, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonPower, lv_color_hex(0x4A6173), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPower, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image4

    ui_Image4 = lv_img_create(ui_ButtonPower);
    lv_img_set_src(ui_Image4, &ui_img_power_png);

    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image4, 0);
    lv_obj_set_y(ui_Image4, 0);

    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelHint

    ui_LabelHint = lv_label_create(ui_ScreenHome);

    lv_obj_set_width(ui_LabelHint, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelHint, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelHint, 0);
    lv_obj_set_y(ui_LabelHint, -68);

    lv_obj_set_align(ui_LabelHint, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelHint, "Good morning, Mike");

    lv_obj_set_style_text_color(ui_LabelHint, lv_color_hex(0x050505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHint, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHint, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_LabelHint, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHint, &ui_font_NeverMindDemiBold, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageLine

    ui_ImageLine = lv_img_create(ui_ScreenHome);
    lv_img_set_src(ui_ImageLine, &ui_img_line_png);

    lv_obj_set_width(ui_ImageLine, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageLine, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageLine, 0);
    lv_obj_set_y(ui_ImageLine, 65);

    lv_obj_set_align(ui_ImageLine, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageLine, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageLine, LV_OBJ_FLAG_SCROLLABLE);

}
void ui_ScreenSensors_screen_init(void)
{

    // ui_ScreenSensors

    ui_ScreenSensors = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ScreenSensors, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ScreenSensors, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenSensors, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StatusBar1

    ui_StatusBar1 = lv_obj_create(ui_ScreenSensors);

    lv_obj_set_width(ui_StatusBar1, 278);
    lv_obj_set_height(ui_StatusBar1, 39);

    lv_obj_set_x(ui_StatusBar1, 0);
    lv_obj_set_y(ui_StatusBar1, 0);

    lv_obj_clear_flag(ui_StatusBar1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_StatusBar1, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatusBar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTime1

    ui_LabelTime1 = lv_label_create(ui_StatusBar1);

    lv_obj_set_width(ui_LabelTime1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTime1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTime1, -113);
    lv_obj_set_y(ui_LabelTime1, 0);

    lv_obj_set_align(ui_LabelTime1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTime1, "6:37");

    lv_obj_set_style_text_color(ui_LabelTime1, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTime1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageWifi1

    ui_ImageWifi1 = lv_img_create(ui_StatusBar1);
    lv_img_set_src(ui_ImageWifi1, &ui_img_269584065);

    lv_obj_set_width(ui_ImageWifi1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageWifi1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageWifi1, 3);
    lv_obj_set_y(ui_ImageWifi1, -3);

    lv_obj_set_align(ui_ImageWifi1, LV_ALIGN_TOP_RIGHT);

    lv_obj_add_flag(ui_ImageWifi1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageWifi1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ChartSensorValue

    ui_ChartSensorValue = lv_chart_create(ui_ScreenSensors);

    lv_obj_set_width(ui_ChartSensorValue, 165);
    lv_obj_set_height(ui_ChartSensorValue, 153);

    lv_obj_set_x(ui_ChartSensorValue, 53);
    lv_obj_set_y(ui_ChartSensorValue, -3);

    lv_obj_set_align(ui_ChartSensorValue, LV_ALIGN_CENTER);

    // ui_RollerSensors

    ui_RollerSensors = lv_roller_create(ui_ScreenSensors);
    lv_roller_set_options(ui_RollerSensors, "Temp\nHuman\nLight\nLevel", LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_RollerSensors, 153);
    lv_obj_set_width(ui_RollerSensors, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_RollerSensors, -96);
    lv_obj_set_y(ui_RollerSensors, -3);

    lv_obj_set_align(ui_RollerSensors, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_RollerSensors, lv_color_hex(0x4A6173), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RollerSensors, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_ButtonNext1

    ui_ButtonNext1 = lv_btn_create(ui_ScreenSensors);

    lv_obj_set_width(ui_ButtonNext1, 30);
    lv_obj_set_height(ui_ButtonNext1, 30);

    lv_obj_set_x(ui_ButtonNext1, 36);
    lv_obj_set_y(ui_ButtonNext1, -10);

    lv_obj_set_align(ui_ButtonNext1, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonNext1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonNext1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonNext1, ui_event_ButtonNext1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonNext1, lv_color_hex(0x4A6173), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonNext1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image7

    ui_Image7 = lv_img_create(ui_ButtonNext1);
    lv_img_set_src(ui_Image7, &ui_img_1840458530);

    lv_obj_set_width(ui_Image7, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image7, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image7, 0);
    lv_obj_set_y(ui_Image7, 1);

    lv_obj_set_align(ui_Image7, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image7, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image7, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonPre2

    ui_ButtonPre2 = lv_btn_create(ui_ScreenSensors);

    lv_obj_set_width(ui_ButtonPre2, 30);
    lv_obj_set_height(ui_ButtonPre2, 30);

    lv_obj_set_x(ui_ButtonPre2, -36);
    lv_obj_set_y(ui_ButtonPre2, -10);

    lv_obj_set_align(ui_ButtonPre2, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonPre2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonPre2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonPre2, ui_event_ButtonPre2, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonPre2, lv_color_hex(0x4A6173), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPre2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image9

    ui_Image9 = lv_img_create(ui_ButtonPre2);
    lv_img_set_src(ui_Image9, &ui_img_669867669);

    lv_obj_set_width(ui_Image9, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image9, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image9, -1);
    lv_obj_set_y(ui_Image9, 1);

    lv_obj_set_align(ui_Image9, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image9, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image9, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonSensorPower

    ui_ButtonSensorPower = lv_btn_create(ui_ScreenSensors);

    lv_obj_set_width(ui_ButtonSensorPower, 30);
    lv_obj_set_height(ui_ButtonSensorPower, 30);

    lv_obj_set_x(ui_ButtonSensorPower, 0);
    lv_obj_set_y(ui_ButtonSensorPower, -10);

    lv_obj_set_align(ui_ButtonSensorPower, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonSensorPower, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonSensorPower, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonSensorPower, lv_color_hex(0x4A6173), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSensorPower, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image13

    ui_Image13 = lv_img_create(ui_ButtonSensorPower);
    lv_img_set_src(ui_Image13, &ui_img_power_png);

    lv_obj_set_width(ui_Image13, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image13, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image13, 0);
    lv_obj_set_y(ui_Image13, 0);

    lv_obj_set_align(ui_Image13, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image13, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image13, LV_OBJ_FLAG_SCROLLABLE);

}
void ui_ScreenSettings_screen_init(void)
{

    // ui_ScreenSettings

    ui_ScreenSettings = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ScreenSettings, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ScreenSettings, lv_color_hex(0xE1E1E1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_StatusBar2

    ui_StatusBar2 = lv_obj_create(ui_ScreenSettings);

    lv_obj_set_width(ui_StatusBar2, 278);
    lv_obj_set_height(ui_StatusBar2, 39);

    lv_obj_set_x(ui_StatusBar2, 0);
    lv_obj_set_y(ui_StatusBar2, 0);

    lv_obj_clear_flag(ui_StatusBar2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_StatusBar2, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatusBar2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTime2

    ui_LabelTime2 = lv_label_create(ui_StatusBar2);

    lv_obj_set_width(ui_LabelTime2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTime2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTime2, -113);
    lv_obj_set_y(ui_LabelTime2, 0);

    lv_obj_set_align(ui_LabelTime2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTime2, "6:37");

    lv_obj_set_style_text_color(ui_LabelTime2, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTime2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageWifi2

    ui_ImageWifi2 = lv_img_create(ui_StatusBar2);
    lv_img_set_src(ui_ImageWifi2, &ui_img_269584065);

    lv_obj_set_width(ui_ImageWifi2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageWifi2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageWifi2, 3);
    lv_obj_set_y(ui_ImageWifi2, -3);

    lv_obj_set_align(ui_ImageWifi2, LV_ALIGN_TOP_RIGHT);

    lv_obj_add_flag(ui_ImageWifi2, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageWifi2, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonWLAN

    ui_ButtonWLAN = lv_btn_create(ui_ScreenSettings);

    lv_obj_set_width(ui_ButtonWLAN, 270);
    lv_obj_set_height(ui_ButtonWLAN, 50);

    lv_obj_set_x(ui_ButtonWLAN, 0);
    lv_obj_set_y(ui_ButtonWLAN, -51);

    lv_obj_set_align(ui_ButtonWLAN, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonWLAN, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonWLAN, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonWLAN, ui_event_ButtonWLAN, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonWLAN, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonWLAN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonWLAN, lv_color_hex(0xC8C8C8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonWLAN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonWLAN, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageWLAN

    ui_ImageWLAN = lv_img_create(ui_ButtonWLAN);
    lv_img_set_src(ui_ImageWLAN, &ui_img_wlan_big2_png);

    lv_obj_set_width(ui_ImageWLAN, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageWLAN, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageWLAN, 0);
    lv_obj_set_y(ui_ImageWLAN, 0);

    lv_obj_set_align(ui_ImageWLAN, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_ImageWLAN, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageWLAN, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelWLAN

    ui_LabelWLAN = lv_label_create(ui_ButtonWLAN);

    lv_obj_set_width(ui_LabelWLAN, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelWLAN, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelWLAN, 39);
    lv_obj_set_y(ui_LabelWLAN, 0);

    lv_obj_set_align(ui_LabelWLAN, LV_ALIGN_LEFT_MID);

    lv_label_set_text(ui_LabelWLAN, "WLAN and Internet");

    lv_obj_set_style_text_color(ui_LabelWLAN, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelWLAN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ImageLine1

    ui_ImageLine1 = lv_img_create(ui_ButtonWLAN);
    lv_img_set_src(ui_ImageLine1, &ui_img_line_png);

    lv_obj_set_width(ui_ImageLine1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageLine1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageLine1, 0);
    lv_obj_set_y(ui_ImageLine1, 32);

    lv_obj_set_align(ui_ImageLine1, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_ImageLine1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageLine1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_TextAreaWLANInfo

    ui_TextAreaWLANInfo = lv_textarea_create(ui_ButtonWLAN);

    lv_obj_set_width(ui_TextAreaWLANInfo, 260);
    lv_obj_set_height(ui_TextAreaWLANInfo, 85);

    lv_obj_set_x(ui_TextAreaWLANInfo, 0);
    lv_obj_set_y(ui_TextAreaWLANInfo, 47);

    lv_obj_set_align(ui_TextAreaWLANInfo, LV_ALIGN_TOP_MID);

    if("" == "") lv_textarea_set_accepted_chars(ui_TextAreaWLANInfo, NULL);
    else lv_textarea_set_accepted_chars(ui_TextAreaWLANInfo, "");

    lv_textarea_set_text(ui_TextAreaWLANInfo,
                         "ESSID:  kernelbot\nFrequency: 2.422GHz\nBit Rate: 72.2 Mb/s\nIP addr: 192.168.31.189");
    lv_textarea_set_placeholder_text(ui_TextAreaWLANInfo, "Placeholder...");

    // ui_SliderWLAN

    ui_SliderWLAN = lv_slider_create(ui_ButtonWLAN);
    lv_slider_set_range(ui_SliderWLAN, 0, 1);

    lv_obj_set_width(ui_SliderWLAN, 35);
    lv_obj_set_height(ui_SliderWLAN, 10);

    lv_obj_set_x(ui_SliderWLAN, -3);
    lv_obj_set_y(ui_SliderWLAN, 0);

    lv_obj_set_align(ui_SliderWLAN, LV_ALIGN_RIGHT_MID);

    lv_obj_set_style_radius(ui_SliderWLAN, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SliderWLAN, lv_color_hex(0x878787), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderWLAN, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_SliderWLAN, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SliderWLAN, lv_color_hex(0x4A6175), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderWLAN, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_SliderWLAN, 3, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SliderWLAN, lv_color_hex(0x555555), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SliderWLAN, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    // ui_ButtonPre1

    ui_ButtonPre1 = lv_btn_create(ui_ScreenSettings);

    lv_obj_set_width(ui_ButtonPre1, 30);
    lv_obj_set_height(ui_ButtonPre1, 30);

    lv_obj_set_x(ui_ButtonPre1, -36);
    lv_obj_set_y(ui_ButtonPre1, -10);

    lv_obj_set_align(ui_ButtonPre1, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonPre1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonPre1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonPre1, ui_event_ButtonPre1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonPre1, lv_color_hex(0x4A6173), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPre1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image10

    ui_Image10 = lv_img_create(ui_ButtonPre1);
    lv_img_set_src(ui_Image10, &ui_img_669867669);

    lv_obj_set_width(ui_Image10, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image10, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image10, -1);
    lv_obj_set_y(ui_Image10, 1);

    lv_obj_set_align(ui_Image10, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image10, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image10, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonWLANexpand

    ui_ButtonWLANexpand = lv_btn_create(ui_ScreenSettings);

    lv_obj_set_width(ui_ButtonWLANexpand, 30);
    lv_obj_set_height(ui_ButtonWLANexpand, 30);

    lv_obj_set_x(ui_ButtonWLANexpand, 36);
    lv_obj_set_y(ui_ButtonWLANexpand, -10);

    lv_obj_set_align(ui_ButtonWLANexpand, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonWLANexpand, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonWLANexpand, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonWLANexpand, ui_event_ButtonWLANexpand, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonWLANexpand, lv_color_hex(0x4A6173), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonWLANexpand, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image11

    ui_Image11 = lv_img_create(ui_ButtonWLANexpand);
    lv_img_set_src(ui_Image11, &ui_img_1840458530);

    lv_obj_set_width(ui_Image11, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image11, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image11, 0);
    lv_obj_set_y(ui_Image11, 1);

    lv_obj_set_align(ui_Image11, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image11, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image11, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonWLANSwitch

    ui_ButtonWLANSwitch = lv_btn_create(ui_ScreenSettings);

    lv_obj_set_width(ui_ButtonWLANSwitch, 30);
    lv_obj_set_height(ui_ButtonWLANSwitch, 30);

    lv_obj_set_x(ui_ButtonWLANSwitch, 0);
    lv_obj_set_y(ui_ButtonWLANSwitch, -10);

    lv_obj_set_align(ui_ButtonWLANSwitch, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_flag(ui_ButtonWLANSwitch, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonWLANSwitch, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonWLANSwitch, ui_event_ButtonWLANSwitch, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonWLANSwitch, lv_color_hex(0x4A6173), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonWLANSwitch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image12

    ui_Image12 = lv_img_create(ui_ButtonWLANSwitch);
    lv_img_set_src(ui_Image12, &ui_img_power_png);

    lv_obj_set_width(ui_Image12, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image12, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image12, 0);
    lv_obj_set_y(ui_Image12, 0);

    lv_obj_set_align(ui_Image12, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image12, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image12, LV_OBJ_FLAG_SCROLLABLE);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenHome_screen_init();
    ui_ScreenSensors_screen_init();
    ui_ScreenSettings_screen_init();
    lv_disp_load_scr(ui_ScreenHome);
}

