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
#include "os_detection.h"

enum {
    TD_C = 0,
    TD_V,
    TD_Z,
    TD_A,
    TD_S,
    TD_X
};

bool is_mac_os(void) {
    os_variant_t detected_os = detected_host_os();
    return (detected_os == OS_MACOS || detected_os == OS_IOS);
}

void td_C (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_C);
  } else {
    if (is_mac_os()) {
      tap_code16(G(KC_C));  // Mac: Cmd+C
    } else {
      tap_code16(C(KC_C));  // Windows: Ctrl+C
    }
  }
}

void td_V (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_V);
  } else {
    if (is_mac_os()) {
      tap_code16(G(KC_V));  // Mac: Cmd+V
    } else {
      tap_code16(C(KC_V));  // Windows: Ctrl+V
    }
  }
}

void td_Z (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_Z);
  } else {
    if (is_mac_os()) {
      tap_code16(G(KC_Z));  // Mac: Cmd+Z
    } else {
      tap_code16(C(KC_Z));  // Windows: Ctrl+Z
    }
  }
}

void td_A (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_A);
  } else {
    if (is_mac_os()) {
      tap_code16(G(KC_A));  // Mac: Cmd+A
    } else {
      tap_code16(C(KC_A));  // Windows: Ctrl+A
    }
  }
}

void td_S (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_S);
  } else {
    if (is_mac_os()) {
      tap_code16(G(KC_S));  // Mac: Cmd+S
    } else {
      tap_code16(C(KC_S));  // Windows: Ctrl+S
    }
  }
}

void td_X (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_X);
  } else {
    if (is_mac_os()) {
      tap_code16(G(KC_X));  // Mac: Cmd+X
    } else {
      tap_code16(C(KC_X));  // Windows: Ctrl+X
    }
  }
}

void dance_cln_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_C);
    unregister_code (KC_V);
    unregister_code (KC_Z);
    unregister_code (KC_A);
    unregister_code (KC_S);
    unregister_code (KC_X);
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_C]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_C, dance_cln_reset),
    [TD_V]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_V, dance_cln_reset),
    [TD_Z]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_Z, dance_cln_reset),
    [TD_A]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_A, dance_cln_reset),
    [TD_S]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_S, dance_cln_reset),
    [TD_X]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_X, dance_cln_reset)
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        QK_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS,      TD(TD_A), TD(TD_S), KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,      TD(TD_Z), TD(TD_X),TD(TD_C),TD(TD_V), KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        QK_GESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  QK_BOOT,
        _______,        UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, UG_SPDU, UG_SPDD, _______, _______, _______, _______,
        KC_CAPS,        RM_TOGG, RM_NEXT, RM_HUEU, RM_HUED, RM_SATU, RM_SATD, RM_VALU, RM_VALD, _______, _______,  _______,         _______, _______,
        _______,                 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______,        _______, _______,                            _______,                   _______, _______, _______, _______, KC_VOLD, _______
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
