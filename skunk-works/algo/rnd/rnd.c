/*============================================================================
 * Title:        Pseudo Random Number Generator implementation.
 * Algorithm:    Various Linear Feedback Shift Register (LFSR) Algorithms.
 * Filename:     rnd.c
 * Platform:     Any
 * Language:     C
 * Author:       Justin Lane (atari2600@jigglesoft.co.uk)
 * Date:         2021-01-10 18:22
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
 *----------------------------------------------------------------------------
 */


#include "rnd.h"
#include <stdio.h> //DEBUG



// Xorshift 8-bit (1-255)

void rnd_xos_init(rnd_xos * addr, uint8_t seed)
{
    puts("            ERROR: rnd_xos_* - NOT IMPLEMENTED OR WORKING!");
    *addr = (seed == RND_XOS_SEED_INVALID) ? RND_XOS_SEED_DEFAULT : seed;
}


void rnd_xos_fix(rnd_xos * addr, uint8_t seed)
{
    if (*addr == RND_XOS_SEED_INVALID) {
        rnd_xos_init(addr, seed);
    }
}


uint8_t rnd_xos_next(rnd_xos * addr)
{
	uint8_t value = *addr;

    	uint8_t carry = (value & UINT8_C(0x01)) ? UINT8_C(0x80) : UINT8_C(0x00);
    	value = ((value >> 1) | carry) ^ 0xB5;
        
	return (*addr = value);
}


uint8_t rnd_xos_next2(rnd_xos * addr)
{
    rnd_xos_next(addr);
    return rnd_xos_next(addr);
}


uint8_t rnd_xos_prev(rnd_xos * addr)
{
	uint8_t value = *addr;


	return (*addr = value);
}


uint8_t rnd_xos_prev2(rnd_xos * addr)
{
    rnd_xos_prev(addr);
    return rnd_xos_prev(addr);
}



// Xorshift 16-bit (1-65535)

void rnd_xos2_init(rnd_xos2 * addr, uint16_t seed)
{
    puts("            ERROR: rnd_xos2_* - NOT IMPLEMENTED OR WORKING!");
    *addr = (seed == RND_XOS2_SEED_INVALID) ? RND_XOS2_SEED_DEFAULT : seed;
}


void rnd_xos2_fix(rnd_xos2 * addr, uint16_t seed)
{
    if (*addr == RND_XOS2_SEED_INVALID) {
        rnd_xos2_init(addr, seed);
    }
}


uint16_t rnd_xos2_next(rnd_xos2 * addr)
{
    uint8_t value = *addr;

    uint16_t carry = (value & UINT16_C(0x0001)) ? UINT16_C(0x8000) : UINT16_C(0x0000);
    value = ((value >> 1) | carry) ^ 0xB5;

    return (*addr = value);
}


uint16_t rnd_xos2_next2(rnd_xos2 * addr)
{
    rnd_xos2_next(addr);
    return rnd_xos2_next(addr);
}


uint16_t rnd_xos2_prev(rnd_xos2 * addr)
{
    uint16_t value = *addr;


    return (*addr = value);
}


uint16_t rnd_xos2_prev2(rnd_xos2 * addr)
{
    rnd_xos2_prev(addr);
    return rnd_xos2_prev(addr);
}



// Galois 8-bit LFSR (1-255)

void rnd_gal_init(rnd_gal * addr, uint8_t seed)
{
    *addr = (seed == RND_GAL_SEED_INVALID) ? RND_GAL_SEED_DEFAULT : seed;
}


void rnd_gal_fix(rnd_gal * addr, uint8_t seed)
{
    if (*addr == RND_GAL_SEED_INVALID) {
        rnd_gal_init(addr, seed);
    }
}


uint8_t rnd_gal_next(rnd_gal * addr, uint8_t algo)
{
    uint8_t value = *addr;

    uint8_t carry = (value & UINT8_C(0x01)) ? UINT8_C(0x80) : UINT8_C(0x00);
    value >>= 1;
    if (carry) {
        value ^= algo;
    }

    return (*addr = value);
}


