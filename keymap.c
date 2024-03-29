/* Copyright 2020 Naoki Katahira
  * Copyright 2023 Elliot Powell
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H

#define frame_size 512

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ~   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                      LOWER, KC_LGUI,  KC_LALT, KC_SPC,   KC_ENT,   KC_BSPC,  KC_RGUI, RAISE
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   |  |   `  |   +  |   {  |   }  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_GRAVE, KC_PLUS, KC_LCBR, KC_RCBR, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGBTOG|RGBHUI|RGBSAI|RGBVAI|      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |RGBMOD|RGBHUD|RGBSAD|RGBVAD|      |      |-------|    |-------|   +  |   =  |   [  |   ]  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,   _______, _______, KC_PLUS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | Alt  | /Space  /       \Enter \  |BackSP| RGUI |RAISE |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

void render_logo(void) {
  static const char PROGMEM logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x06, 0x0e, 0x1e, 0x3e, 0x7e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x0e, 
    0x1e, 0x3e, 0x7e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7e, 0x3e, 0x1c, 
    0x08, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x08, 
    0x1c, 0x3e, 0x7e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7e, 0x3e, 0x1e, 
    0x0e, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x7e, 0x3e, 0x1e, 0x0e, 0x06, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 
    0xf0, 0xe0, 0xc0, 0x80, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x80, 0xc0, 0xe0, 0xf0, 
    0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 
    0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 
    0xf0, 0xe0, 0xc0, 0x80, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x07, 0x03, 0x01, 0x80, 0xc0, 0xe0, 0xf0, 
    0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
    0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x80, 0xc0, 0xe0, 0xf0, 
    0xf0, 0xe0, 0xc0, 0x80, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 
    0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x70, 0x78, 0x7c, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7c, 0x78, 0x70, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 
    0x1f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
    0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(logo, sizeof(logo));
};

void render_text(void) {
  static const char PROGMEM text[] = {
    0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0x00, 0xff, 0x00, 
    0x00, 0xff, 0x00, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3f, 0x40, 0x40, 0x40, 0x3f, 0x00, 0x26, 0x49, 0x49, 0x49, 0x32, 0x00, 0x26, 0x49, 
    0x49, 0x49, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x11, 0x11, 0x11, 0x7e, 0x00, 
    0x7f, 0x40, 0x40, 0x40, 0x40, 0x00, 0x7f, 0x02, 0x04, 0x02, 0x7f, 0x00, 0x7e, 0x11, 0x11, 0x11, 
    0x7e, 0x00, 0x03, 0x04, 0x78, 0x04, 0x03, 0x00, 0x7f, 0x49, 0x49, 0x49, 0x41, 0x00, 0x7f, 0x09, 
    0x09, 0x09, 0x76, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xc0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xf1, 0xf8, 0xf1, 0xfd, 0xff, 0xff, 0x00, 0xff, 0x00, 
    0x00, 0xff, 0x00, 0xff, 0xff, 0xfd, 0xf1, 0xf8, 0xf1, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xc0, 
    0x00, 0x00, 0x42, 0x61, 0x51, 0x49, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x49, 
    0x49, 0x49, 0x36, 0x00, 0x01, 0x01, 0x7f, 0x01, 0x01, 0x00, 0x7f, 0x40, 0x40, 0x40, 0x40, 0x00, 
    0x7f, 0x04, 0x08, 0x10, 0x7f, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0b, 0x08, 0x08, 
    0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x49, 0x49, 0x49, 0x36, 0x00, 0x7f, 0x09, 
    0x09, 0x09, 0x76, 0x00, 0x3e, 0x41, 0x49, 0x49, 0x3a, 0x00, 0x7f, 0x41, 0x41, 0x41, 0x3e, 0x00, 
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x03, 0x3f, 0xff, 0xff, 0xff, 0xfd, 0xf1, 0xf8, 0xf1, 0xfd, 0xff, 0x7f, 0x0f, 0xe0, 0x1f, 0xe0, 
    0xe0, 0x1f, 0xe0, 0x0f, 0x7f, 0xff, 0xfd, 0xf1, 0xf8, 0xf1, 0xfd, 0xff, 0xff, 0xff, 0x3f, 0x03, 
    0x00, 0x00, 0xfe, 0x80, 0x80, 0x80, 0x80, 0x00, 0x7c, 0x82, 0x82, 0x82, 0x44, 0x00, 0xfe, 0x22, 
    0x22, 0x22, 0x1c, 0x00, 0xfe, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xfe, 0x10, 0x10, 0x10, 0xfe, 0x00, 0x7c, 0x82, 0x82, 0x82, 0x7c, 0x00, 0xfe, 0x80, 0x80, 0x80, 
    0x80, 0x00, 0xfe, 0x80, 0x80, 0x80, 0x80, 0x00, 0x06, 0x08, 0xf0, 0x08, 0x06, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xfe, 0x04, 0x08, 0x04, 0xfe, 0x00, 0xfc, 0x22, 0x22, 0x22, 0xfc, 0x00, 
    0x4c, 0x92, 0x92, 0x92, 0x64, 0x00, 0x4c, 0x92, 0x92, 0x92, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x07, 0x27, 0x33, 0x39, 0x3c, 0x0f, 0x01, 0xc0, 0xff, 
    0xff, 0xc0, 0x01, 0x0f, 0x3c, 0x39, 0x33, 0x27, 0x07, 0x0f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x82, 0x82, 0x82, 0x44, 0x00, 0xfe, 0x04, 0x08, 0x04, 0xfe, 0x00, 0xfe, 0x92, 
    0x92, 0x92, 0x6c, 0x00, 0x02, 0x02, 0xfe, 0x02, 0x02, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x02, 0x02, 0xfe, 0x02, 0x02, 0x00, 0xfe, 0x92, 0x92, 0x92, 0x82, 0x00, 0x7c, 0x82, 0x82, 0x82, 
    0x44, 0x00, 0xfe, 0x10, 0x10, 0x10, 0xfe, 0x00, 0xfe, 0x08, 0x10, 0x20, 0xfe, 0x00, 0x82, 0x82, 
    0xfe, 0x82, 0x82, 0x00, 0x7c, 0x82, 0x82, 0x82, 0x44, 0x00, 0x82, 0x82, 0xfe, 0x82, 0x82, 0x00, 
    0xfc, 0x22, 0x22, 0x22, 0xfc, 0x00, 0xfe, 0x08, 0x10, 0x20, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(text, sizeof(text));
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }

  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_text();
  } else {

    render_logo();
  }
  return false;
}
#endif
