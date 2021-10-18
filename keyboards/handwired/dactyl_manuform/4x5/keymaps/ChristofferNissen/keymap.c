#include QMK_KEYBOARD_H
#include "process_ucis.h"
#include "split_util.h"

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3
#define _NAV 4

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
#define NAV MO(_NAV)

const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("aa", 0x00E5),                   // å
    UCIS_SYM("aab", 0x00C5),                  // Å
    UCIS_SYM("ae", 0x00E6),                   // æ
    UCIS_SYM("aeb", 0x00C6),                  // Æ
    UCIS_SYM("oe", 0x00F8),                   // ø
    UCIS_SYM("oeb", 0x00D8),                  // Ø
    UCIS_SYM("poop", 0x1F4A9),                // 💩
    UCIS_SYM("rofl", 0x1F923),                // 🤣
    UCIS_SYM("purpleheart", 0x1f49c)
);

enum custom_keycodes {
  ADJUST,
  EMOJIKEY
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
     *                      | TAB  |SPACE |                             | BS   | ENTER |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                  |NAV(ESC)|Lower([)|Raise(])|Nav(@)|
     *                                    '------+------' '------+------'
     *                                  | ( | { |         |   }  |   )   |
     *                                    '------+------' '------+------'
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F), MT(MOD_LGUI | MOD_LSFT, KC_G),       MT(MOD_RGUI | MOD_RSFT, KC_H), MT(MOD_RCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          XXXXXXX, XXXXXXX,                                                        XXXXXXX, XXXXXXX,
                                                    KC_TAB, KC_SPC,     KC_BSPC, KC_ENT,
                                        LT(NAV, KC_LBRC), LT(LOWER, KC_ESC),      LT(RAISE, KC_QUOT), LT(NAV, KC_RBRC),
                                                    KC_LCBR, KC_LPRN,    KC_RPRN, KC_RCBR
    ),


    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * | lgui | lalt | lsft | lcrtl|      |                             |      | rctrl| rsft | lalt | rgui |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |      |      |      |      |      |                             |      |      |      |      |      |
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
        _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______,
        MT(MOD_LGUI, KC_1), MT(MOD_LALT, KC_2), MT(MOD_LSFT, KC_3), MT(MOD_LCTL, KC_4), KC_5,                                    KC_6, MT(MOD_RCTL, KC_7), MT(MOD_RSFT, KC_8), MT(MOD_LALT, KC_9), MT(MOD_RGUI, KC_0),
        _______, _______, _______, _______, _______,                                    _______, _______, _______, _______, _______,
                 _______, _______,                                                                          _______,  _______,
                                                     _______, _______,  _______, _______,
                                                     _______, LOWER,      RAISE, _______,
                                                     _______, _______,  _______, _______
    ),

    /* Raise
     * ,----------------------------------,                             ,----------------------------------,
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  ~   |   /  |   \  |  |   |   `  |                             |  _   |  -   |  +   |  =   |  |   |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |------|------|------|------|------|                             |-- ---|------|------|------|--`---|
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
    [_RAISE] = LAYOUT(
        _______, _______, _______, _______, EMOJIKEY,                                  _______, _______, _______, _______, _______,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_TILDE, KC_SLSH, KC_BSLS, KC_PIPE, KC_GRV,                                   KC_UNDS, KC_MINS, KC_PLUS, KC_EQL, KC_PIPE,
                 _______,  _______,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, LOWER,  RAISE, _______,
                                                     _______, _______,  _______, _______
    ),

    /* Adjust
     * ,----------------------------------,                             ,----------------------------------,
     * |  F1  |  F2  |  F3  |  F4  |  F5  |                             | VOL+ |      |      |      | RESET|
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
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_VOLU, _______, _______,   _______, RESET,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                                      KC_MUTE, _______, _______,  _______, _______,
        KC_F11,  KC_F12, _______, _______, _______,                                      KC_VOLD, _______, _______, _______, _______,
                 _______, _______,                                                                          _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  KC_DEL, _______,
                                                     _______, _______,  _______, _______
    ),

    [_NAV] = LAYOUT(
        _______, KC_WH_L, KC_MU, KC_WH_R, KC_WH_U,                                       _______, _______, _______, _______, _______,
        _______,  KC_ML , KC_MD,  KC_MR , KC_WH_D,                                      _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        _______, KC_BTN1, _______ , KC_BTN2, _______,                                      _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                 _______, _______,                                                                          _______, _______,
                                   KC_BTN1, KC_BTN2,                                      KC_BTN1, KC_BTN2,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    )

};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMOJIKEY:
            if (record->event.pressed){
                qk_ucis_start();
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}
