#ifndef BASE_ITER_CPP
#define BASE_ITER_CPP

#include "../inc/base_iter.h"

base_iter::base_iter()
{
    index = 0;
    size  = 0;
}

base_iter::base_iter(const base_iter& iter)
{
    index = iter.index;
    size  = iter.size;
}

#endif
