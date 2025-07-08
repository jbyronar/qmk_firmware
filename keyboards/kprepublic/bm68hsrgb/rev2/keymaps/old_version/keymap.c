 /* Copyright 2022 bdtc123
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

enum my_keycodes {
    RMT = SAFE_RANGE,
    RMS,
    RMIH,
    RMDH,
    RMIS,
    RMDS,
    RMIV,
    RMDV,
    Compile,
    Flash,
    Bot,
    FullLed,
    Fantast,
    UsBancol,
};

static void handleBoot(void);
static uint32_t key_timer_boot = 0;
uint32_t tiempo_boot = 0;
bool is_boot_active = false;

void handleBoot(){
  is_boot_active = !is_boot_active;
  if(is_boot_active){
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_ALTERNATING);
    rgblight_mode_noeeprom(RGB_MATRIX_BAND_VAL);
    //tiempo_boot = 60000; //1 minuto
    tiempo_boot = 60000;
  }else{
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        //rgblight_sethsv_noeeprom(HSV_RED); // MI COLOR
        rgblight_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
        tiempo_boot = 0;
  }
}

void matrix_scan_user(void) {
      if (timer_elapsed32(key_timer_boot) > tiempo_boot) {
      key_timer_boot = timer_read32();
      if(is_boot_active){
        SEND_STRING(SS_TAP(X_F13));
      //Si se va a usar funciones del ratón, hay que poner a YES la opción MOUSEKEY_ENABLE en el rules.mk
      // SEND_STRING(SS_TAP(X_WH_U)); //Rueda del ratón hacia arriba
      // SEND_STRING(SS_TAP(X_WH_D)); //Rueda del ratón hacia abajo
      // SEND_STRING(SS_TAP(X_MS_U)); //Mueve el ratón hacia arriba
      // SEND_STRING(SS_TAP(X_MS_D)); //Mueve el ratón hacia abajo
      // SEND_STRING(SS_TAP(X_MS_R)); //Mueve el ratón hacia derecha
      // SEND_STRING(SS_TAP(X_MS_L)); //Mueve el ratón hacia izquierda
      // SEND_STRING(SS_TAP(X_BTN1)); //Pulsa el botón 1 del ratón
      // SEND_STRING(SS_TAP(X_BTN2)); //Pulsa el botón 2 del ratón
      // SEND_STRING(SS_TAP(X_BTN3)); //Pulsa el botón 3 del ratón
      }
    }
};

enum {
    TD_N = 0,
    TD_PGUP,
    TD_2,
    TD_C,
    TD_V,
    TD_Z,
    TD_S,
    TD_X,
    TD_E,
    TD_PLUS,
    TD_SCLN,
    TD_ESC,
    TD_SPC,
    TD_LSFT,
    TD_TAB,
    TD_W,
    TD_A,
    TD_D,
    TD_1
};

void td_N (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_N);

  } else if (state->count == 2) {
    SEND_STRING(SS_TAP(X_SCLN));
    clear_keyboard();
  }else {
    SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_N));
    clear_keyboard();
  }
}

void td_PGUP (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_PGUP);
  } else {
    SEND_STRING("J1020320362a");
    clear_keyboard();
  }
}

void td_2 (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_2);
    reset_tap_dance (state);
  }else if (state->count == 2) {
    SEND_STRING(SS_TAP(X_F2));
    clear_keyboard();
    reset_tap_dance (state);
  }else {
    SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_2));
    clear_keyboard();reset_tap_dance (state);
    reset_tap_dance (state);
  }
}
/*
void td_2 (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_2);
  } else if (state->count == 2) {
    SEND_STRING(SS_TAP(X_F2));
    clear_keyboard();
  }else {
    SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_2));
    clear_keyboard();
  }
}
*/

void td_C (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_C);
  } else {
    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_C));
    clear_keyboard();
  }
}

void td_V (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_V);
  } else {
    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_V));
    clear_keyboard();
  }
}

void td_Z (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_Z);
  } else {
    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_Z));
    clear_keyboard();
  }
}

void td_S (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_S);
  }else if (state->count == 2) {
    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_S));
    clear_keyboard();
  }else {
    SEND_STRING(SS_TAP(X_DOWN));
    clear_keyboard();
  }
}

void td_X (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_X);
  } else {
    SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_X));
    clear_keyboard();
  }
}

void td_PLUS (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_EQL);
  } else {
    SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_EQL));
    clear_keyboard();
  }
}

void td_SCLN (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_SCLN));
    clear_keyboard();
  }
}

void td_ESC (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_ESC);
  } else {
    handleBoot();
  }
}

void td_TAB(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_TAB);
  } else {
    SEND_STRING(SS_DOWN(X_RSFT) SS_TAP(X_TAB));
    clear_keyboard();
  }
}

void td_1(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_1);
  } else {
    layer_move(1);
  }
}

