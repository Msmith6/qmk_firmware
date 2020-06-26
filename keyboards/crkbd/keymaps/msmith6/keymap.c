#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _TXTEDIT 3
#define _FN 4
#define _ADJUST 5
#define _GAME 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  TXTEDIT,
  FN,
  GAME,
  BACKLIT,
  RGBRST,
  COL_BLCK, // collapse code block (VS Code)
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
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,--------------------------------------------------.                    ,-------------------------------------------------------.
      XXXXXXX,         KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                      KC_Y,  KC_U,    KC_I,   KC_O,            KC_P, XXXXXXX,\
  //|--------+-------------+------+------+------+------|                    |-----+------+--------+-------+----------------+--------|
      XXXXXXX, LCTL_T(KC_A),  KC_S,  KC_D,  KC_F,  KC_G,                      KC_H,  KC_J,    KC_K,   KC_L, RCTL_T(KC_SCLN), XXXXXXX,\
  //|--------+-------------+------+------+------+------|                    |-----+------+--------+-------+----------------+--------|
      XXXXXXX,        KC_Z,   KC_X,  KC_C,  KC_V,  KC_B,                      KC_N,  KC_M, KC_COMM, KC_DOT,         KC_SLSH, XXXXXXX,\
  //|--------+-------------+------+------+------+------+--------|  |--------+-----+------+--------+-------+----------------+--------|
                                              FN, LOWER, KC_LSFT,    KC_SPC, RAISE, TXTEDIT \
                                    //`-------------------------'  `------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  KC_ESC, XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL, KC_LALT, XXXXXXX,  KC_TAB, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BSPC,  KC_DEL, XXXXXXX,  KC_ENT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               FN,   LOWER, KC_LSFT,     KC_SPC,   RAISE, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
      XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,                       KC_GRV, KC_QUOT, KC_LPRN, KC_RPRN,KC_BSLASH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
      XXXXXXX,    KC_0,    KC_4,    KC_5,    KC_6, XXXXXXX,                      XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC,  KC_RBRC, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
      XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  KC_DOT,  KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------+--------|
                                               FN,   LOWER, KC_LSFT,     KC_SPC,   RAISE, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_TXTEDIT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,COL_BLCK,CPY_DOWN, CPY_UP, EXP_BLCK, XXXXXXX,                      XXXXXXX,HLW_LEFT, HL_PGDN, HL_PGUP,HLW_RGHT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, MV_LEFT, MV_DOWN,   MV_UP, MV_RGHT, XXXXXXX,                      XXXXXXX, HL_LEFT, HL_DOWN,   HL_UP, HL_RGHT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,DEL_LINE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               FN, XXXXXXX, KC_LSFT,    KC_SPC, XXXXXXX, TXTEDIT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_FN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, KC_RCTL, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               FN, XXXXXXX, KC_LSFT,     KC_SPC, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-------------------------------------------------------.
        RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX,    GAME, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+----------|
                                               FN,   LOWER, KC_LSFT,     KC_SPC,   RAISE, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAME] = LAYOUT( \
  //,------------------------------------------------------.                    ,------------------------------------------------------------.
         KC_4,    KC_3,    KC_Q,    KC_W,    KC_E,     KC_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RALT(KC_F10),\
  //|--------+--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+--------------|
         KC_2,    KC_1,    KC_A,    KC_S,    KC_D,     KC_F,                      XXXXXXX,    GAME, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,\
  //|--------+--------+--------+--------+--------+---------|                    |--------+--------+--------+--------+--------+--------------|
         KC_6,    KC_5,    KC_Z,    KC_X,    KC_C,     KC_V,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RALT(KC_F9),\
  //|--------+--------+--------+--------+--------+---------+--------|  |--------+--------+--------+--------+--------+--------+--------------|
                                             KC_TAB, KC_LSFT, KC_SPC,    XXXXXXX, XXXXXXX, QWERTY \
                                         //`------------------------'  `------------------------'

  )
};

int RGB_current_mode;

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

void render_space(void) {
  oled_write_P(PSTR("     "), false);
}

void render_logo(void) {
  static const char PROGMEM corne_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0
  };
  oled_write_P(corne_logo, false);
  oled_write_P(PSTR("corne"), false);
}

void render_layer_state(void) {
  static const char PROGMEM default_layer[] = {
      0x20, 0x94, 0x95, 0x96, 0x20,
      0x20, 0xb4, 0xb5, 0xb6, 0x20,
      0x20, 0xd4, 0xd5, 0xd6, 0x20, 0
  };
  static const char PROGMEM raise_layer[] = {
      0x20, 0x97, 0x98, 0x99, 0x20,
      0x20, 0xb7, 0xb8, 0xb9, 0x20,
      0x20, 0xd7, 0xd8, 0xd9, 0x20, 0
  };
  static const char PROGMEM lower_layer[] = {
      0x20, 0x9a, 0x9b, 0x9c, 0x20,
      0x20, 0xba, 0xbb, 0xbc, 0x20,
      0x20, 0xda, 0xdb, 0xdc, 0x20, 0
  };
  static const char PROGMEM adjust_layer[] = {
      0x20, 0x9d, 0x9e, 0x9f, 0x20,
      0x20, 0xbd, 0xbe, 0xbf, 0x20,
      0x20, 0xdd, 0xde, 0xdf, 0x20, 0
  };
  static const char PROGMEM text_edit_layer[] = {
      0x20, 0x91, 0x92, 0x93, 0x20,
      0x20, 0xb1, 0xb2, 0xb3, 0x20,
      0x20, 0xd1, 0xd2, 0xd3, 0x20, 0
  };
  static const char PROGMEM game_layer[] = {
      0x20, 0x8e, 0x8f, 0x90, 0x20,
      0x20, 0xae, 0xaf, 0xb0, 0x20,
      0x20, 0xce, 0xcf, 0xd0, 0x20, 0
  };
  if(layer_state_is(_GAME)) {
      oled_write_P(game_layer, false);
  } else if(layer_state_is(_ADJUST)) {
      oled_write_P(adjust_layer, false);
  } else if(layer_state_is(_LOWER)) {
      oled_write_P(lower_layer, false);
  } else if(layer_state_is(_RAISE)) {
      oled_write_P(raise_layer, false);
  } else if(layer_state_is(_TXTEDIT)) {
      oled_write_P(text_edit_layer, false);
  } else if(layer_state_is(_QWERTY)) {
      oled_write_P(default_layer, false);
  } else if(layer_state_is(_FN)) {
      render_space();
      oled_write_P(PSTR("  FN "), false);
      render_space();
  } else {
      oled_write_P(PSTR("UNDEF"), false);
  }
}

void render_status_main(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
}

void render_status_secondary(void) {
    render_logo();
    render_space();
    render_layer_state();
    render_space();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void oled_task_user(void) {
  if(timer_elapsed32(oled_timer) > 30000) {
    oled_off();
    return;
  }
  if(is_keyboard_master()) {
    render_status_main();
  } else {
    render_status_secondary();
  }
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
      oled_timer = timer_read32();
#endif
   }

  switch (keycode) {
    case GAME:
      if (record->event.pressed) {
        layer_clear();
        layer_on(_GAME);
      }
      break;
    case QWERTY:
      if (record->event.pressed) {
        layer_clear();
        set_single_persistent_default_layer(_QWERTY);
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      break;
    case TXTEDIT:
      if(record ->event.pressed) {
        layer_on(_TXTEDIT);
      } else {
        layer_off(_TXTEDIT);
      }
      break;
    case FN:
      if(record ->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
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
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
