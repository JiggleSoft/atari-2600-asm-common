/*============================================================================
 * Title:        Pseudo Random Number Generator include header file.
 * Algorithm:    Linear Feedback Shift Register (LFSR) 16-bit.
 * Filename:     rndlfsr16.h
 * Platform:     Any
 * Language:     C
 * Author:       Justin Lane (atari2600@jigglesoft.co.uk)
 * Date:         2021-01-02 20:31
 * Version:      2.0.0
 * Note:         Ported from Microchip PIC8 implementation.
 *----------------------------------------------------------------------------
 * Copyright (c) 2021 Justin Lane
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------
 */


#ifndef __RNDLFSR16__H__
#define __RNDLFSR16__H__


#include <stdint.h>


#define RND_SEED_DEFAULT INT16_C(0xACE1)


typedef struct {
    uint16_t     sr;
    uint8_t      value;
} rnd_state;


void rnd_init(rnd_state * state);

void rnd_fix_sr(rnd_state * state);

int rnd_next_bit(rnd_state * state);

void rnd_next_bits(rnd_state * state, int number);

uint8_t rnd_get_bit(rnd_state * state);

uint8_t rnd_get_bits(rnd_state * state, int number);

uint8_t rnd_get_byte(rnd_state * state);


#endif /* __RNDLFSR16__H__ */


