#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

bool is_caps_lock_on = false;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum {
  TD_MAS,
  TD_BAJO,
  TD_COMASD,
  TD_PIPA,
  TD_SIGNO,
  TD_MAYOR,
  TD_MENOR,
  TD_LLAVEI,
  TD_LLAVEC,
  TD_PUNTOS,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  |   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | ALT  | LGUI |LOWER | /Enter  /       \Space \  |RAISE | + =  |Right |
 *                   | LEFT |      |      |/       /         \      \ |      |      | ALT  |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  QK_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_BAJO),
  MT(MOD_LSFT, KC_CAPS),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,          KC_H,    KC_J,    KC_K,    KC_L, TD(TD_PUNTOS), TD(TD_COMASD),
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TD(TD_LLAVEI), TD(TD_LLAVEC),  KC_N,    KC_M,    TD(TD_MENOR), TD(TD_MAYOR),  TD(TD_SIGNO), TD(TD_PIPA),
                       KC_LALT, KC_LGUI, MO(_LOWER), KC_ENT,   KC_SPC, MO(_RAISE),TD(TD_MAS), KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | `/~  |      |      |      |      |      |                    |  F6  |  F7  |  F8  | F9   | F10  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      | VOL- |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|      |      |      | ctlrf|      |-------.    ,-------|      |      |  Up  |      |      | VOL+ |
 * |------+------+------+------+------+------| supr  |    | PRINT |------+------+------+------+------+------|
 * |LCTRL |      |      |  C   |  V   |      |-------|    |-------|      | Left | Down |Rigth |      | MUTE |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  ALT | LGUI |LOWER | /Space  /       \Space \  |      |MENU  | ALT  |
 *                   | LEFT |      |      |/       /         \      \ |      |      |RIGTH |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV, _______, _______, _______, _______, _______,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, KC_VOLD,
  KC_LSFT, _______, _______, _______, RCTL(KC_F), _______,                   _______, _______,  KC_UP, _______, _______, KC_VOLU,
  KC_LCTL, _______, _______,  KC_C,    KC_V,   _______, KC_DEL, KC_PSCR, _______, KC_LEFT, KC_DOWN,KC_RGHT, _______, KC_MUTE,
                             KC_LALT, KC_TRNS, KC_SPC,  KC_SPC,  KC_SPC, _______, KC_APP, KC_RALT
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  | F4   | F5   |                    |      |      |      |      |      |Bri + |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |Bri - |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |win  L|      |RGB + |
 * |------+------+------+------+------+------| RGB on |    | RGB - |------+------+------+------+------+------|
 * |      |      |      |      |      |       |-------|    |-------|      |      |      |      |      |RGB - |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  alt |      |      | / Enter /       \ Enter\  |Raise | Prev |Next  |
 *                   | LEFT |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F11,   KC_F1,    KC_F2,   KC_F3,  KC_F4,    KC_F5,                      _______, _______, _______, _______, _______, KC_BRIU,
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_BRID, 
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, LGUI(KC_L), _______, RGB_VAI, 
  _______, _______, _______, _______, _______, _______,  RGB_TOG, RGB_RMOD, _______, _______, _______, _______, _______, RGB_VAD, 
                             KC_LALT, _______, _______,  KC_ENT, KC_ENT,  KC_TRNS, KC_MPRV, KC_MNXT
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};


tap_dance_action_t tap_dance_actions[] = {
  [TD_MAS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_PLUS)),
  [TD_BAJO] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_UNDS)),
  [TD_COMASD] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_DQUO)),
  [TD_PIPA] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, LSFT(KC_PIPE)),
  [TD_SIGNO] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_QUES)),
  [TD_MAYOR] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_GT)),
  [TD_MENOR] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_LT)),
  [TD_LLAVEI] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_LCBR)),
  [TD_LLAVEC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_RCBR)),
  [TD_PUNTOS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_COLN)),
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
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

   switch (keycode) {
        case MT(MOD_LSFT, KC_CAPS):
            if (record->event.pressed) {
                is_caps_lock_on = !is_caps_lock_on; // Alterna el estado de Caps Lock
                
                if (is_caps_lock_on) {
                    // Activar RGB en rojo si se activa Caps Lock
                    rgblight_sethsv(HSV_RED); // Cambia al color rojo
                    rgblight_mode(RGBLIGHT_MODE_BREATHING + 3); // Ajusta el efecto según tu preferencia
                } else {
                    // Volver al estado normal del RGB al desactivar Caps Lock
                      rgblight_sethsv(85, 255, 255); // Cambia al color rojo
                    rgblight_mode(RGBLIGHT_MODE_BREATHING + 3); // Ajusta el efecto según tu preferencia
                }
            }
            break;
    }
    
  return true;
}
