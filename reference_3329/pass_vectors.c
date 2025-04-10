#include <stdint.h>

#include "ntt_3329.h"

/*
  a = [0:2n-1]  array 
  r = [0:n-1]   roots


  a_i + a_{i+n} 

  (a_i - a_{i+n}) * r_i

 */

// single line comment


inline int32_t mul_mod2( int32_t a, int32_t b)
{

  const int32_t N = 3329;

  //const int32_t R = 65536;

  const int32_t Np = 3327;

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
 
  //if(r1>=p)
    //{
      ///r1 = r1-p;
    //}

  return r1;  //nr sub forma Montgomery
}

void pass_vectors(int32_t *a, int32_t *r, int n)
{
  const int32_t N = 256;
  int i;

  int32_t t1,t2,t3,t4;

  //  t1 = add_mod( a[0], a[n]) ;
  // t2 = sub_mod( a[0], a[n]);

  
  
  for (i=0; i<n; i++) 
    {
      //     t1 = add_mod( a[i], a[i+n]) ;
      //     t2 = sub_mod( a[i], a[i+n]);
      t1 =  a[i] + a[i+n] ;
      t2 =  a[i] - a[i+n];
      
      t2 = mul_mod2(t2, r[i]);
      
      a[i] = t1;
      a[i+n] = t2;

      t3 =  a[i+n] + a[i+n+n] ;
      t4 =  a[i+n] - a[i+n+n];
      
      t4 = mul_mod2(t4, r[i+n]);
      
      a[i+n] = t3;
      a[i+n+n] = t4;
      
    }
    

}


void pass_vectors1(int32_t *a, int32_t *r, int n)
{
  const int32_t N = 256;
  int i;
  int k;

  int32_t t1,t2,t3,t4;

  //  t1 = add_mod( a[0], a[n]) ;
  // t2 = sub_mod( a[0], a[n]);

  int perechi = N/(2*n);
  for(k =0; k< perechi; k++)
  {
    for (i=0; i<n; i++) 
    {
      //     t1 = add_mod( a[i], a[i+n]) ;
      //     t2 = sub_mod( a[i], a[i+n]);
      t1 =  a[i +k*n] + a[i+n + k*n] ;
      t2 =  a[i+k*n] - a[i+n+k*n];
      
      t2 = mul_mod2(t2, r[i +k*n]);
      
      a[i +k*n] = t1;
      a[i+n +k*n] = t2;

  
      
    }

  }
  
  
    

}