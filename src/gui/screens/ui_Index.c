// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: LED

#include "../ui.h"

void ui_Index_screen_init(void)
{
    ui_Index = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Index, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_temp_arc = lv_arc_create(ui_Index);
    lv_obj_set_width(ui_temp_arc, 260);
    lv_obj_set_height(ui_temp_arc, 260);
    lv_obj_set_x(ui_temp_arc, 0);
    lv_obj_set_y(ui_temp_arc, 12);
    lv_obj_set_align(ui_temp_arc, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_temp_arc, 200, 350);
    lv_arc_set_value(ui_temp_arc, 250);
    lv_obj_set_style_arc_width(ui_temp_arc, 24, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_width(ui_temp_arc, 24, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_temp_arc, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_temp_arc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_temp_label = lv_label_create(ui_temp_arc);
    lv_obj_set_width(ui_temp_label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_temp_label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_temp_label, 0);
    lv_obj_set_y(ui_temp_label, -2);
    lv_obj_set_align(ui_temp_label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_temp_label, "25.0");
    lv_obj_set_style_text_color(ui_temp_label, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_temp_label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_temp_label, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_temp_arc);
    lv_obj_set_width(ui_Panel1, 228);
    lv_obj_set_height(ui_Panel1, 40);
    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, -15);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_BOTTOM_MID);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel1, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xFF7D00), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Panel1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "อุณหภูมิ");
    lv_obj_set_style_text_font(ui_Label2, &ui_font_th28, LV_PART_MAIN | LV_STATE_DEFAULT);

}