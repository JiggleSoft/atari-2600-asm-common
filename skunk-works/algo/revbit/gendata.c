#include <stdio.h>

// 7 6 5 4 3 2 1 0
// 0 1 2 3 4 5 6 7

unsigned int rev(unsigned int i)
{
unsigned int a = ((i<<7)&0x80U);
unsigned int b = ((i<<5)&0x40U);
unsigned int c = ((i<<3)&0x20U);
unsigned int d = ((i<<1)&0x10U);
unsigned int e = ((i>>1)&0x8U);
unsigned int f = ((i>>3)&0x4U);
unsigned int g = ((i>>5)&0x2U);
unsigned int h = ((i>>7)&0x1U);
unsigned int j = a|b|c|d|e|f|g|h;
//printf("\nrev: %u %u %u %u %u %u %u %u %u %u\n", a, b, c, d, e, f, g, h, i, j);

return j;
//return (((i<<7)&0x80U)|((i<<6)&0x40U)|((i<<5)&0x20U)|((i<<4)&0x10U)|((i<<3)&0x08U)|((i<<2)&0x04U)|((i<<1)&0x02U)|(i&0x01U));
}

int main()
{
  printf("    BYTE    ");
  for(unsigned int i = 0;  i < 16;  i++)
  {
    if (i) { printf(","); }
    //printf("\n%d = %d\n", i, rev(i));
    printf("$%02x", rev(i));
  }
  printf("\n");
  printf("--------------------");
  printf("    BYTE    ");
  for(unsigned int i = 0;  i <= 255;  i+=16)
  {
    if (i) { printf(","); }
    //printf("\n%d = %d\n", i, rev(((i<<4)&0xF0));
    printf("$%02x", rev(i));
  }
  printf("\n");
  printf("--------------------");
  for(unsigned int i = 0;  i <= 255;  i++)
  {
    if (i%16 == 0) { printf("\n    BYTE    "); }
    if (i%16 != 0) { printf(","); }
    //printf("\n%d = %d\n", i, rev(((i<<4)&0xF0));
    printf("$%02x", rev(i));
  }
  printf("\n");
}

