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


enum my_keycodes {
    Pass = SAFE_RANGE,
    WhiteEffect,
    FractalEffect
};

static void changeRandomColor(void);
static uint32_t key_timer_boot = 0;
static uint32_t color_timer = 0;
uint32_t tiempo_boot = 0;
bool is_boot_active = false;
uint8_t random_hue = 0;

void keyboard_post_init_user(void) {
    // Activar bot automáticamente al conectar el teclado
    is_boot_active = true;
    tiempo_boot = 60000; // 1 minuto
    key_timer_boot = timer_read32();
    color_timer = timer_read32();

    // Configurar RGB para indicar bot activo
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_VAL);
}

void changeRandomColor(void) {
    // Generar matiz aleatorio (0-255)
    random_hue = (random_hue + 43) % 256; // Incremento primo para mejor distribución
    rgb_matrix_sethsv_noeeprom(random_hue, 255, rgb_matrix_get_val()); // Saturación máxima, mantener brillo actual
}

enum {
    TD_C = 0,
    TD_V,
    TD_Z,
    TD_A,
    TD_S,
    TD_X,
    TD_UP,
    TD_DOWN,
    TD_LEFT,
    TD_RIGHT,
    TD_ESC,
    TD_SCLN,
    TD_QUOT,
    TD_SLSH,
    TD_COMM,
    TD_DOT,
    TD_LBRC,
    TD_RBRC,
    TD_MINS,
    TD_EQL,
    TD_SPC,
    TD_N,
    TD_LCTL,
    TD_LALT,
    TD_LGUI,
    TD_TAB,
    TD_LSFT,
    TD_E
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

void td_UP (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_UP);
  } else {
    if (is_mac_os()) {
      tap_code16(C(KC_UP));  // Mac: Control+Up (Mission Control)
    } else {
      tap_code16(G(KC_TAB));  // Windows: Win+Tab (Task View)
    }
  }
}

void td_DOWN (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_DOWN);
  } else {
    if (is_mac_os()) {
      tap_code16(C(KC_DOWN));  // Mac: Control+Down (Application Windows)
    } else {
      tap_code16(G(KC_D));  // Windows: Win+D (Show Desktop)
    }
  }
}

void td_LEFT (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LEFT);
  } else {
    if (is_mac_os()) {
      tap_code16(C(KC_LEFT));  // Mac: Control+Left (Desktop Left)
    } else {
      tap_code16(C(G(KC_LEFT)));  // Windows: Ctrl+Win+Left (Desktop Left)
    }
  }
}

void td_RIGHT (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RIGHT);
  } else {
    if (is_mac_os()) {
      tap_code16(C(KC_RIGHT));  // Mac: Control+Right (Desktop Right)
    } else {
      tap_code16(C(G(KC_RIGHT)));  // Windows: Ctrl+Win+Right (Desktop Right)
    }
  }
}

void td_ESC (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_ESC);
  } else if (state->count == 2) {
    // Doble tap: Bloquear pantalla y desactivar bot
    is_boot_active = false;  // Desactivar bot
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);  // Efecto respiración
    rgb_matrix_set_speed_noeeprom(50); // Respiración lenta

    if (is_mac_os()) {
      // Mac: Control + Command + Q (Bloquear pantalla)
      register_code(KC_LCTL);
      register_code(KC_LGUI);
      tap_code(KC_Q);
      unregister_code(KC_LGUI);
      unregister_code(KC_LCTL);
    } else {
      // Windows: Win + L (Bloquear)
      register_code(KC_LGUI);
      tap_code(KC_L);
      unregister_code(KC_LGUI);
    }
  } else {
    // Triple tap: Reactivar bot
    is_boot_active = true;
    tiempo_boot = 60000;
    key_timer_boot = timer_read32();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_VAL);  // Indicador bot activo
  }
}

void td_SCLN (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SCLN);
  } else {
    tap_code16(S(KC_SCLN)); // Shift + ; = :
  }
}

void td_QUOT (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOT);
  } else {
    tap_code16(S(KC_QUOT)); // Shift + ' = "
  }
}

void td_SLSH (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SLSH);
  } else {
    tap_code16(S(KC_SLSH)); // Shift + / = ?
  }
}

