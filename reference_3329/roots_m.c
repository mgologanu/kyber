#include <stdalign.h>
#include <assert.h>
#include <stdint.h>

//r512 sunt inmultite cu R^2, restul doar cu R

const _Alignas(32) int32_t r512[] = {
  1353,3027,1524,2605,1008,491,1689,2081,2087,2189,594,111,1887,2118,2716,2895,2609,1076,1647,1367,3265,2241,1478,1823,1030,865,1389,310,1941,3036,1677,1877,1948,3155,371,2978,691,1760,3288,2632,1467,1636,1180,86,1462,1551,3064,2153,3311,3023,1456,1449,1330,2636,1535,2792,858,1270,1616,840,964,3072,2289,2294,2379,495,1757,3237,1765,44,748,2729,3116,3037,1694,2166,203,122,2074,1968,166,2822,1368,3282,2530,3062,2119,2733,3184,864,1372,21,357,2740,3303,2887,2473,2093,2291,2328,2957,334,2349,3314,3074,2323,2872,2218,1087,1834,1217,715,2168,237,700,1913,2560,243,802,318,2077,2019,1033,916,2256,1733,2829,1487,1976,302,1805,724,2321,2838,1640,1248,1242,1140,2735,3218,1442,1211,613,434,720,2253,1682,1962,64,1088,1851,1506,2299,2464,1940,3019,1388,293,1652,1452,1381,174,2958,351,2638,1569,41,697,1862,1693,2149,3243,1867,1778,265,1176,18,306,1873,1880,1999,693,1794,537,2471,2059,1713,2489,2365,257,1040,1035,950,2834,1572,92,1564,3285,2581,600,213,292,1635,1163,3126,3207,1255,1361,3163,507,1961,47,799,267,1210,596,145,2465,1957,3308,2972,589,26,442,856,1236,1038,1001,372,2995,980,15,255,1006,457,1111,2242,1495,2112,2614,1161,3092,2629,1416,769,3086,2527,3011,1252,1310,2296,2413,1073,1596,500,1842};

static_assert(sizeof(r512)/sizeof(int32_t) == 256, "Wrong initializer list for r512");


const _Alignas(32) int32_t r256[] = {2285,1223,573,2476,3158,516,2648,2931,1493,2036,2500,107,962,1711,1787,448,2970,2777,264,3058,1577,3009,732,1821,287,3047,1727,3082,1855,126,3124,677,2571,652,2004,3239,622,3321,1017,961,1422,1491,1458,1908,2127,2167,411,2264,1812,1015,383,830,182,2663,608,2604,202,1785,3199,2378,1468,1469,1758,2054,1044,2106,2756,853,171,2813,681,398,1836,1293,829,3222,2367,1618,1542,2881,359,552,3065,271,1752,320,2597,1508,3042,282,1602,247,1474,3203,205,2652,758,2677,1325,90,2707,8,2312,2368,1907,1838,1871,1421,1202,1162,2918,1065,1517,2314,2946,2499,3147,666,2721,725,3127,1544,130,951,1861,1860,1571,1275
  //
};

static_assert(sizeof(r256)/sizeof(int32_t) == 128, "Wrong initializer list for r256");


const _Alignas(32) int32_t r128[] = {2285,573,3158,2648,1493,2500,962,1787,2970,264,1577,732,287,1727,1855,3124,2571,2004,622,1017,1422,1458,2127,411,1812,383,182,608,202,3199,1468,1758,1044,2756,171,681,1836,829,2367,1542,359,3065,1752,2597,3042,1602,1474,205,758,1325,2707,2312,1907,1871,1202,2918,1517,2946,3147,2721,3127,130,1861,1571};


static_assert(sizeof(r128)/sizeof(int32_t) == 64, "Wrong initializer list for r128");


const _Alignas(32) int32_t r64[] = {2285,3158,1493,962,2970,1577,287,1855,2571,622,1422,2127,1812,182,202,1468,1044,171,1836,2367,359,1752,3042,1474,758,2707,1907,1202,1517,3147,3127,1861};


static_assert(sizeof(r64)/sizeof(int32_t) == 32, "Wrong initializer list for r64");


const _Alignas(32) int32_t r32[] = {2285,1493,2970,287,2571,1422,1812,202,1044,1836,359,3042,758,1907,1517,3127};

static_assert(sizeof(r32)/sizeof(int32_t) == 16, "Wrong initializer list for r32");

const _Alignas(32) int32_t r16[] = {2285,2970,2571,1812,1044,359,758,1517};

static_assert(sizeof(r16)/sizeof(int32_t) == 8, "Wrong initializer list for r16");

const _Alignas(32) int32_t r8[] = {2285,2571,1044,758};

static_assert(sizeof(r8)/sizeof(int32_t) == 4, "Wrong initializer list for r8");

const _Alignas(32) int32_t r4[] = {2285,1044};

