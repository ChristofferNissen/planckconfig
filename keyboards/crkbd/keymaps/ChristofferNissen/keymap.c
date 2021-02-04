#include QMK_KEYBOARD_H

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
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _I3 4

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
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [AE] = 0x00E6, // æ
    [AEBIG] = 0x00C6, // Æ
    [OE] = 0x00E6, // ø
    [OEBIG] = 0x00C6, // Ø
    [AA] = 0x00E6, // å
    [AABIG] = 0x00C6, // Å
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
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
    UCIS_SYM("poop", 0x1F4A9),                // 💩
    UCIS_SYM("rofl", 0x1F923),                // 🤣
    UCIS_SYM("cuba", 0x1F1E8, 0x1F1FA),       // 🇨🇺
    UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0)  // ಠ_ಠ
);
#endif


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,
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

#if defined(DANISH) && defined(UNICODE_ENABLE)
bool is_shift_active = false;
bool is_a_active = false;
bool is_o_active = false;

uint16_t a_timer = 0;        // we will be using them soon.
uint16_t o_timer = 0;
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_I3] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, I3_macro1, I3_macro2, I3_macro3, I3_macro4,  I3_macro5, I3_macro6, I3_macro7, I3_macro8, I3_macro9, I3_macro0, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_MS_BTN1, KC_MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,KC_RIGHT, EMOJIKEY, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_PLAY_PAUSE,        KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, XXXXXXX, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, LOWER,   KC_SPC,   KC_ENT,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LT(MO(_I3), KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, LT(MO(_I3), KC_QUOT),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,   KC_SPC,   KC_ENT,   RAISE,  KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                      KC_F12, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,   KC_SPC,   KC_ENT,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
    ),


#ifdef UNICODEMAP_ENABLE
  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, XXXXXXX, XXXXXXX, XP(AE, AEBIG), XP(OE, OEBIG), XP(AA, AABIG),                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,   KC_SPC,   KC_ENT,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),
#else
  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,   KC_SPC,   KC_ENT,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),
#endif



  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_IDL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_RST, RGB_ENA,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, RGB_DIS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,   KC_SPC,   KC_ENT,   RAISE, KC_RALT \
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
    case _QWERTY:
      strcat(matrix_line_str, "Default");
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

const char *read_usb_state(void) {

  strcpy(matrix_line_str, "USB  : ");

  switch (USB_DeviceState) {
    case DEVICE_STATE_Unattached:
      strcat(matrix_line_str, "Unattached");
      break;
    case DEVICE_STATE_Suspended:
      strcat(matrix_line_str, "Suspended");
      break;
    case DEVICE_STATE_Configured:
      strcat(matrix_line_str, "Connected");
      break;
    case DEVICE_STATE_Powered:
      strcat(matrix_line_str, "Powered");
      break;
    case DEVICE_STATE_Default:
      strcat(matrix_line_str, "Default");
      break;
    case DEVICE_STATE_Addressed:
      strcat(matrix_line_str, "Addressed");
      break;
    default:
      strcat(matrix_line_str, "Invalid");
  }

  return matrix_line_str;
}


void matrix_scan_user(void) {
   iota_gfx_task();
#if defined(DANISH) && defined(UNICODE_ENABLE)
  if (is_a_active || is_o_active) {
    if (timer_elapsed(a_timer) > 1000) {
      is_a_active = false;
    }
    if (timer_elapsed(o_timer) > 1000) {
      is_o_active = false;
    }
  }
#endif
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_usb_state());
    // matrix_write_ln(matrix, read_keylogs());

    // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    // matrix_write_ln(matrix, read_host_led_state());
    // matrix_write_ln(matrix, read_timelog());
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {

#ifdef UCIS_ENABLE
    case EMOJIKEY:
        if (record->event.pressed)
            qk_ucis_start();
        return false;
        break;
#endif

#if defined(DANISH) && defined(UNICODE_ENABLE)
    default:
        is_a_active = false;
        is_o_active = false;
        break;

    case KC_LSFT:
        // true when pressed down, false on release
        if (record->event.pressed) {
            is_shift_active = true;
        } else {
            is_shift_active = false;
        }
        break;

    case KC_E:
      if (record->event.pressed) {
        // a+e = æ   Shift+a+e = Æ
        if (is_a_active) {
            if (is_shift_active) {
                tap_code(KC_BSPC);
                // UC(0x00C6);
                // SEND_STRING(SS_LALT("D83D+DC83"));
                // send_unicode_hex_string("00C6");
            } else {
                tap_code(KC_BSPC);
                // UC(0x00E6);
                // send_unicode_hex_string("00E6");
            }
          is_a_active = false;
          break;
        }

        // OE = ø       Shift+OE = Ø
        if (is_o_active) {
            if (is_shift_active)
                SEND_STRING("Æ");
            else
                SEND_STRING("æ");
          is_o_active = false;
        }
      }
      break;

    // A+A = å   Shift+A+A = Å
    case KC_A:
      if (record->event.pressed) {
        if (is_a_active) {
            if (is_shift_active)
                SEND_STRING("Å");
            else
                SEND_STRING("å");

          is_a_active = false;

        } else {
            is_a_active = true;
            a_timer = timer_read();
        }
      }
      break;

    case KC_O:
      if (record->event.pressed) {
        if (!is_o_active) {
            is_o_active = true;
            o_timer = timer_read();
        }
      }
      break;
#endif

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
        //SEND_STRING(SS_TAP(X_LGUI) SS_TAP(X_2) ); // selects all and copies
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
        persistent_default_layer_set(1UL<<_QWERTY);
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
          rgb_matrix_set_color(7, 255, 0, 0);
        } else {
          layer_off(_ADJUST);
        }
        return false;
  }
  return true;
}

