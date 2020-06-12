#include QMK_KEYBOARD_H

enum code_keycodes {
  COL_BLCK = SAFE_RANGE, // collapse code block (VS Code)
  EXP_BLCK, // expand code block (VS Code)
  CPY_UP, // copies line up (VS Code)
  CPY_DOWN, // copies line down (VS Code)
  MV_LEFT, // move left (VS Code)
  MV_RGHT, // move right (VS Code)
  MV_UP, // move up (VS Code)
  MV_DOWN, // move down (VS Code)
  DEL_LINE, // delete line (VS Code)
  HLW_LEFT, // highlight word left
  HLW_RGHT, // highlight word right
  HL_LEFT, // highlight left
  HL_RGHT, // highlight right
  HL_UP, // highlight up
  HL_DOWN, // highlight down,
  HL_PGUP, // highlight page up
  HL_PGDN, // highlight page down
  PAR_LEFT, // left paren (
  PAR_RGHT // right paren )
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Layer3|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  GUI | Caps |  Alt |Layer1| Shift| Space|Layer2| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_ortho_4x12(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        MO(3),   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
        KC_LCTL, KC_LGUI, KC_CAPS, KC_LALT, MO(1), KC_LSFT,KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------.
     * |   `  |  F9  |  F10 |  F11 |  F12 |      |      | Home | PgDwn| PgUp |  End |Delete|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F5  |  F6  |  F7  |  F8  |      |      | Left | Down |  Up  | Right|      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |Reset |      |      |      |      | Shift|Layer4|  Alt |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [1] = LAYOUT_ortho_4x12(
        KC_GRV,  KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______,  KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_DELETE,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______, _______,  _______, _______, _______, _______,
        KC_LCTL, RESET, _______, _______, _______, _______, KC_RSFT,    MO(4), KC_RALT, _______, _______, _______
    ),

    /* Layer 2
     * ,-----------------------------------------------------------------------------------.
     * |      |      |   7  |   8  |   9  |      |      |   (  |   )  |   \  |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   0  |   4  |   5  |   6  |      |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |   1  |   2  |   3  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |Layer4|      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [2] = LAYOUT_ortho_4x12(
        _______, _______, KC_7,    KC_8,    KC_9,  _______, _______, PAR_LEFT, PAR_RGHT, KC_BSLASH, _______, _______,
        _______, KC_0,    KC_4,    KC_5,    KC_6,  _______, _______, KC_MINS,  KC_EQL,   KC_LBRC,   KC_RBRC, KC_BSLS,
        _______, _______, KC_1,    KC_2,    KC_3,  _______, _______, _______,  _______,  _______,   _______, _______,
        _______, _______, _______, _______, MO(4), _______, _______, _______,  _______,  _______,   _______, _______
    ),
    /* Layer 3 (Macros)
     * ,--------------------------------------------------------------------------------------------------.
     * |      |COL_BLCK|CPY_DOWN| CPY_UP|EXP_BLCK|      |      |HLW_LEFT|HL_PGDN|HL_PGUP|HLW_RGHT|DEL_LINE|
     * |------+--------+--------+-------+--------+-------------+--------+-------+-------+--------+--------|
     * |      |MV_LEFT |MV_DOWN |  MV_UP|MV_RGHT |      |      |HL_LEFT |HL_DOWN| HL_UP |HL_RGHT |        |
     * |------+--------+--------+-------+--------+------|------+--------+-------+-------+--------+--------|
     * |      |        |        |       |        |      |      |        |       |       |        |        |
     * |------+--------+--------+-------+--------+------+------+--------+-------+-------+--------+--------|
     * |      |        |        |       |        |      |      |        |       |       |        |        |
     * `--------------------------------------------------------------------------------------------------'
     */
    [3] = LAYOUT_ortho_4x12(
        _______, COL_BLCK, CPY_DOWN,  CPY_UP,  EXP_BLCK, _______, _______, HLW_LEFT, HL_PGDN,  HL_PGUP, HLW_RGHT, DEL_LINE,
        _______, MV_LEFT,  MV_DOWN,   MV_UP,   MV_RGHT,  _______, _______, HL_LEFT,  HL_DOWN,  HL_UP,   HL_RGHT,  _______,
        _______, _______,  _______,   _______, _______,  _______, _______, _______,  _______,  _______, _______,  _______,
        _______, _______,  _______,   _______, _______,  _______, _______, _______,  _______,  _______, _______,  _______
    ),
    /* Layer 4 (r_ Indicates RGB Controls)
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |r_Mode|r_Hue+|r_Hue-|      |      |r_TOG |r_VAI |r_VAD |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [4] = LAYOUT_ortho_4x12(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, RGB_TOG, RGB_VAI, RGB_VAD, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch(keycode) {
    case COL_BLCK: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_LBRC) SS_UP(X_LCTL) SS_UP(X_LSFT));
      }
      break;
    }
    case EXP_BLCK: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_RBRC) SS_UP(X_LCTL) SS_UP(X_LSFT));
      }
      break;
    }
    case CPY_UP: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_UP) SS_UP(X_LALT) SS_UP(X_LSFT));
      }
      break;
    }
    case CPY_DOWN: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_DOWN) SS_UP(X_LALT) SS_UP(X_LSFT));
      }
      break;
    }
    case MV_LEFT: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LBRC));
      } else {
        SEND_STRING(SS_UP(X_LBRC) SS_UP(X_LCTL));
      }
      break;
    }
    case MV_RGHT: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_RBRC));
      } else {
        SEND_STRING(SS_UP(X_RBRC) SS_UP(X_LCTL));
      }
      break;
    }
    case MV_UP: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_UP));
      } else {
        SEND_STRING(SS_UP(X_UP) SS_UP(X_LALT));
      }
      break;
    }
    case MV_DOWN: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_DOWN));
      } else {
        SEND_STRING(SS_UP(X_DOWN) SS_UP(X_LALT));
      }
      break;
    }
    case DEL_LINE: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_K) SS_UP(X_LCTL) SS_UP(X_LSFT));
      }
      break;
    }
    case HLW_LEFT: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_DOWN(X_LEFT));
      } else {
        SEND_STRING(SS_UP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_LSFT));
      }
      break;
    }
    case HLW_RGHT: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_DOWN(X_RGHT));
      } else {
        SEND_STRING(SS_UP(X_RGHT) SS_UP(X_LCTL) SS_UP(X_LSFT));
      }
      break;
    }
    case HL_LEFT: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LEFT));
      } else {
        SEND_STRING(SS_UP(X_LEFT) SS_UP(X_LSFT));
      }
      break;
    }
    case HL_RGHT: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_RGHT));
      } else {
        SEND_STRING(SS_UP(X_RGHT) SS_UP(X_LSFT));
      }
      break;
    }
    case HL_UP: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_UP));
      } else {
        SEND_STRING(SS_UP(X_UP) SS_UP(X_LSFT));
      }
      break;
    }
    case HL_DOWN: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_DOWN));
      } else {
        SEND_STRING(SS_UP(X_DOWN) SS_UP(X_LSFT));
      }
      break;
    }
    case HL_PGUP: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_PGUP));
      } else {
        SEND_STRING(SS_UP(X_PGUP) SS_UP(X_LSFT));
      }
      break;
    }
    case HL_PGDN: {
      if(record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_PGDN));
      } else {
        SEND_STRING(SS_UP(X_PGDN) SS_UP(X_LSFT));
      }
      break;
    }
    case PAR_LEFT: {
      if(record->event.pressed) {
        SEND_STRING("(");
      }
      break;
    }
    case PAR_RGHT: {
      if(record->event.pressed) {
        SEND_STRING(")");
      }
      break;
    }
  }
  return true;
}

void led_set_user(uint8_t usb_led) {

    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {

    } else {

    }

    if (IS_LED_ON(usb_led, USB_LED_KANA)) {

    } else {

    }

}
