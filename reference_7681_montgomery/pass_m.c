#include <stdint.h>

#include "ntt_7681.h"

/*
  a = [0:2n-1]  array 
  r = [0:n-1]   roots


  a_i + a_{i+n} 

  (a_i - a_{i+n}) * r_i

 */

// single line comment


inline int32_t mul_mod2( int32_t a, int32_t b)
{

  const int32_t N = 7681;

  //const int32_t R = 65536;

  const int32_t Np = 7679;

  int32_t m;
  int32_t t;
  int32_t r1;
  int32_t T;


  T = a*b;
  m = T & 0xFFFF; //reducere mod 2^16=R
  m = m * Np;
  m = m & 0xFFFF;
  t = T + (m*N);
  r1 = t>>16; // parte intreaga din t/R
 
  return r1;  //nr sub forma Montgomery +-p
}

void pass(int32_t *a, int32_t *r, int n)
{
  int i;

  int32_t t1,t2;

  //  t1 = add_mod( a[0], a[n]) ;
  // t2 = sub_mod( a[0], a[n]);
  
   t1 =  a[0] + a[n];
  // t1 = reduce_small(t1);
  
  t2 =  a[0] - a[n];
  //t1 = reduce_small(t1);

  
  a[0] = t1;
  a[n] = t2;
  
  for (i=1; i<n; i++) 
    {
      //t1 = add_mod( a[i], a[i+n]) ;
      // t2 = sub_mod( a[i], a[i+n]);
      t1 =  a[i] + a[i+n] ;
      t2 =  a[i] - a[i+n];
      
      t2 = mul_mod2(t2, r[i]);
      
      a[i] = t1;
      a[i+n] = t2;
      
    }
    

}
