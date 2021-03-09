#include "keymap.h"

/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers { COLEMAK = 0, LOWER, RAISE, ADJUST, NAV, DISPLAY, CFG };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: COLEMAK
     *
     * ,----------------------------------------------.                              ,--------------------------------------------.
     * |   TAB     |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  \ |    |
     * |-----------+------+------+------+------+------|                              |------+------+------+------+------+---------|
     * | ESC(LCTL) |   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |O(NAV)|ESC(LCTL)|
     * |-----------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+---------|
     * |   ` ~     |   Z  |   X  |   C  |   D  |   V  |ALTosm|CONFIG|  |GUIosm|Leader|   K  |   H  | ,  < | . >  | /  ? |  ' "    |
     * `-------------------------+------+------+------+------+------|  |------+------+------+------+------+-----------------------'
     *                           | DISP | LAlt |      | Bspc | Enter|  |Enter | Space|      | Del  | GUI  |
     *                           |      |      | Lower|      |(Shft)|  |(Shft)|      | Raise|      |      |
     *                           `----------------------------------'  `----------------------------------'
     */
    [COLEMAK] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, LCTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, LT(NAV, KC_O), RCTL_T(KC_ESC), KC_GRV, KC_Z, KC_X, KC_C, KC_D, KC_V, OSM(MOD_LALT), MO(CFG), OSM(MOD_LALT), KC_LEAD, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, MO(DISPLAY), KC_LALT, MO(LOWER), KC_BSPC, MT(MOD_LSFT, KC_ENT), KC_SFTENT, KC_SPC, MO(RAISE), KC_DEL, KC_LGUI),
    /*
     * Lower Layer: Numbers/symbols
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |  1 ! | 2 @  | 3 #  | 4 $  | 5 %  |                              | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   &  |   *  |  [ { |  ] } |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |  (   |   )  |      |      |  |      |      | = +  | - _  |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      | Lower|      |      |  |      |      | Raise|      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [LOWER] = LAYOUT(_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, KC_EQL, KC_MINS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * Raise Layer: same as Lower; on RH
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |  1 ! | 2 @  | 3 #  | 4 $  | 5 %  |                              | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   &  |   *  |  [ { |  ] } |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |  (   |   )  |      |      |  |      |      | = +  | - _  |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [RAISE] = LAYOUT(_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, KC_EQL, KC_MINS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * Adjust: shifted symbols
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              |      |      |      |      |      |   |    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |                              |      |      |      |  {   |  }   |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |   ~    |      |      |      |      |      |      |      |  |      |      |  +   |  _   |  <   |  >   |  ?   |   "    |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [ADJUST] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, KC_DQUO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * Navigation Layer
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              | Home | PgDn | PgUp | End  |      |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |                              | Left | Down | Up   | Right|      |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      | Lower|      |      |  |      |      | Raise|      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [NAV] = LAYOUT(_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /*
     * Display/interface Layer (workspaces)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              |      | WS Up| WinUp|      |      |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |                              | WS L | WinL | WinDn| WinR | WS R |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |  |      |      |      | WS Dn|      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |Play/ |
     *                        |      |      |      |      |      |  |      |      |      |      |Pause |
     *                        `----------------------------------'  `----------------------------------'
     */
    [DISPLAY] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, LCA(KC_UP), LGUI(KC_UP), _______, _______, _______, _______, _______, _______, _______, _______, _______, LCA(KC_LEFT), LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RGHT), LCA(KC_RGHT), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LCA(KC_DOWN), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY),
    /*
     * CONFIG Layer (keyboard, funcs, etc)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              |      | F7   | F8   | F9   | F10  |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |                              |      | F4   | F5   | F6   | F11  |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |      |  |      |      |      | F1   | F2   | F3   | F12  |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [CFG] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_F10, _______, _______, _______, _______, _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, KC_F11, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F12, _______, _______, _______, _______, _______, LGUI(KC_L), RESET, _______, _______, _______, _______),

    // /*
    //  * Layer template
    //  *
    //  * ,-------------------------------------------.                              ,-------------------------------------------.
    //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    //  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        |      |      |      |      |      |  |      |      |      |      |      |
    //  *                        `----------------------------------'  `----------------------------------'
    //  */
    //     [_LAYERINDEX] = LAYOUT(
    //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    //       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    //     ),
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, LOWER, RAISE, ADJUST); }

bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

