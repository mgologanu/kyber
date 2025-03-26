#include <stdalign.h>
#include <assert.h>


onst _Alignas(32) uint32 d256[] = {
};

static_assert(sizeof(d256)/sizeof(double) == 128, "Wrong initializer list for d256");
