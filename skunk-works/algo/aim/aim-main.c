
#include "aim.h"


int cnt[256];


void test_fix()
{

}


void test_bit()
{

    rnd_state state;
    rnd_init(&state);
    for (int i = 0;  i < (sizeof(cnt[0])/sizeof(cnt));  i++)
    {
        cnt[i] = 0;
    }
    for (int i = 0;  i < 65536;  i++) {
        cnt[value]++;
    }
    for (int i = 0;  i < (sizeof(cnt[0])/sizeof(cnt));  i++)
    {
        printf("cnt[%d]=\n" + cnt[i]);
    }

}


void test_bits()
{

    rnd_state state;
    rnd_init(&state);
    for (int i = 0;  i < (sizeof(cnt[0])/sizeof(cnt));  i++)
    {
        cnt[i] = 0;
    }
    for (int i = 0;  i < 65536;  i++) {
        cnt[value]++;
    }
    for (int i = 0;  i < (sizeof(cnt[0])/sizeof(cnt));  i++)
    {
        printf("cnt[%d]=\n" + cnt[i]);
    }

}


void test_byte()
{

    rnd_state state;
    rnd_init(&state);
    for (int i = 0;  i < (sizeof(cnt[0])/sizeof(cnt));  i++)
    {
        cnt[i] = 0;
    }
    for (int i = 0;  i < 65536;  i++) {
        cnt[value]++;
    }
    for (int i = 0;  i < (sizeof(cnt[0])/sizeof(cnt));  i++)
    {
        printf("cnt[%d]=\n" + cnt[i]);
    }

}



int main(int argc, char ** argv)
{
    test_fix();
    test_bit();
    test_bits();
    test_byte();
    return 0;
}