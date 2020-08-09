#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _TXTEDIT 3
#define _FN 4
#define _GAME 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TXTEDIT,
  FN,
  GAME
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
#define HLW_LEFT LCTL(LSFT(KC_LEFT)) // highlight word left
#define HLW_RGHT LCTL(LSFT(KC_RGHT)) // highlight word right
#define HL_LEFT LSFT(KC_LEFT) // highlight left
#define HL_RGHT LSFT(KC_RGHT) // highlight right
#define HL_UP LSFT(KC_UP) // highlight up
#define HL_DOWN LSFT(KC_DOWN) // highlight down,
#define HL_PGUP LSFT(KC_PGUP) // highlight page up
#define HL_PGDN LSFT(KC_PGDN) // highlight page down

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------.                          ,--------------------------------------------------.
             KC_Q,         KC_W,  KC_E,  KC_R,  KC_T,                             KC_Y,     KC_U,    KC_I,   KC_O,            KC_P,\
  //|------------+-------------+------+------+------|                          |------+---------+--------+-------+----------------|
     LCTL_T(KC_A), LALT_T(KC_S),  KC_D,  KC_F,  KC_G,                             KC_H,     KC_J,    KC_K,   KC_L, RCTL_T(KC_SCLN),\
  //|------------+-------------+------+------+------|                          |------+---------+--------+-------+----------------|
             KC_Z,         KC_X,  KC_C,  KC_V,  KC_B,                             KC_N,     KC_M, KC_COMM, KC_DOT,         KC_SLSH,\
  //|------------+-------------+------+------+------+--------|  |--------------+------+---------+--------+-------+----------------|
                                               LOWER, TXTEDIT,   LSFT_T(KC_SPC), RAISE \
                                        //`------------------'  `---------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-------------------------------------------.                    ,---------------------------------------------.
      KC_ESC,    KC_7,    KC_8,    KC_9, XXXXXXX,                       KC_GRV, KC_QUOT, KC_LPRN, KC_RPRN,KC_BSLASH,\
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
        KC_0,    KC_4,    KC_5,    KC_6, XXXXXXX,                      XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC,  KC_RBRC,\
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
     XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOT,  KC_SLSH,\
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------|
                                           LOWER, XXXXXXX,     KC_SPC,   RAISE \
                                    //`------------------'  `-----------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-------------------------------------------.                   ,--------------------------------------------.
      KC_ESC, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,\
  //|-------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------|
     KC_LCTL, KC_LALT, XXXXXXX,  KC_TAB, XXXXXXX,                     XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,\
  //|-------+--------+--------+--------+--------|                   |--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, KC_BSPC,  KC_DEL, XXXXXXX,  KC_ENT,\
  //|-------+--------+--------+--------+--------+--------|  |-------+--------+--------+--------+--------+--------|
                                           LOWER, KC_LSFT,   XXXXXXX,   RAISE \
                                    //`------------------'  `----------------'
  ),

  [_TXTEDIT] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
     COL_BLCK,CPY_DOWN, CPY_UP, EXP_BLCK, XXXXXXX,                      XXXXXXX,HLW_LEFT, HL_PGDN, HL_PGUP,HLW_RGHT,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      MV_LEFT, MV_DOWN,   MV_UP, MV_RGHT, XXXXXXX,                      XXXXXXX, HL_LEFT, HL_DOWN,   HL_UP, HL_RGHT,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,DEL_LINE, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, TXTEDIT,     KC_SPC, XXXXXXX \
                                     //`------------------'  `-----------------'
  ),

  [_FN] = LAYOUT( \
  //,-----------------------------------------.                    ,--------------------------------------------.
     KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|-----+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, KC_RCTL,\
  //|-----+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                         GAME, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|-----+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       XXXXXXX, KC_LSFT,     KC_SPC, XXXXXXX \
                                  //`------------------'  `-----------------'
  ),

  [_GAME] = LAYOUT( \
  //,--------------------------------------------.                    ,------------------------------------------------------.
        KC_6,    KC_1,    KC_W,    KC_2,     KC_3,                      KC_PSCR, XXXXXXX, XXXXXXX, RALT(KC_F9), RALT(KC_F10),\
  //|-------+--------+--------+--------+---------|                    |--------+--------+--------+------------+-------------|
     KC_LSFT,    KC_A,    KC_S,    KC_D,     KC_4,                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX,\
  //|-------+--------+--------+--------+---------|                    |--------+--------+--------+------------+-------------|
        KC_7,    KC_Z,    KC_X,    KC_C,     KC_5,                         GAME, XXXXXXX, XXXXXXX,     XXXXXXX,       KC_ESC,\
  //|-------+--------+--------+--------+---------+--------|  |--------+--------+--------+--------+------------+-------------|
                                           KC_TAB,  KC_SPC,    XXXXXXX, QWERTY \
                                     //`------------------'  `----------------'

  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GAME:
      if (record->event.pressed) {
        layer_clear();
        layer_on(_GAME);
      }
      return false;
    case QWERTY:
      if (record->event.pressed) {
        layer_clear();
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FN);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FN);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FN);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FN);
      }
      return false;
    case TXTEDIT:
      if(record ->event.pressed) {
        layer_on(_TXTEDIT);
      } else {
        layer_off(_TXTEDIT);
      }
      return false;
    case FN:
      if(record ->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
  }
  return true;
}
