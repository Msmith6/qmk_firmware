#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MISC 3
#define _MOUSE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MISC,
  MOUSE
};

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

 [_QWERTY] = LAYOUT_ortho( \
  //,-----------------------------------------------------------------------------------------------------------------------------.
     KC_MUTE,   KC_ESC,         KC_Q,         KC_W,  KC_E,  KC_R,  KC_T,   KC_Y,  KC_U,    KC_I,   KC_O,            KC_P, KC_BSPC,\
  //|-------+---------+-------------+-------------+------+------+------|-------+------+--------+-------+----------------+---------|
      TZ_NXT,  KC_LCTL, LCTL_T(KC_A), LALT_T(KC_S), RSE_D, LWR_F,MISC_G, MISC_H, LWR_J,   RSE_K,   KC_L, RCTL_T(KC_SCLN),  KC_ENT,\
  //|-------+---------+-------------+-------------+------+------+------|-------+------+--------+-------+----------------+---------|
      TZ_PRV,  KC_LSFT, LSFT_T(KC_Z),         KC_X,  KC_C,  KC_V,  KC_B,   KC_N,  KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), KC_RSFT,\
  //|-------+---------+-------------+-------------+------+------+------|-------+------+--------+-------+----------------+---------|
      TZ_OFF,                         KC_TAB, KC_LALT,  KC_LGUI, KC_SPC, KC_SPC, XXXXXXX, XXXXXXX, KC_PSCR
  ),

  [_LOWER] = LAYOUT_ortho( \
  //,--------------------------------------------------------------------------------------------------------------------------.
     _______,  _______,      KC_ESC,    KC_7,    KC_8,    KC_9, XXXXXXX,  KC_GRV, KC_QUOT, KC_LPRN, KC_RPRN,KC_BSLASH, _______,\
  //|-------+---------+------------+--------+--------+--------+--------|--------+--------+--------+--------+---------+---------|
     _______,  _______,LCTL_T(KC_0),    KC_4,   RSE_5,   LWR_6, XXXXXXX, XXXXXXX, LWR_MIN,  KC_EQL, KC_LBRC,  KC_RBRC, _______,\
  //|-------+---------+------------+--------+--------+--------+--------|--------+--------+--------+--------+---------+---------|
     _______,  _______,     _______,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, KC_BSPC, KC_COMM,  KC_DOT,  _______, _______,\
  //|-------+---------+------------+--------+--------+--------+--------+--------+--------+--------+--------+---------+---------|
     _______,                           _______,_______,_______,_______,_______,_______,_______,_______
  ),

  [_RAISE] = LAYOUT_ortho( \
  //,--------------------------------------------------------------------------------------------------------------------.
     _______,  _______, KC_ESC, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,\
  //|-------+---------+-------+--------+--------+--------+--------|--------+--------+--------+--------+--------+---------|
     _______,  _______,KC_LCTL, KC_LALT, _______, SFT_TAB, XXXXXXX, XXXXXXX, KC_LEFT, RSE_DWN,   KC_UP, KC_RGHT, _______,\
  //|-------+---------+-------+--------+--------+--------+--------|--------+--------+--------+--------+--------+---------|
     _______,  _______,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,  KC_DEL, XXXXXXX,  KC_ENT, _______,\
  //|-------+---------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     _______,                           _______,_______,_______,_______,_______,_______,_______,_______
  ),

  [_MISC] = LAYOUT_ortho( \
  //,------------------------------------------------------------------------------------------------------------------.
     _______,  _______,KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_RCTL,   RESET,COL_BLCK,CPY_DOWN,  CPY_UP,EXP_BLCK, _______,\
  //|-------+---------+-----+--------+--------+--------+--------|--------+--------+--------+--------+--------+---------|
     _______,  _______,KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______, MV_LEFT, MV_DOWN,   MV_UP, MV_RGHT, _______,\
  //|-------+---------+-----+--------+--------+--------+--------|--------+--------+--------+--------+--------+---------|
     _______,  _______,KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_RALT, XXXXXXX,DEL_LINE, XXXXXXX, XXXXXXX,   MOUSE, _______,\
  //|-------+---------+-----+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
     _______,                           _______,_______,_______,_______,_______,_______,_______,_______
  ),

  [_MOUSE] = LAYOUT_ortho( \
  //,---------------------------------------------------------------------------------------------------------------------.
     _______,  _______,KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U,  KC_WH_R, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,\
  //|-------+---------+-------+--------+--------+--------+---------|--------+--------+--------+--------+--------+---------|
     _______,  _______,KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R,  KC_BTN1, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,\
  //|-------+---------+-------+--------+--------+--------+---------|--------+--------+--------+--------+--------+---------|
     _______,  _______,KC_LCTL, KC_BTN5, XXXXXXX, KC_BTN4,  KC_BTN3, QWERTY, XXXXXXX,  XXXXXXX, XXXXXXX,   MOUSE, _______,\
  //|-------+---------+-------+--------+--------+--------+---------+--------+--------+--------+--------+--------+---------|
     _______,                           _______,_______,_______,KC_BTN1,_______,_______,_______,_______
  )

};

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
    case RSFT_T(KC_SLSH):
      return false;
    default:
      return true;
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOUSE:
      if (record->event.pressed) {
        layer_clear();
        layer_on(_MOUSE);
      }
      return false;
    case QWERTY:
      if (record->event.pressed) {
        layer_clear();
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    terrazzo_scroll_pixel(clockwise);
    switch(index) {
        case 0:
          clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
          break;
            // switch(get_highest_layer(layer_state)) {
            //   case _RAISE:
            //       break;
            //   default:
            //       break;
            // }
        case 1:
          clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
          break;
    }
}
