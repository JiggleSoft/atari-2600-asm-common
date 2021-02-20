/*============================================================================
 * Title:        Pseudo Random Number Generator implementation.
 * Algorithm:    Linear Feedback Shift Register (LFSR) 16-bit.
 * Filename:     rndlfsr16.c
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
 *----------------------------------------------------------------------------
 * Pseudo Random Number Generator - Linear Feedback Shift Register (LFSR) 16-bit.
 *
 * Feedback (F) is calculated with the taps on rnd_sr_lo bits 0, 2, 3, 5.
 * rnd_sr_lo is shifted right and value shifted out of bit 0 is the output stream.
 * rnd_sr_hi is shifted right and the value shifted out of bit 0 goes into bit 7
 * of rnd_sr_hi. The feedback becomes bit 7 of rndval_hi.
 *
 * rnd_sr_hi                            rnd_sr_lo
 * | 7 | 6 | 5 | 4 | 3 | 2 |  1 |  0 |->| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |->| O |
 *   ^                                            |       |   |       |      u
 *   |                                            |       |    \     /       t
 *   |                                            |       |      XOR         p
 *   |                                            |       |       |          u
 *   |                                            |      XOR------           t
 *   |                                            |       |
 * | F |<----------------------------------------XOR------
 * Feedback
 *
 * Get bits will take the lowest n bits from rndval_lo and then run the feedback
 * and shift process n times.
 * Note that the bits taken will be returned will start population of the
 * returned value from bits 0, then 1, etc.
 *----------------------------------------------------------------------------
 */


#include "rndlfsr16.h"
//#include <stdio.h> //DEBUG


void rnd_init(rnd_state * state)
{
    state->sr = RND_SEED_DEFAULT;
    state->value = UINT8_C(0);
}


void rnd_fix_sr(rnd_state * state)
{
    if (!state->sr) {
        state->sr = RND_SEED_DEFAULT;
    }
}


int rnd_calc_fback(rnd_state * state)
{
	uint8_t fback = (state->sr & 0x002D);
	fback = (fback>>3) ^ fback;
	fback = (fback>>2) ^ fback;
	return (fback & 0x0001);
}


void rnd_shift_bit(rnd_state * state, int fback)
{
    state->sr >>= 1;
    if (fback) state->sr |= UINT16_C(0x8000);
}


int rnd_next_bit(rnd_state * state)
{
//uint16_t sr_before = state->sr; //DEBUG
    int value = (state->sr & UINT16_C(0x0001));
    uint8_t fback = rnd_calc_fback(state);
    rnd_shift_bit(state, fback);
//uint16_t sr_after = state->sr; //DEBUG
//printf("SR before = %04x, FB = %d, SR after = %04x, value= %02x\n", sr_before, fback, sr_after, value); //DEBUG
    return value;
}


void rnd_next_bits(rnd_state * state, int number)
{
    for (int i = 0;  i < number;  i++) {
        rnd_next_bit(state);
    }
}


uint8_t rnd_get_bit(rnd_state * state)
{
    return (state->value = rnd_next_bit(state));
}


uint8_t rnd_get_bits(rnd_state * state, int number)
{
    uint8_t value = UINT8_C(0);
    for (int i = 0;  i < number;  i++) {
	value <<= 1;
        value |= rnd_next_bit(state);
    }
    return (state->value = value);
}


uint8_t rnd_get_byte(rnd_state * state)
{
    uint8_t value = (state->sr & UINT16_C(0x00FF));
    rnd_next_bits(state, 8);
    return (state->value = value);
}


