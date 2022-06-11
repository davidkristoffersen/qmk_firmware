// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "davidkristoffersen.h"

// Code swap from pre to post
typedef const struct code_swap {
    uint16_t pre;
    uint16_t post;
} code_swap_t;

// Array of codes to swap with size
typedef const struct code_swap_wrapper {
    const int lang;
    const int size;
    code_swap_t* arr;
} code_swap_wrapper_t;

// Get special shifted code
uint16_t get_special_shifted_code(uint16_t keycode);

// Get language specific code
uint16_t get_norwegian_code(uint16_t keycode);

// Get matching code from array of two codes
uint16_t get_swapped_code(uint16_t keycode, code_swap_wrapper_t* code_arr);
