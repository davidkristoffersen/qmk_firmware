// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "macros.h"

// Replace key records with macros
bool handle_test(uint16_t keycode) {
    switch (keycode) {
    case KC_T0: {
        // Test QK_MAKE command
        SEND_STRING("qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
        break;
    }
    case KC_T1:
        // Test ascii characters
        SEND_STRING(" !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
        break;
    case KC_T2:
        // Test other characters
#ifdef LAYER_NO
        if (IS_DEFAULT_ON(LAYER_NO)) {
            tap_code16(NO_AE);
            tap_code16(NO_OE);
            tap_code16(NO_AA);
            tap_code16(S(NO_AE));
            tap_code16(S(NO_OE));
            tap_code16(S(NO_AA));
            return false;
        }
#endif
        tap_unicode(UC_ae);
        tap_unicode(UC_oe);
        tap_unicode(UC_aa);
        tap_unicode(UC_AE);
        tap_unicode(UC_OE);
        tap_unicode(UC_AA);
        return false;
        }
    return true;
    };

bool process_debug(uint16_t keycode, keyrecord_t* record) {
    HANDLE_FALSE(handle_test(keycode));
    return true;
}
