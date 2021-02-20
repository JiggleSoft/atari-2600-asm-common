
#include "aim.h"


void rnd_init(rnd_state * state)
{
    state->sr = RND_SEED_DEFAULT;
    state->fback = UINT8_FAST_C(0);
    state->value = UINT8_C(0);
}


void rnd_fix_sr(rnd_state * state)
{
    if (!state->sr) {
        state->sr = RND_SEED_DEFAULT;
    }
}


int rnd_next_bit(rnd_state * state)
{
    int value = (state->sr & UINT16_C(0x0001));
    uint = rnd_calc_fback(state->sr);
    rnd_shift_bit(state->sr);
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
    return rnd_next_bit(state);
}


uint8_t rnd_get_bits(rnd_state * state, int number)
{
    return 0;
}


uint8_t rnd_get_byte(rnd_state * state)
{
    uint8_t value = (state->sr & UINT16_C(0x00FF)));
    rnd_next_bits(8);
    return (state->value = value);
}


