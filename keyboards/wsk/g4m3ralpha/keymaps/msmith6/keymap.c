/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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

#define _QWERTY 0
#define _GAME 1
#define _GAME_EXTRA 2
#define _LOWER 3
#define _RAISE 4
#define _MISC 5
#define _MOUSE 6

enum custom_keycodes {
  ALT_1 = SAFE_RANGE,
  ALT_2,
  ALT_3,
  ALT_4,
  ALT_5,
  CHAT_ENT
};

uint16_t alt_keycode = 0;
uint16_t key_timer;
bool switch_back_to_game = false;

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define COL_BLCK LCTL(LSFT(KC_LBRC)) // collapse code block (VS Code)
#define EXP_BLCK LCTL(LSFT(KC_RBRC)) // expand code block (VS Code)
#define CPY_UP LALT(LSFT(KC_UP)) // copies line up (VS Code)
#define CPY_DOWN LALT(LSFT(KC_DOWN)) // copies line down (VS Code)
#define MV_LEFT LCTL(KC_LBRC) // move left (VS Code)
#define MV_RGHT LCTL(KC_RBRC) // move right (VS Code)
#define MV_UP LALT(KC_UP) // move up (VS Code)
#define MV_DOWN LALT(KC_DOWN) // move down (VS Code)
#define DEL_LINE LCTL(LSFT(KC_K)) // delete line (VS Code)
#define LWR_J LT(_LOWER, KC_J)
#define LWR_F LT(_LOWER, KC_F)
#define LWR_MIN LT(_LOWER, KC_MINS)
#define LWR_6 LT(_LOWER, KC_6)
#define RSE_5 LT(_RAISE, KC_5)
#define RSE_K LT(_RAISE, KC_K)
#define RSE_D LT(_RAISE, KC_D)
#define RSE_DWN LT(_RAISE, KC_DOWN)
#define SFT_TAB LSFT_T(KC_TAB)
#define MISC_G LT(_MISC, KC_G)
#define MISC_H LT(_MISC, KC_H)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------.
             KC_1,         KC_2,  KC_3,  KC_4,  KC_5,\
  //,------------+-------------+------+------+------|------+------+--------+-------+----------------|
             KC_Q,         KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,    KC_I,   KC_O,            KC_P,\
  //|------------+-------------+------+------+------|------+------+--------+-------+----------------|
     LCTL_T(KC_A), LALT_T(KC_S), RSE_D, LWR_F,MISC_G,MISC_H, LWR_J,   RSE_K,   KC_L, RCTL_T(KC_SCLN),\
  //|------------+-------------+------+------+------|------+------+--------+-------+----------------|
     LSFT_T(KC_Z),         KC_X,  KC_C,  KC_V,KC_SPC,  KC_B,  KC_N, RSFT_T(KC_M)
  //|------------+-------------+------+------+------+------+------+--------+-------+----------------|
  ),

 [_GAME] = LAYOUT( \
  //,---------------------------------.
        KC_1, KC_2, KC_3,  KC_4,  KC_5,\
  //,-------+-----+-----+------+------+------|------+------+--------+----------------|
      KC_TAB, KC_Q, KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,    KC_I, LT(_GAME, KC_O),\
  //|-------+-----+-----+------+------+------|------+------+--------+----------------|
     KC_LCTL, KC_A, KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,    KC_K,            KC_L,\
  //|-------+-----+-----+------+------+------|------+------+--------+----------------|
     KC_LSFT, KC_Z, KC_X,  KC_C,  LT(_GAME_EXTRA, KC_SPC), KC_V, KC_B, CHAT_ENT
  //|-------+-----+-----+------+------+------+------+------+--------+----------------|
  ),

 [_GAME_EXTRA] = LAYOUT( \
  //,------------------------------------------------------.
           ALT_1,      ALT_2,      ALT_3,      ALT_4, ALT_5,\
  //,-----------+-----------+-----------+-----------+------+------|------+--------+--------+--------|
          KC_TAB,       KC_W,       KC_E,       KC_R,  KC_T,  KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,\
  //|-----------+-----------+-----------+-----------+------+------|------+--------+--------+--------|
          KC_ESC,       KC_S,       KC_D,       KC_F,  KC_G,  KC_H,  KC_J,    KC_K,    KC_L, KC_SCLN,\
  //|-----------+-----------+-----------+-----------+------+------|------+--------+--------+--------|
         KC_LALT,       KC_X,       KC_C,       KC_V,  _______, KC_B,  KC_N,  KC_M
  //|-----------+-----------+-----------+-----------+------+------+------+--------+--------+--------|
  ),

  [_LOWER] = LAYOUT( \
  //,------------------------------------------------.
             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,\
  //,------------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
           KC_ESC,    KC_7,    KC_8,    KC_9, XXXXXXX,  KC_GRV, KC_QUOT, KC_LPRN, KC_RPRN,KC_BSLASH,\
  //|------------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
     LCTL_T(KC_0),    KC_4,   RSE_5,   LWR_6, XXXXXXX, XXXXXXX, LWR_MIN,  KC_EQL, KC_LBRC,  KC_RBRC,\
  //|------------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
          _______,    KC_1,    KC_2,    KC_3, KC_BSPC, KC_COMM,  KC_DOT, RSFT_T(KC_SLSH)
  //|------------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
  ),

  [_RAISE] = LAYOUT( \
  //,-------------------------------------------.
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,\
  //,-------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
      KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,   KC_END,\
  //|-------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
     KC_LCTL, KC_LALT, _______, SFT_TAB, XXXXXXX, XXXXXXX, KC_LEFT, RSE_DWN,   KC_UP,  KC_RGHT,\
  //|-------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
     XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, KC_BSPC,  KC_DEL, XXXXXXX, CHAT_ENT
  //|-------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
  ),

  [_MISC] = LAYOUT( \
  //,------------------------------------------.
       KC_1,    KC_2,    KC_3,    KC_4, TO(_GAME),\
  //,------+--------+--------+--------+--------|--------+--------+--------+--------+-----------|
      KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_RCTL,   RESET,COL_BLCK,CPY_DOWN,  CPY_UP,   EXP_BLCK,\
  //|------+--------+--------+--------+--------|--------+--------+--------+--------+-----------|
      KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______, MV_LEFT, MV_DOWN,   MV_UP,   MV_RGHT,\
  //|------+--------+--------+--------+--------|--------+--------+--------+--------+-----------|
      KC_F1,   KC_F2,   KC_F3,   KC_F4,     DEL_LINE,     KC_RALT, XXXXXXX, _______
  //|------+--------+--------+--------+--------+--------+--------+--------+--------+-----------|
  ),

  [_MOUSE] = LAYOUT( \
  //,-------------------------------------------.
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,\
  //,-------+--------+--------+--------+--------|---------+--------+--------+--------+------------|
     KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U,  KC_WH_R, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U,     KC_WH_R,\
  //|-------+--------+--------+--------+---------|--------+--------+--------+--------+------------|
     KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R,  KC_BTN1, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U,     KC_MS_R,\
  //|-------+--------+--------+--------+---------|--------+--------+--------+--------+------------|
     KC_LCTL, KC_BTN5, XXXXXXX, KC_BTN4,  KC_BTN3, XXXXXXX, XXXXXXX, TO(_QWERTY)
  //|-------+--------+--------+--------+---------+--------+--------+--------+--------+------------|
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _GAME:
        writePinHigh(D3);
        writePinHigh(D2);
        break;
    default: //  for any other layers, or the default layer
        writePinLow(D3);
        writePinLow(D2);
        break;
    }
  return state;
}

