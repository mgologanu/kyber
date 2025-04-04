#include <stdint.h>

#include "ntt_3329.h"

#define p 3329


void ntt_128(int32_t * a) //128 perechi, 256 numere
{ 
  int32_t t0, t1;
  for(int i =0; i<128; i++)
  {
    t0 = a[i];
    t1 = a[i+1];
    a[2*i] = mul_mod(t0, r256[i]);
    a[2*i+1] = mul_mod(t1, r256[i]);
  }
  pass_struc(a, r128, 64);

  ntt_64(a);
  ntt_64(a+128);

}



void ntt_64(int32_t * a)
{
  pass_struc(a, r64, 32);

  ntt_32(a);
  ntt_32(a+64);
  
}

void ntt_32(int32_t * a)
{
  pass_struc(a, r32, 16);

  for (int i=0; i<64; i++)
    {
      while(a[i] > p)
	{
	  a[i] = a[i]-p;
	}

      while(a[i] < p)
	{
	  a[i] = a[i]+p;
	}
    }
  ntt_16(a);
  ntt_16(a+32);
}


void ntt_16(int32_t * a)
{
  pass_struc(a, r16, 8);

  ntt_8(a);
  ntt_8(a+16);
}


void ntt_8(int32_t * a)
{
  pass_struc(a, r8, 4);
    for (int i=0; i<16; i++)
    {
      while(a[i] > p)
	{
	  a[i] = a[i]-p;
	}

      while(a[i] < p)
	{
	  a[i] = a[i]+p;
	}
    }

  ntt_4(a);
  ntt_4(a+8);
  
}

void ntt_4(int32_t * a)
{
  pass_struc(a, r4, 2);

  ntt_2(a);
  ntt_2(a+4);
  
}


void ntt_2(int32_t * a) //am ramas cu doua perechi
{
 
  pass_struc(a, r2, 1);
    
  
  int32_t t00, t01, t10, t11;
 
  t00 = a[0];
  t01 = a[1];
  t10 = a[2];
  t11 = a[3];
  a[0] = red_finala(t00);
  a[1] = red_finala(t01);
  a[2] = red_finala(t10);
  a[3] = red_finala(t11);
    
}

