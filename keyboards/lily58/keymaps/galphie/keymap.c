#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include "sendstring_spanish.h"
#include "quantum.h"



enum layer_number {
  _QWERTY = 0,
  _SYMB,
  _MISC,
  _MEDIA,
};

/*Para meterlo, hay que compilar con QMK MSYS (qmk compile -kb lily58 -km galphie) y después 
flashear el firmware con QMK Toolbox (el .exe está en Alfonso/COSAS/teclado)*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  º   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |------+------+------+------+------+------|  Del  |    |BackSP |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | SYMB | /Space  /       \Enter \  | MISC | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------' 
 */

[_QWERTY] = LAYOUT( \
          KC_ESC,  ES_1,   ES_2,    ES_3,    ES_4,    ES_5,                    ES_6,    ES_7,    ES_8,    ES_9,    ES_0,    ES_MORD,  \
          KC_TAB,  ES_Q,   ES_W,    ES_E,    ES_R,    ES_T,                    ES_Y,    ES_U,    ES_I,    ES_O,    ES_P,    ES_QUOT,  \
  LCTL_T(KC_CAPS), ES_A,   ES_S,    ES_D,    ES_F,    ES_G,                    ES_H,    ES_J,    ES_K,    ES_L,    ES_NTIL, ES_ACUT,  \
          KC_LSFT, ES_Z,   ES_X,    ES_C,    ES_V,    ES_B, KC_DEL,  KC_BSPC,  ES_N,    ES_M,    ES_COMM, ES_DOT,  ES_MINS,  KC_RSFT, \
                                KC_LALT, KC_LGUI, MO(_SYMB), KC_SPC, KC_ENT, MO(_MISC), KC_RGUI, KC_RALT \
),
/* SYMB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Num |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------| 
 * |   º  |   ¡  |   !  |   ¿  |   ?  |   %  |                    |   &  |   <  |   >  |   |  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      |      |   [  |   ]  |   `  |-------.    ,-------|   *  |   {  |   }  |   +  |      |      | 
 * |------+------+------+------+------+------|  Del  |    |BackSP |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   /  |-------|    |-------|   \  |      |      |      |      |      | 
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | SYMB | /Space  /       \Enter \  | MISC | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMB] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, KC_NUM,   \
  ES_MORD, ES_IEXL, ES_EXLM, ES_IQUE, ES_QUES, ES_PERC,                  ES_AMPR, ES_LABK, ES_RABK, ES_PIPE, XXXXXXX, XXXXXXX,  \
  _______, XXXXXXX, XXXXXXX, ES_LBRC, ES_RBRC, ES_GRV,                   ES_ASTR, ES_LCBR, ES_RCBR, ES_PLUS, XXXXXXX, XXXXXXX,  \
  _______, _______, _______, _______, _______, ES_SLSH, _______, _______, ES_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* MISC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   ↑  |      |      |                    |   /  |   7  |   8  |   9  |   -  |   =  | 
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      |   ←  |   ↓  |   →  |      |-------.    ,-------|   *  |   4  |   5  |   6  |   +  |RCTRL |     
 * |------+------+------+------+------+------|  Del  |    |BackSP |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |      |-------|    |-------|   0  |   1  |   2  |   3  |   .  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | SYMB | /Space  /       \Enter \  | MISC | RGUI |AltGr |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MISC] = LAYOUT( \
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                      KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   \
  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,                    KC_PSLS, KC_P7,   KC_P8,   KC_P9,  KC_PMNS,  KC_PEQL,  \
  _______,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,                    KC_PAST, KC_P4,   KC_P5,   KC_P6,  KC_PPLS,  KC_RCTL,  \
  _______,  _______,  _______,  _______,  _______,  XXXXXXX, _______, _______,   KC_P0,  KC_P1,   KC_P2,   KC_P3,  KC_PDOT,  KC_RSFT,  \
                                  _______, _______, _______, _______, _______, _______, _______, _______ \
),
/* MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Power|      |      |      |      |      |                    |      |      |      |      |      | Sleep|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | Vol↑ |      |      |                    |      |      | Bri↑ |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Prev | Vol↓ | Next |      |-------.    ,-------|      |   ►  | Bri↓ |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Lock |      |      | Mute |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | SYMB | /Space  /       \Enter \  | MISC | RGUI |AltGr |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MEDIA] = LAYOUT( \
   KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,                   XXXXXXX, KC_MPLY, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_LOCK, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
)};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMB, _MISC, _MEDIA);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change her
    oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
