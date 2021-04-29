#include "../inc/base_vector.h"

base_Vector::base_Vector()
{
    this->size = 0;
}

bool base_Vector::is_empty() const noexcept
{
    return !size;
}

int base_Vector::get_size() const noexcept
{
    return size;
}