bool led_update_user(led_t led_state) {
    writePin(D0, led_state.caps_lock);
    return false;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RSE_D:
    case LWR_F:
      return true;
    default:
      return false;
  }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LSFT_T(KC_Z):
    case RSFT_T(KC_M):
      return false;
    default:
      return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_1:
      if (record->event.pressed) {
        register_code(KC_LALT);
        alt_keycode = KC_1;
        key_timer = timer_read();
      }
      return false;
    case ALT_2:
      if (record->event.pressed) {
        register_code(KC_LALT);
        alt_keycode = KC_2;
        key_timer = timer_read();
      }
      return false;
    case ALT_3:
      if (record->event.pressed) {
        register_code(KC_LALT);
        alt_keycode = KC_3;
        key_timer = timer_read();
      }
      return false;
    case ALT_4:
      if (record->event.pressed) {
        register_code(KC_LALT);
        alt_keycode = KC_4;
        key_timer = timer_read();
      }
      return false;
    case ALT_5:
      if (record->event.pressed) {
        register_code(KC_LALT);
        alt_keycode = KC_5;
        key_timer = timer_read();
      }
      return false;
    case CHAT_ENT:
      if (record->event.pressed) {
        tap_code(KC_ENT);
        if (IS_LAYER_ON(_GAME) || switch_back_to_game) {
          switch_back_to_game = !switch_back_to_game;
          layer_invert(_GAME);
        }
      }
      return false;
    case KC_ESC:
      if (switch_back_to_game) {
        switch_back_to_game = false;
        layer_on(_GAME);
      }
      return true;
  }
  return true;
}

void matrix_scan_user(void) {
  if ( alt_keycode != 0 && ( timer_elapsed(key_timer) > 75 ) ) {
    tap_code(alt_keycode);
    unregister_code(KC_LALT);
    alt_keycode = 0;
  }
}