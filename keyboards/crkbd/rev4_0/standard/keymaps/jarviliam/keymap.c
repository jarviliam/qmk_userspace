/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keycodes.h"
#include QMK_KEYBOARD_H

#include "layout.h"

enum layers {
    BASE,
    SYM,
    NUM,
    FUN,
    WIN,
    BUT,
};

#define HOME_N LGUI_T(KC_N)
#define HOME_R LALT_T(KC_R)
#define HOME_T LCTL_T(KC_T)
#define HOME_S LSFT_T(KC_S)
#define HOME_H LSFT_T(KC_H)
#define HOME_A LCTL_T(KC_A)
#define HOME_E LALT_T(KC_E)
#define HOME_I LGUI_T(KC_I)

#define BUT_Q LT(BUT, KC_Q)
#define BUT_SLSH LT(BUT, KC_SLSH)

#define SYM_ENT LT(SYM, KC_ENT)
#define NUM_BSPC LT(NUM, KC_BSPC)
#define FUN_DEL LT(FUN, KC_DEL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR( // Base: Grapite.
          KC_B,         KC_L,    KC_D,    KC_W,    KC_Z, XXXXXXX,    XXXXXXX,    KC_QUOT,    KC_F,      KC_O,   KC_U,            KC_J,
        HOME_N,       HOME_R,  HOME_S,  HOME_T,    KC_G, XXXXXXX,    XXXXXXX,    KC_Y,       HOME_H,    HOME_A,  HOME_E,         HOME_I,
         BUT_Q, ALGR_T(KC_X),    KC_M,    KC_C,    KC_V,                         KC_K,      KC_P,       KC_COMM,  ALGR_T(KC_DOT), BUT_SLSH,
                               KC_ESC,  KC_SPC, KC_TAB,                       SYM_ENT,     NUM_BSPC,    FUN_DEL
    ),

    [SYM] = LAYOUT_LR( // Symbol
        KC_LCBR,    KC_AMPR,     KC_ASTR,   KC_LPRN,    KC_RCBR,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN,    KC_DLR,      KC_PERC,   KC_CIRC,    KC_PLUS,  XXXXXXX,          XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
        KC_TILD,    KC_EXLM,     KC_AT,     KC_HASH,    KC_PIPE,                             XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX,
                                              KC_LPRN,  KC_RPRN,  KC_UNDS,          _______, XXXXXXX, XXXXXXX
    ),

    [NUM] = LAYOUT_LR( // Number
        KC_LBRC,    KC_7,     KC_8,   KC_9,    KC_RBRC,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN,    KC_4,      KC_5,   KC_6,    KC_EQL,  XXXXXXX,          XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
        KC_GRV,    KC_1,     KC_2,     KC_3,    KC_BACKSLASH,                             XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX,
                                              KC_DOT,  KC_0,  KC_MINS,          XXXXXXX, _______, XXXXXXX
    ),

    [FUN] = LAYOUT_LR( // Function
        KC_F12,    KC_F7,     KC_F8,   KC_F9,    KC_PSCR,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F11,    KC_F4,      KC_F5,   KC_F6,    KC_SCRL,  XXXXXXX,          XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
        KC_F10,    KC_F1,     KC_F2,     KC_F3,    KC_PAUS,                             XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX,
                                              KC_APP,  KC_SPC,  KC_TAB,          XXXXXXX, XXXXXXX, _______
    ),
  //   [2] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // ),
  //
  //   [3] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // )
};
