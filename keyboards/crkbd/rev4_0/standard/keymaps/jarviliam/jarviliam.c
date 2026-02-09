
enum layers {
    BASE,
    SYM,
    NUM,
    FUN,
    NAV,
    WIN,
};

#define HOME_N LT(WIN, KC_N)
#define HOME_R LALT_T(KC_R)
#define HOME_T LCTL_T(KC_T)
#define HOME_S LSFT_T(KC_S)
#define HOME_H LSFT_T(KC_H)
#define HOME_A LCTL_T(KC_A)
#define HOME_E LALT_T(KC_E)
#define HOME_I LT(NUM, KC_I)

#define TABLSFT LSFT_T(KC_TAB)
#define TABRSFT RSFT_T(KC_TAB)

#define TMUXL LCTL_T(KC_SPC)

#define WIN_Q LGUI_T(KC_Q)
#define WIN_SLSH LT(WIN, KC_SLSH)

#define FUN_TAB LT(FUN, KC_TAB)

#define NAV_SPC LT(NAV, KC_SPC)
#define SYM_BCK LT(SYM, KC_BACKSPACE)
#define SYM_ENT LT(SYM, KC_ENT)

const uint16_t caps_combo[] PROGMEM  = {KC_C, KC_P, COMBO_END};
const uint16_t copy_combo[] PROGMEM  = {HOME_H, HOME_A,QK_REP, COMBO_END};
const uint16_t paste_combo[] PROGMEM = {KC_P, KC_COMM,QK_REP, COMBO_END};
const uint16_t save_combo[] PROGMEM = {HOME_R, HOME_T,NAV_SPC, COMBO_END};
const uint16_t enter_combo[] PROGMEM = {HOME_A, HOME_E, QK_REP, COMBO_END};
const uint16_t find_combo[] PROGMEM = {KC_M, KC_C, KC_SPC, COMBO_END};
const uint16_t undo_combo[] PROGMEM = {ALGR_T(KC_X),KC_M, KC_SPC, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),
    COMBO(copy_combo, LCTL_T(KC_C)),
    COMBO(paste_combo, LCTL_T(KC_V)),
    COMBO(enter_combo, KC_ENT),
    COMBO(save_combo, LCTL_T(KC_S)),
    COMBO(find_combo, LCTL_T(KC_F)),
    COMBO(undo_combo, LCTL_T(KC_Z))
};

const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, ALGR_T(KC_DOT), KC_QUES); // Shift . is ?
const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM); // Shift , is !
const key_override_t slsh_key_override = ko_make_basic(MOD_MASK_SHIFT, LGUI_T(KC_SLASH), KC_BSLS); // Shift / is backslash


const key_override_t* key_overrides[] = {
    &dot_key_override,
    &comm_key_override,
    &slsh_key_override,
};

#ifdef CHORDAL_HOLD
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case HOME_S:
        case HOME_H:
            return TAPPING_TERM - 45;
        default:
            return TAPPING_TERM;
    }
}

void housekeeping_task_user(void) {}
