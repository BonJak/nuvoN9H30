//
// Created by user on 11/18/22.
//

#ifndef A1_COMPONENTS_H
#define A1_COMPONENTS_H

#include "src/layouts/grid/lv_grid.h"
#include "src/layouts/flex/lv_flex.h"
#include "src/core/lv_disp.h"
#include "src/core/lv_obj.h"
#include "src/widgets/label/lv_label.h"
#include "src/widgets/textarea/lv_textarea.h"



// flex wrappers
static lv_obj_t * flex_wrapper;
static lv_obj_t * flex_left;
static lv_obj_t * flex_right;
static lv_obj_t * flex_bottom;

/*************
 * Labels & Text Display * Left Side
 *************/
static lv_obj_t *freq_row;
static lv_obj_t *vswr_row;
static lv_obj_t *refl_coef_amp_row;
static lv_obj_t *refl_coef_phase_row;
static lv_obj_t *incid_pwr_row ;
static lv_obj_t *incid_pwr_phase_row;
static lv_obj_t *refl_power_row;
static lv_obj_t *refl_pwr_phase_row;

/*************
 * Labels & Text Display * Right Sidef
 *************/

static lv_obj_t *match_type_row;
static lv_obj_t *match_L_row;
static lv_obj_t *match_C1_row;
static lv_obj_t *match_C2_row;

/*************
 * Functions *
 *************/
void create_layout();


#endif //A1_COMPONENTS_H











