
enum layers {
    BASE,
    SYM,
    NUM,
    FUN,
    NAV,
    WIN,
    RSYM,
    EXP,
};

#define HOME_N LT(WIN, KC_N)
#define HOME_R LALT_T(KC_R)
#define HOME_T LCTL_T(KC_T)
#define HOME_S LSFT_T(KC_S)
#define HOME_H LSFT_T(KC_H)
#define HOME_A LCTL_T(KC_A)
#define HOME_E LALT_T(KC_E)
#define HOME_I LGUI_T(KC_I)

#define TOG_EXP DF(EXP)

#define WIN_Q LGUI_T(KC_Q)
#define WIN_SLSH LT(WIN, KC_SLSH)

#define NAV_SPC LT(NAV, KC_SPC)
#define SYM_ENT LT(SYM, KC_ENT)
#define NUM_TAB LT(NUM, KC_TAB)
#define FUN_QOUT LT(FUN, KC_COMM)

const uint16_t caps_combo[] PROGMEM  = {KC_C, KC_P, COMBO_END};
const uint16_t copy_combo[] PROGMEM  = {KC_X, KC_M, COMBO_END};
const uint16_t paste_combo[] PROGMEM = {KC_M, KC_C, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG)
    COMBO(copy_combo, L_GUI_T(KC_C))
    COMBO(paste_combo, L_GUI_T(KC_V))
};

#ifdef CHORDAL_HOLD
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void housekeeping_task_user(void) {}
