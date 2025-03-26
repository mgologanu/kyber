#include <stdint.h>

#include "ntt_7681.h"

/*
  a = [0:2n-1]  array 
  r = [0:n-1]   roots


  a_i + a_{i+n} 

  (a_i - a_{i+n}) * r_i

 */

// single line comment

void pass(int32_t *a, int32_t *r, int n)
{
  int i;

  int32_t t1,t2;
  
  for (i=0; i<n; i++) 
    {
      t1 = add_mod( a[i], a[i+n]) ;
      t2 = sub_mod( a[i], a[i+n]);

      t2 = mul_mod(t2, r[i]);
      
      a[i] = t1;
      a[i+n] = t2;
      
    }
    

}
