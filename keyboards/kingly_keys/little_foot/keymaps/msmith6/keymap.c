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

 [_QWERTY] = LAYOUT_big_space_base( \
  //,-----------------------------------------------------------------------------------------------.
             KC_1,         KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,    KC_8,   KC_9,            KC_0,\
  //,------------+-------------+------+------+------|------+------+--------+-------+----------------|
             KC_Q,         KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,    KC_I,   KC_O,            KC_P,\
  //|------------+-------------+------+------+------|------+------+--------+-------+----------------|
     LCTL_T(KC_A), LALT_T(KC_S), RSE_D, LWR_F,MISC_G,MISC_H, LWR_J,   RSE_K,   KC_L, RCTL_T(KC_SCLN),\
  //|------------+-------------+------+------+------|------+------+--------+-------+----------------|
     LSFT_T(KC_Z),         KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH),\
  //|------------+-------------+------+------+------+------+------+--------+-------+----------------|
                                                 KC_SPC
  //                                      `-------------------'
  ),

 [_GAME] = LAYOUT_big_space_base( \
  //,--------------------------------------------------------------------------------.
        KC_1, KC_2, KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9, LT(_GAME, KC_0),\
  //,-------+-----+-----+------+------+------|------+------+--------+----------------|
      KC_TAB, KC_Q, KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,    KC_I,            KC_O,\
  //|-------+-----+-----+------+------+------|------+------+--------+----------------|
     KC_LCTL, KC_A, KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,    KC_K,            KC_L,\
  //|-------+-----+-----+------+------+------|------+------+--------+----------------|
     KC_LSFT, KC_Z, KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM,        CHAT_ENT,\
  //|-------+-----+-----+------+------+------+------+------+--------+----------------|
                                 LT(_GAME_EXTRA, KC_SPC)
  //                               `-------------------'
  ),

 [_GAME_EXTRA] = LAYOUT_big_space_base( \
  //,------------------------------------------------------------------------------------------------.
           ALT_1,      ALT_2,      ALT_3,      ALT_4, ALT_5,  KC_6,  KC_7,    KC_8,    KC_9,    KC_0,\
  //,-----------+-----------+-----------+-----------+------+------|------+--------+--------+--------|
          KC_TAB,       KC_W,       KC_E,       KC_R,  KC_T,  KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,\
  //|-----------+-----------+-----------+-----------+------+------|------+--------+--------+--------|
          KC_ESC,       KC_S,       KC_D,       KC_F,  KC_G,  KC_H,  KC_J,    KC_K,    KC_L, KC_SCLN,\
  //|-----------+-----------+-----------+-----------+------+------|------+--------+--------+--------|
         KC_LALT,       KC_X,       KC_C,       KC_V,  KC_B,  KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,\
  //|-----------+-----------+-----------+-----------+------+------+------+--------+--------+--------|
                                                     KC_TRNS
  //                                          `-------------------'
  ),

  [_LOWER] = LAYOUT_big_space_base( \
  //,----------------------------------------------------------------------------------------------.
           KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,\
  //,------------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
           KC_ESC,    KC_7,    KC_8,    KC_9, XXXXXXX,  KC_GRV, KC_QUOT, KC_LPRN, KC_RPRN,KC_BSLASH,\
  //|------------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
     LCTL_T(KC_0),    KC_4,   RSE_5,   LWR_6, XXXXXXX, XXXXXXX, LWR_MIN,  KC_EQL, KC_LBRC,  KC_RBRC,\
  //|------------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
          _______,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, KC_BSPC, KC_COMM,  KC_DOT,  _______,\
  //|------------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
                                                  KC_SPC
  //                                       `-------------------'
  ),

  [_RAISE] = LAYOUT_big_space_base( \
  //,-----------------------------------------------------------------------------------------.
      KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,\
  //,-------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
      KC_ESC, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,   KC_END,\
  //|-------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
     KC_LCTL, KC_LALT, _______, SFT_TAB, XXXXXXX, XXXXXXX, KC_LEFT, RSE_DWN,   KC_UP,  KC_RGHT,\
  //|-------+--------+--------+--------+--------|--------+--------+--------+--------+---------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,  KC_DEL, XXXXXXX, CHAT_ENT,\
  //|-------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
                                              KC_SPC
  //                                  `-------------------'
  ),

  [_MISC] = LAYOUT_big_space_base( \
  //,------------------------------------------------------------------------------------------.
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,  TO(_GAME),\
  //,------+--------+--------+--------+--------|--------+--------+--------+--------+-----------|
      KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_RCTL,   RESET,COL_BLCK,CPY_DOWN,  CPY_UP,   EXP_BLCK,\
  //|------+--------+--------+--------+--------|--------+--------+--------+--------+-----------|
      KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______, MV_LEFT, MV_DOWN,   MV_UP,   MV_RGHT,\
  //|------+--------+--------+--------+--------|--------+--------+--------+--------+-----------|
      KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_RALT, XXXXXXX,DEL_LINE, XXXXXXX, XXXXXXX, TO(_MOUSE),\
  //|------+--------+--------+--------+--------+--------+--------+--------+--------+-----------|
                                           KC_SPC
  //                                `-------------------'
  ),

  [_MOUSE] = LAYOUT_big_space_base( \
  //,----------------------------------------------------------------------------------------------.
      KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,    KC_8,        KC_9,\
  //,-------+--------+--------+--------+--------|---------+--------+--------+--------+------------|
     KC_WH_L, KC_WH_D, KC_MS_U, KC_WH_U,  KC_WH_R, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U,     KC_WH_R,\
  //|-------+--------+--------+--------+---------|--------+--------+--------+--------+------------|
     KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R,  KC_BTN1, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U,     KC_MS_R,\
  //|-------+--------+--------+--------+---------|--------+--------+--------+--------+------------|
     KC_LCTL, KC_BTN5, XXXXXXX, KC_BTN4,  KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY),\
  //|-------+--------+--------+--------+---------+--------+--------+--------+--------+------------|
                                              KC_BTN1
  //                                   `-------------------'

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