void dance_cln_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_N);
    unregister_code (KC_PGUP);
    unregister_code (KC_2);
    unregister_code (KC_C);
    unregister_code (KC_V);
    unregister_code (KC_Z);
    unregister_code (KC_S);
    unregister_code (KC_X);
    unregister_code (KC_EQL);
    unregister_code (KC_SCLN);
    unregister_code (KC_ESC);
    unregister_code (KC_TAB);
    unregister_code (KC_1);

    reset_tap_dance(state);
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_N]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_N, dance_cln_reset),
    [TD_PGUP]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_PGUP, dance_cln_reset),
    [TD_2]  = ACTION_TAP_DANCE_FN (td_2),
    [TD_C]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_C, dance_cln_reset),
    [TD_V]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_V, dance_cln_reset),
    [TD_Z]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_Z, dance_cln_reset),
    [TD_S]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_S, dance_cln_reset),
    [TD_X]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_X, dance_cln_reset),
    [TD_E]  = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_DEL),
    [TD_PLUS]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_PLUS, dance_cln_reset),
    [TD_SCLN]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_SCLN, dance_cln_reset),
    [TD_ESC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_ESC, dance_cln_reset),
    [TD_SPC]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
    [TD_W]  = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_UP),
    [TD_A]  = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_LEFT),
    [TD_D]  = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_RGHT),
    [TD_TAB]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_TAB, dance_cln_reset),
    [TD_LSFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_BSPC),
    [TD_1]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_1, dance_cln_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RMT:
      if (record->event.pressed)
      {rgb_matrix_toggle();
      }
      return false;
    case RMS:
      if (record->event.pressed)
      {rgb_matrix_step();
      }
      return false;
      case RMIH:
      if (record->event.pressed)
      {rgb_matrix_increase_hue();
      }
      return false;
      case RMDH:
      if (record->event.pressed)
      {rgb_matrix_decrease_hue();
      }
      return false;
      case RMIS:
      if (record->event.pressed)
      {rgb_matrix_increase_sat();
      }
      return false;
      case RMDS:
      if (record->event.pressed)
      {rgb_matrix_decrease_sat();
      }
      return false;
      case RMIV:
      if (record->event.pressed)
      {rgb_matrix_increase_val();
      }
      return false;
      case RMDV:
      if (record->event.pressed)
      {rgb_matrix_decrease_val();
      }
      return true;
      case Compile:
      if (record->event.pressed)
      {SEND_STRING("qmk compile  -kb kprepublic/bm68hsrgb/rev2 -km imperial");
      }
      return true;
      case Flash:
      if (record->event.pressed)
      {SEND_STRING("qmk flash  -kb kprepublic/bm68hsrgb/rev2 -km imperial");
      }
      return true;
      case FullLed:
      if (record->event.pressed)
      {rgblight_mode_noeeprom(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
      }
      return true;
      case UsBancol:
      if (record->event.pressed)
      {SEND_STRING("j85072840084");
      }
      return true;
      case Fantast:
      if (record->event.pressed)
      {rgblight_mode_noeeprom(RGB_MATRIX_PIXEL_FRACTAL);
      }
      return true;
      default:
      return true;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        TD(TD_ESC),     TD(TD_1),      KC_2,    KC_3,       KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,        KC_MINS, TD(TD_PLUS), KC_BSPC, KC_DEL,
        TD(TD_TAB),     KC_Q,      TD(TD_W),    TD(TD_E),   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,        KC_LBRC, KC_RBRC,     KC_BSLS, KC_END,
        KC_CAPS,        TD(TD_A),  TD(TD_S),    TD(TD_D),   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SCLN), KC_QUOT,              KC_ENT,  TD(TD_PGUP),
        TD(TD_LSFT),    TD(TD_Z),  TD(TD_X),    TD(TD_C),   TD(TD_V), KC_B,    TD(TD_N),KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT, KC_UP,                KC_PGDN,
        KC_LCTL,        KC_LGUI,   KC_LALT,                            TD(TD_SPC),                 KC_RALT, TG(1),   KC_RCTL,     KC_LEFT, KC_DOWN,              KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        QK_GESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME,  QK_BOOT,
        _______,        _______, _______, _______, _______, _______,_______, UsBancol, _______, _______, _______, _______, _______, _______,  _______,
        _______,        _______, _______, _______, Flash  , _______,_______, _______, _______, _______, FullLed, Fantast,          _______,   _______,
        _______,                 _______, _______, Compile, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______,        _______, _______,                            _______,                   _______,   TG(1), _______, _______, KC_VOLD, KC_MPLY
    ),
    [2] = LAYOUT_65_ansi(
        QK_GESC,        _______, _______,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  QK_BOOT,
        _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______, _______, _______, _______,
        KC_CAPS,        RMT,     RMS,     RMIH,    RMDH,    RMIS,    RMDS,    RMIV,    RMDV,    _______, _______,  _______,         _______, _______,
        _______,                 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______,        _______, _______,                            _______,                   _______, _______, _______, _______, KC_VOLD, _______
    ),
    [3] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )
};


//Primer intentio para cambio rbg
/*

#define _BASE 0
#define _FUNCTIONS 1

uint8_t rgbmode;
static void setGameRGB(int);
bool rgbStatus = true;

void matrix_scan_user(void) {
    if(rgb_matrix_config.mode != RGB_MATRIX_CUSTOM_Functions){
        rgbmode = rgb_matrix_config.mode;
    }
}

void setGameRGB(int n) {
  switch (n) {
    case 1:
        if(!rgbmode) rgbmode = rgb_matrix_config.mode;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_Functions);
    break;
  }
};

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
    case _FUNCTIONS:
        setGameRGB(1);
    break;

    default:
    rgbStatus = rgb_matrix_is_enabled();
    if(rgbStatus == true){
        rgb_matrix_mode_noeeprom(rgbmode);
    }

    break;
  }
  return state;
}
*/
