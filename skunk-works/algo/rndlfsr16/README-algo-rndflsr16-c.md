# Algorithm - Random (Rnd)

Fast bit stream pseudo random number generator implemented with a 16-bit linear feedback shift register (LFSR).
This version was written in a reusable 'C' library to allow the algorithm to be tested and exercised. 
This algorithms has already been implemented in Microchip PIC8 and for in 65xx CPU primarily the Atari 2600 console.
This algorithm uses only bitwise and shift operations so is useful for platforms without multiplication and division support.


## Description

Generate pseudo random numbers efficiently utilising a Linear Feedback Shift Register.

The initial seed value is 0xACE1.

Here is an illustration of this LFSR's implementation:-

```
; Feedback (F) is calculated with the taps on rnd_sr_lo bits 0, 2, 3, 5.
; rnd_sr_lo is shifted right and value shifted out of bit 0 is the output stream.
; rnd_sr_hi is shifted right and the value shifted out of bit 0 goes into bit 7
; of rnd_sr_hi. The feedback becomes bit 7 of rndval_hi.
;
; rnd_sr_hi                            rnd_sr_lo
; | 7 | 6 | 5 | 4 | 3 | 2 |  1 |  0 |->| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |->| O |
;   ^                                            |       |   |       |      u
;   |                                            |       |    \     /       t
;   |                                            |       |      XOR         p
;   |                                            |       |       |          u
;   |                                            |      XOR------           t
;   |                                            |       |
; | F |<----------------------------------------XOR------
; Feedback
;
```

## Implementation

### Files

 * Makefile - Make file to build the application (default all target), and also to clean, and run.
 * rndlfsr16.h - Random number generator header file.
 * rndlfsr16.c - Random number generator implementation.
 * rndlfsr16-main.c - Application to exercise the random number generator.


### Example Usage

```
// Used to store the state.
rnd_state state;

// Initialise the state. Must be called once.
rnd_init(&state);

// Get a 1 bit random value.
uint8_t random_value = rnd_get_bit(&state);

/// Get 1 to 8 bits random value. Four bits in this example.
uint8_t random_value = rnd_get_bits(&state, 4);

// Get 8 bits random value. Note bits are in reverse order from the rnd_get_bits function. 
uint8_t random_value = rnd_get_byte(&state);

// Get the last returned random value returned from rnd_get_bit|bits|byte.
uint8_t last_random_value = state.value;
```

Please refer to the rndlfsr16-main.c file for other examples of usage.


## Build and Run Output

```
$ make run
cc -c rndlfsr16.c -o rndlfsr16.o
cc -c rndlfsr16-main.c -o rndlfsr16-main.o
cc -o rndlfsr16-main rndlfsr16-main.o rndlfsr16.o
./rndlfsr16-main
MAIN: START
test_fix(): START
test_fix(): FINISH
test_bit(): START
Count = 2, Min = 32767, Max = 32769, Total = 65536, Average = 32768
test_bit(): FINISH
test_bits(): START
Count = 16, Min = 4095, Max = 4096, Total = 65536, Average = 4096
test_bits(): FINISH
test_byte(): START
Count = 256, Min = 255, Max = 256, Total = 65536, Average = 256
test_byte(): FINISH
performance_byte_std(): START
Count = 1000000, Duration =  7179.000 microseconds
performance_byte_std(): FINISH
performance_byte_lfsr(): START
Count = 1000000, Duration = 137496.000 microseconds
performance_byte_lfsr(): FINISH
MAIN: FINISH
```

Initially the rnd_fix_sr function is tested.

The rnd_get_bit function is called 65536 times and there are two possible result (0 or 1) values.\
The values have an occurrence count minimum of 32767 and a maximum of 32768 so are very evenly distributed.

The rnd_get_bits function is called 65536 times also and 4 bit number is requested each time so there is a count of 16 possible values (0 - 15).\
The values have an occurrence count minimum of 4095 and a maximum of 4096 so are also very evenly distributed.

The rnd_get_byte function is called 65536 times also and an 8 bit number is requested each time so there is a count of 256 possible values (0 - 255).\
The values have an occurrence count minimum of 255 and a maximum of 256 so are also very evenly distributed.

Lastly performance test is run by utilising the stdlib rand function is run 1 million times.\
The stdlib rand function runs in approximately 7.2 milliseconds fpr the one million calls (includes time for the loop).
The LFSR function runs in approximately 138 milliseconds fpr the one million calls (includes time for the loop).


It may appear shocking that the LFSR implementation is slower but it is designed to be written in assembler and for platforms without multiply and divide instructions.\
On its designed platforms and with a specific implementation it will out perform the standard c library implementation that relied on multiplication and division.  


## Contact Us

Please email atari2600@jigglesoft.co.uk regarding this repository.


