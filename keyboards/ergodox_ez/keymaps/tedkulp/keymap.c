#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define _CO 0
#define _QW 1
#define _MD 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Default Colemak Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  ~   |           |  -   |   6  |   7  |   8  |   9  |   0  |   +=   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   F  |   P  |   G  |  [   |           |  ]   |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|  (   |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl| LAlt |  L1  |      | ~L2  |                                       | ~L2  |      |      | RAlt | RCtrl |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |LShift| LCtl |       | PgUp | PgDn |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RAlt |      |      |
 *                                 | BkSp | Esc  |------|       |------| Enter| Space|
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_CO] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,  KC_4,    KC_5,    KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_F,  KC_P,    KC_G,    KC_LBRC,
        KC_LCTL, KC_A,    KC_R,    KC_S,  KC_T,    KC_D,
        KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,    KC_LCBR,
        KC_LCTL, KC_LALT, TG(_QW), KC_NO, MO(_MD),

                                                   KC_LSFT, KC_DEL,
                                                            KC_LALT,
                                          KC_BSPC, KC_ESC,  KC_LGUI,

        // right hand
        KC_MINS, KC_6,   KC_7,    KC_8,    KC_9,   KC_0,    KC_EQL,
        KC_RBRC, KC_J,   KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSLS,
                 KC_H,   KC_J,    KC_K,    KC_L,   KC_O,    KC_QUOT,
        KC_RCBR, KC_K,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                         MO(_MD), KC_NO,   KC_NO,  KC_RALT, KC_RCTL,

        KC_PGDN, KC_PGUP,
        KC_RALT,
        KC_RGUI, KC_ENT, KC_SPC
    ),
/* Keymap 1: QWERTY Emergency Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   :  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  L0  |      |      |                                       |      |      |      |      |       |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_QW] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
       KC_TRNS,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
       KC_TRNS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
       KC_TRNS, KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Helper functions
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | Vol+ |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|      |           | Vol- |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_MD] = LAYOUT_ergodox(
       // left hand
       F(0),    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_VOLU,  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_VOLD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

enum function_id {
    TEENSY_KEY,
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(TEENSY_KEY),            // Teensy key
};

// MACRODOWN only works in this function
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    return MACRO_NONE;
};

/*
 * User defined action function
 */
void action_function(keyrecord_t *event, uint8_t id, uint8_t opt) {
  // static uint8_t shift_esc_shift_mask;
  switch (id) {
      case TEENSY_KEY:
          clear_keyboard();
          print("\n\nJump to bootloader... ");
          _delay_ms(250);
          bootloader_jump(); // should not return
          print("not supported.\n");
          break;
      // }
  }
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};