LEADER_EXTERNS();

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_C) {  // Inline Code
            SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        SEQ_ONE_KEY(KC_P) {  // Invoke Password Manager
            SEND_STRING(SS_LCTRL(SS_LALT("\\")));
        }
        SEQ_ONE_KEY(KC_S) {  // Windows screenshot
            SEND_STRING(SS_LGUI("\nS"));
        }
        SEQ_TWO_KEYS(KC_F, KC_P) {  // Fusion Projection prefix
            SEND_STRING("[Projection] ");
        }
        SEQ_TWO_KEYS(KC_B, KC_B) {  // Basecone invoice description
            SEND_STRING("[Leveranciersnaam] [Factuurnummer]");
        }
        SEQ_TWO_KEYS(KC_E, KC_S) {  // Support email splitkb
            SEND_STRING("support@splitkb.com");
        }
        SEQ_TWO_KEYS(KC_E, KC_T) {  // Email splitkb
            SEND_STRING("thomas@splitkb.com");
        }
        SEQ_TWO_KEYS(KC_E, KC_P) {  // Email personal
            SEND_STRING("mail@thomasbaart.nl");
        }
        SEQ_TWO_KEYS(KC_S, KC_D) {  // Splitkb documentation
            SEND_STRING("https://docs.splitkb.com/");
        }
        SEQ_TWO_KEYS(KC_S, KC_V) {  // Splitkb VAT number
            SEND_STRING("NL210593349B01");
        }
        SEQ_TWO_KEYS(KC_B, KC_C) {  // Discord bongocat
            SEND_STRING(":bongocat:\n");
        }
        SEQ_TWO_KEYS(KC_C, KC_B) {  // Discord code block
            SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
        }
        SEQ_TWO_KEYS(KC_Y, KC_S) {  // Greeting
            SEND_STRING("Yours sincerely,\n\nThomas Baart");
        }
        SEQ_THREE_KEYS(KC_M, KC_V, KC_G) {  // Greeting
            SEND_STRING("Met vriendelijke groet,\n\nThomas Baart");
        }
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_yarhar_logo(void) {
    static const char PROGMEM yarhar_logo[] = {// 'yarhar300', 128x64px
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                               0xff, 0x7f, 0x3f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0x3f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0x1f, 0x1f, 0x0f, 0x1f, 0x1f, 0x3f, 0x3f, 0x79, 0xf1, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x1e, 0x1e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x1e, 0x1e, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf1, 0x79, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x1f, 0x1f, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x8f, 0x8f, 0xce, 0xae, 0x74, 0x70, 0xf8, 0xf8, 0x70, 0x74, 0xae, 0xce, 0x8f, 0x8f, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xe0, 0xf0, 0xf0, 0x78, 0x78, 0x3c, 0x3c, 0x1e, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x1e, 0x1e, 0x3c, 0x78, 0x78, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    oled_write_raw_P(yarhar_logo, sizeof(yarhar_logo));
}

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("TBS's Kyria\n\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case COLEMAK:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case LOWER:
            oled_write_P(PSTR("Symb (L)\n"), false);
            break;
        case RAISE:
            oled_write_P(PSTR("Symb (R)\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Symb (Up)\n"), false);
            break;
        case NAV:
            oled_write_P(PSTR("Arrows (Vi)\n"), false);
            break;
        case DISPLAY:
            oled_write_P(PSTR("Workspaces\n"), false);
            break;
        case CFG:
            oled_write_P(PSTR("Config/Funcs\n"), false);
            break;
        default:
            oled_write_P(PSTR("Not in KS\n"), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard layer
    } else {
        render_yarhar_logo();
    }
}
#endif

// Layer-specific encoder knob functions
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // left knob
        switch (get_highest_layer(layer_state)) {
            case COLEMAK:  // Volume
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            case LOWER:  // Desktop switching
                if (clockwise) {
                    tap_code16(C(KC_RIGHT));
                } else {
                    tap_code16(C(KC_LEFT));
                }
                break;
            case RAISE:  // Mousewheel L/R
                if (clockwise) {
                    tap_code(KC_WH_L);
                } else {
                    tap_code(KC_WH_R);
                }
                break;
            case DISPLAY:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            default:  // No action
                if (clockwise) {
                    tap_code(KC_NO);
                } else {
                    tap_code(KC_NO);
                }
                break;
        }
    } else if (index == 1) {  // right knob
        switch (get_highest_layer(layer_state)) {
            case COLEMAK:  // Undo / Redo
                if (clockwise) {
                    tap_code16(LGUI(KC_Z));
                } else {
                    tap_code16(SGUI(KC_Z));
                }
                break;
            case RAISE:  // Mouse wheel U/D
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
                break;
            case DISPLAY:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            default:  // No action
                if (clockwise) {
                    tap_code(KC_NO);
                } else {
                    tap_code(KC_NO);
                }
                break;
        }
    }
}
#endif
