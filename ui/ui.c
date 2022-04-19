// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: HamsterBearDesktop

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_BgImage;
lv_obj_t * ui_StatusBar;
lv_obj_t * ui_LabelBattery;
lv_obj_t * ui_LabelTime;
lv_obj_t * ui_ImageBattery;
lv_obj_t * ui_ImageBluetooth;
lv_obj_t * ui_PanelApps;
lv_obj_t * ui_ButtonMusic;
lv_obj_t * ui_Image3;
lv_obj_t * ui_LabelMusic;
lv_obj_t * ui_ButtonSetting;
lv_obj_t * ui_Image2;
lv_obj_t * ui_LabelSetting;
lv_obj_t * ui_ButtonBrowser;
lv_obj_t * ui_Image4;
lv_obj_t * ui_LabelBrowser;
lv_obj_t * ui_ButtonSensors;
lv_obj_t * ui_Image1;
lv_obj_t * ui_LabelSensors;
lv_obj_t * ui_ButtonSystemInfo;
lv_obj_t * ui_Image8;
lv_obj_t * ui_LabelSystemInfo;
lv_obj_t * ui_PanelMore;
lv_obj_t * ui_ButtonBack;
lv_obj_t * ui_Image7;
lv_obj_t * ui_ButtonNext;
lv_obj_t * ui_Image5;
lv_obj_t * ui_ButtonPre;
lv_obj_t * ui_Image6;
lv_obj_t * ui_ImageLine;
lv_obj_t * ui_LabelTips;
lv_obj_t * ui_Sensors;
lv_obj_t * ui_BgImage1;
lv_obj_t * ui_StatusBar1;
lv_obj_t * ui_LabelBattery1;
lv_obj_t * ui_LabelTime1;
lv_obj_t * ui_ImageBattery1;
lv_obj_t * ui_ImageBluetooth1;
lv_obj_t * ui_LabelTips1;
lv_obj_t * ui_PanelMain;
lv_obj_t * ui_Roller1;
lv_obj_t * ui_ImageLine1;
lv_obj_t * ui_ButtonPre1;
lv_obj_t * ui_Image11;

