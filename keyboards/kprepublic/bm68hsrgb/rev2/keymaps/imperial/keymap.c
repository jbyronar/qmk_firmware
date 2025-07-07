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

#define _BASE 0
#define _FUNCTIONS 1

uint8_t rgbmode;
static void setGameRGB(int);
bool rgbStatus = true;

void matrix_scan_user(void) {
    if(rgb_matrix_config.mode != RGB_MATRIX_SOLID_COLOR){
        rgbmode = rgb_matrix_config.mode;
    }
}

void setGameRGB(int n) {
  switch (n) {
    case 1:
        if(!rgbmode) rgbmode = rgb_matrix_config.mode;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    break;
    case 5:
        if(!rgbmode) rgbmode = rgb_matrix_config.mode;
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    break;
  }
};

enum my_keycodes {
    RMT = SAFE_RANGE,
    RMS,
    RMIH,
    RMDH,
    RMIS,
    RMDS,
    RMIV,
    RMDV,
    Prueba
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
      case Prueba:
      if (record->event.pressed)
      {rgb_matrix_decrease_val();
      }
      return true;
      default:
      return true;
  }
}
bool rgb_matrix_indicators_user(void) {
    if (biton32(layer_state) == _FUNCTIONS) {
        rgb_matrix_set_color(1, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(2, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(3, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(4, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(5, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(6, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(7, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(8, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(9, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(10, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(11, 0x87, 0xCE, 0xEB);
        rgb_matrix_set_color(12, 0x87, 0xCE, 0xEB);
        
        rgb_matrix_set_color(13, 0xFF, 0x45, 0x00);
        rgb_matrix_set_color(14, 0xFF, 0x00, 0x00);
        
        rgb_matrix_set_color(16, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(17, 0x00, 0xFF, 0x00);
        rgb_matrix_set_color(18, 0xFF, 0xD7, 0x00);
        rgb_matrix_set_color(19, 0xFF, 0xD7, 0x00);
        rgb_matrix_set_color(20, 0xFF, 0xD7, 0x00);
        rgb_matrix_set_color(21, 0xFF, 0xD7, 0x00);
        rgb_matrix_set_color(22, 0xFF, 0xD7, 0x00);
        rgb_matrix_set_color(23, 0xFF, 0xD7, 0x00);
        rgb_matrix_set_color(24, 0xFF, 0xD7, 0x00);
        rgb_matrix_set_color(25, 0xFF, 0xD7, 0x00);
        
        rgb_matrix_set_color(31, 0xFF, 0x00, 0xFF);
        rgb_matrix_set_color(32, 0xFF, 0x00, 0xFF);
        rgb_matrix_set_color(33, 0xFF, 0x00, 0xFF);
        rgb_matrix_set_color(34, 0xFF, 0x00, 0xFF);
        rgb_matrix_set_color(35, 0xFF, 0x00, 0xFF);
        rgb_matrix_set_color(36, 0xFF, 0x00, 0xFF);
        rgb_matrix_set_color(37, 0xFF, 0x00, 0xFF);
        rgb_matrix_set_color(38, 0xFF, 0x00, 0xFF);
        
        rgb_matrix_set_color(50, 0x00, 0x80, 0xFF);
        
        rgb_matrix_set_color(56, 0x80, 0x80, 0x80);
        rgb_matrix_set_color(63, 0xFF, 0x45, 0x00);
        rgb_matrix_set_color(67, 0x80, 0x80, 0x80);
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
    case _FUNCTIONS:
        setGameRGB(5);
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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        QK_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, TG(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        QK_GESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  QK_BOOT,
        _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______, _______, _______, _______,
        KC_CAPS,        RMT,     RMS,     RMIH,    RMDH,    RMIS,    RMDS,    RMIV,    RMDV,    _______, _______,  _______,         _______, _______,
        Prueba,                 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______,        _______, _______,                            _______,                   _______, TG(1),   _______, _______, KC_VOLD, _______
    ),
    [2] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )
};