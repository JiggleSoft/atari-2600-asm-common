/*============================================================================
 * Title:        Missile Aiming 2D Vector Calculator include header file.
 * Algorithm:    Calculate specific magnitude vector between two co-ordinates.
 * Filename:     aim.h
 * Platform:     Any
 * Language:     C
 * Author:       Justin Lane (atari2600@jigglesoft.co.uk)
 * Date:         2021-01-02 20:31
 * Version:      2.0.0
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


#ifndef __AIM__H__
#define __AIM__H__


#include <stdint.h>


typedef enum { XPOS_YPOS, XNEG_YPOS, XNEG_YNEG, XPOS_YNEG } Quadrant;


typedef struct {
    int bit_count;  // Bits in use for the data size.

    int frac_bits;  // Fractional bits within the data entries.

    int data_size;  // Number of entries within the data.

    int8_t *data;   // The data.
} aim_table;


typedef struct {
    int bit_count;  // Number of bits of precision. Value copied from the aim_table.

    int frac_bits;  // Fractional bits within vector tables data entries. Value copied from the aim_table.

    int data_size;  // Number of data entries in the aim table. Value copied from the aim_table.

    uint8_t x1;     // From X co-ordinate.
    uint8_t y1;     // From Y co-ordinate.

    uint8_t x2;     // To X co-ordinate.
    uint8_t y2;     // To Y co-ordinate.

    int16_t dx;     // Delta X (x2 - x1).
    int16_t dy;     // Delta Y (y2 - y1).

    uint8_t adx;    // Absolute delta X.
    uint8_t ady;    // Absolute delta Y.

    Quadrant quad;  // Quadrant.

    uint8_t sadx;   // Scaled absolute delta X to fit within table size.
    uint8_t sady;   // Scaled absolute delta Y to fit within table size.

    int8_t vecx;    // Vector X from the table.
    int8_t vecy;    // Vector Y from the table.
} aim_calculation;


void aim_init(rnd_table * state, int bit_count, int frac_bits);

void aim_done(aim_table * state);

void aim_calc(aim_table * state, uint8_t x1, uint8_t x1, uint8_t x1, uint8_t x1, aim_calculation * calcs); // calcs okay to be null.



#endif /* __AIM__H__ */


