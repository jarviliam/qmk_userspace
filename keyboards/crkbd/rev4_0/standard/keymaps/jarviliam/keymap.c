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

#include QMK_KEYBOARD_H

#include "layout.h"
#include "jarviliam.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR( // Base: Grapite.
          KC_B,         KC_L,    KC_D,    KC_W,    KC_Z, XXXXXXX,    XXXXXXX,    KC_QUOT,    KC_F,      KC_O,   KC_U,            KC_J,
        HOME_N,       HOME_R,  HOME_T, HOME_S,     KC_G, XXXXXXX,    XXXXXXX,    KC_Y,       HOME_H,    HOME_A,  HOME_E,         HOME_I,
         WIN_Q, ALGR_T(KC_X),    KC_M,    KC_C,    KC_V,                         KC_K,      KC_P,       KC_COMM,  ALGR_T(KC_DOT), WIN_SLSH,
                               KC_ESC,  NAV_SPC, KC_TAB,                       SYM_ENT,     NUM_BSPC,    FUN_DEL
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
        KC_F12,    KC_F7,     KC_F8,   KC_F9,    KC_PSCR,  QK_BOOT,          XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F11,    KC_F4,      KC_F5,   KC_F6,    KC_SCRL,  XXXXXXX,          XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
        KC_F10,    KC_F1,     KC_F2,     KC_F3,    KC_PAUS,                             XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX,
                                              KC_APP,  KC_SPC,  KC_TAB,          XXXXXXX, XXXXXXX, _______
    ),

    [NAV] = LAYOUT_LR( // Navigation
        XXXXXXX,    XXXXXXX,     XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,          XXXXXXX, KC_AGIN, S(KC_INS),  C(KC_INS), S(KC_DEL), KC_UNDO,
        KC_LGUI,    KC_LALT,    KC_LCTL,   KC_LSFT,    XXXXXXX,  XXXXXXX,          XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,
        XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,                             KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                              XXXXXXX,  _______,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [WIN] = LAYOUT_LR( // Window
        XXXXXXX,    XXXXXXX,     XXXXXXX,   XXXXXXX,    XXXXXXX,  XXXXXXX,          XXXXXXX, G(KC_TAB), G(KC_8),  G(KC_9), G(KC_4), KC_UNDO,
        KC_LGUI,    KC_LALT,    KC_LCTL,   KC_LSFT,    XXXXXXX,  XXXXXXX,          XXXXXXX, G(S(KC_LEFT)), G(KC_1), G(KC_2), G(KC_3),  G(S(KC_RIGHT)),
        _______, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,                             XXXXXXX, G(KC_7), G(KC_6), G(KC_5), XXXXXXX,
                                              XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [RSYM] = LAYOUT_LR( // Revised Symbol
        XXXXXXX,    KC_LABK,     KC_RABK,   KC_BSLS,    KC_GRV,  XXXXXXX,          XXXXXXX, KC_AMPR, KC_MINS,  KC_LBRC, KC_RBRC, _______,
        KC_EXLM,    KC_MINS,    KC_PLUS,   KC_EQL,    KC_HASH,  XXXXXXX,          XXXXXXX, KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN,  KC_PERC,
        XXXXXXX, KC_SLSH,   KC_ASTR, KC_CIRC,  XXXXXXX,                                     KC_TILD, KC_DLR, KC_LCBR, KC_RCBR, _______,
                                              XXXXXXX,  XXXXXXX,  XXXXXXX,          XXXXXXX, XXXXXXX, _______
    ),
};
