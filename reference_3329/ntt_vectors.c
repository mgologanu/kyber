#include <stdint.h>

#include "ntt_3329.h"

#define p 3329


void ntt_v_256(int32_t * a)
{
  int i;

  int32_t t;
  
  for (i=0; i<256; i++) 
    {
      t = a[i];
      t = mul_mod(t, r512[i]);
      a[i] = t;
    }

  pass_vectors(a, r256, 128);

  ntt_v_128(a);
  

}



void ntt_v_128(int32_t * a)
{
  pass_vectors(a, r128, 64);

  ntt_v_64(a);
  
}

void ntt_v_64(int32_t * a)
{
  pass_vectors(a, r64, 32);

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
  ntt_v_32(a);

}


void ntt_v_32(int32_t * a)
{
  pass_vectors(a, r32, 16);

  ntt_v_16(a);

}


void ntt_v_16(int32_t * a)
{
  pass_vectors(a, r16, 8);
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

  ntt_v_8(a);

  
}

void ntt_v_8(int32_t * a)
{
  pass_vectors(a, r8, 4);

  ntt_v_4(a);

  
}


void ntt_v_4(int32_t * a)
{
 
  pass_vectors(a, r4, 2);
    
  
  int32_t t00, t01, t10, t11;
  /*
  t00 = add_mod(a[0],a[2]);
  t01 = add_mod(a[1],a[3]);

  t10 = sub_mod(a[0],a[2]);
  t11 = sub_mod(a[1],a[3]);
    */
  t00 = a[0];
  t01 = a[1];
  t10 = a[2];
  t11 = a[3];
  a[0] = red_finala(t00);
  a[1] = red_finala(t01);
  a[2] = red_finala(t10);
  a[3] = red_finala(t11);
    
}