// #ifdef RGB_MATRIX_ENABLE

// void suspend_power_down_keymap(void) { rgb_matrix_set_suspend_state(true); }

// void suspend_wakeup_init_keymap(void) { rgb_matrix_set_suspend_state(false); }

// void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_type) {
//     HSV hsv = {hue, sat, val};
//     if (hsv.v > rgb_matrix_config.hsv.v) {
//         hsv.v = rgb_matrix_config.hsv.v;
//     }

//     RGB rgb = hsv_to_rgb(hsv);
//     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
//         if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
//             rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//         }
//     }
// }

// void check_default_layer(uint8_t mode, uint8_t type) {
//     switch (get_highest_layer(default_layer_state)) {
//       default: {
//             rgb_matrix_set_color_all(0, 0,0);
//             break;
//         }
//     }
// }

// void rgb_matrix_indicators_user(void) {

//     switch (get_highest_layer(layer_state)) {
//         case _QWERTY:
//             // rgb_matrix_set_color_all(0, 255, 255); //Light up all the keys in blue
//             rgb_matrix_enable();
//             break;

//         case _ADJUST:
//             // should only be flashed to left side
//             rgb_matrix_disable();
//             rgb_matrix_set_color_all(0, 0,0);

//             // Row 2
//             rgb_matrix_set_color(16, 255, 255, 0);
//             rgb_matrix_set_color(19, 255, 255, 0);
//             rgb_matrix_set_color(22, 255, 255, 0);
//             rgb_matrix_set_color(23, 255, 255, 0);

//             // Row 3
//             rgb_matrix_set_color(12, 0, 255, 255);
//             rgb_matrix_set_color(15, 0, 255, 255);
//             rgb_matrix_set_color(20, 0, 255, 255);
//             rgb_matrix_set_color(21, 0, 255, 255);
//             rgb_matrix_set_color(26, 0, 255, 255);
//             break;

//         case _LOWER:
//             rgb_matrix_disable();
//             rgb_matrix_set_color_all(0, 0,0);

//             // Arrow keys
//             rgb_matrix_set_color(11, 255, 0, 0);
//             rgb_matrix_set_color(16, 255, 0, 0);
//             rgb_matrix_set_color(19, 255, 0, 0);
//             rgb_matrix_set_color(22, 255, 0, 0);

//             // Mouse keys
//             rgb_matrix_set_color(12, 255, 0, 255);
//             rgb_matrix_set_color(15, 255, 0, 255);
//             rgb_matrix_set_color(20, 255, 0, 255);
//             rgb_matrix_set_color(21, 255, 0, 255);
//             break;

//         case _RAISE:
//             rgb_matrix_disable();
//             rgb_matrix_set_color_all(0,0,0); // rest of keys
//             rgb_matrix_set_color(1, 0, 100, 255);
//             // rgb_matrix_set_color(81, 0, 100, 255);
//             // rgb_matrix_set_color(62, 255, 0, 100);
//             rgb_matrix_set_color(50, 255, 0, 100);
//             rgb_matrix_set_color(51, 255, 0, 100);
//             rgb_matrix_set_color(52, 255, 0, 100);
//             rgb_matrix_set_color(53, 255, 0, 100);
//             break;

//         case _I3:
//             // should only be flashed to right side
//             rgb_matrix_disable();
//             rgb_matrix_set_color_all(0,0,0); // rest of keys
//             rgb_matrix_set_color(9, 0, 100, 255);
//             rgb_matrix_set_color(10, 0, 100, 255);
//             rgb_matrix_set_color(17, 0, 100, 255);
//             rgb_matrix_set_color(18, 0, 100, 255);
//             rgb_matrix_set_color(23, 0, 100, 255);
//             rgb_matrix_set_color(26, 255, 100, 0);
//             break;

//         default: {
//             check_default_layer(IS_LAYER_ON(_ADJUST), LED_FLAG_UNDERGLOW);
//             break;
//         }
//     }

//     check_default_layer(0, LED_FLAG_MODIFIER);

// }
// #endif
