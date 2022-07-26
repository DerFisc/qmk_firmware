/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

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

/* sources:
https://github.com/kingdase/hasu-usb-usb-neo/blob/master/qmk/keymap.c
https://docs.qmk.fm/#/squeezing_avr
https://www.neo-layout.org/Benutzerhandbuch/Tastaturbelegung/
https://eurkey.steffen.bruentjen.eu/layout.html
https://geekhack.org/index.php?topic=69169.0
https://docs.qmk.fm/#/feature_space_cadet
https://docs.qmk.fm/#/mod_tap
https://docs.qmk.fm/#/one_shot_keys
https://docs.qmk.fm/#/feature_layers
https://docs.qmk.fm/#/keycodes
https://docs.qmk.fm/#/keycodes_us_ansi_shifted

Layout in OS is expected to be Eurokey
US International might work as well with some special characters not working
Default layer is slightly modified US (mostly @ and Umlaute added)
Layer 1 slightly modified german
Neo3 for programming
Neo4 for moving
Mouse for mouse

Control layer for switching is Grave hold

works with usb_usb converter, but probably also normal qmk keyboards

Things what might be useful to add:
tap-dance keys
https://gist.github.com/weilbith/26cdac334c2fd76d5ed26adf10fa826c
https://docs.qmk.fm/#/feature_tap_dance?id=example-5-using-tap-dance-for-advanced-mod-tap-and-layer-tap-keys
lead keys https://docs.qmk.fm/#/feature_leader_key
more one shot keys

compile with qmk compile -km mo_quertyz
flash with .\avrdude.exe -p m32u4 -P com7 -c avr109 -U flash:w:converter_usb_usb_pro_micro_mo_test.hex
and grave + 0 key for bootloader mode


*/


#include QMK_KEYBOARD_H

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.
#define _QWERTY 0
#define _QUERTZ 1
#define _CONTROL 2
#define _neo3 3
#define _neo4 4
#define _neo_mouse 5

#define __NO__ KC_NO

// for debugging
/* 
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}*/



// https://docs.qmk.fm/#/feature_key_overrides
// 0b001 bitmask for layer 1
// important, you have to override the key the layer actually sends on the position not the key the keyboard sends on that position aka ss instead of minus and the key has to be defined on that layer
//const key_override_t dach_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_GRAVE, RALT(KC_SEMICOLON), 0b010);
const key_override_t two_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, KC_DOUBLE_QUOTE, 0b010);
// const key_override_t three_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_3, KC_DOUBLE_QUOTE, 0b001); can't generate code
// const key_override_t four_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_4, KC_DOUBLE_QUOTE, 0b001); same
// const key_override_t five_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_5, KC_DOUBLE_QUOTE, 0b001); same
const key_override_t six_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, KC_AMPERSAND, 0b010);
const key_override_t seven_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, KC_SLASH, 0b010);
const key_override_t eight_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, KC_LEFT_PAREN, 0b010);
const key_override_t nine_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, KC_RIGHT_PAREN, 0b010);
const key_override_t zero_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_EQUAL, 0b010);
const key_override_t ss_key_override = ko_make_with_layers(MOD_MASK_SHIFT, RALT(KC_S), LSFT(KC_SLASH), 0b010);
const key_override_t grave_key_override = ko_make_with_layers(MOD_MASK_SHIFT, RALT(KC_QUOT), KC_GRAVE, 0b010);

const key_override_t seven_alt_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_7, KC_LEFT_CURLY_BRACE, 0b010);
const key_override_t eight_alt_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_8, KC_LEFT_BRACKET, 0b010);
const key_override_t nine_alt_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_9, KC_RIGHT_BRACKET, 0b010);
const key_override_t zero_alt_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_0, KC_RIGHT_CURLY_BRACE, 0b010);
const key_override_t ss_alt_key_override = ko_make_with_layers(MOD_MASK_ALT, RALT(KC_S), KC_BACKSLASH, 0b010);

