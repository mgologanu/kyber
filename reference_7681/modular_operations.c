#include<stdint.h>

#include "ntt_7681.h"

int32_t mul_mod( int32_t a, int32_t b)
{

  const int32_t p = 7681;

  const int32_t pow_R = 32;

  const int32_t Rp = 559167;

  int32_t res;
  
  int32_t ab;

  ab = a*b;

  //printf("ab = %d\n", ab);

  int64_t t;

  t = (int64_t) ab * (int64_t) Rp;

  int32_t q;
  
  q = t >> pow_R;

  res = ab - q*p;

  if(res>=p)
    {
      res = res-p;
    }

  return res;  
}

int32_t add_mod( int32_t a, int32_t b)
{
  const int32_t p = 7681;
  int32_t res;
  
  res = a+b;

  if(res>=p)
    {
      res = res-p;
    }
  else if(res < 0)
    {
      res = res + p;
    }

  return res;  
}

int32_t sub_mod( int32_t a, int32_t b)
{
  const int32_t p = 7681;
  int32_t res;
  
  res = a-b;

  if(res>=p)
    {
      res = res-p;
    }
  else if(res<0)
    {
      res = res + p;
    }

  return res;  
}