// Copyright 2022 David Kristoffersen (@davidkristoffersen)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "layouts.h"

/* QGMLWB
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  Q   |  G   |  M   |  L   |  W   |  B   |  Y   |  U   |  V   |  '"  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  D   |  S   |  T   |  N   |  R   |  I   |  A   |  E   |  O   |  H   |Return|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  Z   |  X   |  C   |  F   |  J   |  K   |  P   |  ,;  |  .:  |  -_  |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |NumPad| GUI  | Lower|LSpace|RSpace| Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
*/
// English Layout
// | Ctrl | Alt  |NumPad| GUI  | Lower|LSpace|RSpace| Raise| Left | Down |  Up  | Right|
#define qgmlwb_en_map LAYOUT_ortho_4x12_TRUNCATE(\
    TAB,  Q,    G,    M,    L,    W,    B,    Y,    U,    V,    QUOT, BSPC,\
    ESC,  D,    S,    T,    N,    R,    I,    A,    E,    O,    H,    ENT,\
    LSFT, Z,    X,    C,    F,    J,    K,    P,    COMM, DOT,  MINS, BSLS,\
    LCTL, LALT, NUMP, LGUI, LOWR, LSPC, RSPC, RAIS, LEFT, DOWN, UP,   RIGHT\
)
// Norwegian Layout
#define qgmlwb_no_map qgmlwb_en_map

/* Lower - QGMLWB
 * ,-----------------------------------------------------------------------------------.
 * |  !   |  %   |  [   |  {   |  (   |  <   |  >   |  )   |  }   |  ]   |  &   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  | Mute | XXXX | Refr | XXXX | XXXX | XXXX |  =   |  +   |  *   |  /   |  ~   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Sleep|ScrLck| Caps |NumLck|PrtScr| Ins  | End  | Home |  Æ   |  Ø   |  Å   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Adjust| Bri- | Vol- | Vol+ | Bri+ |
 * `-----------------------------------------------------------------------------------'
*/
#define qgmlwb_lower_map LAYOUT_ortho_4x12_TRUNCATE(\
    EXLM, PERC, LBRC, LCBR, LPRN, LT,   GT,  RPRN, RCBR, RBRC, AMPR, __,\
    DEL,  MUTE, XX,   WREF, XX,   XX,   XX,  EQL,  PLUS, ASTR, SLSH, TILD,\
    __,   SLEP, SLCK, CAPS, NLCK, PSCR, INS, END,  HOME, AE,   OE,   AA,\
    __,   __,   __,   __,   __,   __,   __,  ADJU, BRID, VOLD, VOLU, BRIU\
)

/* Raise - QGMLWB
 * ,-----------------------------------------------------------------------------------.
 * |  ?   |  9   |  7   |  5   |  3   |  1   |  0   |  2   |  4   |  6   |  8   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del+ |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  #   |  @   |  ^   |  $   |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | PgDn | PgUp | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RCtrl| RAlt |      |      |Adjust|      |      |      | Prev | Stop | Play | Next |
 * `-----------------------------------------------------------------------------------'
*/
#define qgmlwb_raise_map LAYOUT_ortho_4x12_TRUNCATE(\
    QUES, 9,  7,  5,  3,    1,   0,   2,    4,    6,    8,    __,\
    DELW, F1, F2, F3, F4,   F5,  F6,  HASH, AT,   CIRC, DLR,  GRV,\
    __,   F7, F8, F9, F10,  F11, F12, PGDN, PGUP, XX,   XX,   XX,\
    __,   __, __, __, ADJU, __,  __,  __,   MPRV, MSTP, MPLY, MNXT\
)
