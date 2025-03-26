#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "minunit.h"

#include<immintrin.h>
#include <stdalign.h>

#include "ntt_7681.h"

const int32_t p = 7681;

MU_TEST(test_mul_mod) {

  
  int32_t a = 4032;
  int32_t b = 1796;

  int32_t c = a*b-((a*b)/p)*p;

  int32_t cc = mul_mod(a,b);
 
  printf("%d %d\n", c, cc);
  
  mu_assert(c == cc, "Mul gresit");

  for (int i =0; i<p-1; i++)
    {
      for (int j =0; j<p-1; j++)
	{
    a = i;
	  b = j;
	  c = a*b-((a*b)/p)*p;
	  cc =  mul_mod(a,b);
	  mu_assert(c == cc, "Mul gresit");
	}
    }
}

MU_TEST(test_add_mod) {

  
  int32_t a = -10;
  int32_t b = -3;

  int32_t c = a+b +p;

  int32_t cc = add_mod(a,b);
 
  printf("%d %d\n", c, cc);
  
  mu_assert(c == cc, "Add gresit");
/*
for (int i =0; i<p-1; i++)
    {
      for (int j =0; j<p-1; j++)
	{
    a = i;
	  b = j;
	  c = a*b-((a*b)/p)*p;
	  cc =  mul_mod(a,b);
	  mu_assert(c == cc, "Mul gresit");
	}
    }
*/
  
}


MU_TEST(test_sub_mod) {

  
  int32_t a = 5032;
  int32_t b = 6796;

  int32_t c = a-b + p;

  int32_t cc = sub_mod(a,b);
 
  printf("%d %d\n", c, cc);
  
  mu_assert(c == cc, "Sub gresit");
/*
for (int i =0; i<p-1; i++)
    {
      for (int j =0; j<p-1; j++)
	{
    a = i;
	  b = j;
	  c = a*b-((a*b)/p)*p;
	  cc =  mul_mod(a,b);
	  mu_assert(c == cc, "Mul gresit");
	}
    }
*/
  
}


MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_mul_mod);
  MU_RUN_TEST(test_add_mod);
  MU_RUN_TEST(test_sub_mod);
 
}

int main(int argc, char *argv[]) {
        MU_RUN_SUITE(test_suite);
        MU_REPORT();
        return minunit_fail;
}
