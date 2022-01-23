#include QMK_KEYBOARD_H
// #include "process_ucis.h"

extern uint8_t is_master;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _BASE 1
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5
#define _I3 6
#define _ARROW 7
#define _MOUSEL 8
#define _MOUSER 9
#define _EMOJI 10

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define I3 MO(_I3)
#define MOUSEL TT(_MOUSEL)
#define MOUSER TT(_MOUSER)
#define ARROW MO(_ARROW)
#define ENABLE_LT TT(_BASE)
#define EMOJI MO(_EMOJI)

#ifdef UNICODEMAP_ENABLE
enum unicode_names {
    AE,
    AEBIG,
    OE,
    OEBIG,
    AA,
    AABIG,
    BANG,
    IRONY,
    SNEK,
    PURPLEHEART
};

const uint32_t PROGMEM unicode_map[] = {
    [AE] = 0x00E6, // æ
    [AEBIG] = 0x00C6, // Æ
    [OE] = 0x00F8, // ø
    [OEBIG] = 0x00D8, // Ø
    [AA] = 0x00E5, // å
    [AABIG] = 0x00C5, // Å
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [PURPLEHEART] = 0x1F49C, // 💜
};
// Then you can use X(SNEK) etc. in your keymap.
// Characters often come in lower and upper case pairs, such as å and Å. To make inputting these characters easier, you can use XP(i, j)
#endif

#ifdef UCIS_ENABLE
const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("aa", 0x00E5),                   // å
    UCIS_SYM("aab", 0x00C5),                  // Å
    UCIS_SYM("ae", 0x00E6),                   // æ
    UCIS_SYM("aeb", 0x00C6),                  // Æ
    UCIS_SYM("oe", 0x00F8),                   // ø
    UCIS_SYM("oeb", 0x00D8),                  // Ø
    UCIS_SYM("poop", 0x1F4A9)                // 💩
);
#endif

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ADJUST,
  BACKLIT,
  RGBRST,
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
  RGB_ENA,
  RGB_DIS,
  RGB_RST,  // Reset RGB
  RGB_UND,  // Toggle RGB underglow as layer indicator
  RGB_IDL,  // RGB Idling animations
  RGB_MAP,  // RGB_MATRIX_TYPING_HEATMAP
  RGB_NXS,  // RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  RGB_SOL,  // RGB_MATRIX_SOLID_COLOR
  RGB_CYC,  // RGB_MATRIX_CYCLE_ALL
  RGB_DUO,  // RGB_MATRIX_RAINBOW_PINWHEELS
  RGB_SCR,   // RGB_MATRIX_CYCLE_LEFT_RIGHT
  EMOJIKEY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_I3] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, I3_macro1, I3_macro2, I3_macro3, I3_macro4,  I3_macro5, I3_macro6, I3_macro7, I3_macro8, I3_macro9, I3_macro0, KC_LSFT,\
  //|-- ------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_ESC,   KC_TAB, LT(LOWER, KC_SPC),   LT(RAISE, KC_BSPC), KC_ENT, KC_QUOT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_MOUSEL] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       MOUSEL, XXXXXXX, XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, XXXXXXX,                     KC_WH_U, KC_WH_L, KC_MS_UP, KC_WH_R, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_WH_D, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MOUSEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_MS_BTN1, XXXXXXX, KC_MS_BTN2, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, KC_MS_BTN2, KC_MS_BTN1,      KC_MS_BTN1, KC_MS_BTN2, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_UP, KC_WH_R, KC_WH_U,               XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, XXXXXXX, XXXXXXX, MOUSER,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,XXXXXXX, KC_MS_BTN1, XXXXXXX, KC_MS_BTN2, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MOUSER,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        XXXXXXX, KC_MS_BTN2, KC_MS_BTN1,      KC_MS_BTN1, KC_MS_BTN1, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_BASE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       ENABLE_LT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_DEL ,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        I3,    KC_A,  KC_S,  KC_D, KC_F, KC_G,                                 KC_H, KC_J, KC_K, KC_L, KC_SCLN, I3,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        MOUSEL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_ESC, KC_TAB, LT(LOWER, KC_SPC),    LT(RAISE, KC_BSPC), KC_ENT, KC_QUOT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        ENABLE_LT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        I3,    MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LSFT, KC_D), MT(MOD_LCTL, KC_F),    KC_G,                         KC_H,    MT(MOD_RCTL, KC_J), MT(MOD_RSFT, KC_K), MT(MOD_LALT, KC_L), MT(MOD_RGUI, KC_SCLN), I3,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        MOUSEL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        LT(MOUSEL, KC_ESC), LT(ARROW, KC_TAB), LT(LOWER, KC_SPC),    LT(RAISE, KC_BSPC), KC_ENT, LT(MOUSER, KC_QUOT) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,                            KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, LOWER,      RAISE, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ARROW] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PLUS, XXXXXXX, KC_LBRC, KC_RBRC, XP(AA, AABIG),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TILDE, KC_SLSH, KC_BSLS, KC_PIPE, KC_GRV,                      KC_EQL, KC_MINS, KC_UNDS, KC_LCBR, KC_RCBR, XP(OE, OEBIG),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XP(AE, AEBIG),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_ESC, KC_TAB, LOWER,         RAISE,   KC_ENT, KC_QUOT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_IDL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_RST, RGB_ENA,                     KC_AUDIO_MUTE, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, RGB_DIS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_ESC,   KC_TAB,   LOWER,     RAISE,    KC_ENT, KC_QUOT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_EMOJI] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, X(PURPLEHEART), X(SNEK), XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_ESC,   LT(_LOWER, KC_TAB),   KC_SPC,   KC_BSPC,   LT(_RAISE, KC_ENT), KC_QUOT \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

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

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
        RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

