/*============================================================================
 * Title:        Pseudo Random Number Generator exerciser application.
 * Algorithm:    Various Linear Feedback Shift Register (LFSR) Algorithms.
 * Filename:     rnd-main.c
 * Platform:     Any
 * Language:     C
 * Author:       Justin Lane (atari2600@jigglesoft.co.uk)
 * Date:         2021-01-10 18:24
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


#include "rnd.h"
#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define lengthof(a) (sizeof(a)/sizeof(a[0]))




static void init_cnt(unsigned int * cnts, int count)
{
    for (int i = 0;  i < count;  i++) {
        cnts[i] = 0;
    }
}


static void dump_cnt(int * cnts, int count)
{
    unsigned int values = 0;
    unsigned int min = INT_MAX;
    unsigned int max = INT_MIN;
    long total = 0L;
    long average = 0L;
    for (int i = 0;  i < count;  i++) {
        //printf("cnts[%d]=%d\n", i, cnts[i]);
        if (cnts[i] > 0) {
           values++;
        }
        if (cnts[i] < min) {
            min = cnts[i];
        }
        if (cnts[i] > min) {
            max = cnts[i];
        }
        total += cnts[i];
    }
    average = total / count;
    printf("        Count = %d, Values = %d, Coverage = %d percent, Min = %ud, Max = %ud, Total = %ld, Average = %ld\n", count, values, ((values*100)/count), min, max, total, average);
}


/*
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
*/



#define RND_CALLS 256
#define SHOW_GRAPH 0


static void run_rand(const char * name,
                     uint8_t seed,
                     void (*init)(uint8_t * addr, uint8_t seed),
                     uint8_t (*func)(uint8_t * addr))
{
    printf("    run_rand: START of %s\n", name);

    unsigned int cnt[256];
    init_cnt(cnt, lengthof(cnt));

    uint8_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < RND_CALLS;  i++) {
        uint8_t value = (*func)(&random);
        cnt[value]++;
#if SHOW_GRAPH
        printf("%5d=%d: ", i, (int)value);
        for (int j = 0;  j < value;  j+=4) {
            printf(" ");
        }
        puts("*");
#endif
    }

    dump_cnt(cnt, lengthof(cnt));

    printf("    run_rand: FINISH of %s\n", name);
}


static void run_rand_algo(const char * name,
                     uint8_t seed,
                     uint8_t algo,
                     void (*init)(uint8_t * addr, uint8_t seed),
                     uint8_t (*func)(uint8_t * addr, uint8_t algo))
{
    printf("    run_rand: START of %s\n", name);

    unsigned int cnt[256];
    init_cnt(cnt, lengthof(cnt));

    uint8_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < RND_CALLS;  i++) {
        uint8_t value = (*func)(&random, algo);
        cnt[value]++;
#if SHOW_GRAPH
        printf("%5d=%d: ", i, (int)value);
        for (int j = 0;  j < value;  j+=4) {
            printf(" ");
        }
        puts("*");
#endif
    }

    dump_cnt(cnt, lengthof(cnt));

    printf("    run_rand: FINISH of %s\n", name);
}


#define RND_CALLS2 65536
#define SHOW_GRAPH2 0


static void run_rand2(const char * name,
                     uint16_t seed,
                     void (*init)(uint16_t * addr, uint16_t seed),
                     uint16_t (*func)(uint16_t * addr))
{
    printf("    run_rand2: START of %s\n", name);

    unsigned int cnt[65536];
    init_cnt(cnt, lengthof(cnt));

    uint16_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < RND_CALLS2;  i++) {
        uint16_t value = (*func)(&random);
        cnt[value]++;
#if SHOW_GRAPH2
        printf("%5d=%d: ", i, (int)value);
        for (int j = 0;  j < value;  j+=1024) {
            printf(" ");
        }
        puts("*");
#endif
    }

    dump_cnt(cnt, lengthof(cnt));

    printf("    run_rand2: FINISH of %s\n", name);
}


static void run_rand_algo2(const char * name,
                          uint16_t seed,
                          uint16_t algo,
                          void (*init)(uint16_t * addr, uint16_t seed),
                          uint16_t (*func)(uint16_t * addr, uint16_t algo))
{
    printf("    run_rand2: START of %s\n", name);

    unsigned int cnt[65536];
    init_cnt(cnt, lengthof(cnt));

    uint16_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < RND_CALLS2;  i++) {
        uint16_t value = (*func)(&random, algo);
        cnt[value]++;
#if SHOW_GRAPH2
        printf("%5d=%d: ", i, (int)value);
        for (int j = 0;  j < value;  j+=1024) {
            printf(" ");
        }
        puts("*");
#endif
    }

    dump_cnt(cnt, lengthof(cnt));

    printf("    run_rand2: FINISH of %s\n", name);
}



static void perf_rand(int iterations)
{
    for (int i = 0;  i < iterations;  i++) {
        uint8_t val = (uint8_t)(rand() * 255);
    }
}



#define TEST_NEXT_PREV_COUNT 1024


static void test_next_prev(const char * name,
                     uint8_t seed,
                     void (*init)(uint8_t * addr, uint8_t seed),
                     uint8_t (*func_next)(uint8_t * addr),
                     uint8_t (*func_prev)(uint8_t * addr))
{
    printf("    test_next_prev: %s", name);

    int pos = 0;
    int val[TEST_NEXT_PREV_COUNT];

    uint8_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < TEST_NEXT_PREV_COUNT;  i++) {
        uint8_t value = (*func_next)(&random);
        val[i] = value;
    }
    (*func_next)(&random);
    int success = 1;
    for (int i = TEST_NEXT_PREV_COUNT-1; i >= 0;  i--) {
        uint8_t value = (*func_prev)(&random);
        if (value != val[i]) {
            success = 0;
            break;
        }
    }
    if (success) {
        puts(".        SUCCESS.");
    } else {
        puts(".        FAIL...!");
    }
}

