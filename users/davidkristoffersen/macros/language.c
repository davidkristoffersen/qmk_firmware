// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "macros.h"

#ifdef MULTI_LANGUAGE
// Shift codes conversion struct
typedef struct shift_code {
    uint16_t pre;
    uint16_t post;
    int      lang;
} shift_code_t;

// Array of shift code translations
const shift_code_t SHIFT_CODES [] = {
#ifdef LAYER_NO
    {.lang = LAYER_NO, .pre = KC_QUOT, .post = NO_DQUO},
    {.lang = LAYER_NO, .pre = KC_BSLS, .post = NO_PIPE},
#endif
#ifdef LAYER_EN
    {.lang = LAYER_EN, .pre = KC_COMM, .post = KC_SCLN},
    {.lang = LAYER_EN, .pre = KC_DOT,  .post = KC_COLN},
#endif
};
const int SHIFT_CODES_SIZE = sizeof(SHIFT_CODES) / sizeof(SHIFT_CODES[0]);

#if defined LAYER_EN && defined LAYER_NO
// Array of English to Norwegian code translations
const uint16_t EN_NO_CODES[25][2] = {
    {KC_QUOT, NO_QUOT},
    {KC_MINS, NO_MINS},
    {KC_BSLS, NO_BSLS},
    {KC_LBRC, NO_LBRC},
    {KC_LCBR, NO_LCBR},
    {KC_LPRN, NO_LPRN},
    {KC_LT,   NO_LESS},
    {KC_GT,   NO_GRTR},
    {KC_RPRN, NO_RPRN},
    {KC_RCBR, NO_RCBR},
    {KC_RBRC, NO_RBRC},
    {KC_AMPR, NO_AMPR},
    {KC_EQL,  NO_EQL},
    {KC_PLUS, NO_PLUS},
    {KC_ASTR, NO_ASTR},
    {KC_SLSH, NO_SLSH},
    {KC_TILD, NO_TILD},
    {KC_AE,   NO_AE},
    {KC_OE,   NO_OE},
    {KC_AA,   NO_AA},
    {KC_QUES, NO_QUES},
    {KC_AT,   NO_AT},
    {KC_CIRC, NO_CIRC},
    {KC_DLR,  NO_DLR},
    {KC_GRV,  NO_GRV}
};
const int EN_NO_CODES_SIZE = sizeof(EN_NO_CODES) / sizeof(EN_NO_CODES[0]);
#endif

// Handle conversion of special shift codes
bool handle_shift(uint16_t keycode, keyrecord_t* record) {
    if (get_mods() & MOD_MASK_SHIFT) {
        // Current active language
        int lang = get_language();
        // No action was needed
        if (lang == -1) return true;

        for (int i = 0; i < SHIFT_CODES_SIZE; i++) {
            if (lang == SHIFT_CODES[i].lang && keycode == SHIFT_CODES[i].pre) {
                // Tap new key while shift is disabled
                unregister_code(KC_LSFT);
                tap_code16(SHIFT_CODES[i].post);
                register_code(KC_LSFT);

                return false;
            }
        }
    }
    return true;
}

// Handle conversion of English to Norwegian codes
bool handle_language(uint16_t keycode, keyrecord_t* record) {
#if defined LAYER_EN && defined LAYER_NO
    if (get_language() == LAYER_NO) {
        for (int i = 0; i < EN_NO_CODES_SIZE; i++) {
            if (keycode == EN_NO_CODES[i][0]) {
                // Disable old key and tap the new key
                unregister_code(keycode);
                tap_code16(EN_NO_CODES[i][1]);
                return false;
            }
        }
    }
#endif
    return true;
}

bool process_language(uint16_t keycode, keyrecord_t* record) {
    handle_false(handle_shift(keycode, record));
    handle_false(handle_language(keycode, record));
    return true;
}
#endif
