#include<stdint.h>
#include <math.h>

#include "ntt_7681.h"

int32_t mul_mod( int32_t a, int32_t b)
{

  const int32_t p = 7681;

  //const int32_t R = 65536;

  const int32_t p_prim = 7679;

  int32_t m;
  int32_t t;
  int32_t r1;
  int32_t T;
 

  T = a*b;
  m = T & 0xFFFF; //reducere mod 2^16=R
  m = m * p_prim;
  m = m & 0xFFFF;
  t = T + (m*p);
  r1 = t>>16; // parte intreaga din t/R
 
  //if(r1>=p)
    //{
      ///r1 = r1-p;
    //}

  return r1;  //nr sub forma Montgomery
}

int32_t red_finala(int32_t a)
{
  const int32_t p = 7681;
  const int32_t R_inv = 900;
  int32_t rez;
  rez = a * R_inv;
  int32_t parte_intreaga = rez/p;
  rez = rez - parte_intreaga * p;
  return rez;
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



int32_t reduce_small(int32_t x)
{
  const int32_t p = 7681;

  const int32_t v_red =  17474;
     
  int32_t t1,t2,m,r1;

  
  t2 = (x*v_red) >> 27;					
  m = t2 * p;						
  t1 = x - m;						
  t2 = t1-p;						
  if (t2 == 0)					
    r1 = t2;						
  else						
    r1 = t1;

  return r1;
 
}
  