uint8_t rnd_gal_next2(rnd_gal * addr, uint8_t algo)
{
    rnd_gal_next(addr, algo);
    return rnd_gal_next(addr, algo);
}


uint8_t rnd_gal_prev(rnd_gal * addr, uint8_t algo)
{
    uint8_t value = *addr;

    uint8_t carry = (value & UINT8_C(0x80)) ? UINT8_C(0x01) : UINT8_C(0x00);
    value <<= 1;
    if (carry) {
        value ^= algo;
    }

    return (*addr = value);
}


uint8_t rnd_gal_prev2(rnd_gal * addr, uint8_t algo)
{
    rnd_gal_prev(addr, algo);
    return rnd_gal_prev(addr, algo);
}



// Galois 8-bit LFSR Extended to Full Range (0-255)

void rnd_galx_init(rnd_galx * addr, uint8_t seed)
{
    *addr = seed;
}


void rnd_galx_fix(rnd_galx * addr, uint8_t seed)
{
}


uint8_t rnd_galx_next(rnd_galx * addr, uint8_t algo)
{
    uint8_t value = *addr;

    if (value == UINT8_C(0)) {
        value ^= algo;
        return (*addr = value);
    } else if (value == UINT8_C(~algo)) {
        value = 0x00;
        return (*addr = value);
    }
    uint8_t carry = (value & UINT8_C(0x01)) ? UINT8_C(0x80) : UINT8_C(0x00);
    value >>= 1;
    if (carry && value) {
        value ^= algo;
    }

    return (*addr = value);
}


uint8_t rnd_galx_next2(rnd_galx * addr, uint8_t algo)
{
    rnd_galx_next(addr, algo);
    return rnd_galx_next(addr, algo);
}


uint8_t rnd_galx_prev(rnd_galx * addr, uint8_t algo)
{
    uint8_t value = *addr;

    if (value == UINT8_C(~algo)) {
        value = 0x00;
        return (*addr = value);
    } else if (value == UINT8_C(0)) {
        value ^= algo;
        return (*addr = value);
    }
    uint8_t carry = (value & UINT8_C(0x80)) ? UINT8_C(0x01) : UINT8_C(0x00);
    value <<= 1;
    if (carry) {
        value ^= algo;
    }

    return (*addr = value);
}


uint8_t rnd_galx_prev2(rnd_galx * addr, uint8_t algo)
{
    rnd_galx_prev(addr, algo);
    return rnd_galx_prev(addr, algo);
}



// Galois 16-bit LFSR (1-65535)

void rnd_gal2_init(rnd_gal2 * addr, uint16_t seed)
{
    puts("            ERROR: rnd_gal2_* - NOT IMPLEMENTED OR WORKING!");
    *addr = (seed == RND_GAL2_SEED_INVALID) ? RND_GAL2_SEED_DEFAULT : seed;
}


void rnd_gal2_fix(rnd_gal2 * addr, uint16_t seed)
{
    if (*addr == RND_GAL2_SEED_INVALID) {
        rnd_gal2_init(addr, seed);
    }
}


uint16_t rnd_gal2_next(rnd_gal2 * addr, uint16_t algo)
{
	uint16_t value = *addr;

    	uint16_t carry = (value & UINT16_C(0x0001)) ? UINT16_C(0x8000) : UINT16_C(0x0000);
    	value >>= 1;
        if (carry) {
 		value ^= algo;
	}
        
	return (*addr = value);
}


uint16_t rnd_gal2_next2(rnd_gal2 * addr, uint16_t algo)
{
    rnd_gal2_next(addr, algo);
    return rnd_gal2_next(addr, algo);
}


uint16_t rnd_gal2_prev(rnd_gal2 * addr, uint16_t algo)
{
	uint16_t value = *addr;

    	uint16_t carry = (value & UINT16_C(0x8000)) ? UINT16_C(0x0001) : UINT16_C(0x0000);
    	value <<= 1;
        if (carry) {
 		value ^= algo;
	}

	return (*addr = value);
}


uint16_t rnd_gal2_prev2(rnd_gal2 * addr, uint16_t algo)
{
    rnd_gal2_prev(addr, algo);
    return rnd_gal2_prev(addr, algo);
}



