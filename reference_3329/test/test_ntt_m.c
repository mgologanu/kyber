#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "minunit.h"

#include<immintrin.h>
#include <stdalign.h>

#include "ntt_3329.h"

const int32_t p = 3329;

MU_TEST(test_mul_mod) {

  
  int32_t a = 2000;
  int32_t b = 1796;
  int32_t a_r = 2612;
  int32_t b_r = 2532;

  int32_t c = a*b-((a*b)/p)*p;

  int32_t d = mul_mod(a_r,b_r);
  int32_t cc = red_finala(d);
  
 
  printf("%d %d\n", c, cc);
  
  mu_assert(c == cc, "Mul gresit");


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

  
  int32_t a = 2000;
  int32_t b = 1762;

  int32_t c = a-b ;

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
  
  int32_t A_octave[] = {2429,2845,425,795,1865,1356,624,31,2483,2197,2725,2668,2707,517,1488,2194,1971,803,922,231,2319,613,1075,606,306,3143,1380,2718,1155,531,818,1586,2874,155,304,1442,2619,1712,2169,2159,1479,2634,2864,2014,1679,3200,102,1923,1603,558,681,316,517,931,1732,1999,2024,1094,2276,2159,2187,1973,2637,2158,2373,198,2986,247,1482,449,1157,1290,1057,2220,1124,1019,400,2206,1225,2233,1376,2880,2664,614,1960,1974,2934,2679,2860,2217,2897,3234,1905,36,2306,2145,219,581,3000,1378,2392,2835,1685,1091,1054,2150,543,3192,2518,3246,2277,570,239,2522,838,1990,126,2637,126,818,3232,1075,940,742,2617,630,650,2776,2606,482,2208,868,1949,2149,3066,1896,2996,2306,63,883,2463,1313,1951,2999,97,1806,2830,2104,1771,2453,370,2605,871,1467,2426,1985,2363,658,1015,655,501,664,1249,3120,106,3100,1274,1919,1890,2147,1961,1949,1738,461,2772,1270,3095,2089,1051,2576,1628,1735,3195,2034,655,524,3195,901,2007,1419,157,2334,2344,2825,634,850,2523,2642,672,1604,216,3280,1317,905,1165,1532,3059,777,242,1752,2052,533,1006,1858,2336,1183,1656,1668,2037,2946,2184,1048,104,2825,877,111,1363,1989,1995,659,12,506,1551,2022,3212,1591,1637,2330,1625,2795,774,70,1002,3194,928,987,2717,3005,2883,149,2594,3105,2502,2134,2717,2303};

  for (int i = 0; i<256; i++)
  {
  printf("%d", a[i]);
    mu_assert(a[i] == A_octave[i], "NTT 256 gresit");
  }


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
