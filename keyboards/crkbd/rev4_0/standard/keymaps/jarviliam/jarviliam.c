
#ifdef ACHORDION_ENABLE
#    include "features/achordion.h"
#endif // ACHORDION_ENABLE

enum layers {
    BASE,
    SYM,
    NUM,
    FUN,
    NAV,
    WIN,
    RSYM,
};

#define HOME_N LGUI_T(KC_N)
#define HOME_R LALT_T(KC_R)
#define HOME_T LCTL_T(KC_T)
#define HOME_S LSFT_T(KC_S)
#define HOME_H LSFT_T(KC_H)
#define HOME_A LCTL_T(KC_A)
#define HOME_E LALT_T(KC_E)
#define HOME_I LGUI_T(KC_I)

#define WIN_Q LT(WIN, KC_Q)
#define WIN_SLSH LT(WIN, KC_SLSH)

#define NAV_SPC LT(NAV, KC_SPC)
#define SYM_ENT LT(SYM, KC_ENT)
#define NUM_BSPC LT(NUM, KC_BSPC)
#define FUN_DEL LT(FUN, KC_DEL)

const uint16_t caps_combo[] PROGMEM = {KC_C, KC_P, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG)
};
// clang-format on
//
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         default:
//             return TAPPING_TERM;
//     }
// }

#ifdef ACHORDION_ENABLE
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // Allow thumb layer same key for button macros (flash).
    // This is fixed to Layout 5_3_2, might need to adjust for 3_2_ex2
    dprintf("key=0x%04X\n", tap_hold_keycode);
    dprintf("other=0x%04X\n", other_keycode);

    // Exceptionally consider the following chords as holds, even though they
    // are on the same hand in Dvorak.
    // switch (tap_hold_keycode) {
    //   case KC_ESC:  // ESC + Q.
    //       dprintf("here");
    //     if (other_keycode == KC_Q) { return true; }
    //     break;
    //
    //   case KC_DEL:  // S + H and S + G.
    //       dprintf("there");
    //     if (other_keycode == KC_QUOT) { return true; }
    //     break;
    // }
    uint8_t row = other_record->event.key.row;
    dprintf("%d\n", row);
    if (row == 0 || row == 4) {
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (record->event.pressed) {
    //     dprintf("kc=0x%04X, row=%2u, col=%2u\n", keycode, record->event.key.row, record->event.key.col);
    // }
#ifdef ACHORDION_ENABLE
    if (!process_achordion(keycode, record)) {
        return false;
    }
#endif
    return true;
}
