// Copyright 2022 Artjoms Rizihs (@artjomsR)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "art.h"
#include "string_funcs.h"
#include "string.h"

bool mac_ctrl_on;

int char_to_bspace;
int char_to_del;

enum combo_events {
  HOMEROW_UP,
  HOMEROW_LEFT,
  HOMEROW_RIGHT,
  HOMEROW_DOWN,
  HOMEROW_PREV_WORD,
  HOMEROW_NEXT_WORD,
  HOMEROW_HOME,
  HOMEROW_END,
  ED_CS_ENTER,
  CTRL_C_C,
  BSPC_LSFT_CLEAR
};

const uint16_t PROGMEM combo_up[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM combo_left[] = {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM combo_right[] = {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM combo_down[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_l_click[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM combo_r_click[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM combo_end[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_home[] = {KC_W, KC_R, COMBO_END};

const uint16_t PROGMEM combo_ctrl_f_wman[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_alt_pscr[] = {KC_LWIN, KC_LALT, KC_LCTL, COMBO_END};

const uint16_t PROGMEM combo_m_play[] = {KC_RIGHT, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_LCTL, KC_V, COMBO_END};

const uint16_t PROGMEM combo_enter2[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM combo_ctrl_c_c[] = {KC_LCTL, KC_C, COMBO_END};
const uint16_t PROGMEM combo_ed_left[] = {KC_BSPC, KC_UP, COMBO_END};
const uint16_t PROGMEM combo_ed_right[] = {KC_BSPC, KC_DOWN, COMBO_END};

const uint16_t PROGMEM combo_f1[] = {KC_1, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_f2[] = {KC_2, KC_W, COMBO_END};
const uint16_t PROGMEM combo_f3[] = {KC_3, KC_E, COMBO_END};
const uint16_t PROGMEM combo_f4[] = {KC_4, KC_R, COMBO_END};
const uint16_t PROGMEM combo_f5[] = {KC_5, KC_T, COMBO_END};
const uint16_t PROGMEM combo_f6[] = {KC_6, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_f7[] = {KC_7, KC_U, COMBO_END};
const uint16_t PROGMEM combo_f8[] = {KC_8, KC_I, COMBO_END};
const uint16_t PROGMEM combo_f9[] = {KC_9, KC_O, COMBO_END};
const uint16_t PROGMEM combo_f10[] = {KC_0, KC_P, COMBO_END};
const uint16_t PROGMEM combo_f11[] = {KC_SLSH, KC_RSFT, COMBO_END};
const uint16_t PROGMEM combo_f12[] = {TO(GAMING), KC_RCTL, COMBO_END};
const uint16_t PROGMEM combo_ins[] = {KC_RALT, KC_HOME, COMBO_END};
const uint16_t PROGMEM combo_break[] = {KC_HOME, KC_END, COMBO_END};
const uint16_t PROGMEM combo_pscreen[] = {KC_END, TO(GAMING), COMBO_END};

const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};

combo_t key_combos[] = {
  [HOMEROW_UP] = COMBO(combo_up, KC_UP),
  [HOMEROW_LEFT] = COMBO(combo_left, KC_LEFT),
  [HOMEROW_RIGHT] = COMBO(combo_right, KC_RIGHT),
  [HOMEROW_DOWN] = COMBO(combo_down, KC_DOWN),
  [HOMEROW_HOME] = COMBO(combo_home, KC_HOME),
  [HOMEROW_END] = COMBO(combo_end, KC_END),
  [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
  [CTRL_C_C] = COMBO_ACTION(combo_ctrl_c_c),

  #if defined(KEYBOARD_ktec_ergodone)
  COMBO(combo_ctrl_f_wman, C(KC_U)),
  COMBO(combo_alt_pscr, A(KC_PRINT_SCREEN)),

  COMBO(combo_m_play, KC_MPLY),
  COMBO(combo_enter, KC_ENTER),

  COMBO(combo_l_click, KC_MS_BTN1),
  COMBO(combo_r_click, KC_APPLICATION),
  COMBO(combo_ed_left, KC_LEFT),
  COMBO(combo_ed_right, KC_RIGHT),
  COMBO(combo_enter2, KC_ENTER),

  COMBO(combo_f1, KC_F1),
  COMBO(combo_f2, KC_F2),
  COMBO(combo_f3, KC_F3),
  COMBO(combo_f4, KC_F4),
  COMBO(combo_f5, KC_F5),
  COMBO(combo_f6, KC_F6),
  COMBO(combo_f7, KC_F7),
  COMBO(combo_f8, KC_F8),
  COMBO(combo_f9, KC_F9),
  COMBO(combo_f10, KC_F10),
  COMBO(combo_f11, KC_F11),
  COMBO(combo_f12, KC_F12),
  COMBO(combo_ins, KC_INS),
  COMBO(combo_break, KC_BRK),
  COMBO(combo_pscreen, KC_PRINT_SCREEN),
  #endif

};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
      case HOMEROW_PREV_WORD:
        if (pressed) {
          if (is_win) {
            tap_code16(C(KC_LEFT));
          } else {
            tap_code16(A(KC_LEFT));
          }
        }
        break;
      case HOMEROW_NEXT_WORD:
        if (pressed) {
          if (is_win) {
            tap_code16(C(KC_RIGHT));
          } else {
            tap_code16(A(KC_RIGHT));
          }
        }
        break;
      case BSPC_LSFT_CLEAR:
        if (pressed) {
          tap_code16(KC_END);
          tap_code16(S(KC_HOME));
          tap_code16(KC_BSPC);
        }
        break;
      case ED_CS_ENTER:
        if (pressed) {
          tap_code16(C(S(KC_ENTER)));
        }
        break;
      case CTRL_C_C:
        if (pressed) {
          SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
          wait_ms(20);
          SEND_STRING(SS_LCTL(SS_TAP(X_C) SS_TAP(X_C)));
        }
        break;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(GAMING)) {
    switch (combo_index) {
      case HOMEROW_UP:
      case HOMEROW_LEFT:
      case HOMEROW_RIGHT:
      case HOMEROW_DOWN:
      case HOMEROW_HOME:
      case HOMEROW_END:
        return false;
    }
  }

  return !layer_state_is(BASE);
}

bool is_mac_with_base_layer_off(void) {
  return !is_win && !layer_state_is(BASE);
}

void switch_lang(void) {
  if (is_win) {
    SEND_STRING(SS_LALT(SS_TAP(X_LSFT)));
  } else {
    send_string(lang_switch_combo);
    wait_ms(10);
  }
}

void press_n_times(int times, uint16_t key) {
  for (int i=0; i<times; i++) {
    // wait_ms(TYPING_INTERVAL);
    tap_code16(key);
  }
}


bool handle_del_bspace(void) {
  if (char_to_bspace > 1 || char_to_del > 0) {
    layer_off(GIT_C);
    layer_off(GIT_R);
    layer_off(GIT_S);

    press_n_times(char_to_bspace, KC_BACKSPACE);
    char_to_bspace = 1;
    press_n_times(char_to_del, KC_DEL);
    char_to_del = 0;

    return false;
  }

  if (is_mac_with_base_layer_off()) {
    uint8_t mod_state = get_mods() & MOD_MASK_CTRL;
    if (get_mods() & mod_state) {
      del_mods(mod_state);
      add_mods(MOD_LALT);
      mac_ctrl_on = true;
    }
  }
  return true;
}

void send_string_with_translation(const char *string) {
  #if WORKMAN_TO_QWERTY_HW_MAPPING
  if (layer_state_is(WORKMAN)) {
    int isUpperCase = 0;
    for (int i = 0; i < strlen(string); i++) {
      char toPrint = string[i];
      if (isupper(toPrint)) {
        if (toPrint == 'P') {
          SEND_STRING(":");
          continue;
        }

        isUpperCase = 1;
        toPrint = tolower(toPrint);
      }
      switch (toPrint) {
        case ':':
          toPrint = 'I';
          break;

        case 'w':
          toPrint = 'd';
          break;
        case 'e':
          toPrint = 'r';
          break;
        case 'r':
          toPrint = 'w';
          break;
        case 't':
          toPrint = 'b';
          break;
        case 'y':
          toPrint = 'j';
          break;
        case 'u':
          toPrint = 'f';
          break;
        case 'i':
          toPrint = 'u';
          break;
        case 'o':
          toPrint = 'p';
          break;
        case 'p':
          toPrint = ';';
          break;

        case 'd':
          toPrint = 'h';
          break;
        case 'f':
          toPrint = 't';
          break;
        case 'h':
          toPrint = 'y';
          break;
        case 'j':
          toPrint = 'n';
          break;
        case 'k':
          toPrint = 'e';
          break;
        case 'l':
          toPrint = 'o';
          break;
        case ';':
          toPrint = 'i';
          break;

        case 'b':
          toPrint = 'm';
          break;
        case 'n':
          toPrint = 'k';
          break;
        case 'm':
          toPrint = 'l';
          break;
      }
      if (isUpperCase) {
        isUpperCase = 0;
        toPrint = toupper(toPrint);
      }
      send_char(toPrint);
    }
  } else {
    send_string(string);
  }
  #else
  send_string(string);
  #endif
}

void send_string_remembering_length(const char *string) {
  send_string_with_translation(string);
  char_to_bspace = strlen(string);
}

void send_shifted_strings(const char *string1, const char *string2) {
  if (get_mods() & MOD_MASK_SHIFT) {
    clear_mods();
    send_string_remembering_length(string2);
  } else {
    send_string_remembering_length(string1);
  }
}

void send_shifted_strings_add(const char *string1, const char *string2) {
  bool shifted = get_mods() & MOD_MASK_SHIFT;
  clear_mods();

  send_string_remembering_length(string1);

  if (shifted) {
    send_string(string2);
    char_to_bspace = strlen(string1) + strlen(string2);
  }
}
