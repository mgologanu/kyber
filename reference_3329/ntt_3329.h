#ifndef _NTT_3329_H
#define _NTT_3329_H       1


int32_t mul_mod( int32_t a, int32_t b);
int32_t add_mod( int32_t a, int32_t b);
int32_t sub_mod( int32_t a, int32_t b);
int32_t red_finala(int32_t a);


// void pass(int32_t *a, int32_t *r, int n);
//void pass_vectors(int32_t *a, int32_t *r, int n);
void pass_struc(int32_t *a, int32_t *r, int n);




extern int32_t r256[];
extern int32_t r128[];
extern int32_t r64[];
extern int32_t r32[];
extern int32_t r16[];
extern int32_t r8[];
extern int32_t r4[];
extern int32_t r2[];


void ntt_128(int32_t * a);
void ntt_64(int32_t * a);
void ntt_32(int32_t * a);
void ntt_16(int32_t * a);
void ntt_8(int32_t * a);
void ntt_4(int32_t * a);
void ntt_2(int32_t * a);

void ntt_v_256(int32_t * a);
void ntt_v_128(int32_t * a);
void ntt_v_64(int32_t * a);
void ntt_v_32(int32_t * a);
void ntt_v_16(int32_t * a);
void ntt_v_8(int32_t * a);
void ntt_v_4(int32_t * a);


  

#endif /* ntt_3329.h */
