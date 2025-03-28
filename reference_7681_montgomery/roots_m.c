#include <stdalign.h>
#include <assert.h>
#include <stdint.h>

//r512 sunt inmultite cu R^2, restul doar cu R

const _Alignas(32) int32_t r512[] = {
  5569,813,2862,5030,4981,472,953,4772,4753,7237,7110,5926,1843,4844,4638,7314,4320,781,4620,1582,6221,5319,3986,2808,3196,3003,6405,6732,769,3359,289,6686,2336,2243,5912,1652,7176,1340,5114,6127,1842,5379,2610,1592,871,2556,7439,6574,808,5537,2571,7095,6270,2147,3505,6670,3215,519,6532,235,4852,358,495,4010,5330,5782,2073,4690,2537,2242,6447,7305,1454,5572,6889,1265,6834,7647,2828,177,5158,5630,6583,3674,746,302,7412,5657,7500,4663,1620,1253,5573,6354,3293,4875,3415,1053,5039,166,3362,6365,5089,4140,4909,587,876,7562,2217,4460,2691,4343,3838,5178,2611,1057,2899,597,3207,4799,5670,545,303,6877,4,5541,431,7526,6115,581,4086,3075,6290,6809,5660,5895,3066,3424,3919,248,5578,3679,5752,2761,5298,7540,6306,5930,7384,5275,4483,5748,4901,4867,14,191,5349,3298,2200,5874,6620,6922,6653,4629,4448,1430,3050,4303,2195,868,4161,1355,4770,5823,3181,3347,6709,5393,2801,6941,4169,4756,5632,5513,49,4509,7200,3862,19,5197,127,1184,4083,4680,206,5005,2994,3539,3842,3038,3042,902,1333,1178,7293,193,4279,7354,5963,5091,3070,1284,4350,93,4012,4260,2157,5836,3907,6668,4285,4144,2769,1018,721,5996,2798,865,5766,2952,2966,3157,825,4123,6323,4516,3455,2696,1668,6297,3064,4494,7544,4166,6361,7229,3709,5064,2153,295,3476,6823,5851,3563,6364,5624
  //#include "roots/puteri_512.txt"
};

static_assert(sizeof(r512)/sizeof(int32_t) == 256, "Wrong initializer list for r512");


const _Alignas(32) int32_t r256[] = {4088,2665,4877,5109,7064,727,7285,3417,1414,2579,7132,373,3706,3750,810,6627,5487,5548,6360,1681,6385,6295,438,4949,5186,1919,5146,5290,5444,2835,3992,2,4056,6898,2043,3145,2830,1533,5800,2789,2876,2649,3153,3692,6082,6291,7,6515,1100,3310,7167,2224,1525,4938,5921,2385,5431,7195,5241,5925,2816,3865,3600,3850,3904,5882,103,1497,1921,1521,4507,7487,5980,6822,1535,2175,2006,4919,5794,5983,5225,4201,1399,2883,1483,4253,7002,5568,834,1532,3772,7021,5695,4917,1738,6766,3182,1056,6250,1350,3364,1464,4126,2919,5362,5521,5371,730,5688,6083,638,3456,3696,6513,4725,4093,5124,6760,6376,3405,121,7277,2555,4546,2088,2233,4415,5255
  //
};

static_assert(sizeof(r256)/sizeof(int32_t) == 128, "Wrong initializer list for r256");


const _Alignas(32) int32_t r128[] = {4088,4877,7064,7285,1414,7132,3706,810,5487,6360,6385,438,5186,5146,5444,3992,4056,2043,2830,5800,2876,3153,6082,7,1100,7167,1525,5921,5431,5241,2816,3600,3904,103,1921,4507,5980,1535,2006,5794,5225,1399,1483,7002,834,3772,5695,1738,3182,6250,3364,4126,5362,5371,5688,638,3696,4725,5124,6376,121,2555,2088,4415};


static_assert(sizeof(r128)/sizeof(int32_t) == 64, "Wrong initializer list for r128");


const _Alignas(32) int32_t r64[] = {4088,7064,1414,3706,5487,6385,5186,5444,4056,2830,2876,6082,1100,1525,5431,2816,3904,1921,5980,2006,5225,1483,834,5695,3182,3364,5362,5688,3696,5124,121,2088};


static_assert(sizeof(r64)/sizeof(int32_t) == 32, "Wrong initializer list for r64");


const _Alignas(32) int32_t r32[] = {4088,1414,5487,5186,4056,2876,1100,5431,3904,5980,5225,834,3182,5362,3696,121};

static_assert(sizeof(r32)/sizeof(int32_t) == 16, "Wrong initializer list for r32");

const _Alignas(32) int32_t r16[] = {4088,5487,4056,1100,3904,5225,3182,3696};

static_assert(sizeof(r16)/sizeof(int32_t) == 8, "Wrong initializer list for r16");

const _Alignas(32) int32_t r8[] = {4088,4056,3904,3182};

static_assert(sizeof(r8)/sizeof(int32_t) == 4, "Wrong initializer list for r8");

const _Alignas(32) int32_t r4[] = {4088,3904};

