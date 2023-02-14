// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "davidkristoffersen.h"

#undef KC_RSPC
#define KC_RSPC KC_SPACE

#undef KC_LSPC
#ifdef SPLIT_SPACE
#   define KC_LSPC LT(NUMPAD, KC_NO)
#else
#   define KC_LSPC KC_SPACE
#endif

void handle_split_space(uint16_t keycode);
