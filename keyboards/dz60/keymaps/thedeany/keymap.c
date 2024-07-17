#include QMK_KEYBOARD_H
#include <print.h>

#define WINDOWS_LAYER 0
#define MAC_LAYER 1
#define FN_LAYER 2
#define MAC_FN_LAYER 3
#define MACRO_LAYER 4
#define MAC_MACRO_LAYER 5
#define TOGGLE_LAYER 6
#define NUMPAD_LAYER 7

enum custom_keycodes { WINDOWS = SAFE_RANGE, MAC };

uint32_t rgb_mode = 1;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WINDOWS_LAYER] = LAYOUT(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        MO(FN_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RGUI, KC_NO, MO(MACRO_LAYER), KC_RCTL
    ),

    [MAC_LAYER] = LAYOUT(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        MO(MAC_FN_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, KC_RALT, KC_NO, MO(MAC_MACRO_LAYER), KC_RCTL
    ),

    [FN_LAYER] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL,
        KC_NO, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
        KC_NO, RGB_VAI, RGB_VAD, KC_NO, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END, KC_NO, KC_NO,
        _______, KC_NO, KC_NO, KC_NO, BL_TOGG, BL_DEC, BL_INC, BL_STEP, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_NO,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(1), _______
    ),

    [MAC_FN_LAYER] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL,
        KC_NO, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET,
        KC_NO, RGB_VAI, RGB_VAD, KC_NO, KC_NO, LCMD(KC_LEFT), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, LCMD(KC_RIGHT), KC_NO, KC_NO,
        _______, KC_NO, KC_NO, KC_NO, BL_TOGG, BL_DEC, BL_INC, BL_STEP, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_NO,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(1), _______
    ),

    [MACRO_LAYER] = LAYOUT(
        KC_NO, WINDOWS, MAC, TO(NUMPAD_LAYER), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_NO, KC_NO,
        _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_NO,
        _______, _______, _______, KC_NO, KC_NO, KC_NO, _______, _______, KC_NO, KC_NO, _______
    ),

    [MAC_MACRO_LAYER] = LAYOUT(
        KC_NO, WINDOWS, MAC, TO(NUMPAD_LAYER), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCMD(KC_LEFT), KC_LEFT, KC_DOWN, KC_RIGHT, LCMD(KC_RIGHT), KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [NUMPAD_LAYER] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_ENT,
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RGUI, KC_NO, TO(MACRO_LAYER), KC_RCTL
    ),
};

// for use with Mito Godspeed
void underglow_mito_godspeed(void) {
    rgblight_sethsv_noeeprom(80, 8, 80);
}

// for use with Tai Hao Sunshine
void underglow_sunshine(void) {
    uint8_t a;
    uint8_t b;

    for (a = 0; a <= 7; a = a + 1) {
        rgblight_sethsv_at(16, 223, 199, a); // pink
    }
    for (b = 8; b <= 15; b = b + 1) {
        rgblight_sethsv_at(32, 231, 191, b); // orange
    }
}

// for use with Tai Hao Miami
void underglow_miami(void) {
    // rgblight_sethsv_at(72, 119, 183, 1);	// blue
    rgblight_sethsv_at(72, 119, 183, 2); // blue
    rgblight_sethsv_at(72, 119, 183, 3); // blue
    rgblight_sethsv_at(72, 119, 183, 4); // blue
    rgblight_sethsv_at(72, 119, 183, 5); // blue
    // rgblight_sethsv_at(72, 119, 183, 6);	// blue
    // rgblight_sethsv_at(72, 119, 183, 10); // blue
    rgblight_sethsv_at(72, 119, 183, 11); // blue
    rgblight_sethsv_at(72, 119, 183, 12); // blue
    rgblight_sethsv_at(72, 119, 183, 13); // blue

    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 0);  // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 1);  // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 6);  // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 7);  // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 8);  // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 9);  // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 10); // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 14); // pink
    rgblight_sethsv_at(0x00, 0x9F, 0xB7, 15); // pink
}

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    static uint8_t old_layer = 255;
    uint8_t        new_layer = biton32(state);

    if (old_layer != new_layer) {
        uprintf("Layer changed: %d\n", new_layer);
        switch (new_layer) {
            case WINDOWS_LAYER:
            case MAC_LAYER:
                rgblight_mode(rgb_mode);
                // underglow_sunshine();
                // underglow_miami();
                underglow_mito_godspeed();
                break;
            case FN_LAYER:
            case MAC_FN_LAYER:
                rgblight_mode_noeeprom(1);
                break;
            case MACRO_LAYER:
            case MAC_MACRO_LAYER:
                rgblight_setrgb(0xFF, 0x00, 0x00);
                break;
            case TOGGLE_LAYER:
                rgblight_setrgb(0xFF, 0x00, 0xAF);
                break;
            case NUMPAD_LAYER:
                rgblight_setrgb(0x33, 0xEC, 0xFF);
        }
    }
