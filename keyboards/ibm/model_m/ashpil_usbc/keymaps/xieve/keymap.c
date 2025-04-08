#include configurator.c


/*
const key_override_t *key_overrides[] = {
    &ko_make_basic(MOD_MASK_SHIFT, QK_DYNAMIC_MACRO_PLAY_1, QK_DYNAMIC_MACRO_RECORD_START_1),
    &ko_make_basic(MOD_MASK_SHIFT, QK_DYNAMIC_MACRO_PLAY_2, QK_DYNAMIC_MACRO_RECORD_START_2),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_fullsize_iso_wkl(
        KC_ESC,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,     KC_F12,                 KC_PSCR,    KC_SCRL,    KC_PAUS,
        KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP,    KC_NUM, KC_PSLS,KC_PAST,KC_PMNS,
        KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,    KC_RBRC,                KC_DEL,     KC_END,     KC_PGDN,    KC_P7,  KC_P8,  KC_P9,  KC_PPLS,
        KC_LGUI,    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,    KC_BSLS,    KC_ENT,                                         KC_P4,  KC_P5,  KC_P6,
        KC_LSFT,    TT(1),  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,                KC_RSFT,                KC_UP,                  KC_P1,  KC_P2,  KC_P3,  KC_PENT,
        KC_LCTL,    KC_LALT,                                    KC_SPC,                                         KC_RALT,    KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_P0,          KC_PDOT
    ),
    [1] = LAYOUT_fullsize_iso_wkl(
        KC_TRNS,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_TRNS,    KC_MRWD,    KC_MPLY,    KC_MFFD,    KC_TRNS,    KC_APP,     KC_TRNS,    QK_DYNAMIC_MACRO_RECORD_START_1,    QK_DYNAMIC_MACRO_PLAY_1,    KC_TRNS,    KC_TRNS,    QK_BOOT,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_CAPS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_COMM
    ),
};

void keyboard_pre_init_user() {
    gpio_set_pin_output(D5);
}

// Use ScrLck indicator as layer indicator
layer_state_t layer_state_set_user(layer_state_t state) {
    gpio_write_pin(D5, IS_LAYER_OFF_STATE(state, 1));
    return state;
}
