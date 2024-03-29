/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keycodes.h"

// For heatmap
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE LAYER
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |  Tab   |   Q    |   W    |   F    |   P    |   B    |      |    J   |   L    |   U    |   Y    |   -    |  Bksp |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | SHIFT  |   A    |   R    |   S    |   T    |   G    |      |    M   |   N    |   E    |   I    |   O    |  ; :  |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | CTRL   |   Z    |   X    |   C    |   D    |   V    |      |    K   |   H    |  , <   |  . >   |  / ?   |   ESC |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                        ,---------------------------------,      ,--------------------------.
                        |   CTRL  | SHIFT |  SHORT, SPACE |      |  ENT  | SYMBOLS  |  Alt  |
                        |---------+-------+---------------'      +-------+----------+-------|\
  ),
*/
  [L_BASE] = LAYOUT_split_3x6_3(

    KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,    KC_U,    KC_Y,   MINUS,  KC_BSPC,
    KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_SCLN,
    KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,  KC_COMMA, KC_DOT, KC_SLSH,  KC_ESC,

                             KC_LCTL, KC_LSFT, SHORT_SPC,            KC_ENT, MO(1), KC_RALT
  ),



/*
 * SYMBOLS LAYER
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |  Tab   |        |        |   _    |    '   |        |      |        |  [ 7   |  ] 8   |   9    |        |  Bksp |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |  SHIFT |        |   %    |   {    |    }   |   ,    |      |  \ 0   |  ( 4   |  ) 5   |   6    |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |  CTRL  |        |   !    |        |    "   |   +    |      |        |  = 1   |  @ 2   |   3    |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       | SHIFT | SPACE |  | ENTER |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_SYMBOLS] = LAYOUT_split_3x6_3(

    _______, XXXXXXX,   XXXXXXX, KC_UNDS, KC_QUOT,  XXXXXXX,           XXXXXXX,  LBRC_7,  RBRC_8,  KC_INT9, XXXXXXX, _______,
    _______, XXXXXXX,KC_PERCENT, KC_LCBR, KC_RCBR, KC_COMMA,            BSLS_0,  LPRN_4,  RPRN_5,  KC_INT6, XXXXXXX, XXXXXXX,
    _______, XXXXXXX,   KC_EXLM, XXXXXXX,  DQUOTE,  KC_PPLS,           XXXXXXX, EQUAL_1,  EMAIL_2,  KC_INT3, XXXXXXX, XXXXXXX,

                                  XXXXXXX, KC_LSFT,  KC_SPC,           KC_ENT,  _______, XXXXXXX
  ),


/*
 * SHORTCUTS LAYER
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |  Tab   |        |        |        |        |        |      |        |        |        |        |        |  Bksp |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |  SHIFT | VSCODE |INTELLIJ| BROWSER|  TMUX  | CTRL+C |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |  CTRL  |        |        |        |        | CTRL+V |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       | SHIFT | SPACE |  | ENTER |CTRL+B |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [L_SHORTCUTS] = LAYOUT_split_3x6_3(

      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, VSCODE, INTELLIJ, BROWSER,    TMUX, C(KC_C),            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_V),            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                                    XXXXXXX, XXXXXXX, _______,     XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [L_RGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define GIT_STATUS "Counter: 9"

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case L_BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            oled_write_ln_P(PSTR(GIT_STATUS), false);
            break;
        case L_SYMBOLS:
            oled_write_ln_P(PSTR("SYMBOLS"), false);
            break;
        case L_SHORTCUTS:
            oled_write_ln_P(PSTR("SHORTCUTS"), false);
            break;
        case L_RGB:
            oled_write_ln_P(PSTR("RGB"), false);
            break;
        default:
            oled_write_ln_P(PSTR("ERROR"), false);
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }

    if (keycode < 60 || keycode == KC_LSFT) {
        if (keycode == KC_LSFT) {
            name = '^';
            oled_write_P(PSTR("LSFT"), false);
        } else {
            name = code_to_name[keycode];
        }
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
    oled_write_ln_P(PSTR(GIT_STATUS), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef CONSOLE_ENABLE
        uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
             keycode,
             record->event.key.row,
             record->event.key.col,
             get_highest_layer(layer_state),
             record->event.pressed,
             get_mods(),
             get_oneshot_mods(),
             record->tap.count
             );
    #endif
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    return true;
}

#endif // OLED_ENABLE
