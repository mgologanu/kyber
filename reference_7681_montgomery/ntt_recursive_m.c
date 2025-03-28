#include <stdint.h>

#include "ntt_7681.h"



void ntt_256(int32_t * a)
{
  int i;

  int32_t t;
  
  for (i=0; i<256; i++) 
    {
      t = a[i];
      t = mul_mod(t, r512[i]);
      a[i] = t;
    }

  pass(a, r256, 128);

  ntt_128(a);
  ntt_128(a+128);

}



void ntt_128(int32_t * a)
{
  pass(a, r128, 64);

  ntt_64(a);
  ntt_64(a+64);
  
}

void ntt_64(int32_t * a)
{
  pass(a, r64, 32);

  ntt_32(a);
  ntt_32(a+32);
}


void ntt_32(int32_t * a)
{
  pass(a, r32, 16);

  ntt_16(a);
  ntt_16(a+16);
}


void ntt_16(int32_t * a)
{
  pass(a, r16, 8);

  ntt_8(a);
  ntt_8(a+8);
  
}

void ntt_8(int32_t * a)
{
  pass(a, r8, 4);

  ntt_4(a);
  ntt_4(a+4);
  
}


void ntt_4(int32_t * a)
{
 
  pass(a, r4, 2);
  ntt_2(a);
  ntt_2(a+2);
    
}

void ntt_2(int32_t * a)
{
  int32_t t0, t1;
  t0 = add_mod(a[0],a[1]);
  t1 = sub_mod(a[0],a[1]);

  a[0] = red_finala(t0);
  a[1] = red_finala(t1);

}
