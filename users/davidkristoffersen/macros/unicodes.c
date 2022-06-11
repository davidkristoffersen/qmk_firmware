// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "macros.h"

#ifdef UNICODE_ENABLE

code_swap_t UNICODE_CODES [] = {
    {KC_AE, 0x00E6},
    {KC_OE, 0x00F8},
    {KC_AA, 0x00E5},
};
code_swap_wrapper_t UNICODE_WRAPPER = { CODES_WRAPPER(UNICODE_CODES) };

// Tap unicode codes
bool handle_unicode(uint16_t keycode) {
    uint16_t swapped_code = get_swapped_code(keycode, &UNICODE_WRAPPER);
    if (swapped_code != keycode) {
        tap_code16(UC(swapped_code));
        // return false
    }
    return true;
}
#endif

bool process_unicodes(uint16_t keycode, keyrecord_t* record) {
#ifdef UNICODE_ENABLE
    HANDLE_FALSE(handle_unicode(keycode));
#endif
    return true;
}