#endif

    old_layer = new_layer;
    return state;
}

// Initialize variable holding the binary
// representation of active modifiers
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    uprintf("mod_state: %d\n", mod_state);

    switch (keycode) {
        case WINDOWS:
            if (record->event.pressed) {
                print("Base layer just switched to Windows\n");
                set_single_persistent_default_layer(WINDOWS_LAYER);
                layer_move(WINDOWS_LAYER);
            }
            return false;
            break;
        case MAC:
            if (record->event.pressed) {
                print("Base layer just switched to macOS\n");
                set_single_persistent_default_layer(MAC_LAYER);
                layer_move(MAC_LAYER);
            }
            return false;
            break;
        case RGB_MOD:
            if (record->event.pressed) {
                // wait for keyup to set the new mode
            } else {
                rgb_mode = rgblight_get_mode();
                uprintf("Changed RGB mode to %d\n", rgb_mode);
            }
            break;
            // 	case RGB_VAI:
            // 	case RGB_VAD:
            // 		if (record->event.pressed)
            // 		{
            // 			// wait for keyup to set the new value
            // 		}
            // 		else
            // 		{
            // #ifdef RGBLIGHT_EFFECT_BREATHE_MAX
            // #undef RGBLIGHT_EFFECT_BREATHE_MAX
            // #endif

            // 			uint8_t value = rgblight_get_val();
            // #define RGBLIGHT_EFFECT_BREATHE_MAX (value)
            // 		}
            // 		break;
            // case KC_BSPC: {
            //     // Initialize a boolean variable that keeps track
            //     // of the delete key status: registered or not?
            //     static bool delkey_registered;
            //     if (record->event.pressed) {
            //         print("Pressed BSPC\n");
            //         // Detect the activation of either shift keys
            //         if (mod_state & MOD_MASK_SHIFT) {
            //             print("Shift key is pressed\n");
            //             // First temporarily canceling both shifts so that
            //             // shift isn't applied to the KC_DEL keycode
            //             del_mods(MOD_MASK_SHIFT);
            //             register_code(KC_DEL);
            //             // Update the boolean variable to reflect the status of KC_DEL
            //             delkey_registered = true;
            //             uprintf("delkey_registered: %b\n", delkey_registered);
            //             // Reapplying modifier state so that the held shift key(s)
            //             // still work even after having tapped the Backspace/Delete key.
            //             set_mods(mod_state);
            //             return false;
            //         }
            //     } else { // on release of KC_BSPC
            //         // In case KC_DEL is still being sent even after the release of KC_BSPC
            //         if (delkey_registered) {
            //             unregister_code(KC_DEL);
            //             delkey_registered = false;
            //             return false;
            //         }
            //     }
            //     // Let QMK process the KC_BSPC keycode as usual outside of shift
            //     return true;
            // }
    }

    // Feature: Both Shifts == Caps Lock
    // Detect the activation of both Shifts
    if ((mod_state & MOD_MASK_SHIFT) == MOD_MASK_SHIFT) {
        // Toggle Caps_lock value
        tap_code(KC_CAPS);
    }

    return true;
}

const uint16_t PROGMEM delete_combo[] = {KC_EQL, KC_BSPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(delete_combo, KC_DEL),
};

void keyboard_post_init_user(void) {
    uprintf("KB Post Init...\nSetting underglow...\n");
    // rgblight_mode_noeeprom(20);
    // _delay_ms(3000);
    // rgblight_mode_noeeprom(1);
    // underglow_sunshine();
    // underglow_miami();
    underglow_mito_godspeed();
}
