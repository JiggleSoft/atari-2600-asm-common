/*============================================================================
 * Title:        Pseudo Random Number Generator include header file.
 * Algorithm:    Various Linear Feedback Shift Register (LFSR) Algorithms.
 * Filename:     rnd.h
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
 *---------------------------------------------------------------------------
 */


#ifndef __RND__H__
#define __RND__H__


#include <stdint.h>



// Xorshift 8-bit (1-255)

#define RND_XOS_SEED_DEFAULT UINT8_C(0xA1)
#define RND_XOS_SEED_INVALID UINT8_C(0x00)

typedef uint8_t rnd_xos;

void rnd_xos_init(rnd_xos * addr, uint8_t seed);
void rnd_xos_fix(rnd_xos * addr, uint8_t seed);
uint8_t rnd_xos_next(rnd_xos * addr);
uint8_t rnd_xos_next2(rnd_xos * addr);
uint8_t rnd_xos_prev(rnd_xos * addr);
uint8_t rnd_xos_prev2(rnd_xos * addr);



// Xorshift 16-bit (1-65535)

#define RND_XOS2_SEED_DEFAULT UINT16_C(0xBA5E)
#define RND_XOS2_SEED_INVALID UINT16_C(0x0000)

typedef uint16_t rnd_xos2;

void rnd_xos2_init(rnd_xos2 * addr, uint16_t seed);
void rnd_xos2_fix(rnd_xos2 * addr, uint16_t seed);
uint16_t rnd_xos2_next(rnd_xos2 * addr);
uint16_t rnd_xos2_next2(rnd_xos2 * addr);
uint16_t rnd_xos2_prev(rnd_xos2 * addr);
uint16_t rnd_xos2_prev2(rnd_xos2 * addr);



// Galois 8-bit LFSR (1-255)

#define RND_GAL_SEED_DEFAULT UINT8_C(0xA5)
#define RND_GAL_SEED_INVALID UINT8_C(0x00)

#define RND_GAL_ALG0_NEXT UINT8_C(0x8E)
#define RND_GAL_ALG1_NEXT UINT8_C(0x95)
#define RND_GAL_ALG2_NEXT UINT8_C(0x96)
#define RND_GAL_ALG3_NEXT UINT8_C(0xA6)
#define RND_GAL_ALG4_NEXT UINT8_C(0xAF)
#define RND_GAL_ALG5_NEXT UINT8_C(0xB1)
#define RND_GAL_ALG6_NEXT UINT8_C(0xB2)
#define RND_GAL_ALG7_NEXT UINT8_C(0xB4)
#define RND_GAL_ALG8_NEXT UINT8_C(0xB8)
#define RND_GAL_ALG9_NEXT UINT8_C(0xC3)
#define RND_GAL_ALGA_NEXT UINT8_C(0xC6)
#define RND_GAL_ALGB_NEXT UINT8_C(0xD4)
#define RND_GAL_ALGC_NEXT UINT8_C(0xE1)
#define RND_GAL_ALGD_NEXT UINT8_C(0xE7)
#define RND_GAL_ALGE_NEXT UINT8_C(0xF3)
#define RND_GAL_ALGF_NEXT UINT8_C(0xFA)

#define RND_GAL_ALG0_PREV UINT8_C(0x1D)
#define RND_GAL_ALG1_PREV UINT8_C(0x2B)
#define RND_GAL_ALG2_PREV UINT8_C(0x2D)
#define RND_GAL_ALG3_PREV UINT8_C(0x4D)
#define RND_GAL_ALG4_PREV UINT8_C(0x5F)
#define RND_GAL_ALG5_PREV UINT8_C(0x63)
#define RND_GAL_ALG6_PREV UINT8_C(0x65)
#define RND_GAL_ALG7_PREV UINT8_C(0x69)
#define RND_GAL_ALG8_PREV UINT8_C(0x71)
#define RND_GAL_ALG9_PREV UINT8_C(0x87)
#define RND_GAL_ALGA_PREV UINT8_C(0x8D)
#define RND_GAL_ALGB_PREV UINT8_C(0xA9)
#define RND_GAL_ALGC_PREV UINT8_C(0xC3)
#define RND_GAL_ALGD_PREV UINT8_C(0xCF)
#define RND_GAL_ALGE_PREV UINT8_C(0xE7)
#define RND_GAL_ALGF_PREV UINT8_C(0xF5)

#define RND_GAL_ALG_NEXT  RND_GAL_ALG0_NEXT
#define RND_GAL_ALG_PREV  RND_GAL_ALG0_PREV

typedef uint8_t rnd_gal;

void rnd_gal_init(rnd_gal * addr, uint8_t seed);
void rnd_gal_fix(rnd_gal * addr, uint8_t seed);
uint8_t rnd_gal_next(rnd_gal * addr, uint8_t algo);
uint8_t rnd_gal_next2(rnd_gal * addr, uint8_t algo);
uint8_t rnd_gal_prev(rnd_gal * addr, uint8_t algo);
uint8_t rnd_gal_prev2(rnd_gal * addr, uint8_t algo);