char matrix_line_str[24];

const char *read_layer_state(void) {
  uint8_t layer = biton32(layer_state);

  strcpy(matrix_line_str, "Layer: ");

  switch (layer)
  {
    case _ARROW:
      strcat(matrix_line_str, "Arrow keys");
      break;
    case _EMOJI:
      strcat(matrix_line_str, "EMOJI");
      break;
    case _BASE:
      strcat(matrix_line_str, "NO LAYER TAP");
      break;
    case _QWERTY:
      strcat(matrix_line_str, "Default");
      break;
    case _MOUSEL:
      strcat(matrix_line_str, "MOUSE LEFT");
      break;
    case _MOUSER:
      strcat(matrix_line_str, "MOUSE RIGHT");
      break;
    case _LOWER:
      strcat(matrix_line_str, "Lower");
      break;
    case _RAISE:
      strcat(matrix_line_str, "Raise");
      break;
    case _ADJUST:
      strcat(matrix_line_str, "Adjust");
      break;
    case _I3:
      strcat(matrix_line_str, "I3");
      break;
    default:
      sprintf(matrix_line_str + strlen(matrix_line_str), "Unknown (%d)", layer);
  }

  return matrix_line_str;
}

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#    ifndef SPLIT_KEYBOARD
    if (is_master) {
#    endif
        return OLED_ROTATION_270;
#    ifndef SPLIT_KEYBOARD
    }  else {
        return rotation;
    }
#    endif
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifndef SPLIT_KEYBOARD
    if (keycode == RESET && !is_master) {
        return false;
    }
#endif

  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
  }

  switch (keycode) {

#ifdef UCIS_ENABLE
    case EMOJIKEY:
        if (record->event.pressed)
            qk_ucis_start();
        return false;
        break;
#endif

#ifdef I3UI
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

#ifdef RGB_MATRIX_ENABLE
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      #ifdef RGB_MATRIX_ENABLE
      if (record->event.pressed) {
          rgb_matrix_mode(RGB_current_mode);
          rgb_matrix_step();
          RGB_current_mode = rgb_matrix_config.mode;
        }
      #endif
      return false;
    case RGB_DIS:
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          rgb_matrix_disable();
        }
      #endif
    case RGB_ENA:
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
            rgb_matrix_config.enable = false;
        }
      #endif
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
        //   rgb_matrix_mode(RGB_current_mode);
          rgb_matrix_enable();
          RGB_current_mode = rgb_matrix_config.mode;
        }
      #endif
      break;
#endif

    // default
    case QWERTY:
      if (record->event.pressed) {
        layer_move(_QWERTY);
        persistent_default_layer_set(1UL << _QWERTY);
        set_single_persistent_default_layer(_QWERTY);
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
        //   rgb_matrix_set_color(7, 255, 0, 0);
        } else {
          layer_off(_ADJUST);
        }
        return false;
  }
  return true;
}

#ifdef CUSTOM_RGB
void rgb_matrix_indicators_user(void) {
    if(rgb_matrix_config.enable) {
        if(IS_LAYER_ON(_ADJUST)) {
            // rgb_matrix_set_color_all(0,0,0);
            // rgb_matrix_set_color(0, 0, 0, 0);
            // rgb_matrix_set_color(1, 0, 0, 0);
            // rgb_matrix_set_color(2, 0, 0, 0);
            rgb_matrix_set_color(13, 10, 10, 10);

        // } else if (IS_LAYER_ON(_LOWER)){
        // } else if (IS_LAYER_ON(_RAISE)){
        // } else if (IS_LAYER_ON(_I3)){
        //     rgb_matrix_set_color_all(0,0,0);
        //     rgb_matrix_set_color(9, 255, 255, 255);
        //     rgb_matrix_set_color(10, 255, 255, 255);
        //     rgb_matrix_set_color(17, 255, 255, 255);
        //     rgb_matrix_set_color(18, 255, 255, 255);
        //     rgb_matrix_set_color(23, 255, 255, 255);

            rgb_matrix_set_color(16, 255, 255, 255);
        } else if (IS_LAYER_ON(_QWERTY)){
            // rgb_matrix_set_color_all(0,0,0);
            // rgb_matrix_set_color(19, 255, 255, 255);
        }

    }
}
// Netlight 113,125,213
#endif