// Galois 16-bit LFSR Extended to Full Range (0-65535)

void rnd_gal2x_init(rnd_gal2x * addr, uint16_t seed)
{
    puts("            ERROR: rnd_gal2x_* - NOT IMPLEMENTED OR WORKING!");
    *addr = seed;
}


void rnd_gal2x_fix(rnd_gal2x * addr, uint16_t seed)
{
}


uint16_t rnd_gal2x_next(rnd_gal2x * addr, uint16_t algo)
{
	uint16_t value = *addr;

        if (value == UINT16_C(0)) {
 		value ^= algo;
	        return (*addr = value);
        } else if (value == UINT16_C(~algo)) {
		value = 0x00;
	        return (*addr = value);
	}
    	uint16_t carry = (value & UINT16_C(0x01)) ? UINT16_C(0x160) : UINT16_C(0x00);
    	value >>= 1;
        if (carry && value) {
 		value ^= algo;
	}
        
	return (*addr = value);
}


uint16_t rnd_gal2x_next2(rnd_gal2x * addr, uint16_t algo)
{
    rnd_gal2x_next(addr, algo);
    return rnd_gal2x_next(addr, algo);
}


uint16_t rnd_gal2x_prev(rnd_gal2x * addr, uint16_t algo)
{
	uint16_t value = *addr;

        if (value == UINT16_C(~algo)) {
		value = 0x00;
	        return (*addr = value);
        } else if (value == UINT16_C(0)) {
 		value ^= algo;
	        return (*addr = value);
        }
    	uint16_t carry = (value & UINT16_C(0x160)) ? UINT16_C(0x01) : UINT16_C(0x00);
    	value <<= 1;
        if (carry) {
 		value ^= algo;
	}

	return (*addr = value);
}


uint16_t rnd_gal2x_prev2(rnd_gal2x * addr, uint16_t algo)
{
    rnd_gal2x_prev(addr, algo);
    return rnd_gal2x_prev(addr, algo);
}



// Fibonacci 8-bit LFSR (1-255)

void rnd_fib_init(rnd_fib * addr, uint8_t seed)
{
    puts("            ERROR: rnd_fib_* - NOT IMPLEMENTED OR WORKING!");
    *addr = (seed == RND_FIB_SEED_INVALID) ? RND_FIB_SEED_DEFAULT : seed;
}


void rnd_fib_fix(rnd_fib * addr, uint8_t seed)
{
    if (*addr == RND_FIB_SEED_INVALID) {
        rnd_fib_init(addr, seed);
    }
}


uint8_t rnd_fib_next(rnd_fib * addr)
{
	uint8_t value = *addr;

    	//uint8_t carry = (value & UINT8_C(0x01)) ? UINT8_C(0x80) : UINT8_C(0x00);
    	//value = ((value >> 1) | carry) ^ 0xB5;
        
	return (*addr = value);
}


uint8_t rnd_fib_next2(rnd_fib * addr)
{
    rnd_fib_next(addr);
    return rnd_fib_next(addr);
}


uint8_t rnd_fib_prev(rnd_fib * addr)
{
	uint8_t value = *addr;


	return (*addr = value);
}


uint8_t rnd_fib_prev2(rnd_fib * addr)
{
    rnd_fib_prev(addr);
    return rnd_fib_prev(addr);
}



// Fibonacci 16-bit LFSR (1-65536)

void rnd_fib2_init(rnd_fib2 * addr, uint16_t seed)
{
    puts("            ERROR: rnd_fib2_* - NOT IMPLEMENTED OR WORKING!");
    *addr = (seed == RND_FIB2_SEED_INVALID) ? RND_FIB2_SEED_DEFAULT : seed;
}


void rnd_fib2_fix(rnd_fib2 * addr, uint16_t seed)
{
    if (*addr == RND_FIB2_SEED_INVALID) {
        rnd_fib2_init(addr, seed);
    }
}


uint16_t rnd_fib2_next(rnd_fib2 * addr)
{
    uint16_t value = *addr;

    //uint8_t carry = (value & UINT8_C(0x01)) ? UINT8_C(0x80) : UINT8_C(0x00);
    //value = ((value >> 1) | carry) ^ 0xB5;

    return (*addr = value);
}