static void test_next_prev_algo(const char * name,
                     uint8_t seed,
                     uint8_t algo_next,
                     uint8_t algo_prev,
                     void (*init)(uint8_t * addr, uint8_t seed),
                     uint8_t (*func_next)(uint8_t * addr, uint8_t algo),
                     uint8_t (*func_prev)(uint8_t * addr, uint8_t algo))
{
    printf("    test_next_prev_algo: %s", name);

    int pos = 0;
    int val[TEST_NEXT_PREV_COUNT];

    uint8_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < TEST_NEXT_PREV_COUNT;  i++) {
        uint8_t value = (*func_next)(&random, algo_next);
        val[i] = value;
    }
    (*func_next)(&random, algo_next);
    int success = 1;
    for (int i = TEST_NEXT_PREV_COUNT-1; i >= 0;  i--) {
        uint8_t value = (*func_prev)(&random, algo_prev);
        if (value != val[i]) {
            success = 0;
            break;
        }
    }
    if (success) {
        puts(".        SUCCESS.");
    } else {
        puts(".        FAIL...!");
    }
}


static void test_next_prev2(const char * name,
                           uint16_t seed,
                           void (*init)(uint16_t * addr, uint16_t seed),
                           uint16_t (*func_next)(uint16_t * addr),
                           uint16_t (*func_prev)(uint16_t * addr))
{
    printf("    test_next_prev: %s", name);

    int pos = 0;
    int val[TEST_NEXT_PREV_COUNT];

    uint16_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < TEST_NEXT_PREV_COUNT;  i++) {
        uint16_t value = (*func_next)(&random);
        val[i] = value;
    }
    (*func_next)(&random);
    int success = 1;
    for (int i = TEST_NEXT_PREV_COUNT-1; i >= 0;  i--) {
        uint16_t value = (*func_prev)(&random);
        if (value != val[i]) {
            success = 0;
            break;
        }
    }
    if (success) {
        puts(".        SUCCESS.");
    } else {
        puts(".        FAIL...!");
    }
}

static void test_next_prev_algo2(const char * name,
                                uint16_t seed,
                                uint16_t algo_next,
                                uint16_t algo_prev,
                                void (*init)(uint16_t * addr, uint16_t seed),
                                uint16_t (*func_next)(uint16_t * addr, uint16_t algo),
                                uint16_t (*func_prev)(uint16_t * addr, uint16_t algo))
{
    printf("    test_next_prev_algo: %s", name);

    int pos = 0;
    int val[TEST_NEXT_PREV_COUNT];

    uint16_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < TEST_NEXT_PREV_COUNT;  i++) {
        uint16_t value = (*func_next)(&random, algo_next);
        val[i] = value;
    }
    (*func_next)(&random, algo_next);
    int success = 1;
    for (int i = TEST_NEXT_PREV_COUNT-1; i >= 0;  i--) {
        uint16_t value = (*func_prev)(&random, algo_prev);
        if (value != val[i]) {
            success = 0;
            break;
        }
    }
    if (success) {
        puts(".        SUCCESS.");
    } else {
        puts(".        FAIL...!");
    }
}



#define PERF_COUNT 1000000


static void run_perf_func(const char * name,
                          void (*func)(int iterations))
{
    printf("    run_perf_func: %s", name);

    clock_t start, stop;
    start = clock();

    (*func)(PERF_COUNT);

    stop = clock();
    double dur = (stop - start) * 1000000 / CLOCKS_PER_SEC;
    printf(".        Count = %d, Duration = %9.3f microseconds\n", PERF_COUNT, dur);
}


static void run_perf_rand(const char * name,
                     uint8_t seed,
                     void (*init)(uint8_t * addr, uint8_t seed),
                     uint8_t (*func)(uint8_t * addr))
{
    printf("    run_perf_rand: %s", name);

    clock_t start, stop;
    start = clock();

    uint8_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < PERF_COUNT;  i++) {
        uint8_t value = (*func)(&random);
    }

    stop = clock();
    double dur = (stop - start) * 1000000 / CLOCKS_PER_SEC;
    printf(".        Count = %d, Duration = %9.3f microseconds\n", PERF_COUNT, dur);
}


static void run_perf_rand_algo(const char * name,
                     uint8_t seed,
                     uint8_t algo,
                     void (*init)(uint8_t * addr, uint8_t seed),
                     uint8_t (*func)(uint8_t * addr, uint8_t algo))
{
    printf("    run_perf_rand_algo: %s", name);

    clock_t start, stop;
    start = clock();

    uint8_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < PERF_COUNT;  i++) {
        uint8_t value = (*func)(&random, algo);
    }

    stop = clock();
    double dur = (stop - start) * 1000000 / CLOCKS_PER_SEC;
    printf(".        Count = %d, Duration = %9.3f microseconds\n", PERF_COUNT, dur);
}


static void run_perf_rand2(const char * name,
                          uint16_t seed,
                          void (*init)(uint16_t * addr, uint16_t seed),
                          uint16_t (*func)(uint16_t * addr))
{
    printf("    run_perf_rand: %s", name);

    clock_t start, stop;
    start = clock();

    uint16_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < PERF_COUNT;  i++) {
        uint16_t value = (*func)(&random);
    }

    stop = clock();
    double dur = (stop - start) * 1000000 / CLOCKS_PER_SEC;
    printf(".        Count = %d, Duration = %9.3f microseconds\n", PERF_COUNT, dur);
}


static void run_perf_rand_algo2(const char * name,
                               uint16_t seed,
                               uint16_t algo,
                               void (*init)(uint16_t * addr, uint16_t seed),
                               uint16_t (*func)(uint16_t * addr, uint16_t algo))
{
    printf("    run_perf_rand_algo: %s", name);

    clock_t start, stop;
    start = clock();

    uint16_t random;

    (*init)(&random, seed);

    for (int i = 0;  i < PERF_COUNT;  i++) {
        uint16_t value = (*func)(&random, algo);
    }

    stop = clock();
    double dur = (stop - start) * 1000000 / CLOCKS_PER_SEC;
    printf(".        Count = %d, Duration = %9.3f microseconds\n", PERF_COUNT, dur);
}


#define RUN_RAND_ENABLE 1
#define TEXT_NEXT_PREV_ENABLE 1
#define TEST_PERF_ENABLE 1

