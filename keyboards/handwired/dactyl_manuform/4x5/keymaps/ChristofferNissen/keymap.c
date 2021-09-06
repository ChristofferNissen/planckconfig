#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3
#define _I3 4

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2[]

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum custom_keycodes {
  ADJUST,
  I3,
  I3_macro1,
  I3_macro2,
  I3_macro3,
  I3_macro4,
  I3_macro5,
  I3_macro6,
  I3_macro7,
  I3_macro8,
  I3_macro9,
  I3_macro0,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *                      | ESC  |SPACE |                             | BS   | ENTER |
     *                      |  +   |      |                             |  +   |   +   |
     *                      | SHIFT|      |                             | CTRL  |SHIFT |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    | Raise  | GUI | | ALT | Lower  |
     *                                    '------+------' '------+------'
     *                                    | TAB  | LBRC  | | RBRC  | Del  |
     *                                    '------+------' '------+------'
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                          XXXXXXX, XXXXXXX,                                                        XXXXXXX, XXXXXXX,
                                                     SFT_ESC, KC_SPC, KC_BSPC, SFT_ENT,
                                                     RAISE,  KC_LGUI,  KC_LCTRL,  LOWER,
                                                     KC_TAB,   KC_LBRC,   KC_RBRC, KC_LALT
    ),

    /* Raise
     * ,----------------------------------,                             ,----------------------------------,
     * |      | mbtn1|  mup |mbtn2|      |                              |      |      |      |      |      |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |      | mleft| mdown|mright|      |                             | left | down | up   |right |      |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |      |      |      |                             | HOME | PgDn | PgUp |  END |      |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         |      |      |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_RAISE] = LAYOUT(
        _______, KC_MS_BTN1, KC_MU, KC_MS_BTN2, _______,                                  _______, _______, _______,   _______, _______,
        _______, KC_ML,   KC_MD,   KC_MR,   _______,                                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______,
        _______, _______, _______, _______, _______,                                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
                 _______, _______,                                                                          _______,  _______,
                                                     _______, _______,  KC_BSPC, KC_DEL,
                                                     _______, _______,  _______, _______,
                                                     _______, KC_LPRN,  KC_LPRN, _______
    ),

    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  ~   |   -  |   =  |      |      |                             |      |  /   |  \   |  ?   |  |   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LOWER] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_GRV,   KC_MINS,  KC_EQL,   _______,   _______,                               _______, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
                 _______,  _______,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, KC_LPRN,  KC_LPRN, _______
    ),

    /* Adjust
     * ,----------------------------------,                             ,----------------------------------,
     * |  F1  |  F2  |  F3  |  F4  |  F5  |                             | VOL+ |      |      |      |      |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  F6  |  F7  |  F8  |  F9  |  F10 |                             | MUTE |      |      |      |      |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  F11 |  F12 |      |      |      |                             | VOL- |      |      |      |      |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_ADJUST] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_VOLU, _______, _______,   _______, _______,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                                      KC_MUTE, _______, _______,  _______, _______,
        KC_F11,  KC_F12, _______, _______, _______,                                      KC_VOLD, _______, _______, _______, _______,
                 _______, _______,                                                                          _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

    // [_I3] = LAYOUT(
    //     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    //     I3_macro1,    I3_macro2,    I3_macro3,    I3_macro4,    I3_macro5,                               I3_macro6,    I3_macro7,    I3_macro8,    I3_macro9,    I3_macro0,
    //     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                         XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX,
    //                       XXXXXXX, XXXXXXX,                                                        XXXXXXX, XXXXXXX,
    //                                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                                                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    //                                                  RAISE,   XXXXXXX,   XXXXXXX, LOWER
    // ),
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        #ifdef I3UI
        case I3:
            if (record->event.pressed) {
                layer_on(_I3);
            } else {
                layer_off(_I3);
            }
            return false;
            break;
        case I3_macro1:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("1"));
            }
            return false;
            break;
        case I3_macro2:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("2"));
            }
            return false;
            break;
        case I3_macro3:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("3"));
            }
            return false;
            break;
        case I3_macro4:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("4"));
            }
            return false;
            break;
        case I3_macro5:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("5"));
            }
            return false;
            break;
        case I3_macro6:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("6"));
            }
            return false;
            break;
        case I3_macro7:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("7"));
            }
            return false;
            break;
        case I3_macro8:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("8"));
            }
            return false;
            break;
        case I3_macro9:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("9"));
            }
            return false;
            break;
        case I3_macro0:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("0"));
            }
            return false;
            break;
        #endif

        case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
        } else {
            layer_off(_LOWER);
        }
        return false;
        case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
        } else {
            layer_off(_RAISE);
        }
        return false;
        case ADJUST:
            if (record->event.pressed) {
            layer_on(_ADJUST);
            //   rgb_matrix_set_color(7, 255, 0, 0);
            } else {
            layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

