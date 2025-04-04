
#include<stdint.h>
#include<stdio.h>


typedef struct {
  int32_t a;
  int32_t b;
} pereche;


pereche  struc_mul_scalar(pereche x, int32_t u)
{
  pereche y;
  y.a = x.a * u;
  y.b = x.b * u;

  return y;
 
}

void mul_scalar2(pereche x, int32_t u, pereche * py)
{
  //  (*py).a = x.a * u;
  // (*py).b = x.b * u;

  py->a = x.a * u;
  py->b = x.b * u;
  
}

/*
int main()
{

  pereche x;

  x.a = 1;
  x.b = 2;

  pereche y;

  int32_t u = 4;

  // y =  struc_mul_scalar(x, u); 

  // printf("%d %d\n", y.a, y.b); 

  mul_scalar2(x, u, &y);
  
  printf("%d %d\n", y.a, y.b);


  pereche vec[2] = {{0,1},{2,3}};

  printf("%d %d\n", vec[0].a, vec[0].b);
  printf("%d %d\n", vec[1].a, vec[1].b);

  printf("%d %d\n", vec->a, vec->b);

  printf("%d %d\n", (vec+1)->a, (vec+1)->b);


  int32_t aa[8] = {1,2,3,4,5,6,7,8};

  pereche * v;

  v = (pereche *) aa;

  printf("\n");
  printf("%d %d\n", v[0].a, v[0].b);
  printf("%d %d\n", v[1].a, v[1].b);
  printf("%d %d\n", v[2].a, v[2].b);
  printf("%d %d\n", v[3].a, v[3].b);
  
  
  

}
*/


#include "ntt_3329.h"
  
void pass_struc(int32_t *a, int32_t *r, int n)
{
  pereche * v;

  v = (pereche *) a;


  for (int i=0; i<n; i++) 
    {
      //     t1 = add_mod( a[i], a[i+n]) ;
      //     t2 = sub_mod( a[i], a[i+n]);

      pereche t1;

      t1.a = v[i].a + v[i+n].a;
      t1.b= v[i].b + v[i+n].b;

      pereche t2;

      t2.a = v[i].a - v[i+n].a;
      t2.b= v[i].b - v[i+n].b;

      pereche t2_redus;

      t2_redus.a =  mul_mod(t2.a, r[i]); // inmultirea Montgomery
      t2_redus.b =  mul_mod(t2.b, r[i]);
      
      
      a[2*i] = t1.a;
      a[2*i+1] = t1.b;
      a[2*i+2*n] = t2_redus.a;
      a[2*i+1+2*n] = t2_redus.b;
      
    }
  
}
  