uint16_t rnd_fib2_next2(rnd_fib2 * addr)
{
    rnd_fib2_next(addr);
    return rnd_fib2_next(addr);
}


uint16_t rnd_fib2_prev(rnd_fib2 * addr)
{
    uint16_t value = *addr;


    return (*addr = value);
}


uint16_t rnd_fib2_prev2(rnd_fib2 * addr)
{
    rnd_fib2_prev(addr);
    return rnd_fib2_prev(addr);
}



// Fibonacci 8-bit LFSR (Pitfall II) (1-255)

void rnd_pfii_init(rnd_pfii * addr, uint8_t seed)
{
    puts("            ERROR: rnd_pfii_* - NOT IMPLEMENTED OR WORKING!");
    *addr = (seed == RND_PFII_SEED_INVALID) ? RND_PFII_SEED_DEFAULT : seed;
}


void rnd_pfii_fix(rnd_pfii * addr, uint8_t seed)
{
    if (*addr == RND_PFII_SEED_INVALID) {
        rnd_pfii_init(addr, seed);
    }
}


uint8_t rnd_pfii_next(rnd_pfii * addr)
{
	uint8_t value = *addr;

        uint8_t carry = (value << 1) ^ value;
        carry = (carry << 1) ^ value;
        carry = (carry << 2) ^ value;
        carry <<= 1;
    	carry = (carry & UINT8_C(0x80)) ? UINT8_C(0x01) : UINT8_C(0x00);
    	value = ((value << 1) | carry);
        
                //LDA             addr
                //ASL
                //EOR             addr
                //ASL
                //EOR             addr
                //ASL
                //ASL
                //EOR             addr
                //ASL
                //ROL             addr
                //RND_SET_DEST_FROM_ADDR  addr,dest

	return (*addr = value);
}


uint8_t rnd_pfii_next2(rnd_pfii * addr)
{
    rnd_pfii_next(addr);
    return rnd_pfii_next(addr);
}


uint8_t rnd_pfii_prev(rnd_pfii * addr)
{
	uint8_t value = *addr;

                //LDA             addr
                //ASL
                //EOR             addr
                //ASL
                //EOR             addr
                //ASL
                //ASL
                //ROL
                //EOR             addr
                //LSR
                //ROR             addr

	return (*addr = value);
}


uint8_t rnd_pfii_prev2(rnd_pfii * addr)
{
    rnd_pfii_prev(addr);
    return rnd_pfii_prev(addr);
}



// Galois 8-bit LFSR (Batari Basic) (1-255) - DUPLICATE OF RND_GAL_ALG7

void rnd_bas_init(rnd_bas * addr, uint8_t seed)
{
    *addr = (seed == RND_BAS_SEED_INVALID) ? RND_BAS_SEED_DEFAULT : seed;
}


void rnd_bas_fix(rnd_bas * addr, uint8_t seed)
{
    if (*addr == RND_BAS_SEED_INVALID) {
        rnd_bas_init(addr, seed);
    }
}


/*
    LDA rand
    LSR
    BCC *+4
    EOR #$B4
    STA rand
*/


#define RND_BAS_ALG_NEXT 0xB4


uint8_t rnd_bas_next(rnd_bas * addr)
{
	uint8_t value = *addr;

    uint8_t carry = (value & UINT8_C(0x01)) ? UINT8_C(0x80) : UINT8_C(0x00);
    value >>= 1;
    if (carry) {
        value ^= RND_BAS_ALG_NEXT;
    }

    return (*addr = value);
}


uint8_t rnd_bas_next2(rnd_bas * addr)
{
    rnd_bas_next(addr);
    return rnd_bas_next(addr);
}


#define RND_BAS_ALG_PREV 0x69


uint8_t rnd_bas_prev(rnd_bas * addr)
{
	uint8_t value = *addr;

    uint8_t carry = (value & UINT8_C(0x80)) ? UINT8_C(0x01) : UINT8_C(0x00);
    value <<= 1;
    if (carry) {
        value ^= RND_BAS_ALG_PREV;
    }

	return (*addr = value);
}