//const key_override_t ue_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, LSFT(RALT(KC_U)), 0b001); not needed
const key_override_t plus_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_PLUS, KC_ASTERISK, 0b010);
//const key_override_t oe_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, LSFT(RALT(KC_O)), 0b001);
//const key_override_t ae_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, LSFT(RALT(KC_A)), 0b001);
//const key_override_t hash_key_override = ko_make_with_layers(MOD_MASK_SHIFT, LT(_neo3,KC_F21), KC_QUOTE, 0b010);
//const key_override_t hash2_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_HASH, KC_QUOTE, 0b010);
const key_override_t comma_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SEMICOLON, 0b010);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLON, 0b010);
//const key_override_t minus_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINUS, LSFT(KC_MINUS), 0b010);

const key_override_t plus_alt_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_PLUS, KC_TILDE, 0b010);

const key_override_t nubs_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, 0b010);
const key_override_t nubs_alt_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_LEFT_ANGLE_BRACKET, KC_PIPE, 0b010);

// provides at at q like in german and € and E for ralt leader tap
const key_override_t at_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_Q, KC_AT, 0b011);
const key_override_t euro_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_E, RALT(KC_5), 0b011);
// provide ä keys when tapping altgr - done via function
//const key_override_t ue_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_LBRC, RALT(KC_U), 0b001);
//const key_override_t oe_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_SCLN, RALT(KC_O), 0b001);
//const key_override_t ae_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_QUOT, RALT(KC_A), 0b001);



// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &two_key_override,
    &six_key_override,
    &seven_key_override,
    &eight_key_override,
    &nine_key_override,
    &zero_key_override,
    &ss_key_override,
    &grave_key_override,	
	&seven_alt_key_override,
	&eight_alt_key_override,
	&nine_alt_key_override,
	&zero_alt_key_override,
	&ss_alt_key_override,
	&plus_key_override,
	&comma_key_override,
	&dot_key_override,
	&plus_alt_key_override,
	&nubs_key_override,
	&nubs_alt_key_override,
	&at_key_override,
	&euro_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [_QWERTY] = LAYOUT_all(
                      KC_F13,  KC_F14,  KC_F15,  KC_F16, KC_F17, KC_F18, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,               KC_MEDIA_PLAY_PAUSE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    LT(_CONTROL, KC_GRAVE),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    LT(0,KC_MINS), KC_EQL,  KC_JYEN, KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    LT(0,KC_LBRC), KC_RBRC,          LT(_neo3,KC_BSLS),     KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    LT(_neo3,KC_F22), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    LT(0,KC_SCLN), LT(0,KC_QUOT),          LT(_neo3,KC_NUHS), KC_ENT,                                    KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    KC_LSPO, LT(_neo4, KC_NUBS), KC_Z,    LT(0,KC_X),    LT(0,KC_C),    LT(0,KC_V),   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RO,   KC_SFTENT,              KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    KC_LCTL, KC_LGUI, LALT_T(KC_F21), KC_MHEN, KC_HANJ,         LT(_neo_mouse,KC_SPC),         KC_HAEN, KC_HENK, KC_KANA, LT(_neo4,KC_F21), KC_RGUI, LT(0,KC_NO),  KC_RCPC,     KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),
    [_QUERTZ] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    LT(_CONTROL,KC_F21),  ______,  KC_2,  ______,  ______, ______, KC_6,  KC_7,  KC_8, KC_9,  KC_0, RALT(KC_S), RALT(KC_QUOT), ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______,   KC_Z,  ______,  ______, ______,  ______, RALT(KC_U), KC_PLUS,         LT(_neo3,KC_F21),     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  RALT(KC_O), RALT(KC_A),         LT(_neo3,KC_F21), ______,                              ______,______,______,______,    ______,______,
    ______,  LT(_neo4, KC_LEFT_ANGLE_BRACKET),  	KC_Y,  ______,  ______, ______, ______,  ______,  ______, KC_COMM,  KC_DOT, KC_MINUS,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
	// control layer to switch layers and toggle bootloader
    [_CONTROL] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  DF(0),  DF(1),  ______,  ______, ______, ______,  ______,  ______, ______,  QK_BOOTLOADER, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
    [_neo3] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  LSFT(RALT(KC_1)),  LSFT(RALT(KC_2)),  LSFT(RALT(KC_3)),  KC_RIGHT_ANGLE_BRACKET, KC_LEFT_ANGLE_BRACKET, ______, ______, KC_COMMA,  ______, ______, RALT(KC_S),RALT(KC_U), ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  KC_AT,  KC_UNDS,  KC_LBRC,  KC_RBRC,  KC_CIRC,  KC_EXLM,  KC_LABK,  KC_RABK,  KC_EQL,   KC_AMPR, RALT(KC_O), RALT(KC_A),         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  KC_BSLS,  KC_SLSH,  KC_LCBR,  KC_RCBR,  KC_ASTR,  KC_QUES,  KC_LPRN,  KC_RPRN,  KC_MINS,  KC_COLN,  KC_AT,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  KC_HASH,  KC_DOLLAR,  KC_PIPE, KC_TILDE, KC_GRAVE,  KC_PLUS,  KC_PERC,  KC_DQUO,  KC_QUOT,  KC_SCLN,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
    [_neo4] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, KC_ASTERISK, ______,  KC_LCBR,  KC_LBRC, KC_RBRC,   KC_RCBR, KC_BACKSLASH, KC_ASTERISK, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  KC_PGUP,  KC_BSPC,  KC_UP,    KC_DEL,   KC_PGDN,  KC_SLASH, KC_7,     KC_8,     KC_9, KC_PLUS, KC_MINUS, KC_TILDE,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   KC_EQUAL, KC_4,     KC_5,     KC_6,  KC_COMMA, KC_DOT,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,   KC_ESC,   KC_TAB,   KC_INS,   KC_ENT,   LCTL(KC_Z),   KC_COLN,  KC_1,     KC_2,     KC_3,     KC_SCLN,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
    [_neo_mouse] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,   __NO__,    __NO__,  __NO__,   __NO__,   __NO__,   __NO__,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,   __NO__,   __NO__,   KC_MS_UP,    __NO__,   __NO__,   __NO__,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,   __NO__,   KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT, __NO__,   __NO__,  ______,  ______, ______,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,   ______,   __NO__,   KC_MS_BTN3,   KC_MS_BTN2,   KC_MS_BTN1,  __NO__,  ______,  ______, ______,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
};

