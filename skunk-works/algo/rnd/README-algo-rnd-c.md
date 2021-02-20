# Algorithm - Random (Rnd)

Various pseudo random number generation implementation.
This algorithm uses only bitwise and shift operations so is useful for platforms without multiplication and division support.


## Description


## Implementation

### Files

 * Makefile - Make file to build the application (default all target), and also to clean, and run.
 * rnd.h - Random number generator header file.
 * rnd.c - Random number generator implementation.
 * rnd-main.c - Application to exercise the random number generator.


### Common API

#### Data Types

typedef uint<SIZE>_t rnd_<IMPL>


#### Constants (#defines)

```RND_<IMPL>_SEED_DEFAULT```

```RND_<IMPL>_SEED_INVALID```

```RND_<IMPL>_ALG_NEXT```

```RND_<IMPL>_ALG_PREV```

```RND_<IMPL>_ALG<NUM>_NEXT```

```RND_<IMPL>_ALG<NUM>_PREV```


#### Initialisation

```void rnd_<IMPL>_init(rnd_<IMPL> * addr, rnd_<IMPL> seed);```


#### Fix

```void rnd_<IMPL>_fix(rnd_<IMPL> * addr, rnd_<IMPL> seed);```


#### Next

```uint<SIZE>_t rnd_<IMPL>_next(rnd_<IMPL> * addr);```

or

```uint<SIZE>_t rnd_<IMPL>_next(rnd_<IMPL> * addr, uint<SIZE>_t algo);```


#### Next 2

```uint<SIZE>_t rnd_<IMPL>_next2(rnd_<IMPL> * addr);```

or

```uint<SIZE>_t rnd_<IMPL>_next2(rnd_<IMPL> * addr, uint<SIZE>_t algo);```


#### Previous

```uint<SIZE>_t rnd_<IMPL>_prev(rnd_<IMPL> * addr);```

or

```uint<SIZE>_t rnd_<IMPL>_prev(rnd_<IMPL> * addr, uint<SIZE>_t algo);```


#### Previous 2

```uint<SIZE>_t rnd_<IMPL>_prev2(rnd_<IMPL> * addr);```

or

```uint<SIZE>_t rnd_<IMPL>_prev2(rnd_<IMPL> * addr, uint<SIZE>_t algo);```


###  Implementation Details

#### Standard Library rand() Function

Just calls off to the 'C' standard libraries (#include <stdlib.h>) rand() method multiplying by the maximum number required and casting to a relevant type e.g. uint8_t.
Implementation is not known and only used in performance tests for comparison.

#### Xorshift 8-bit (1-255)

DOESN'T SEEM TO WORK !!!

#### Xorshift 16-bit (1-65535)

TODO: TEST.

#### Galois 8-bit LFSR (1-255)

Algorithm (GAL) is as follows:-

 * Shifts bits within the 8-bit state value either right (next) or left (previous).
 * New bit to be shifted in will be zero.
 * If a 1 was shifted out then XOR the state value with the algorithm value.

Note:-

 * The state value must not be zero otherwise no other values than zero will be produced.
 * There are 16 algorithm values for next and a corresponding value for previous that give the total 1-255 range of values. 


#### Galois 8-bit LFSR Extended to Full Range (0-255)

Algorithm (GALX) is as follows:-

 * If the 8-bit state value is zero then XOR the state value with the current algorithm value.
   * This value is then returned.
 * If the 8-bit state value is the complement of the current algorithms value then set the state value to zero.
   * This value is then returned.
 * Otherwise perform the same function as the GAL algorithm:-
   * Shifts bits within the 8-bit state value either right (next) or left (previous).
   * New bit to be shifted in will be zero.
   * If a 1 was shifted out then XOR the state value with the algorithm value.
    
Note:-

 * The state value may be zero.
 * There are 16 algorithm values for next and a corresponding value for previous that give the total 0-255 range of values.


#### Galois 16-bit LFSR (1-65535)

TODO: TEST.

#### Galois 16-bit LFSR Extended to Full Range (0-65535)

TODO: TEST.

#### Fibonacci 8-bit LFSR (1-255)

TODO: TEST.

#### Fibonacci 16-bit LFSR (1-65535)

TODO: TEST.

#### Fibonacci 8-bit LFSR (Pitfall II)

TODO: TEST.

#### Galois 8-bit LFSR (Batari Basic) (1-255) - DUPLICATE OF RND_GAL_ALG7

TODO: TEST.

#### Galois 16-bit LFSR (Batari Basic) (1-65535)

TODO: TEST.

#### Fibonacci 16-bit LFSR (Ported from Microchip PIC8)

TODO: TEST.


## Build and Run Output

```
$ make run
cc -c rnd.c -o rnd.o
cc -c rnd-main.c -o rnd-main.o
cc -o rnd-main rnd-main.o rnd.o
./rnd-main
```


## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.


/