void td_COMM (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_COMM);
  } else {
    tap_code16(S(KC_COMM)); // Shift + , = <
  }
}

void td_DOT (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_DOT);
  } else {
    tap_code16(S(KC_DOT)); // Shift + . = >
  }
}

void td_LBRC (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LBRC);
  } else {
    tap_code16(S(KC_LBRC)); // Shift + [ = {
  }
}

void td_RBRC (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RBRC);
  } else {
    tap_code16(S(KC_RBRC)); // Shift + ] = }
  }
}

void td_MINS (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MINS);
  } else {
    tap_code16(S(KC_MINS)); // Shift + - = _
  }
}

void td_EQL (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_EQL);
  } else {
    tap_code16(S(KC_EQL)); // Shift + = = +
  }
}

void td_SPC (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_SPC);
  } else {
    tap_code16(KC_ENT); // Doble tap = Enter
  }
}

void td_N (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_N);
  } else {
    // Método específico por OS para ñ
    if (is_mac_os()) {
      // Mac: Option + n, luego n = ñ
      register_code(KC_LALT);  // Option en Mac
      tap_code(KC_N);
      unregister_code(KC_LALT);
      tap_code(KC_N);
    } else {
      // Windows: Alt + 164 (código ASCII)
      register_code(KC_LALT);
      tap_code(KC_KP_1);
      tap_code(KC_KP_6);
      tap_code(KC_KP_4);
      unregister_code(KC_LALT);
    }
  }
}

void td_LCTL (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LCTL);
  } else {
    if (is_mac_os()) {
      tap_code16(A(C(KC_LEFT)));  // Mac: Ctrl+Alt+Left
    } else {
      tap_code16(G(KC_LEFT));  // Windows: Win+Left
    }
  }
}

void td_LALT (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_LALT);
  } else {
    if (is_mac_os()) {
      tap_code16(A(C(KC_RIGHT)));  // Mac: Ctrl+Alt+Right
    } else {
      tap_code16(G(KC_RIGHT));  // Windows: Win+Right
    }
  }
}

void td_LGUI (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
    } else if (state->count == 2) {
        // Doble toque: Captura de área seleccionada
        if (is_mac_os()) {
            tap_code16(S(G(KC_4))); // Mac: Cmd+Shift+4
        } else {
            tap_code16(S(G(KC_S))); // Windows: Win+Shift+S
        }
    } else if (state->count == 3) {
        // Triple toque: Captura de pantalla completa
        if (is_mac_os()) {
            tap_code16(S(G(KC_3))); // Mac: Cmd+Shift+3
        } else {
            tap_code16(G(KC_PSCR)); // Windows: Win+PrtScn
        }
    }
}

void td_TAB (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_TAB);
    } else {
        // Shift+Tab funciona en ambos sistemas operativos
        tap_code16(S(KC_TAB)); // Shift+Tab para devolver tabulación
    }
}

void td_LSFT (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
    } else {
        tap_code16(KC_DEL); // Segunda función: Suprimir/Delete
    }
}

