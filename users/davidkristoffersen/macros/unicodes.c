// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "macros.h"

#ifdef UNICODE

code_swap_t UNICODE_SWAPS [] = {
    {KC_AE, UC_ae, UC_AE},
    {KC_OE, UC_oe, UC_OE},
    {KC_AA, UC_aa, UC_AA},
};
code_swap_wrapper_t UNICODE_WRAPPER = { CODES_WRAPPER(UNICODE_SWAPS) };

// Tap unicode codes
bool handle_unicode(uint16_t keycode) {
    if (IS_DEFAULT_OFF(LAYER_EN)) return true;
    uint16_t swapped_code;
    swapped_code = get_swapped_code(keycode, &UNICODE_WRAPPER);
    if (swapped_code != keycode) {
        tap_unicode(swapped_code);
        return false;
    }
    return true;
}
#endif

bool process_unicodes(uint16_t keycode, keyrecord_t* record) {
#ifdef UNICODE
    HANDLE_FALSE(handle_unicode(keycode));
#endif
    return true;
}
