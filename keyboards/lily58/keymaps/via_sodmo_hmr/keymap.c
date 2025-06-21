 /* Copyright 2020 Naoki Katahira
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
#include <stdio.h>

//extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER LT(_LOWER, KC_TAB)
#define ADJST MO(_ADJUST)

// Home Row Mods
#define HM_A LCTL_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LGUI_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J RSFT_T(KC_J)
#define HM_K RGUI_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RCTL_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |RShift|
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  Esc |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   '  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI | Tab  | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      | LWR  |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  XXXXXXX,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  XXXXXXX,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
  KC_LSFT,    HM_A,   HM_S,    HM_D,    HM_F,    KC_G,                     KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_RSFT,
  KC_ESC,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                     XXXXXXX, KC_LGUI, LOWER,   KC_SPC,                   KC_ENT,  RAISE,   KC_BCPS, XXXXXXX
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |   {  |                    |   }  |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |   (  |-------.    ,-------|   )  |   4  |   5  |   6  |   =  |  ~   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |   [  |-------|    |-------|   ]  |   1  |   2  |   3  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /Space  /       \ADJST \  |  0   |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_LCBR,                   KC_RCBR, KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
  _______, _______, _______, _______, _______, KC_LPRN,                   KC_RPRN, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
  _______, _______, _______, _______, _______, KC_LBRC, _______, _______, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TILD,
                             _______, _______, _______, _______, ADJST,   KC_0,    _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |                    |  ^   |  &   |  *   |   '  |  "   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      | Cpp  |-------.    ,-------| Left | Down |  Up  |Right |      |  `   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|  -   |   |  |      |   _  |   -  |-------|    |-------|VolUp |VolDn |Cprev |Cnext |  \   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /ADJST  /       \Enter \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `-------------------''-------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______,
  _______, _______, _______, _______, _______, KC_MPLY,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
  KC_LSFT, KC_MINS, KC_PIPE, _______, _______, _______,   _______, _______, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_BSLS, KC_GRAVE,
                             _______, _______, _______,  ADJST, _______,  _______, _______, _______
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

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_0;  // I want the layer information to be straight
  return OLED_ROTATION_270;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(logo, false);
}

static void render_pizza(void) {
    static const char PROGMEM pizza[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x20, 0x10, 0x98, 0x4c, 0xce, 0xdb,
        0x11, 0x11, 0xe2, 0x22, 0x42, 0x42, 0xcc, 0x88, 0x18, 0x10, 0x10, 0x30, 0x20, 0x40, 0x80, 0x00,
        0x00, 0x80, 0xc0, 0x30, 0x18, 0xc8, 0x44, 0xe2, 0xe1, 0xe4, 0xec, 0xcb, 0x02, 0x43, 0x31, 0x39,
        0x68, 0x6c, 0x74, 0x77, 0x76, 0x78, 0xb8, 0x80, 0x81, 0xc2, 0x6e, 0xb8, 0xc0, 0x60, 0x1f, 0x07,
        0xfc, 0x07, 0xf0, 0x80, 0xe7, 0x3c, 0x07, 0xc7, 0xe7, 0x73, 0x59, 0x48, 0x2c, 0x34, 0x16, 0x13,
        0x0a, 0x0e, 0x1e, 0x30, 0x1f, 0x07, 0x02, 0x03, 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0xf0, 0x00, 0xf9, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_raw_P(pizza, sizeof(pizza));
}

bool oled_task_user(void) {
  #ifdef OLED_FLIP
  bool condition = !is_keyboard_master();
  #else
  bool condition = is_keyboard_master();
  #endif
  if (condition) {
    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("Layer"), false);
    oled_write_ln_P(PSTR("-----"), false);

    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        oled_write_ln_P(PSTR("Deflt"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("- 0 -"), false);
        break;
    case _RAISE:
        oled_write_ln_P(PSTR("Raise"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("- 2 -"), false);
        break;
    case _LOWER:
        oled_write_ln_P(PSTR("Lower"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("- 1 -"), false);
        break;
    case _ADJUST:
        oled_write_ln_P(PSTR("Adjst"), false);
        oled_write_ln_P(PSTR(""), false);
        oled_write_ln_P(PSTR("- 3 -"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undefined"), false);
    }

    render_pizza();

  } else {
      render_logo();
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    // set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