void td_E (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_E);
    } else {
        // Abrir explorador de archivos
        if (is_mac_os()) {
            tap_code16(G(KC_SPC)); // Mac: Cmd+Space (Spotlight)
        } else {
            tap_code16(G(KC_E)); // Windows: Win+E (Explorer)
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
    unregister_code (KC_UP);
    unregister_code (KC_DOWN);
    unregister_code (KC_LEFT);
    unregister_code (KC_RIGHT);
    unregister_code (KC_ESC);
    unregister_code (KC_SCLN);
    unregister_code (KC_QUOT);
    unregister_code (KC_SLSH);
    unregister_code (KC_COMM);
    unregister_code (KC_DOT);
    unregister_code (KC_LBRC);
    unregister_code (KC_RBRC);
    unregister_code (KC_MINS);
    unregister_code (KC_EQL);
    unregister_code (KC_SPC);
    unregister_code (KC_N);
    unregister_code (KC_LCTL);
    unregister_code (KC_LALT);
    unregister_code (KC_LGUI);
    unregister_code (KC_TAB);
    unregister_code (KC_LSFT);
    unregister_code (KC_E);
    // Limpiar modificadores RALT específicamente
    unregister_code (KC_RALT);
    // Limpiar modificadores débiles para evitar interferencia
    clear_weak_mods();
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_C]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_C, dance_cln_reset),
    [TD_V]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_V, dance_cln_reset),
    [TD_Z]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_Z, dance_cln_reset),
    [TD_A]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_A, dance_cln_reset),
    [TD_S]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_S, dance_cln_reset),
    [TD_X]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_X, dance_cln_reset),
    [TD_UP]    = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_UP, dance_cln_reset),
    [TD_DOWN]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_DOWN, dance_cln_reset),
    [TD_LEFT]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_LEFT, dance_cln_reset),
    [TD_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_RIGHT, dance_cln_reset),
    [TD_ESC]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_ESC, dance_cln_reset),
    [TD_SCLN]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_SCLN, dance_cln_reset),
    [TD_QUOT]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_QUOT, dance_cln_reset),
    [TD_SLSH]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_SLSH, dance_cln_reset),
    [TD_COMM]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_COMM, dance_cln_reset),
    [TD_DOT]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_DOT, dance_cln_reset),
    [TD_LBRC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_LBRC, dance_cln_reset),
    [TD_RBRC]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_RBRC, dance_cln_reset),
    [TD_MINS]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_MINS, dance_cln_reset),
    [TD_EQL]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_EQL, dance_cln_reset),
    [TD_SPC]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_SPC, dance_cln_reset),
    [TD_N]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_N, dance_cln_reset),
    [TD_LCTL]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_LCTL, dance_cln_reset),
    [TD_LALT]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_LALT, dance_cln_reset),
    [TD_LGUI]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_LGUI, dance_cln_reset),
    [TD_TAB]   = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_TAB, dance_cln_reset),
    [TD_LSFT]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_LSFT, dance_cln_reset),
    [TD_E]     = ACTION_TAP_DANCE_FN_ADVANCED (NULL, td_E, dance_cln_reset)
};

void matrix_scan_user(void) {
    if (timer_elapsed32(key_timer_boot) > tiempo_boot) {
        key_timer_boot = timer_read32();
        if(is_boot_active){
            if (is_mac_os()) {
                tap_code(KC_RSFT);  // Right Shift para macOS (invisible)
            } else {
                tap_code(KC_F13);   // F13 para Windows
            }
        }
    }

    // Cambio de color cada 1 minuto (60000ms)
    if (timer_elapsed32(color_timer) > 60000) {
        color_timer = timer_read32();
        if (rgb_matrix_is_enabled()) {
            changeRandomColor();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case Pass:
            if (record->event.pressed) {
                SEND_STRING("M1020320362r");
            }
            return false;
        case WhiteEffect:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                rgb_matrix_sethsv_noeeprom(0, 0, 255); // HSV para blanco sólido
            }
            return false;
        case FractalEffect:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_SPLASH);
            }
            return false;
        default:
            return true;
    }
}