extern lv_indev_t * indev_keypad;

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
static void ui_event_ButtonSensors(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Sensors, LV_SCR_LOAD_ANIM_OVER_LEFT, 150, 0);
    }
}
static void ui_event_ButtonBack(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_OVER_LEFT, 150, 0);
    }
}
static void ui_event_ButtonNext(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        slide_right_out_Animation(ui_ButtonSetting, 0);
        slide_right_out_Animation(ui_ButtonBrowser, 0);
        slide_right_out_Animation(ui_ButtonMusic, 0);
        slide_right_out_Animation(ui_ButtonSensors, 0);
        slide_right_out_Animation(ui_ButtonSystemInfo, 0);
    }
}
static void ui_event_ButtonPre(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        slide_left_out_Animation(ui_ButtonMusic, 0);
        slide_left_out_Animation(ui_ButtonBrowser, 0);
        slide_left_out_Animation(ui_ButtonSetting, 0);
        slide_left_out_Animation(ui_ButtonSensors, 0);
        slide_left_out_Animation(ui_ButtonSystemInfo, 0);
    }
}
static void ui_event_ButtonPre1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Screen1, LV_SCR_LOAD_ANIM_OVER_LEFT, 150, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{

    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_BgImage

    ui_BgImage = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_BgImage, &ui_img_hamsterbear_desktop_bg_lite_png);

    lv_obj_set_width(ui_BgImage, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BgImage, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BgImage, 0);
    lv_obj_set_y(ui_BgImage, 0);

    lv_obj_set_align(ui_BgImage, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_BgImage, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_BgImage, LV_OBJ_FLAG_SCROLLABLE);

    // ui_StatusBar

    ui_StatusBar = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_StatusBar, 278);
    lv_obj_set_height(ui_StatusBar, 39);

    lv_obj_set_x(ui_StatusBar, 0);
    lv_obj_set_y(ui_StatusBar, 0);

    lv_obj_clear_flag(ui_StatusBar, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_StatusBar, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatusBar, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelBattery

    ui_LabelBattery = lv_label_create(ui_StatusBar);

    lv_obj_set_width(ui_LabelBattery, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelBattery, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelBattery, 85);
    lv_obj_set_y(ui_LabelBattery, 0);

    lv_obj_set_align(ui_LabelBattery, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelBattery, "54%");

    lv_obj_set_style_text_color(ui_LabelBattery, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBattery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

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

    // ui_ImageBattery

    ui_ImageBattery = lv_img_create(ui_StatusBar);
    lv_img_set_src(ui_ImageBattery, &ui_img_icn_battery_png);

    lv_obj_set_width(ui_ImageBattery, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageBattery, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageBattery, 116);
    lv_obj_set_y(ui_ImageBattery, 0);

    lv_obj_set_align(ui_ImageBattery, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageBattery, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageBattery, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ImageBluetooth

    ui_ImageBluetooth = lv_img_create(ui_StatusBar);
    lv_img_set_src(ui_ImageBluetooth, &ui_img_icn_bluetooth_png);

    lv_obj_set_width(ui_ImageBluetooth, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageBluetooth, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageBluetooth, 54);
    lv_obj_set_y(ui_ImageBluetooth, 0);

    lv_obj_set_align(ui_ImageBluetooth, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageBluetooth, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageBluetooth, LV_OBJ_FLAG_SCROLLABLE);

    // ui_PanelApps

    ui_PanelApps = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_PanelApps, 278);
    lv_obj_set_height(ui_PanelApps, 130);

    lv_obj_set_x(ui_PanelApps, 0);
    lv_obj_set_y(ui_PanelApps, 40);

    lv_obj_set_align(ui_PanelApps, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_PanelApps, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonMusic

    ui_ButtonMusic = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonMusic, 80);
    lv_obj_set_height(ui_ButtonMusic, 80);

    lv_obj_set_x(ui_ButtonMusic, 0);
    lv_obj_set_y(ui_ButtonMusic, 0);

    lv_obj_set_align(ui_ButtonMusic, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonMusic, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonMusic, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonMusic, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMusic, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image3

    ui_Image3 = lv_img_create(ui_ButtonMusic);
    lv_img_set_src(ui_Image3, &ui_img_music_png);

    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image3, 0);
    lv_obj_set_y(ui_Image3, -10);

    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelMusic

    ui_LabelMusic = lv_label_create(ui_ButtonMusic);

    lv_obj_set_width(ui_LabelMusic, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelMusic, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelMusic, 0);
    lv_obj_set_y(ui_LabelMusic, 30);

    lv_obj_set_align(ui_LabelMusic, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelMusic, "Music");

    lv_obj_set_style_text_color(ui_LabelMusic, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMusic, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonSetting

    ui_ButtonSetting = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonSetting, 80);
    lv_obj_set_height(ui_ButtonSetting, 80);

    lv_obj_set_x(ui_ButtonSetting, 89);
    lv_obj_set_y(ui_ButtonSetting, 0);

    lv_obj_set_align(ui_ButtonSetting, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonSetting, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonSetting, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonSetting, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSetting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image2

    ui_Image2 = lv_img_create(ui_ButtonSetting);
    lv_img_set_src(ui_Image2, &ui_img_setting_png);

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

    // ui_ButtonBrowser

    ui_ButtonBrowser = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonBrowser, 80);
    lv_obj_set_height(ui_ButtonBrowser, 80);

    lv_obj_set_x(ui_ButtonBrowser, -88);
    lv_obj_set_y(ui_ButtonBrowser, 0);

    lv_obj_set_align(ui_ButtonBrowser, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonBrowser, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonBrowser, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonBrowser, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBrowser, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image4

    ui_Image4 = lv_img_create(ui_ButtonBrowser);
    lv_img_set_src(ui_Image4, &ui_img_browser_png);

    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image4, 0);
    lv_obj_set_y(ui_Image4, -10);

    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelBrowser

    ui_LabelBrowser = lv_label_create(ui_ButtonBrowser);

    lv_obj_set_width(ui_LabelBrowser, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelBrowser, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelBrowser, 0);
    lv_obj_set_y(ui_LabelBrowser, 30);

    lv_obj_set_align(ui_LabelBrowser, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelBrowser, "Browser");

    lv_obj_set_style_text_color(ui_LabelBrowser, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBrowser, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonSensors

    ui_ButtonSensors = lv_btn_create(ui_PanelApps);

    lv_obj_set_width(ui_ButtonSensors, 80);
    lv_obj_set_height(ui_ButtonSensors, 80);

    lv_obj_set_x(ui_ButtonSensors, 176);
    lv_obj_set_y(ui_ButtonSensors, 0);

    lv_obj_set_align(ui_ButtonSensors, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonSensors, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonSensors, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonSensors, ui_event_ButtonSensors, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonSensors, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSensors, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image1

    ui_Image1 = lv_img_create(ui_ButtonSensors);
    lv_img_set_src(ui_Image1, &ui_img_sensor_png);

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

    lv_obj_set_x(ui_ButtonSystemInfo, 264);
    lv_obj_set_y(ui_ButtonSystemInfo, 0);

    lv_obj_set_align(ui_ButtonSystemInfo, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonSystemInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonSystemInfo, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_ButtonSystemInfo, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSystemInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image8

    ui_Image8 = lv_img_create(ui_ButtonSystemInfo);
    lv_img_set_src(ui_Image8, &ui_img_monitor_png);

    lv_obj_set_width(ui_Image8, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image8, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image8, 0);
    lv_obj_set_y(ui_Image8, -8);

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

    // ui_PanelMore

    ui_PanelMore = lv_obj_create(ui_Screen1);

    lv_obj_set_width(ui_PanelMore, 278);
    lv_obj_set_height(ui_PanelMore, 41);

    lv_obj_set_x(ui_PanelMore, 0);
    lv_obj_set_y(ui_PanelMore, 70);

    lv_obj_set_align(ui_PanelMore, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_PanelMore, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonBack

    ui_ButtonBack = lv_btn_create(ui_PanelMore);

    lv_obj_set_width(ui_ButtonBack, 30);
    lv_obj_set_height(ui_ButtonBack, 30);

    lv_obj_set_x(ui_ButtonBack, 0);
    lv_obj_set_y(ui_ButtonBack, 0);

    lv_obj_set_align(ui_ButtonBack, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonBack, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonBack, ui_event_ButtonBack, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonBack, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image7

    ui_Image7 = lv_img_create(ui_ButtonBack);
    lv_img_set_src(ui_Image7, &ui_img_1871139225);

    lv_obj_set_width(ui_Image7, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image7, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image7, 0);
    lv_obj_set_y(ui_Image7, 0);

    lv_obj_set_align(ui_Image7, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image7, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image7, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonNext

    ui_ButtonNext = lv_btn_create(ui_PanelMore);

    lv_obj_set_width(ui_ButtonNext, 30);
    lv_obj_set_height(ui_ButtonNext, 30);

    lv_obj_set_x(ui_ButtonNext, 33);
    lv_obj_set_y(ui_ButtonNext, 0);

    lv_obj_set_align(ui_ButtonNext, LV_ALIGN_CENTER);

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

    ui_ButtonPre = lv_btn_create(ui_PanelMore);

    lv_obj_set_width(ui_ButtonPre, 30);
    lv_obj_set_height(ui_ButtonPre, 30);

    lv_obj_set_x(ui_ButtonPre, -34);
    lv_obj_set_y(ui_ButtonPre, 0);

    lv_obj_set_align(ui_ButtonPre, LV_ALIGN_CENTER);

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

    // ui_ImageLine

    ui_ImageLine = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_ImageLine, &ui_img_img_line_png);

    lv_obj_set_width(ui_ImageLine, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageLine, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageLine, 24);
    lv_obj_set_y(ui_ImageLine, 91);

    lv_obj_set_align(ui_ImageLine, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageLine, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageLine, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelTips

    ui_LabelTips = lv_label_create(ui_Screen1);

    lv_obj_set_width(ui_LabelTips, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTips, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTips, 0);
    lv_obj_set_y(ui_LabelTips, 105);

    lv_obj_set_align(ui_LabelTips, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTips, "Don't have a good day, have a great day");

    lv_obj_set_style_text_color(ui_LabelTips, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTips, &ui_font_NeverMindDemiBold, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_Sensors_screen_init(void)
{

    // ui_Sensors

    ui_Sensors = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Sensors, LV_OBJ_FLAG_SCROLLABLE);

    // ui_BgImage1

    ui_BgImage1 = lv_img_create(ui_Sensors);
    lv_img_set_src(ui_BgImage1, &ui_img_hamsterbear_desktop_bg_lite_png);

    lv_obj_set_width(ui_BgImage1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_BgImage1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_BgImage1, 0);
    lv_obj_set_y(ui_BgImage1, 0);

    lv_obj_set_align(ui_BgImage1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_BgImage1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_BgImage1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_StatusBar1

    ui_StatusBar1 = lv_obj_create(ui_Sensors);

    lv_obj_set_width(ui_StatusBar1, 278);
    lv_obj_set_height(ui_StatusBar1, 39);

    lv_obj_set_x(ui_StatusBar1, 0);
    lv_obj_set_y(ui_StatusBar1, 0);

    lv_obj_clear_flag(ui_StatusBar1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(ui_StatusBar1, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_StatusBar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelBattery1

    ui_LabelBattery1 = lv_label_create(ui_StatusBar1);

    lv_obj_set_width(ui_LabelBattery1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelBattery1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelBattery1, 85);
    lv_obj_set_y(ui_LabelBattery1, 0);

    lv_obj_set_align(ui_LabelBattery1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelBattery1, "54%");

    lv_obj_set_style_text_color(ui_LabelBattery1, lv_color_hex(0xEBEBEB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBattery1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

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

    // ui_ImageBattery1

    ui_ImageBattery1 = lv_img_create(ui_StatusBar1);
    lv_img_set_src(ui_ImageBattery1, &ui_img_icn_battery_png);

    lv_obj_set_width(ui_ImageBattery1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageBattery1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageBattery1, 116);
    lv_obj_set_y(ui_ImageBattery1, 0);

    lv_obj_set_align(ui_ImageBattery1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageBattery1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageBattery1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ImageBluetooth1

    ui_ImageBluetooth1 = lv_img_create(ui_StatusBar1);
    lv_img_set_src(ui_ImageBluetooth1, &ui_img_icn_bluetooth_png);

    lv_obj_set_width(ui_ImageBluetooth1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageBluetooth1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageBluetooth1, 54);
    lv_obj_set_y(ui_ImageBluetooth1, 0);

    lv_obj_set_align(ui_ImageBluetooth1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageBluetooth1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageBluetooth1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelTips1

    ui_LabelTips1 = lv_label_create(ui_Sensors);

    lv_obj_set_width(ui_LabelTips1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTips1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTips1, 0);
    lv_obj_set_y(ui_LabelTips1, 105);

    lv_obj_set_align(ui_LabelTips1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTips1, "Rise above, focus on science");

    lv_obj_set_style_text_color(ui_LabelTips1, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTips1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTips1, &ui_font_NeverMindDemiBold, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PanelMain

    ui_PanelMain = lv_obj_create(ui_Sensors);

    lv_obj_set_width(ui_PanelMain, 278);
    lv_obj_set_height(ui_PanelMain, 154);

    lv_obj_set_x(ui_PanelMain, 0);
    lv_obj_set_y(ui_PanelMain, 40);

    lv_obj_set_align(ui_PanelMain, LV_ALIGN_TOP_MID);

    lv_obj_clear_flag(ui_PanelMain, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Roller1

    ui_Roller1 = lv_roller_create(ui_PanelMain);
    lv_roller_set_options(ui_Roller1, "Light\nLevel\nDistance\nTemp\n", LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_Roller1, 142);
    lv_obj_set_width(ui_Roller1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Roller1, -86);
    lv_obj_set_y(ui_Roller1, -3);

    lv_obj_set_align(ui_Roller1, LV_ALIGN_CENTER);

    lv_obj_set_style_border_color(ui_Roller1, lv_color_hex(0x969696), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Roller1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Roller1, lv_color_hex(0xEBEBEB), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Roller1, lv_color_hex(0x2D2D2D), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Roller1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_ImageLine1

    ui_ImageLine1 = lv_img_create(ui_Sensors);
    lv_img_set_src(ui_ImageLine1, &ui_img_img_line_png);

    lv_obj_set_width(ui_ImageLine1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageLine1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageLine1, 24);
    lv_obj_set_y(ui_ImageLine1, 91);

    lv_obj_set_align(ui_ImageLine1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageLine1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageLine1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonPre1

    ui_ButtonPre1 = lv_btn_create(ui_Sensors);

    lv_obj_set_width(ui_ButtonPre1, 30);
    lv_obj_set_height(ui_ButtonPre1, 30);

    lv_obj_set_x(ui_ButtonPre1, 7);
    lv_obj_set_y(ui_ButtonPre1, 98);

    lv_obj_set_align(ui_ButtonPre1, LV_ALIGN_LEFT_MID);

    lv_obj_add_flag(ui_ButtonPre1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonPre1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonPre1, ui_event_ButtonPre1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonPre1, lv_color_hex(0x2D2D2D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPre1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image11

    ui_Image11 = lv_img_create(ui_ButtonPre1);
    lv_img_set_src(ui_Image11, &ui_img_arrow_left_png);

    lv_obj_set_width(ui_Image11, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image11, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image11, -1);
    lv_obj_set_y(ui_Image11, 1);

    lv_obj_set_align(ui_Image11, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image11, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image11, LV_OBJ_FLAG_SCROLLABLE);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Sensors_screen_init();

	lv_group_t *g = lv_group_create();
	lv_group_add_obj(g, ui_ButtonPre);
	lv_group_add_obj(g, ui_ButtonBack);
	lv_group_add_obj(g, ui_ButtonNext);
	lv_group_add_obj(g, ui_ButtonPre1);

	lv_indev_set_group(indev_keypad, g);
	
    lv_disp_load_scr(ui_Screen1);
}

