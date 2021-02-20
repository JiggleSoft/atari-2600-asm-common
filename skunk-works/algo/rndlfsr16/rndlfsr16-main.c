/*============================================================================
 * Title:        Pseudo Random Number Generator exerciser application.
 * Algorithm:    Linear Feedback Shift Register (LFSR) 16-bit.
 * Filename:     rndlfsr16-main.c
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


#include "rndlfsr16.h"
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define lengthof(a) (sizeof(a)/sizeof(a[0]))


#define RND_CALLS 65536


static void init_cnt(int * cnts, int count)
{
    for (int i = 0;  i < count;  i++) {
        cnts[i] = 0;
    }
}


static void dump_cnt(int * cnts, int count)
{
    int min = INT_MAX;
    int max = INT_MIN;
    long total = 0L;
    long average = 0L;
    for (int i = 0;  i < count;  i++) {
        //printf("cnts[%d]=%d\n", i, cnts[i]);
        if (cnts[i] < min) {
            min = cnts[i];
        }
        if (cnts[i] > min) {
            max = cnts[i];
        }
        total += cnts[i];
    }
    average = total / count;
    printf("        Count = %d, Min = %d, Max = %d, Total = %ld, Average = %ld\n", count, min, max, total, average);
}


static void test_fix()
{
    puts("    test_fix(): START");
    rnd_state state;
    rnd_init(&state);
    state.sr = UINT16_C(0);
    rnd_fix_sr(&state);
    if (state.sr == UINT16_C(0)) {
        puts("        FAILED!!!");
    }
    if (state.sr != RND_SEED_DEFAULT) {
        puts("        FAILED!!!");
    }
    state.sr = UINT16_C(0x1234);
    rnd_fix_sr(&state);
    if (state.sr == UINT16_C(0)) {
        puts("        FAILED!!!");
    }
    if (state.sr != 0x1234) {
        puts("        FAILED!!!");
    }
    puts("    test_fix(): FINISH");
}


static void test_bit()
{
    puts("    test_bit(): START");

    rnd_state state;
    rnd_init(&state);

    int cnt[2];
    init_cnt(cnt, lengthof(cnt));

    for (int i = 0;  i < RND_CALLS;  i++) {
	uint8_t value = rnd_get_bit(&state);
        cnt[value]++;
    }

    dump_cnt(cnt, lengthof(cnt));

    puts("    test_bit(): FINISH");
}


static void test_bits()
{
    puts("    test_bits(): START");

    rnd_state state;
    rnd_init(&state);

    int cnt[16];
    init_cnt(cnt, lengthof(cnt));

    for (int i = 0;  i < RND_CALLS;  i++) {
	uint8_t value = rnd_get_bits(&state, 4);
        cnt[value]++;
    }

    dump_cnt(cnt, lengthof(cnt));

    puts("    test_bits(): FINISH");
}


static void test_byte()
{
    puts("    test_byte(): START");

    rnd_state state;
    rnd_init(&state);

    int cnt[256];
    init_cnt(cnt, lengthof(cnt));

    for (int i = 0;  i < RND_CALLS;  i++) {
        uint8_t value = rnd_get_byte(&state);
        cnt[value]++;
    }

    dump_cnt(cnt, lengthof(cnt));

    puts("    test_byte(): FINISH");
}


#define PERF_COUNT 1000000


static void performance_byte_std()
{
    puts("    performance_byte_std(): START");

    clock_t start, stop;
    start = clock();
    for (int i = 0;  i < PERF_COUNT;  i++)
    {
        uint8_t val = (uint8_t)(rand() * 255);
    }
    stop = clock();
    double dur = (stop - start) * 1000000 / CLOCKS_PER_SEC;
    printf("        Count = %d, Duration = %9.3f microseconds\n", PERF_COUNT, dur);

    puts("    performance_byte_std(): FINISH");
}


static void performance_byte_lfsr()
{
    puts("    performance_byte_lfsr(): START");

    rnd_state state;
    rnd_init(&state);
    clock_t start, stop;
    start = clock();
    for (int i = 0;  i < PERF_COUNT;  i++)
    {
        uint8_t val = rnd_get_byte(&state);
    }
    stop = clock();
    double dur = (stop - start) * 1000000 / CLOCKS_PER_SEC;
    printf("        Count = %d, Duration = %9.3f microseconds\n", PERF_COUNT, dur);

    puts("    performance_byte_lfsr(): FINISH");
}



int main(int argc, char ** argv)
{
    puts("MAIN: START");
    test_fix();
    test_bit();
    test_bits();
    test_byte();
    performance_byte_std();
    performance_byte_lfsr();
    puts("MAIN: FINISH");
    return 0;
}
