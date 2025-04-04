#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "timing.h"

#include "ntt_7681.h"

#define NR_RUNS 10000000

#define VAL_MAX 20000


#define N 256
int main()
{
  
  int32_t i;

  timing start;
  timing finish;
  timing t[2];
  
  double * result = (double *) malloc(NR_RUNS*sizeof(double)); 

  
  _Alignas(32) int32_t a[N];
  
  for (i=0; i<N; i++)
    {
      a[i] = i;
    }
  
  
  timing_now(&start);

  for (i=0; i<NR_RUNS; i++)
    {
      a[0] = i - (i/7681)*7681;
      timing_now(&t[0]);
      ntt_256(a);
      timing_now(&t[1]);
      result[i] = timing_diff(&t[1],&t[0]);
    }

  
  printf("%d ", N);
  for (i=0; i<3*8; i++)
    {
      printf(" %7.0f", result[i+NR_RUNS-3*8]);
    }
  printf("\n");
  timing_now(&finish);


  
  double mean = 0;
  double min = result[0];
  double max = result[0];

  int nb = 0;
  int nb2 = 0;
  
  for (i=0; i<NR_RUNS; i++)
    {
      if (result[i] < 0 || result[i] > VAL_MAX)
	{

	}
      else
	{
	  nb = nb + 1;
	  mean = mean +  result[i];
	  if (result[i] < min) min = result[i];
	  if (result[i] > max) max = result[i];
	}
    }
  mean = mean/nb;

  double std_sq = 0;
  for (i=0; i<NR_RUNS; i++)
    {
      if (result[i] < 0 || result[i] > VAL_MAX)
	{

	}
      else
	{
	  nb2 = nb2 + 1;
	  std_sq = std_sq + (result[i]-mean)*(result[i]-mean);
	}
    }
  
  printf("mean: %g, std: %g, min: %g, max: %g, nb: %d, nb2: %d\n",  mean, sqrt(std_sq/(nb2-1)), min, max, nb, nb2);

  free(result);
 }