#define STD_ENABLE 1
#define XOR_ENABLE 0
#define GAL_ENABLE 1
#define GALX_ENABLE 1
#define GAL2_ENABLE 0
#define GAL2X_ENABLE 0
#define FIB_ENABLE 0
#define FIB2_ENABLE 0
#define PFII_ENABLE 0
//OKAY: #define BAS_ENABLE 0
//DUFF: #define BAS2_ENABLE 1
#define PIC2_ENABLE 0


int main(int argc, char ** argv)
{
    puts("MAIN: START");

#if RUN_RAND_ENABLE

    puts("----------------------------------------------------------------------------");
    puts(" RUN RANDOM FUNCTIONS");
    puts("----------------------------------------------------------------------------");

#if XOR_ENABLE
    // Xorshift 8-bit (1-255)
    run_rand("rnd_xos_next", RND_XOS_SEED_DEFAULT, rnd_xos_init, rnd_xos_next);
    // Xorshift 16-bit (1-65535)
    run_rand("rnd_xos_next", 100, rnd_xos_init, rnd_xos_next);
#endif

#if GAL_ENABLE
    // Galois 8-bit LFSR (1-255)
    run_rand_algo("rnd_gal_next alg0", RND_GAL_SEED_DEFAULT, RND_GAL_ALG0_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg1", RND_GAL_SEED_DEFAULT, RND_GAL_ALG1_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG2_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg3", RND_GAL_SEED_DEFAULT, RND_GAL_ALG3_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg4", RND_GAL_SEED_DEFAULT, RND_GAL_ALG4_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg5", RND_GAL_SEED_DEFAULT, RND_GAL_ALG5_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg6", RND_GAL_SEED_DEFAULT, RND_GAL_ALG6_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg7", RND_GAL_SEED_DEFAULT, RND_GAL_ALG7_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg8", RND_GAL_SEED_DEFAULT, RND_GAL_ALG8_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next alg9", RND_GAL_SEED_DEFAULT, RND_GAL_ALG9_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next algA", RND_GAL_SEED_DEFAULT, RND_GAL_ALGA_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next algB", RND_GAL_SEED_DEFAULT, RND_GAL_ALGB_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next algC", RND_GAL_SEED_DEFAULT, RND_GAL_ALGC_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next algD", RND_GAL_SEED_DEFAULT, RND_GAL_ALGD_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next algE", RND_GAL_SEED_DEFAULT, RND_GAL_ALGE_NEXT, rnd_gal_init, rnd_gal_next);
    run_rand_algo("rnd_gal_next algF", RND_GAL_SEED_DEFAULT, RND_GAL_ALGF_NEXT, rnd_gal_init, rnd_gal_next);

    run_rand_algo("rnd_gal_next2 alg0", RND_GAL_SEED_DEFAULT, RND_GAL_ALG0_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg1", RND_GAL_SEED_DEFAULT, RND_GAL_ALG1_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG2_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg3", RND_GAL_SEED_DEFAULT, RND_GAL_ALG3_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg4", RND_GAL_SEED_DEFAULT, RND_GAL_ALG4_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg5", RND_GAL_SEED_DEFAULT, RND_GAL_ALG5_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg6", RND_GAL_SEED_DEFAULT, RND_GAL_ALG6_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg7", RND_GAL_SEED_DEFAULT, RND_GAL_ALG7_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg8", RND_GAL_SEED_DEFAULT, RND_GAL_ALG8_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 alg9", RND_GAL_SEED_DEFAULT, RND_GAL_ALG9_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 algA", RND_GAL_SEED_DEFAULT, RND_GAL_ALGA_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 algB", RND_GAL_SEED_DEFAULT, RND_GAL_ALGB_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 algC", RND_GAL_SEED_DEFAULT, RND_GAL_ALGC_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 algD", RND_GAL_SEED_DEFAULT, RND_GAL_ALGD_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 algE", RND_GAL_SEED_DEFAULT, RND_GAL_ALGE_NEXT, rnd_gal_init, rnd_gal_next2);
    run_rand_algo("rnd_gal_next2 algF", RND_GAL_SEED_DEFAULT, RND_GAL_ALGF_NEXT, rnd_gal_init, rnd_gal_next2);

    run_rand_algo("rnd_gal_prev alg0", RND_GAL_SEED_DEFAULT, RND_GAL_ALG0_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg1", RND_GAL_SEED_DEFAULT, RND_GAL_ALG1_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG2_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg3", RND_GAL_SEED_DEFAULT, RND_GAL_ALG3_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg4", RND_GAL_SEED_DEFAULT, RND_GAL_ALG4_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg5", RND_GAL_SEED_DEFAULT, RND_GAL_ALG5_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg6", RND_GAL_SEED_DEFAULT, RND_GAL_ALG6_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg7", RND_GAL_SEED_DEFAULT, RND_GAL_ALG7_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg8", RND_GAL_SEED_DEFAULT, RND_GAL_ALG8_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev alg9", RND_GAL_SEED_DEFAULT, RND_GAL_ALG9_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev algA", RND_GAL_SEED_DEFAULT, RND_GAL_ALGA_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev algB", RND_GAL_SEED_DEFAULT, RND_GAL_ALGB_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev algC", RND_GAL_SEED_DEFAULT, RND_GAL_ALGC_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev algD", RND_GAL_SEED_DEFAULT, RND_GAL_ALGD_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev algE", RND_GAL_SEED_DEFAULT, RND_GAL_ALGE_PREV, rnd_gal_init, rnd_gal_prev);
    run_rand_algo("rnd_gal_prev algF", RND_GAL_SEED_DEFAULT, RND_GAL_ALGF_PREV, rnd_gal_init, rnd_gal_prev);

    run_rand_algo("rnd_gal_prev2 alg0", RND_GAL_SEED_DEFAULT, RND_GAL_ALG0_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg1", RND_GAL_SEED_DEFAULT, RND_GAL_ALG1_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG2_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg3", RND_GAL_SEED_DEFAULT, RND_GAL_ALG3_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg4", RND_GAL_SEED_DEFAULT, RND_GAL_ALG4_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg5", RND_GAL_SEED_DEFAULT, RND_GAL_ALG5_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg6", RND_GAL_SEED_DEFAULT, RND_GAL_ALG6_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg7", RND_GAL_SEED_DEFAULT, RND_GAL_ALG7_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg8", RND_GAL_SEED_DEFAULT, RND_GAL_ALG8_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 alg9", RND_GAL_SEED_DEFAULT, RND_GAL_ALG9_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 algA", RND_GAL_SEED_DEFAULT, RND_GAL_ALGA_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 algB", RND_GAL_SEED_DEFAULT, RND_GAL_ALGB_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 algC", RND_GAL_SEED_DEFAULT, RND_GAL_ALGC_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 algD", RND_GAL_SEED_DEFAULT, RND_GAL_ALGD_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 algE", RND_GAL_SEED_DEFAULT, RND_GAL_ALGE_PREV, rnd_gal_init, rnd_gal_prev2);
    run_rand_algo("rnd_gal_prev2 algF", RND_GAL_SEED_DEFAULT, RND_GAL_ALGF_PREV, rnd_gal_init, rnd_gal_prev2);
#endif

#if GALX_ENABLE
    // Galois 8-bit LFSR Extended to Full Range (0-255)
    run_rand_algo("rnd_galx_next alg0", RND_GALX_SEED_DEFAULT, RND_GALX_ALG0_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg1", RND_GALX_SEED_DEFAULT, RND_GALX_ALG1_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG2_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg3", RND_GALX_SEED_DEFAULT, RND_GALX_ALG3_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg4", RND_GALX_SEED_DEFAULT, RND_GALX_ALG4_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg5", RND_GALX_SEED_DEFAULT, RND_GALX_ALG5_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg6", RND_GALX_SEED_DEFAULT, RND_GALX_ALG6_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg7", RND_GALX_SEED_DEFAULT, RND_GALX_ALG7_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg8", RND_GALX_SEED_DEFAULT, RND_GALX_ALG8_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next alg9", RND_GALX_SEED_DEFAULT, RND_GALX_ALG9_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next algA", RND_GALX_SEED_DEFAULT, RND_GALX_ALGA_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next algB", RND_GALX_SEED_DEFAULT, RND_GALX_ALGB_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next algC", RND_GALX_SEED_DEFAULT, RND_GALX_ALGC_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next algD", RND_GALX_SEED_DEFAULT, RND_GALX_ALGD_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next algE", RND_GALX_SEED_DEFAULT, RND_GALX_ALGE_NEXT, rnd_galx_init, rnd_galx_next);
    run_rand_algo("rnd_galx_next algF", RND_GALX_SEED_DEFAULT, RND_GALX_ALGF_NEXT, rnd_galx_init, rnd_galx_next);

    run_rand_algo("rnd_galx_next2 alg0", RND_GALX_SEED_DEFAULT, RND_GALX_ALG0_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg1", RND_GALX_SEED_DEFAULT, RND_GALX_ALG1_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG2_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg3", RND_GALX_SEED_DEFAULT, RND_GALX_ALG3_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg4", RND_GALX_SEED_DEFAULT, RND_GALX_ALG4_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg5", RND_GALX_SEED_DEFAULT, RND_GALX_ALG5_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg6", RND_GALX_SEED_DEFAULT, RND_GALX_ALG6_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg7", RND_GALX_SEED_DEFAULT, RND_GALX_ALG7_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg8", RND_GALX_SEED_DEFAULT, RND_GALX_ALG8_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 alg9", RND_GALX_SEED_DEFAULT, RND_GALX_ALG9_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 algA", RND_GALX_SEED_DEFAULT, RND_GALX_ALGA_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 algB", RND_GALX_SEED_DEFAULT, RND_GALX_ALGB_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 algC", RND_GALX_SEED_DEFAULT, RND_GALX_ALGC_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 algD", RND_GALX_SEED_DEFAULT, RND_GALX_ALGD_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 algE", RND_GALX_SEED_DEFAULT, RND_GALX_ALGE_NEXT, rnd_galx_init, rnd_galx_next2);
    run_rand_algo("rnd_galx_next2 algF", RND_GALX_SEED_DEFAULT, RND_GALX_ALGF_NEXT, rnd_galx_init, rnd_galx_next2);

    run_rand_algo("rnd_galx_prev alg0", RND_GALX_SEED_DEFAULT, RND_GALX_ALG0_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg1", RND_GALX_SEED_DEFAULT, RND_GALX_ALG1_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG2_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg3", RND_GALX_SEED_DEFAULT, RND_GALX_ALG3_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg4", RND_GALX_SEED_DEFAULT, RND_GALX_ALG4_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg5", RND_GALX_SEED_DEFAULT, RND_GALX_ALG5_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg6", RND_GALX_SEED_DEFAULT, RND_GALX_ALG6_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg7", RND_GALX_SEED_DEFAULT, RND_GALX_ALG7_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg8", RND_GALX_SEED_DEFAULT, RND_GALX_ALG8_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev alg9", RND_GALX_SEED_DEFAULT, RND_GALX_ALG9_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev algA", RND_GALX_SEED_DEFAULT, RND_GALX_ALGA_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev algB", RND_GALX_SEED_DEFAULT, RND_GALX_ALGB_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev algC", RND_GALX_SEED_DEFAULT, RND_GALX_ALGC_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev algD", RND_GALX_SEED_DEFAULT, RND_GALX_ALGD_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev algE", RND_GALX_SEED_DEFAULT, RND_GALX_ALGE_PREV, rnd_galx_init, rnd_galx_prev);
    run_rand_algo("rnd_galx_prev algF", RND_GALX_SEED_DEFAULT, RND_GALX_ALGF_PREV, rnd_galx_init, rnd_galx_prev);

    run_rand_algo("rnd_galx_prev2 alg0", RND_GALX_SEED_DEFAULT, RND_GALX_ALG0_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg1", RND_GALX_SEED_DEFAULT, RND_GALX_ALG1_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG2_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg3", RND_GALX_SEED_DEFAULT, RND_GALX_ALG3_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg4", RND_GALX_SEED_DEFAULT, RND_GALX_ALG4_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg5", RND_GALX_SEED_DEFAULT, RND_GALX_ALG5_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg6", RND_GALX_SEED_DEFAULT, RND_GALX_ALG6_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg7", RND_GALX_SEED_DEFAULT, RND_GALX_ALG7_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg8", RND_GALX_SEED_DEFAULT, RND_GALX_ALG8_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 alg9", RND_GALX_SEED_DEFAULT, RND_GALX_ALG9_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 algA", RND_GALX_SEED_DEFAULT, RND_GALX_ALGA_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 algB", RND_GALX_SEED_DEFAULT, RND_GALX_ALGB_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 algC", RND_GALX_SEED_DEFAULT, RND_GALX_ALGC_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 algD", RND_GALX_SEED_DEFAULT, RND_GALX_ALGD_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 algE", RND_GALX_SEED_DEFAULT, RND_GALX_ALGE_PREV, rnd_galx_init, rnd_galx_prev2);
    run_rand_algo("rnd_galx_prev2 algF", RND_GALX_SEED_DEFAULT, RND_GALX_ALGF_PREV, rnd_galx_init, rnd_galx_prev2);
#endif

#if GAL2_ENABLE
    // Galois 16-bit LFSR (1-65535)
    run_rand_algo2("rnd_gal2_next alg", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_NEXT, rnd_gal2_init, rnd_gal2_next);

    run_rand_algo2("rnd_gal2_next2 alg", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_NEXT, rnd_gal2_init, rnd_gal2_next2);

    run_rand_algo2("rnd_gal2_prev alg", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_PREV, rnd_gal2_init, rnd_gal2_prev);

    run_rand_algo2("rnd_gal2_prev2 alg", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_PREV, rnd_gal2_init, rnd_gal2_prev2);
#endif

#if GAL2X_ENABLE
    // Galois 16-bit LFSR Extended to Full Range (0-65535)
    run_rand_algo2("rnd_gal2x_next alg", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_NEXT, rnd_gal2x_init, rnd_gal2x_next);

    run_rand_algo2("rnd_gal2x_next2 alg", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_NEXT, rnd_gal2x_init, rnd_gal2x_next2);

    run_rand_algo2("rnd_gal2x_prev alg", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_PREV, rnd_gal2x_init, rnd_gal2x_prev);

    run_rand_algo2("rnd_gal2x_prev2 alg", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_PREV, rnd_gal2x_init, rnd_gal2x_prev2);
#endif

#if FIB_ENABLE
    // Fibonacci 8-bit LFSR (1-255)
    run_rand("rnd_fib_next", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next);
    run_rand("rnd_fib_prev", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_prev);
    run_rand("rnd_fib_next2", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next2);
    run_rand("rnd_fib_prev2", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_prev2);
#endif

#if FIB2_ENABLE
    // Fibonacci 16-bit LFSR (1-65535)
    run_rand2("rnd_fib2_next", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next);
    run_rand2("rnd_fib2_prev", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_prev);
    run_rand2("rnd_fib2_next2", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next2);
    run_rand2("rnd_fib2_prev2", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_prev2);
#endif

#if PFII_ENABLE
    // Fibonacci 8-bit LFSR (Pitfall II)
    run_rand("rnd_pfii_next", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next);
    run_rand("rnd_pfii_prev", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_prev);
    run_rand("rnd_pfii_next2", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next2);
    run_rand("rnd_pfii_prev2", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_prev2);
#endif

#if BAS_ENABLE
    // Galois 8-bit LFSR (Batari Basic) (1-255) - DUPLICATE OF RND_GAL_ALG7
    run_rand("rnd_bas_next", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next);
    run_rand("rnd_bas_prev", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_prev);
    run_rand("rnd_bas_next2", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next2);
    run_rand("rnd_bas_prev2", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_prev2);
#endif

#if BAS2_ENABLE
    // Galois 16-bit LFSR (Batari Basic) (1-65535)
    run_rand2("rnd_bas2_next", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next);
    run_rand2("rnd_bas2_prev", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_prev);
    run_rand2("rnd_bas2_next2", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next2);
    run_rand2("rnd_bas2_prev2", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_prev2);
#endif

#if PIC2_ENABLE
    // Fibonacci 16-bit LFSR (Ported from Microchip PIC8)
    run_rand2("rnd_pic2_next", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next);
    run_rand2("rnd_pic2_prev", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_prev);
    run_rand2("rnd_pip2_next2", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next2);
    run_rand2("rnd_pic2_prev2", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_prev2);
#endif

#endif

#if TEXT_NEXT_PREV_ENABLE

    puts("----------------------------------------------------------------------------");
    puts(" TEST NEXT AND PREV FUNCTIONS");
    puts("----------------------------------------------------------------------------");

#if XOR_ENABLE
    // Xorshift 8-bit (1-255)
    test_next_prev("rnd_xos", RND_XOS_SEED_DEFAULT, rnd_xos_init, rnd_xos_next, rnd_xos_prev);
    // Xorshift 16-bit (1-65535)
#endif

#if GAL_ENABLE
    // Galois 8-bit LFSR (1-255)
    test_next_prev_algo("rnd_gal alg0", RND_GAL_SEED_DEFAULT, RND_GAL_ALG0_NEXT, RND_GAL_ALG0_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg1", RND_GAL_SEED_DEFAULT, RND_GAL_ALG1_NEXT, RND_GAL_ALG1_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG2_NEXT, RND_GAL_ALG2_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg3", RND_GAL_SEED_DEFAULT, RND_GAL_ALG3_NEXT, RND_GAL_ALG3_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg4", RND_GAL_SEED_DEFAULT, RND_GAL_ALG4_NEXT, RND_GAL_ALG4_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg5", RND_GAL_SEED_DEFAULT, RND_GAL_ALG5_NEXT, RND_GAL_ALG5_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg6", RND_GAL_SEED_DEFAULT, RND_GAL_ALG6_NEXT, RND_GAL_ALG6_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg7", RND_GAL_SEED_DEFAULT, RND_GAL_ALG7_NEXT, RND_GAL_ALG7_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg8", RND_GAL_SEED_DEFAULT, RND_GAL_ALG8_NEXT, RND_GAL_ALG8_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal alg9", RND_GAL_SEED_DEFAULT, RND_GAL_ALG9_NEXT, RND_GAL_ALG9_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal algA", RND_GAL_SEED_DEFAULT, RND_GAL_ALGA_NEXT, RND_GAL_ALGA_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal algB", RND_GAL_SEED_DEFAULT, RND_GAL_ALGB_NEXT, RND_GAL_ALGB_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal algC", RND_GAL_SEED_DEFAULT, RND_GAL_ALGC_NEXT, RND_GAL_ALGC_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal algD", RND_GAL_SEED_DEFAULT, RND_GAL_ALGD_NEXT, RND_GAL_ALGD_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal algE", RND_GAL_SEED_DEFAULT, RND_GAL_ALGE_NEXT, RND_GAL_ALGE_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);
    test_next_prev_algo("rnd_gal algF", RND_GAL_SEED_DEFAULT, RND_GAL_ALGF_NEXT, RND_GAL_ALGF_PREV, rnd_gal_init, rnd_gal_next, rnd_gal_prev);

    test_next_prev_algo("rnd_gal 2 alg0", RND_GAL_SEED_DEFAULT, RND_GAL_ALG0_NEXT, RND_GAL_ALG0_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg1", RND_GAL_SEED_DEFAULT, RND_GAL_ALG1_NEXT, RND_GAL_ALG1_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG2_NEXT, RND_GAL_ALG2_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg3", RND_GAL_SEED_DEFAULT, RND_GAL_ALG3_NEXT, RND_GAL_ALG3_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg4", RND_GAL_SEED_DEFAULT, RND_GAL_ALG4_NEXT, RND_GAL_ALG4_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg5", RND_GAL_SEED_DEFAULT, RND_GAL_ALG5_NEXT, RND_GAL_ALG5_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg6", RND_GAL_SEED_DEFAULT, RND_GAL_ALG6_NEXT, RND_GAL_ALG6_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg7", RND_GAL_SEED_DEFAULT, RND_GAL_ALG7_NEXT, RND_GAL_ALG7_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg8", RND_GAL_SEED_DEFAULT, RND_GAL_ALG8_NEXT, RND_GAL_ALG8_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 alg9", RND_GAL_SEED_DEFAULT, RND_GAL_ALG9_NEXT, RND_GAL_ALG9_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 algA", RND_GAL_SEED_DEFAULT, RND_GAL_ALGA_NEXT, RND_GAL_ALGA_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 algB", RND_GAL_SEED_DEFAULT, RND_GAL_ALGB_NEXT, RND_GAL_ALGB_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 algC", RND_GAL_SEED_DEFAULT, RND_GAL_ALGC_NEXT, RND_GAL_ALGC_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 algD", RND_GAL_SEED_DEFAULT, RND_GAL_ALGD_NEXT, RND_GAL_ALGD_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 algE", RND_GAL_SEED_DEFAULT, RND_GAL_ALGE_NEXT, RND_GAL_ALGE_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
    test_next_prev_algo("rnd_gal 2 algF", RND_GAL_SEED_DEFAULT, RND_GAL_ALGF_NEXT, RND_GAL_ALGF_PREV, rnd_gal_init, rnd_gal_next2, rnd_gal_prev2);
#endif

#if GALX_ENABLE
    // Galois 8-bit LFSR Extended to Full Range (0-255)
    test_next_prev_algo("rnd_galx alg0", RND_GALX_SEED_DEFAULT, RND_GALX_ALG0_NEXT, RND_GALX_ALG0_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg1", RND_GALX_SEED_DEFAULT, RND_GALX_ALG1_NEXT, RND_GALX_ALG1_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG2_NEXT, RND_GALX_ALG2_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg3", RND_GALX_SEED_DEFAULT, RND_GALX_ALG3_NEXT, RND_GALX_ALG3_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg4", RND_GALX_SEED_DEFAULT, RND_GALX_ALG4_NEXT, RND_GALX_ALG4_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg5", RND_GALX_SEED_DEFAULT, RND_GALX_ALG5_NEXT, RND_GALX_ALG5_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg6", RND_GALX_SEED_DEFAULT, RND_GALX_ALG6_NEXT, RND_GALX_ALG6_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg7", RND_GALX_SEED_DEFAULT, RND_GALX_ALG7_NEXT, RND_GALX_ALG7_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg8", RND_GALX_SEED_DEFAULT, RND_GALX_ALG8_NEXT, RND_GALX_ALG8_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx alg9", RND_GALX_SEED_DEFAULT, RND_GALX_ALG9_NEXT, RND_GALX_ALG9_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx algA", RND_GALX_SEED_DEFAULT, RND_GALX_ALGA_NEXT, RND_GALX_ALGA_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx algB", RND_GALX_SEED_DEFAULT, RND_GALX_ALGB_NEXT, RND_GALX_ALGB_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx algC", RND_GALX_SEED_DEFAULT, RND_GALX_ALGC_NEXT, RND_GALX_ALGC_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx algD", RND_GALX_SEED_DEFAULT, RND_GALX_ALGD_NEXT, RND_GALX_ALGD_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx algE", RND_GALX_SEED_DEFAULT, RND_GALX_ALGE_NEXT, RND_GALX_ALGE_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx algF", RND_GALX_SEED_DEFAULT, RND_GALX_ALGF_NEXT, RND_GALX_ALGF_PREV, rnd_galx_init, rnd_galx_next, rnd_galx_prev);
    test_next_prev_algo("rnd_galx 2 alg0", RND_GALX_SEED_DEFAULT, RND_GALX_ALG0_NEXT, RND_GALX_ALG0_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg1", RND_GALX_SEED_DEFAULT, RND_GALX_ALG1_NEXT, RND_GALX_ALG1_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG2_NEXT, RND_GALX_ALG2_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg3", RND_GALX_SEED_DEFAULT, RND_GALX_ALG3_NEXT, RND_GALX_ALG3_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg4", RND_GALX_SEED_DEFAULT, RND_GALX_ALG4_NEXT, RND_GALX_ALG4_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg5", RND_GALX_SEED_DEFAULT, RND_GALX_ALG5_NEXT, RND_GALX_ALG5_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg6", RND_GALX_SEED_DEFAULT, RND_GALX_ALG6_NEXT, RND_GALX_ALG6_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg7", RND_GALX_SEED_DEFAULT, RND_GALX_ALG7_NEXT, RND_GALX_ALG7_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg8", RND_GALX_SEED_DEFAULT, RND_GALX_ALG8_NEXT, RND_GALX_ALG8_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 alg9", RND_GALX_SEED_DEFAULT, RND_GALX_ALG9_NEXT, RND_GALX_ALG9_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 algA", RND_GALX_SEED_DEFAULT, RND_GALX_ALGA_NEXT, RND_GALX_ALGA_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 algB", RND_GALX_SEED_DEFAULT, RND_GALX_ALGB_NEXT, RND_GALX_ALGB_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 algC", RND_GALX_SEED_DEFAULT, RND_GALX_ALGC_NEXT, RND_GALX_ALGC_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 algD", RND_GALX_SEED_DEFAULT, RND_GALX_ALGD_NEXT, RND_GALX_ALGD_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 algE", RND_GALX_SEED_DEFAULT, RND_GALX_ALGE_NEXT, RND_GALX_ALGE_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
    test_next_prev_algo("rnd_galx 2 algF", RND_GALX_SEED_DEFAULT, RND_GALX_ALGF_NEXT, RND_GALX_ALGF_PREV, rnd_galx_init, rnd_galx_next2, rnd_galx_prev2);
#endif

#if GAL2_ENABLE
    // Galois 16-bit LFSR (1-65535)
    test_next_prev_algo2("rnd_gal2 alg0", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_NEXT, RND_GAL2_ALG_PREV, rnd_gal2_init, rnd_gal2_next, rnd_gal2_prev);

    test_next_prev_algo2("rnd_gal2 2 alg0", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_NEXT, RND_GAL2_ALG_PREV, rnd_gal2_init, rnd_gal2_next2, rnd_gal2_prev2);
#endif

#if GAL2X_ENABLE
    // Galois 16-bit LFSR Extended to Full Range (0-65535)
    test_next_prev_algo2("rnd_gal2x alg0", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_NEXT, RND_GAL2X_ALG_PREV, rnd_gal2x_init, rnd_gal2x_next, rnd_gal2x_prev);

    test_next_prev_algo2("rnd_gal2x 2 alg0", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_NEXT, RND_GAL2X_ALG_PREV, rnd_gal2x_init, rnd_gal2x_next2, rnd_gal2x_prev2);
#endif

#if FIB_ENABLE
    // Fibonacci 8-bit LFSR (1-255)
    test_next_prev("rnd_fib_next", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next, rnd_fib_prev);
    test_next_prev("rnd_fib_prev", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next, rnd_fib_prev);
    test_next_prev("rnd_fib_next2", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next2, rnd_fib_prev2);
    test_next_prev("rnd_fib_prev2", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next2, rnd_fib_prev2);
#endif

#if FIB2_ENABLE
    // Fibonacci 16-bit LFSR (1-65535)
    test_next_prev2("rnd_fib2_next", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next, rnd_fib2_prev);
    test_next_prev2("rnd_fib2_prev", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next, rnd_fib2_prev);
    test_next_prev2("rnd_fib2_next2", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next2, rnd_fib2_prev2);
    test_next_prev2("rnd_fib2_prev2", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next2, rnd_fib2_prev2);
#endif

#if PFII_ENABLE
    // Fibonacci 8-bit LFSR (Pitfall II)
    test_next_prev("rnd_pfii_next", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next, rnd_pfii_prev);
    test_next_prev("rnd_pfii_prev", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next, rnd_pfii_prev);
    test_next_prev("rnd_pfii_next2", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next2, rnd_pfii_prev2);
    test_next_prev("rnd_pfii_prev2", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next2, rnd_pfii_prev2);
#endif

#if BAS_ENABLE
    // Galois 8-bit LFSR (Batari Basic) (1-255) - DUPLICATE OF RND_GAL_ALG7
    test_next_prev("rnd_bas_next", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next, rnd_bas_prev);
    test_next_prev("rnd_bas_prev", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next, rnd_bas_prev);
    test_next_prev("rnd_bas_next2", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next2, rnd_bas_prev2);
    test_next_prev("rnd_bas_prev2", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next2, rnd_bas_prev2);
#endif

#if BAS2_ENABLE
    // Galois 16-bit LFSR (Batari Basic) (1-65535)
    test_next_prev2("rnd_bas2_next", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next, rnd_bas2_prev);
    test_next_prev2("rnd_bas2_prev", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next, rnd_bas2_prev);
    test_next_prev2("rnd_bas2_next2", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next2, rnd_bas2_prev2);
    test_next_prev2("rnd_bas2_prev2", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next2, rnd_bas2_prev2);
#endif

#if PIC2_ENABLE
    // Fibonacci 16-bit LFSR (Ported from Microchip PIC8)
    test_next_prev2("rnd_pic2_next", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next, rnd_pic2_prev);
    test_next_prev2("rnd_pic2_prev", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next, rnd_pic2_prev);
    test_next_prev2("rnd_pic2_next2", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next2, rnd_pic2_prev2);
    test_next_prev2("rnd_pic2_prev2", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next2, rnd_pic2_prev2);
#endif

#endif

#if TEST_PERF_ENABLE

    puts("----------------------------------------------------------------------------");
    puts(" TEST PERFORMANCE OF FUNCTIONS");
    puts("----------------------------------------------------------------------------");

#if STD_ENABLE
    // Standard Library rand() Function
    run_perf_func("std.rand", perf_rand);
#endif

#if XOR_ENABLE
    // Xorshift 8-bit (1-255)
    run_perf_rand("rnd_xos_next", RND_XOS_SEED_DEFAULT, rnd_xos_init, rnd_xos_next);
    // Xorshift 16-bit (1-65535)
    run_perf_rand2("rnd_xos2_next", RND_XOS2_SEED_DEFAULT, rnd_xos2_init, rnd_xos2_next);
#endif

#if GAL_ENABLE
    // Galois 8-bit LFSR (1-255)
    run_perf_rand_algo("rnd_gal_next", RND_GAL_SEED_DEFAULT, RND_GAL_ALG_NEXT, rnd_gal_init, rnd_gal_next);
    run_perf_rand_algo("rnd_gal_next2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG_NEXT, rnd_gal_init, rnd_gal_next2);
    run_perf_rand_algo("rnd_gal_prev", RND_GAL_SEED_DEFAULT, RND_GAL_ALG_PREV, rnd_gal_init, rnd_gal_prev);
    run_perf_rand_algo("rnd_gal_prev2", RND_GAL_SEED_DEFAULT, RND_GAL_ALG_PREV, rnd_gal_init, rnd_gal_prev2);
#endif

#if GALX_ENABLE
    // Galois 8-bit LFSR Extended to Full Range (0-255)
    run_perf_rand_algo("rnd_galx_next", RND_GALX_SEED_DEFAULT, RND_GALX_ALG_NEXT, rnd_galx_init, rnd_galx_next);
    run_perf_rand_algo("rnd_galx_next2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG_NEXT, rnd_galx_init, rnd_galx_next2);
    run_perf_rand_algo("rnd_galx_prev", RND_GALX_SEED_DEFAULT, RND_GALX_ALG_PREV, rnd_galx_init, rnd_galx_prev);
    run_perf_rand_algo("rnd_galx_prev2", RND_GALX_SEED_DEFAULT, RND_GALX_ALG_PREV, rnd_galx_init, rnd_galx_prev2);
#endif

#if GAL2_ENABLE
    // Galois 16-bit LFSR (1-65535)
    run_perf_rand_algo2("rnd_gal2_next", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_NEXT, rnd_gal2_init, rnd_gal2_next);
    run_perf_rand_algo2("rnd_gal2_next2", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_NEXT, rnd_gal2_init, rnd_gal2_next2);
    run_perf_rand_algo2("rnd_gal2_prev", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_PREV, rnd_gal2_init, rnd_gal2_prev);
    run_perf_rand_algo2("rnd_gal2_prev2", RND_GAL2_SEED_DEFAULT, RND_GAL2_ALG_PREV, rnd_gal2_init, rnd_gal2_prev2);
#endif

#if GAL2X_ENABLE
    // Galois 16-bit LFSR Extended to Full Range (0-65535)
    run_perf_rand_algo2("rnd_gal2x_next", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_NEXT, rnd_gal2x_init, rnd_gal2x_next);
    run_perf_rand_algo2("rnd_gal2x_next2", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_NEXT, rnd_gal2x_init, rnd_gal2x_next2);
    run_perf_rand_algo2("rnd_gal2x_prev", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_PREV, rnd_gal2x_init, rnd_gal2x_prev);
    run_perf_rand_algo2("rnd_gal2x_prev2", RND_GAL2X_SEED_DEFAULT, RND_GAL2X_ALG_PREV, rnd_gal2x_init, rnd_gal2x_prev2);
#endif

#if FIB_ENABLE
    // Fibonacci 8-bit LFSR (1-255)
    run_perf_rand("rnd_fib_next", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next);
    run_perf_rand("rnd_fib_next2", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_next2);
    run_perf_rand("rnd_fib_prev", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_prev);
    run_perf_rand("rnd_fib_prev2", RND_FIB_SEED_DEFAULT, rnd_fib_init, rnd_fib_prev2);
#endif

#if FIB2_ENABLE
    // Fibonacci 16-bit LFSR (1-65535)
    run_perf_rand2("rnd_fib2_next", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next);
    run_perf_rand2("rnd_fib2_next2", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_next2);
    run_perf_rand2("rnd_fib2_prev", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_prev);
    run_perf_rand2("rnd_fib2_prev2", RND_FIB2_SEED_DEFAULT, rnd_fib2_init, rnd_fib2_prev2);
#endif

#if PFII_ENABLE
    // Fibonacci 8-bit LFSR (Pitfall II)
    run_perf_rand("rnd_pfii_next", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next);
    run_perf_rand("rnd_pfii_next2", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_next2);
    run_perf_rand("rnd_pfii_prev", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_prev);
    run_perf_rand("rnd_pfii_prev2", RND_PFII_SEED_DEFAULT, rnd_pfii_init, rnd_pfii_prev2);
#endif

#if BAS_ENABLE
    // Galois 8-bit LFSR (Batari Basic) (1-255) - DUPLICATE OF RND_GAL_ALG7
    run_perf_rand("rnd_bas_next", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next);
    run_perf_rand("rnd_bas_next2", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_next2);
    run_perf_rand("rnd_bas_prev", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_prev);
    run_perf_rand("rnd_bas_prev2", RND_BAS_SEED_DEFAULT, rnd_bas_init, rnd_bas_prev2);
#endif

#if BAS2_ENABLE
    // Galois 16-bit LFSR (Batari Basic) (1-65535)
    run_perf_rand2("rnd_bas2_next", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next);
    run_perf_rand2("rnd_bas2_next2", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_next2);
    run_perf_rand2("rnd_bas2_prev", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_prev);
    run_perf_rand2("rnd_bas2_prev2", RND_BAS2_SEED_DEFAULT, rnd_bas2_init, rnd_bas2_prev2);
#endif

#if PIC2_ENABLE
    // Fibonacci 16-bit LFSR (Ported from Microchip PIC8)
    run_perf_rand2("rnd_pic2_next", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next);
    run_perf_rand2("rnd_pic2_next2", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_next2);
    run_perf_rand2("rnd_pic2_prev", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_prev);
    run_perf_rand2("rnd_pic2_prev2", RND_PIC2_SEED_DEFAULT, rnd_pic2_init, rnd_pic2_prev2);
#endif

#endif

    puts("MAIN: FINISH");
    return 0;
}