// https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md
// https://www.reddit.com/r/olkb/comments/qyrogi/comment/hm1foco/?utm_source=share&utm_medium=web2x&context=3
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case LT(_neo3,KC_F21): //sends hash on tap and layer on hold on german; extra handling to also be able to shift
			// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_advanced_keycodes.md
			// https://github.com/qmk/qmk_firmware/blob/master/docs/mod_tap.md
			// https://www.reddit.com/r/olkb/comments/qyrogi/comment/hm1foco/?utm_source=share&utm_medium=web2x&context=3
		if (record->tap.count && record->event.pressed) {
			if (get_mods() & MOD_MASK_SHIFT) { // check if shifted
				del_mods(MOD_BIT(KC_LSFT));	// delete shift status
				del_mods(MOD_BIT(KC_RSFT));
				tap_code16(KC_QUOTE); // send code if shifted
				add_mods(MOD_BIT(KC_LSFT));	// add shift status again (makes problems if rshift is used, because lsft sticks
			} else {
				tap_code16(KC_HASH); // Intercept tap function to send hash
			}
			return false;
		} else if (record->event.pressed) {
			return true; // Return true for normal processing of hold keycode
		}
		break;
	case LT(_neo3,KC_F22): //sends skip word on tap and layer on hold
			if (record->tap.count && record->event.pressed) {
			tap_code16(LCTL(KC_RIGHT)); // Intercept tap function to send skip word
			return false;
		} else if (record->event.pressed) {
			return true; // Return true for normal processing of hold keycode
		}
		break;
	case LALT_T(KC_F21): //sends skip word on tap and layer on hold
			if (record->tap.count && record->event.pressed) {
			tap_code16(LCTL(KC_LEFT)); // Intercept tap function to send skip word
			return false;
		} else if (record->event.pressed) {
			return true; // Return true for normal processing of hold keycode
		}
		break;
	case LT(_CONTROL,KC_F21): //sends dach on tap and layer on hold
		if (record->tap.count && record->event.pressed) {
			if (get_mods() & MOD_MASK_SHIFT) { // check if shifted
				del_mods(MOD_BIT(KC_LSFT));	// delete shift status
				del_mods(MOD_BIT(KC_RSFT));
				tap_code16(RALT(KC_SEMICOLON)); // send code if shifted
				add_mods(MOD_BIT(KC_LSFT));	// add shift status again
			} else {
				tap_code16(KC_CIRCUMFLEX); // Intercept tap function to send dach if not shifted
			}
			return false;
		} else if (record->event.pressed) {
			return true; // Return true for normal processing of hold keycode
		}
		break;
	case LT(_neo4,KC_F21): //sends oneshot ralt on tap and layer on hold
		if (record->tap.count && record->event.pressed) {
			// https://docs.qmk.fm/#/one_shot_keys
			add_oneshot_mods(MOD_BIT(KC_RALT)); // Intercept tap function to send oneshot ralt
			return false;
		} else if (record->event.pressed) {
			return true; // Return true for normal processing of hold keycode
		}
		break;
	// ae, oe, ue for long tap respective keys in us layout
	case LT(0,KC_QUOT): //sends KC on tap and ä on hold
		if (record->tap.count && record->event.pressed) {
			return true; // Return true for normal processing of tap keycode
		} else if (record->event.pressed) {
			tap_code16(RALT(KC_A)); // Intercept hold function to send ae
			return false;
		}
		break;
	case LT(0,KC_LBRC): //sends KC on tap and ü on hold
		if (record->tap.count && record->event.pressed) {
			return true; // Return true for normal processing of tap keycode
		} else if (record->event.pressed) {
			tap_code16(RALT(KC_U)); // Intercept hold function to send ae
			return false;
		}
		break;
	case LT(0,KC_SCLN): //sends KC on tap and ö on hold
		if (record->tap.count && record->event.pressed) {
			return true; // Return true for normal processing of tap keycode
		} else if (record->event.pressed) {
			tap_code16(RALT(KC_O)); // Intercept hold function to send ae
			return false;
		}
		break;
	case LT(0,KC_MINS): //sends KC on tap and ß on hold
		if (record->tap.count && record->event.pressed) {
			return true; // Return true for normal processing of tap keycode
		} else if (record->event.pressed) {
			tap_code16(RALT(KC_S)); // Intercept hold function to send ae
			return false;
		}
		break;
	case LT(0,KC_NO): //sends ) on tap and KC_App on hold
		if (record->tap.count && record->event.pressed) {
			tap_code16(LSFT(KC_0)); // Intercept tap function to send )
		} else if (record->event.pressed) {
			tap_code16(KC_APP); // Intercept hold function to send app menu
		}
		return false;
		break;		
	// https://docs.qmk.fm/#/mod_tap
	case LT(0,KC_X):
		if (!record->tap.count && record->event.pressed) {
			tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
			return false;
		}
		return true;             // Return true for normal processing of tap keycode
	case LT(0,KC_C):
		if (!record->tap.count && record->event.pressed) {
			tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
			return false;
		}
		return true;             // Return true for normal processing of tap keycode
	case LT(0,KC_V):
		if (!record->tap.count && record->event.pressed) {
			tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
			return false;
		}
		return true;             // Return true for normal processing of tap keycode
    }
  return true;
}


/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case LT(0,KC_COLN): //sends colon on tap and semicolon on hold
		if (record->tap.count && record->event.pressed) {
			return true; // Return true for normal processing of tap keycode
			break;
		} else if (record->event.pressed) {
			tap_code16(KC_SCLN); // Intercept hold function to send SEMICOLON    
			return false;
		}
		return true; // this allows for normal processing of key release!
  }
}
*/