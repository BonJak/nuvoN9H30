//
// Created by user on 11/18/22.
//

#include "components.h"
#include "src/widgets/img/lv_img.h"

extern lv_img_dsc_t CL_s;

void create_layout(void) {


    flex_wrapper = lv_obj_create(lv_scr_act());
    lv_obj_set_size(flex_wrapper, 800, 480);
    lv_obj_set_flex_flow(flex_wrapper, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(flex_wrapper, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    flex_left = lv_obj_create(lv_scr_act());
    lv_obj_set_flex_flow(flex_left, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(flex_left, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_set_size(flex_left, 350, 300);
    lv_obj_set_parent(flex_left, flex_wrapper);
    lv_obj_set_style_border_width(flex_left, 0, 0);

    // create a button


    freq_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(freq_row, "Frequency:\t %.2f \t %s", 1.46, "MHz");
    lv_obj_set_parent(freq_row, flex_left);

    vswr_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(vswr_row, "VSWR:\t %.2f", 1.22);
    lv_obj_set_parent(vswr_row, flex_left);

    // use objects in header file capital gamma symbol :  Γ
    refl_coef_amp_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(refl_coef_amp_row, "Refl. Coeff. Amp.:\t %.2f", 0.0);
    lv_obj_set_parent(refl_coef_amp_row, flex_left);

    refl_coef_phase_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(refl_coef_phase_row, "Refl. Coeff. Phase:\t %.2f", 0.0);
    lv_obj_set_parent(refl_coef_phase_row, flex_left);

    incid_pwr_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(incid_pwr_row, "Incident Power:\t %.2f", 0.0);
    lv_obj_set_parent(incid_pwr_row, flex_left);

    incid_pwr_phase_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(incid_pwr_phase_row, "Incident Power Phase:\t %.2f", 0.0);
    lv_obj_set_parent(incid_pwr_phase_row, flex_left);

    refl_power_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(refl_power_row, "Reflected Power:\t %.2f", 0.0);
    lv_obj_set_parent(refl_power_row, flex_left);

    refl_pwr_phase_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(refl_pwr_phase_row, "Reflected Power Phase:\t %.2f", 0.0);
    lv_obj_set_parent(refl_pwr_phase_row, flex_left);

    flex_right = lv_obj_create(lv_scr_act());
    lv_obj_set_flex_flow(flex_right, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(flex_right, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_size(flex_right, 350, 300);
    lv_obj_set_parent(flex_right, flex_wrapper);
    lv_obj_set_style_border_width(flex_right, 0, 0);

    match_type_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(match_type_row, "Match Type:\t %s", "CL");
    lv_obj_set_parent(match_type_row, flex_right);

    match_L_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(match_L_row, "L:\t %.3f uH", 1.205);
    lv_obj_set_parent(match_L_row, flex_right);

    match_C1_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(match_C1_row, "C1:\t %.3f nF", 1.440);
    lv_obj_set_parent(match_C1_row, flex_right);

    match_C2_row = lv_label_create(lv_scr_act());
    lv_label_set_text_fmt(match_C2_row, "C2:\t %.2f", 0.0);
    lv_obj_set_parent(match_C2_row, flex_right);


    flex_bottom = lv_obj_create(lv_scr_act());
    lv_obj_set_flex_flow(flex_bottom, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(flex_bottom, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_size(flex_bottom, 400, 150);
    lv_obj_set_parent(flex_bottom, flex_wrapper);
    lv_obj_set_style_border_width(flex_bottom, 0, 0);
    // disable scrollbar
    lv_obj_set_scrollbar_mode(flex_bottom, LV_SCROLLBAR_MODE_OFF);


    lv_obj_t * CL_img = lv_img_create(lv_scr_act());
    lv_img_set_src(CL_img, &CL_s);
    lv_obj_set_parent(CL_img, flex_bottom);


}