// Galois 8-bit LFSR Extended to Full Range (0-255)

#define RND_GALX_SEED_DEFAULT UINT8_C(0xA5)

#define RND_GALX_ALG0_NEXT UINT8_C(0x8E)
#define RND_GALX_ALG1_NEXT UINT8_C(0x95)
#define RND_GALX_ALG2_NEXT UINT8_C(0x96)
#define RND_GALX_ALG3_NEXT UINT8_C(0xA6)
#define RND_GALX_ALG4_NEXT UINT8_C(0xAF)
#define RND_GALX_ALG5_NEXT UINT8_C(0xB1)
#define RND_GALX_ALG6_NEXT UINT8_C(0xB2)
#define RND_GALX_ALG7_NEXT UINT8_C(0xB4)
#define RND_GALX_ALG8_NEXT UINT8_C(0xB8)
#define RND_GALX_ALG9_NEXT UINT8_C(0xC3)
#define RND_GALX_ALGA_NEXT UINT8_C(0xC6)
#define RND_GALX_ALGB_NEXT UINT8_C(0xD4)
#define RND_GALX_ALGC_NEXT UINT8_C(0xE1)
#define RND_GALX_ALGD_NEXT UINT8_C(0xE7)
#define RND_GALX_ALGE_NEXT UINT8_C(0xF3)
#define RND_GALX_ALGF_NEXT UINT8_C(0xFA)

#define RND_GALX_ALG0_PREV UINT8_C(0x1D)
#define RND_GALX_ALG1_PREV UINT8_C(0x2B)
#define RND_GALX_ALG2_PREV UINT8_C(0x2D)
#define RND_GALX_ALG3_PREV UINT8_C(0x4D)
#define RND_GALX_ALG4_PREV UINT8_C(0x5F)
#define RND_GALX_ALG5_PREV UINT8_C(0x63)
#define RND_GALX_ALG6_PREV UINT8_C(0x65)
#define RND_GALX_ALG7_PREV UINT8_C(0x69)
#define RND_GALX_ALG8_PREV UINT8_C(0x71)
#define RND_GALX_ALG9_PREV UINT8_C(0x87)
#define RND_GALX_ALGA_PREV UINT8_C(0x8D)
#define RND_GALX_ALGB_PREV UINT8_C(0xA9)
#define RND_GALX_ALGC_PREV UINT8_C(0xC3)
#define RND_GALX_ALGD_PREV UINT8_C(0xCF)
#define RND_GALX_ALGE_PREV UINT8_C(0xE7)
#define RND_GALX_ALGF_PREV UINT8_C(0xF5)

#define RND_GALX_ALG_NEXT  RND_GALX_ALG0_NEXT
#define RND_GALX_ALG_PREV  RND_GALX_ALG0_PREV

typedef uint8_t rnd_galx;

void rnd_galx_init(rnd_galx * addr, uint8_t seed);
void rnd_galx_fix(rnd_galx * addr, uint8_t seed);
uint8_t rnd_galx_next(rnd_galx * addr, uint8_t algo);
uint8_t rnd_galx_next2(rnd_galx * addr, uint8_t algo);
uint8_t rnd_galx_prev(rnd_galx * addr, uint8_t algo);
uint8_t rnd_galx_prev2(rnd_galx * addr, uint8_t algo);



// Galois 16-bit LFSR (1-65535)

#define RND_GAL2_SEED_DEFAULT UINT16_C(0xBA5E)
#define RND_GAL2_SEED_INVALID UINT16_C(0x0000)

#define RND_GAL2_ALG_NEXT UINT16_C(0x8E8E)
#define RND_GAL2_ALG_PREV UINT16_C(0x1D1D)

typedef uint16_t rnd_gal2;

void rnd_gal2_init(rnd_gal2 * addr, uint16_t seed);
void rnd_gal2_fix(rnd_gal2 * addr, uint16_t seed);
uint16_t rnd_gal2_next(rnd_gal2 * addr, uint16_t algo);
uint16_t rnd_gal2_next2(rnd_gal2 * addr, uint16_t algo);
uint16_t rnd_gal2_prev(rnd_gal2 * addr, uint16_t algo);
uint16_t rnd_gal2_prev2(rnd_gal2 * addr, uint16_t algo);



// Galois 16-bit LFSR Extended to Full Range (0-65535)

#define RND_GAL2X_SEED_DEFAULT UINT8_C(0xA5)

#define RND_GAL2X_ALG_NEXT UINT8_C(0x8E)
#define RND_GAL2X_ALG_PREV UINT8_C(0x1D)

typedef uint16_t rnd_gal2x;