uint8_t rnd_bas_prev2(rnd_bas * addr)
{
    rnd_bas_prev(addr);
    return rnd_bas_prev(addr);
}



// Galois 16-bit LFSR (Batari Basic) (1-65535)

void rnd_bas2_init(rnd_bas2 * addr, uint16_t seed)
{
    *addr = (seed == RND_BAS2_SEED_INVALID) ? RND_BAS2_SEED_DEFAULT : seed;
}


void rnd_bas2_fix(rnd_bas2 * addr, uint16_t seed)
{
    if (*addr == RND_BAS2_SEED_INVALID) {
        rnd_bas2_init(addr, seed);
    }
}


/*
    LDA rand
    LSR
    ROL rand16
    BCC *+4
    EOR #$B4
    STA rand
    EOR rand16
*/


#define RND_BAS2_ALG_NEXT 0xB4

static int i  = 0;
uint16_t rnd_bas2_next(rnd_bas2 * addr)
{
    uint16_t value = *addr;

    uint8_t lo = (value & UINT16_C(0x00FF));
    uint8_t hi = ((value >> 8) & UINT16_C(0x00FF));

    uint8_t lo_carry = (lo & UINT8_C(0x01)) ? UINT8_C(0x01) : UINT8_C(0x00);
    lo >>= 1;
    uint8_t hi_carry = (hi & UINT8_C(0x80)) ? UINT8_C(0x01) : UINT8_C(0x00);
    hi <<= 1;
    hi |= lo_carry;
    if (hi_carry) {
        lo ^= RND_BAS2_ALG_NEXT;
    }
    //Discarded ???? bug in 6502 or unnecessary instruction ???? -
    hi ^= lo;
// returned as random number !!!

    printf("%5d=%d: ", i, (int)hi);
    for (int j = 0;  j < hi;  j+=4) {
        printf(" ");
    }
    puts("*");
//
//    printf("%5d=%d: ", i, (int)lo);
//    for (int j = 0;  j < lo;  j+=4) {
//        printf(" ");
//    }
//    puts("X");

    i++;

    value = ((hi << 8) | (lo));

    return (*addr = value);
}


uint16_t rnd_bas2_next2(rnd_bas2 * addr)
{
    rnd_bas2_next(addr);
    return rnd_bas2_next(addr);
}


#define RND_BAS2_ALG_PREV 0xFFFF


uint16_t rnd_bas2_prev(rnd_bas2 * addr)
{
    uint16_t value = *addr;


    return (*addr = value);
}


uint16_t rnd_bas2_prev2(rnd_bas2 * addr)
{
    rnd_bas2_prev(addr);
    return rnd_bas2_prev(addr);
}



// Fibonacci 16-bit LFSR (Ported from Microchip PIC8) (1-65536)

void rnd_pic2_init(rnd_pic2 * addr, uint16_t seed)
{
    puts("            ERROR: rnd_pic2_* - NOT IMPLEMENTED OR WORKING!");
    *addr = (seed == RND_PIC2_SEED_INVALID) ? RND_PIC2_SEED_DEFAULT : seed;
}


void rnd_pic2_fix(rnd_pic2 * addr, uint16_t seed)
{
    if (*addr == RND_PIC2_SEED_INVALID) {
        rnd_pic2_init(addr, seed);
    }
}


uint16_t rnd_pic2_next(rnd_pic2 * addr)
{
    uint16_t value = *addr;

    //uint8_t carry = (value & UINT8_C(0x01)) ? UINT8_C(0x80) : UINT8_C(0x00);
    //value = ((value >> 1) | carry) ^ 0xB5;

    return (*addr = value);
}


uint16_t rnd_pic2_next2(rnd_pic2 * addr)
{
    rnd_pic2_next(addr);
    return rnd_pic2_next(addr);
}


uint16_t rnd_pic2_prev(rnd_pic2 * addr)
{
    uint16_t value = *addr;


    return (*addr = value);
}


uint16_t rnd_pic2_prev2(rnd_pic2 * addr)
{
    rnd_pic2_prev(addr);
    return rnd_pic2_prev(addr);
}


