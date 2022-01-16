/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

// #define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
// use :dfu-split-left or :dfu-split-right
// sudo util/docker_build.sh crkbd:ChristofferNissen:dfu-split-left

#define SSD1306OLED
#define USE_I2C
#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 175

#ifdef RGBLIGHT_ENABLE
    // #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    // #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#undef FORCE_NKRO
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_SPLIT { 27, 27 }

    #define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 175
    #define RGB_MATRIX_STARTUP_VAL 75
    #define RGB_MATRIX_LED_FLUSH_LIMIT 16

    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 5
    #define RGB_MATRIX_SPD_STEP 10

    #define DISABLE_RGB_MATRIX_ALPHAS_MODS
    #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    // #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    // #define DISABLE_RGB_MATRIX_BREATHING
    #define DISABLE_RGB_MATRIX_BAND_SAT
    #define DISABLE_RGB_MATRIX_BAND_VAL
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL

    #define DISABLE_RGB_MATRIX_CYCLE_ALL
    #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define DISABLE_RGB_MATRIX_DUAL_BEACON
    #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
    #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define DISABLE_RGB_MATRIX_RAINDROPS
    #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

    #define DISABLE_RGB_MATRIX_SPLASH
    #define DISABLE_RGB_MATRIX_MULTISPLASH
    #define DISABLE_RGB_MATRIX_SOLID_SPLASH
    #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

    // #define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
    // #define RBG_MATRIX_FRAMEBUFFER_EFFECTS
    // #define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
    #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
    #define DISABLE_RGB_MATRIX_DIGITAL_RAIN

    #define RGB_MATRIX_ANIMATION_SPEED_DEFAULT UINT8_MAX / 2
    #define RGB_MATRIX_ANIMATION_SPEED_SLOW RGB_MATRIX_ANIMATION_SPEED_DEFAULT / 4
    #define RGB_MATRIX_ANIMATION_SPEED_SLOWER RGB_MATRIX_ANIMATION_SPEED_SLOW / 3

#endif

#define OLED_DISABLE_TIMEOUT
#define OLED_FONT_H "keyboards/crkbd/keymaps/ChristofferNissen/glcdfont.c"

#undef PRODUCT
#define PRODUCT Awesome Corne Keyboard

#define USB_POLLING_INTERVAL_MS 1

// #define RGB_DISABLE_TIMEOUT
// #define RGBLIGHT_SLEEP


#define RGBLIGHT_SPLIT

// ChristofferNissen custom
// #define DANISH
#define I3UI
#define UNICODE_SELECTED_MODES UC_LNX



// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD_PER_KEY

// Other settings //
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Other settings //
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD


// Shamelessly stolen mouse key settings from @pierrechevalier83 //

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Hz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100

#define TAPPING_TOGGLE 3