void rnd_gal2x_init(rnd_gal2x * addr, uint16_t seed);
void rnd_gal2x_fix(rnd_gal2x * addr, uint16_t seed);
uint16_t rnd_gal2x_next(rnd_gal2x * addr, uint16_t algo);
uint16_t rnd_gal2x_next2(rnd_gal2x * addr, uint16_t algo);
uint16_t rnd_gal2x_prev(rnd_gal2x * addr, uint16_t algo);
uint16_t rnd_gal2x_prev2(rnd_gal2x * addr, uint16_t algo);



// Fibonacci 8-bit LFSR (1-255)

#define RND_FIB_SEED_DEFAULT UINT8_C(0xFF)
#define RND_FIB_SEED_INVALID UINT8_C(0x00)

typedef uint8_t rnd_fib;

void rnd_fib_init(rnd_fib * addr, uint8_t seed);
void rnd_fib_fix(rnd_fib * addr, uint8_t seed);
uint8_t rnd_fib_next(rnd_fib * addr);
uint8_t rnd_fib_next2(rnd_fib * addr);
uint8_t rnd_fib_prev(rnd_fib * addr);
uint8_t rnd_fib_prev2(rnd_fib * addr);



// Fibonacci 16-bit LFSR (1-65535)

#define RND_FIB2_SEED_DEFAULT UINT8_C(0xBA5E)
#define RND_FIB2_SEED_INVALID UINT8_C(0x0000)

typedef uint16_t rnd_fib2;

void rnd_fib2_init(rnd_fib2 * addr, uint16_t seed);
void rnd_fib2_fix(rnd_fib2 * addr, uint16_t seed);
uint16_t rnd_fib2_next(rnd_fib2 * addr);
uint16_t rnd_fib2_next2(rnd_fib2 * addr);
uint16_t rnd_fib2_prev(rnd_fib2 * addr);
uint16_t rnd_fib2_prev2(rnd_fib2 * addr);



// Fibonacci 8-bit LFSR (Pitfall II) (1-255)

#define RND_PFII_SEED_DEFAULT UINT8_C(0xFF)
#define RND_PFII_SEED_INVALID UINT8_C(0x00)

typedef uint8_t rnd_pfii;

void rnd_pfii_init(rnd_pfii * addr, uint8_t seed);
void rnd_pfii_fix(rnd_pfii * addr, uint8_t seed);
uint8_t rnd_pfii_next(rnd_pfii * addr);
uint8_t rnd_pfii_next2(rnd_pfii * addr);
uint8_t rnd_pfii_prev(rnd_pfii * addr);
uint8_t rnd_pfii_prev2(rnd_pfii * addr);



// Galois 8-bit LFSR (Batari Basic) (1-255) - DUPLICATE OF RND_GAL_ALG7

#define RND_BAS_SEED_DEFAULT UINT8_C(0xFF)
#define RND_BAS_SEED_INVALID UINT8_C(0x00)

typedef uint8_t rnd_bas;

void rnd_bas_init(rnd_bas * addr, uint8_t seed);
void rnd_bas_fix(rnd_bas * addr, uint8_t seed);
uint8_t rnd_bas_next(rnd_bas * addr);
uint8_t rnd_bas_next2(rnd_bas * addr);
uint8_t rnd_bas_prev(rnd_bas * addr);
uint8_t rnd_bas_prev2(rnd_bas * addr);



// Galois 16-bit LFSR (Batari Basic) (1-65535)

#define RND_BAS2_SEED_DEFAULT UINT16_C(0x00FF)
#define RND_BAS2_SEED_INVALID UINT16_C(0x0000)

typedef uint16_t rnd_bas2;

void rnd_bas2_init(rnd_bas2 * addr, uint16_t seed);
void rnd_bas2_fix(rnd_bas2 * addr, uint16_t seed);
uint16_t rnd_bas2_next(rnd_bas2 * addr);
uint16_t rnd_bas2_next2(rnd_bas2 * addr);
uint16_t rnd_bas2_prev(rnd_bas2 * addr);
uint16_t rnd_bas2_prev2(rnd_bas2 * addr);



// Fibonacci 16-bit LFSR (Ported from Microchip PIC8) (1-65535)

#define RND_PIC2_SEED_DEFAULT UINT16_C(0xBA5E)
#define RND_PIC2_SEED_INVALID UINT16_C(0x0000)

typedef uint16_t rnd_pic2;

void rnd_pic2_init(rnd_pic2 * addr, uint16_t seed);
void rnd_pic2_fix(rnd_pic2 * addr, uint16_t seed);
uint16_t rnd_pic2_next(rnd_pic2 * addr);
uint16_t rnd_pic2_next2(rnd_pic2 * addr);
uint16_t rnd_pic2_prev(rnd_pic2 * addr);
uint16_t rnd_pic2_prev2(rnd_pic2 * addr);



#endif /* __RND__H__ */


