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


MU_TEST(test_ntt256) {

  int32_t a[256] ;

  for (int i = 0; i<256; i++)
    {
      a[i] = i;
    }

  ntt_256(a);

  int32_t A_octave[] = {4483,6202,3139,6555,6593,384,3337,7507,1308,7140,7630,4856,6638,6699,7092,173,1427,5520,5758,5150,6894,1256,6862,2580,7310,2609,4921,6599,991,2061,3447,5877,7555,3238,5993,3631,2536,4523,2032,7389,1354,665,4958,2897,7105,962,7551,7360,2715,6753,3281,2732,4488,5640,800,2261,3485,7410,7328,6527,3838,4562,2435,1573,6188,5423,7660,6627,6882,6533,602,5925,5847,6655,1995,3835,1870,1173,1271,766,3718,259,2319,6487,2390,4553,3737,3174,3141,5010,6705,4223,1904,2918,7095,3351,2424,3177,5900,1549,5915,6736,5916,1033,1413,6288,2376,5313,7213,261,275,2649,5647,6796,2427,80,5980,6664,1920,6461,2124,5155,2355,6894,5074,3322,945,3553,7561,6220,5318,58,2262,2049,3472,6868,52,3614,7088,3381,4473,1211,2548,887,6861,2581,3660,3298,2557,2185,3582,7361,4556,1984,1513,3248,3995,6021,3289,6301,573,4312,5776,6184,1460,2339,5657,4750,1833,5206,3592,5399,1536,4999,1427,7562,6479,5609,2207,7059,3001,1898,7341,7107,6745,7089,6008,627,4379,3476,4008,3053,7169,860,2628,3820,3956,1184,5613,7569,6751,6672,6350,1919,7175,1401,2533,5386,7661,2563,3400,6653,7248,5944,6683,4714,2841,3443,6903,3351,215,1081,3107,1250,3472,1858,2339,1282,6302,3640,4921,2953,7229,5138,7662,252,6092,2566,2107,6683,7012,4168,3214,4208,939,4464,54,4568,1867,4818,3961,2205,2648,2269,4100,1872};

  for (int i = 0; i<256; i++)
    mu_assert(a[i] == A_octave[i], "NTT 256 gresit");



}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_mul_mod);
  MU_RUN_TEST(test_add_mod);
  MU_RUN_TEST(test_sub_mod);
  MU_RUN_TEST(test_ntt256);
 
}

int main(int argc, char *argv[]) {
        MU_RUN_SUITE(test_suite);
        MU_REPORT();
        return minunit_fail;
}