bool rgb_matrix_indicators_user(void) {
    if (get_highest_layer(layer_state) == 0) {
        // Tecla de control principal - ESC en blanco
        rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);   // ESC - Blanco

        // Categoría: Edición de texto (shortcuts de productividad) - Cian
        rgb_matrix_set_color(31, 0x00, 0xFF, 0xFF);  // A (Seleccionar todo)
        rgb_matrix_set_color(32, 0x00, 0xFF, 0xFF);  // S (Guardar)
        rgb_matrix_set_color(45, 0x00, 0xFF, 0xFF);  // Z (Deshacer)
        rgb_matrix_set_color(46, 0x00, 0xFF, 0xFF);  // X (Cortar)
        rgb_matrix_set_color(47, 0x00, 0xFF, 0xFF);  // C (Copiar)
        rgb_matrix_set_color(48, 0x00, 0xFF, 0xFF);  // V (Pegar)

        // Categoría: Símbolos y puntuación (tap dance) - Amarillo
        rgb_matrix_set_color(40, 0xFF, 0xFF, 0x00);  // ; (:)
        rgb_matrix_set_color(41, 0xFF, 0xFF, 0x00);  // ' (")
        rgb_matrix_set_color(54, 0xFF, 0xFF, 0x00);  // / (?)
        rgb_matrix_set_color(52, 0xFF, 0xFF, 0x00);  // , (<)
        rgb_matrix_set_color(53, 0xFF, 0xFF, 0x00);  // . (>)
        rgb_matrix_set_color(27, 0xFF, 0xFF, 0x00);  // [ ({)
        rgb_matrix_set_color(26, 0xFF, 0xFF, 0x00);  // ] (})
        rgb_matrix_set_color(11, 0xFF, 0xFF, 0x00);  // - (_)
        rgb_matrix_set_color(12, 0xFF, 0xFF, 0x00);  // = (+)
        rgb_matrix_set_color(50, 0xFF, 0x00, 0x00);  // N (Ñ) - Rojo

        // Categoría: Navegación de documentos - Violeta
        rgb_matrix_set_color(15, 0x8A, 0x2B, 0xE2);  // TAB (Shift+TAB) - Violeta

        // Categoría: Acción destructiva - Magenta oscuro
        rgb_matrix_set_color(44, 0x8B, 0x00, 0x8B);  // L_SHIFT (Delete) - Magenta oscuro

        // Categoría: Explorador de archivos - Turquesa
        rgb_matrix_set_color(18, 0x40, 0xE0, 0xD0);  // E (Win+E/Cmd+Space) - Turquesa

        // Categoría: Navegación de escritorios - Naranja
        rgb_matrix_set_color(56, 0xFF, 0x80, 0x00);  // UP (Mission Control/Task View)
        rgb_matrix_set_color(65, 0xFF, 0x80, 0x00);  // LEFT (Escritorio izquierdo)
        rgb_matrix_set_color(66, 0xFF, 0x80, 0x00);  // DOWN (App Windows/Show Desktop)
        rgb_matrix_set_color(67, 0xFF, 0x80, 0x00);  // RIGHT (Escritorio derecho)

        // Categoría: Acceso a capas - Verde lima
        rgb_matrix_set_color(63, 0x80, 0xFF, 0x00);  // TG(1) - Acceso a capa de funciones

        // Categoría: Barra espaciadora (space/enter) - Rosa
        rgb_matrix_set_color(61, 0xFF, 0x80, 0xFF);  // Space (Enter) - Rosa

        // Categoría: Ajuste de ventanas - Púrpura Oscuro
        rgb_matrix_set_color(58, 0x4B, 0x00, 0x82);  // L_CTL (Ventana Derecha) - Púrpura Oscuro
        rgb_matrix_set_color(60, 0x4B, 0x00, 0x82);  // L_ALT (Ventana Izquierda) - Púrpura Oscuro

        // Categoría: Captura de pantalla - Naranja
        rgb_matrix_set_color(59, 0xFF, 0xA5, 0x00);  // L_GUI (Captura de pantalla) - Naranja
    } else if (get_highest_layer(layer_state) == 1) {
        // ESC para regresar a capa 0 en blanco
        rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);   // TO(0) - Blanco

        // Tecla de función (Capa 1 activa)
        rgb_matrix_set_color(63, 0x00, 0xFF, 0xFF);  // TG(1) - Cian brillante

        // Teclas de función F1-F12 en verde
        rgb_matrix_set_color(1, 0x00, 0xFF, 0x00);   // F1 - Verde
        rgb_matrix_set_color(2, 0x00, 0xFF, 0x00);   // F2 - Verde
        rgb_matrix_set_color(3, 0x00, 0xFF, 0x00);   // F3 - Verde
        rgb_matrix_set_color(4, 0x00, 0xFF, 0x00);   // F4 - Verde
        rgb_matrix_set_color(5, 0x00, 0xFF, 0x00);   // F5 - Verde
        rgb_matrix_set_color(6, 0x00, 0xFF, 0x00);   // F6 - Verde
        rgb_matrix_set_color(7, 0x00, 0xFF, 0x00);   // F7 - Verde
        rgb_matrix_set_color(8, 0x00, 0xFF, 0x00);   // F8 - Verde
        rgb_matrix_set_color(9, 0x00, 0xFF, 0x00);   // F9 - Verde
        rgb_matrix_set_color(10, 0x00, 0xFF, 0x00);  // F10 - Verde
        rgb_matrix_set_color(11, 0x00, 0xFF, 0x00);  // F11 - Verde
        rgb_matrix_set_color(12, 0x00, 0xFF, 0x00);  // F12 - Verde

        // Teclas RGB Underglow en púrpura
        rgb_matrix_set_color(16, 0x80, 0x00, 0xFF);  // UG_TOGG - Púrpura
        rgb_matrix_set_color(17, 0x80, 0x00, 0xFF);  // UG_NEXT - Púrpura
        rgb_matrix_set_color(18, 0x80, 0x00, 0xFF);  // UG_HUEU - Púrpura
        rgb_matrix_set_color(19, 0x80, 0x00, 0xFF);  // UG_HUED - Púrpura
        rgb_matrix_set_color(20, 0x80, 0x00, 0xFF);  // UG_SATU - Púrpura
        rgb_matrix_set_color(21, 0x80, 0x00, 0xFF);  // UG_SATD - Púrpura
        rgb_matrix_set_color(22, 0x80, 0x00, 0xFF);  // UG_VALU - Púrpura
        rgb_matrix_set_color(23, 0x80, 0x00, 0xFF);  // UG_VALD - Púrpura
        rgb_matrix_set_color(24, 0x80, 0x00, 0xFF);  // UG_SPDU - Púrpura
        rgb_matrix_set_color(25, 0x80, 0x00, 0xFF);  // UG_SPDD - Púrpura

        // Teclas RGB Matrix en azul
        rgb_matrix_set_color(31, 0x00, 0x80, 0xFF);  // RM_TOGG - Azul
        rgb_matrix_set_color(32, 0x00, 0x80, 0xFF);  // RM_NEXT - Azul
        rgb_matrix_set_color(33, 0x00, 0x80, 0xFF);  // RM_HUEU - Azul
        rgb_matrix_set_color(34, 0x00, 0x80, 0xFF);  // RM_HUED - Azul
        rgb_matrix_set_color(35, 0x00, 0x80, 0xFF);  // RM_SATU - Azul
        rgb_matrix_set_color(36, 0x00, 0x80, 0xFF);  // RM_SATD - Azul
        rgb_matrix_set_color(37, 0x00, 0x80, 0xFF);  // RM_VALU - Azul
        rgb_matrix_set_color(38, 0x00, 0x80, 0xFF);  // RM_VALD - Azul

        // Teclas de volumen en amarillo
        rgb_matrix_set_color(56, 0xFF, 0xFF, 0x00);  // KC_VOLU - Amarillo
        rgb_matrix_set_color(66, 0xFF, 0xFF, 0x00);  // KC_VOLD - Amarillo

        // Tecla especial NK_TOGG en naranja
        rgb_matrix_set_color(49, 0xFF, 0x80, 0x00);  // NK_TOGG - Naranja

        // Tecla TG(2) para acceso a capa de mouse en verde lima
        rgb_matrix_set_color(64, 0x80, 0xFF, 0x00);  // TG(2) - Verde lima

        // Tecla QK_BOOT en rojo (advertencia)
        rgb_matrix_set_color(14, 0xFF, 0x00, 0x00);  // QK_BOOT - Rojo

        // Tecla Pass en magenta
        rgb_matrix_set_color(43, 0xFF, 0x00, 0xFF);  // Pass - Magenta

        // Barra espaciadora en blanco
        rgb_matrix_set_color(61, 0xFF, 0xFF, 0xFF);  // Spacebar - Blanco

        // Alt izquierdo en azul claro
        rgb_matrix_set_color(60, 0x80, 0xFF, 0xFF);  // Alt izquierdo - Azul claro

        // Controles de media en verde
        rgb_matrix_set_color(51, 0x00, 0xFF, 0x00);  // M (Previous) - Verde
        rgb_matrix_set_color(52, 0x00, 0xFF, 0x00);  // , (Play/Pause) - Verde
        rgb_matrix_set_color(53, 0x00, 0xFF, 0x00);  // . (Next) - Verde
    } else if (get_highest_layer(layer_state) == 2) {
        // Capa 2 - Funciones de Mouse

        // ESC para regresar a capa 0 en blanco
        rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);   // TO(0) - Blanco

        // Control de velocidad del mouse en magenta
        rgb_matrix_set_color(1, 0xFF, 0x00, 0xFF);   // MS_ACL0 - Magenta
        rgb_matrix_set_color(2, 0xFF, 0x00, 0xFF);   // MS_ACL1 - Magenta
        rgb_matrix_set_color(3, 0xFF, 0x00, 0xFF);   // MS_ACL2 - Magenta

        // Movimiento del cursor solo en flechas direccionales en verde claro
        rgb_matrix_set_color(56, 0x80, 0xFF, 0x80);  // MS_UP (Flecha UP) - Verde claro
        rgb_matrix_set_color(65, 0x80, 0xFF, 0x80);  // MS_LEFT (Flecha LEFT) - Verde claro
        rgb_matrix_set_color(66, 0x80, 0xFF, 0x80);  // MS_DOWN (Flecha DOWN) - Verde claro
        rgb_matrix_set_color(67, 0x80, 0xFF, 0x80);  // MS_RGHT (Flecha RIGHT) - Verde claro

        // Scroll del mouse en azul claro
        rgb_matrix_set_color(16, 0x80, 0xFF, 0xFF);  // MS_WHLU (Q) - Azul claro
        rgb_matrix_set_color(18, 0x80, 0xFF, 0xFF);  // MS_WHLD (E) - Azul claro
        rgb_matrix_set_color(45, 0x80, 0xFF, 0xFF);  // MS_WHLL (Z) - Azul claro
        rgb_matrix_set_color(46, 0x80, 0xFF, 0xFF);  // MS_WHLR (X) - Azul claro

        // Botones del mouse en rojo claro (ASD)
        rgb_matrix_set_color(31, 0xFF, 0x80, 0x80);  // MS_BTN2 (A - Clic derecho) - Rojo claro
        rgb_matrix_set_color(32, 0xFF, 0x80, 0x80);  // MS_BTN3 (S - Clic central) - Rojo claro
        rgb_matrix_set_color(33, 0xFF, 0x80, 0x80);  // MS_BTN1 (D - Clic izquierdo) - Rojo claro

        // Tecla de función TG(2) con color random/vibrante
        rgb_matrix_set_color(63, 0xFF, 0x40, 0x80);  // TG(2) - Rosa vibrante
    }
    return true;
}




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        TD(TD_ESC),     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD(TD_MINS), TD(TD_EQL),  KC_BSPC, KC_HOME,
        TD(TD_TAB),     KC_Q,    KC_W,    TD(TD_E), KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_LBRC), TD(TD_RBRC), KC_BSLS, KC_PGUP,
        KC_CAPS,      TD(TD_A), TD(TD_S), KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SCLN), TD(TD_QUOT),          KC_ENT,  KC_PGDN,
        TD(TD_LSFT),  TD(TD_Z), TD(TD_X),TD(TD_C),TD(TD_V), KC_B,    TD(TD_N), KC_M,    TD(TD_COMM), TD(TD_DOT),  TD(TD_SLSH), KC_RSFT, TD(TD_UP), KC_END,
        TD(TD_LCTL),    TD(TD_LGUI), TD(TD_LALT),                        TD(TD_SPC),                KC_RALT, TG(1),   KC_RCTL, TD(TD_LEFT), TD(TD_DOWN), TD(TD_RIGHT)
    ),
    [1] = LAYOUT_65_ansi(
        TO(0),          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  QK_BOOT,
        _______,        UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, UG_SPDU, UG_SPDD, _______, _______, _______, _______,
        KC_CAPS,        RM_TOGG, RM_NEXT, RM_HUEU, RM_HUED, RM_SATU, RM_SATD, RM_VALU, RM_VALD, _______, _______,  _______,         _______, Pass,
        _______,                 _______, _______, _______, _______, _______, NK_TOGG, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_VOLU, _______,
        _______,        _______, FractalEffect,                      WhiteEffect,               _______, _______, TG(2),   _______, KC_VOLD, _______
    ),
    [2] = LAYOUT_65_ansi(
        TO(0),          MS_ACL0, MS_ACL1, MS_ACL2, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______,        MS_WHLU, _______, MS_WHLD, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______,        MS_BTN1, MS_BTN3, MS_BTN1, _______, _______, _______, _______, _______, _______, _______,  _______,           _______, _______,
        _______,                 MS_WHLL, MS_WHLR, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  MS_UP,   _______,
        _______,        _______, _______,                            _______,                   _______, TG(2),   _______,  MS_LEFT, MS_DOWN, MS_RGHT
    ),
    [3] = LAYOUT_65_ansi(
        TO(0),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )
};
