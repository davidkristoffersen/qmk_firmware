// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "davidkristoffersen.h"

// Default layer if none is specified
#define LAYER_DEFAULT -1

// Check if layer is an active default layer
#define IS_DEFAULT_ON(layer) is_default_on(layer)
// Check if layer is an inactive default layer
#define IS_DEFAULT_OFF(layer) !is_default_on(layer)

// Return false if test equal false
#define HANDLE_FALSE(bool) if (!bool) return false;
// Generic array lenght define
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr)[0])
// Printf-like functionality for send_string
#define SEND_VAR(str, ...) \
    do { \
        char var[128]; \
        sprintf(var, str, __VA_ARGS__); \
        send_string(var); \
    } while(0)

#define CONST_STRUCT(TYPE) typedef const struct TYPE TYPE##_t
#define CONST_WRAPPER(TYPE) typedef const struct TYPE##_wrapper { \
        const int size; \
        TYPE##_t* arr; \
    } TYPE##_arr_t
#define CODES_WRAPPER(CODES) .size = ARR_LEN(CODES), .arr = CODES

// Unicode characters
#define UC_AE 0x00C6 // Æ
#define UC_OE 0x00D8 // Ø
#define UC_AA 0x00C5 // Å

#define UC_ae 0x00E6 // æ
#define UC_oe 0x00F8 // ø
#define UC_aa 0x00E5 // å
