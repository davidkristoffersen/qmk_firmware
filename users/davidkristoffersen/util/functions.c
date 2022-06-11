// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "functions.h"

#ifndef NO_SPECIAL_SHIFT
#ifdef LAYER_NO
code_swap_t NO_SHIFT_SWAPS [] = {
   {NO_QUOT, NO_DQUO},
   {NO_BSLS, NO_PIPE},
};
#endif

code_swap_t EN_SHIFT_SWAPS [] = {
    {KC_COMM, KC_SCLN},
    {KC_DOT, KC_COLN},
};

// Array of shift code conversions
code_swap_wrapper_t SHIFT_WRAPPER [] = {
#ifdef LAYER_NO
    {.lang = LAYER_NO, CODES_WRAPPER(NO_SHIFT_SWAPS)},
#endif
    {.lang = LAYER_EN, CODES_WRAPPER(EN_SHIFT_SWAPS) }
};
const int SHIFT_WRAPPER_SIZE = ARR_LEN(SHIFT_WRAPPER);
#endif

#ifdef LAYER_NO
// Array of English to Norwegian code translations
code_swap_t EN2NO_SWAPS [] = {
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
code_swap_wrapper_t EN2NO_WRAPPER = { CODES_WRAPPER(EN2NO_SWAPS) };
#endif

// Check if layer is an active default layer
bool is_default_on(int layer) {
    return layer == LAYER_DEFAULT
        ? true
        : layer_state_cmp(default_layer_state, layer);
}

#ifndef NO_SPECIAL_SHIFT
// Get special shifted code
uint16_t get_special_shifted_code(uint16_t keycode) {
    for (int i = 0; i < SHIFT_WRAPPER_SIZE; i++) {
        if (IS_DEFAULT_OFF(SHIFT_WRAPPER[i].lang)) continue;
        uint16_t swapped_code = get_swapped_code(keycode, &SHIFT_WRAPPER[i]);
        if (swapped_code != keycode) return swapped_code;
    }
    return keycode;
}
#endif

#ifdef LAYER_NO
// Get language specific code
uint16_t get_norwegian_code(uint16_t keycode) {
    if (IS_DEFAULT_ON(LAYER_NO)) {
        uint16_t swapped_code = get_swapped_code(keycode, &EN2NO_WRAPPER);
        if (swapped_code != keycode) return swapped_code;
    }
    return keycode;
}
#endif

// Get matching code from set of two codes
uint16_t get_swapped_code(uint16_t keycode, code_swap_wrapper_t* code_wrapper) {
    for (int i = 0; i < code_wrapper->size; i++) {
        if (keycode == code_wrapper->arr[i].pre) {
            return get_mods() & MOD_MASK_SHIFT && code_wrapper->arr[i].shift
                ? code_wrapper->arr[i].shift
                : code_wrapper->arr[i].post;
        }
    }
    return keycode;
}

// Tap unicode hex value
void tap_unicode(uint16_t hex) {
    unicode_input_start();
    register_hex(hex);
    unicode_input_finish();
}
