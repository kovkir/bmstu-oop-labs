#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <cmath>
#include <stdarg.h>

#include "class_vector.h"
#include "class_iterator.h"
#include "class_const_iterator.h"
#include "errors.h"

#define EPS 1e-6
#define CONVERSION_TO_DEGREES(angle) ((angle) * 180 / M_PI)

template<typename Type>
Iterator<Type> Vector<Type>::begin(void) noexcept
{
    Iterator<Type> iter(*this);
    return iter;
}

template<typename Type>
Iterator<Type> Vector<Type>::end(void) noexcept
{
    Iterator<Type> iter(*this);
    return iter + this->size;
}

template<typename Type>
Const_Iterator<Type> Vector<Type>::begin(void) const noexcept
{
    Const_Iterator<Type> iter(*this);
    return iter;
}

template<typename Type>
Const_Iterator<Type> Vector<Type>::end(void) const noexcept
{
    Const_Iterator<Type> iter(*this);
    return iter + this->size;
}

template<typename Type>
Const_Iterator<Type> Vector<Type>::c_begin(void) const noexcept
{
    Const_Iterator<Type> iter(*this);
    return iter;
}

template<typename Type>
Const_Iterator<Type> Vector<Type>::c_end(void) const noexcept
{
    Const_Iterator<Type> iter(*this);
    return iter + this->size;
}

template<typename Type>
Vector<Type>::Vector()
{
    this->size = 0;
    this->mem_alloc(size, __LINE__);
}

template<typename Type>
Vector<Type>::Vector(int size)
{
    check_vec_size(size, __LINE__);
    
    this->size = size;
    this->mem_alloc(size, __LINE__);
    
    Iterator<Type> iter = this->begin();

    for (; iter; iter++)
        *iter = 0;
}

template<typename Type>
Vector<Type>::Vector(int size, Type elem, ...)
{
    check_vec_size(size, __LINE__);

    this->size = size;
    this->mem_alloc(size, __LINE__);

    Iterator<Type> iter = this->begin();
    va_list args;

    va_start(args, elem);
    for (; iter; iter++)
    {
        *iter = elem;
        elem = va_arg(args, Type);
    }
    va_end(args);
}

template<typename Type>
Vector<Type>::Vector(int size, const Type *arr)
{
    check_vec_size(size, __LINE__);
    check_array(arr, __LINE__);
    
    this->size = size;
    this->mem_alloc(size, __LINE__);

    Iterator<Type> iter = this->begin();

    for (int i = 0; iter; i++, iter++)
        *iter = arr[i];
}

template<typename Type>
Vector<Type>::Vector(std::initializer_list<Type> list)
{
    this->size = list.size();
    this->mem_alloc(size, __LINE__);
    
    Iterator<Type> iter = this->begin();

    for (auto &elem : list)
    {
        *iter = elem;
        iter++;
    }
}

template <typename Type>
template <typename Type1>
Vector<Type>::Vector(Type1 begin, Type1 end)
{   
    int amount = 0;
    for (auto iter = begin; iter != end; iter++)
        amount++;

    check_vec_size(amount, __LINE__);

    this->size = amount;
    this->mem_alloc(amount, __LINE__);

    int i = 0;
    for (auto iter = begin; iter != end; iter++, i++)
        (*this)[i] = *iter;
}

template<typename Type>
Vector<Type>::Vector(const Vector<Type> &vec)
{
    this->size = vec.size;
    this->mem_alloc(size, __LINE__);
    
    Iterator<Type> new_iter = this->begin();
    Const_Iterator<Type> old_iter = vec.begin();

    for (; new_iter; new_iter++, old_iter++)
        *new_iter = *old_iter;
}

template<typename Type>
Vector<Type>::Vector(Vector<Type> &&vec) noexcept
{
    this->size = vec.size;
    this->vec_ptr = vec.vec_ptr;
    vec.vec_ptr.reset();
}

template <typename Type>
bool Vector<Type>::operator == (const Vector<Type> &vec) const
{
    if (this->size != vec.size)
        return false;

    Const_Iterator<Type> iter_1 = this->begin();
    Const_Iterator<Type> iter_2 = vec.begin();
    
    bool is_equalual = true;

    for (; is_equalual  &&iter_1; iter_1++, iter_2++)
        if (fabs(*iter_1 - *iter_2) > EPS)
            is_equalual = false;
    
    return is_equalual;
}

template <typename Type>
bool Vector<Type>::operator != (const Vector<Type> &vec) const
{
    return !(*this == vec);
}

template <typename Type>
bool Vector<Type>::is_equal(const Vector<Type> &vec) const
{
    return *this == vec;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator = (const Vector<Type> &vec)
{
    this->size = vec.size;
    this->mem_alloc(size, __LINE__);
    
    Iterator<Type> new_iter = this->begin();
    Const_Iterator<Type> old_iter = vec.begin();

    for (; new_iter; new_iter++, old_iter++)
        *new_iter = *old_iter;
    
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator = (std::initializer_list<Type> list)
{
    this->size = list.size();
    this->mem_alloc(size, __LINE__);
    
    Iterator<Type> iter = this->begin();

    for (auto &elem : list)
    {
        *iter = elem;
        iter++;
    }

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator = (Vector<Type> &&vec) noexcept
{
    this->size = vec.size;
    this->mem_alloc(size, __LINE__);
    this->vec_ptr = vec.vec_ptr;
    vec.vec_ptr.reset();
    
    return *this;
}

template<typename Type>
Type &Vector<Type>::get_elem(int index)
{
    check_vec_size(this->size, __LINE__);
    check_index(index, __LINE__);
    
    Iterator<Type> iter = this->begin();

    for (int i = 0; i < index; i++, iter++);
    
    return *iter;
}

template<typename Type>
const Type &Vector<Type>::get_elem(int index) const
{
    check_vec_size(this->size, __LINE__);
    check_index(index, __LINE__);
    
    Const_Iterator<Type> iter = this->begin();

    for (int i = 0; i < index; i++, iter++);
    
    return *iter;
}

template<typename Type>
void Vector<Type>::set_elem(int index, const Type &number)
{
    check_index(index, __LINE__);
    
    get_elem(index) = number;
}

template<typename Type>
Type &Vector<Type>::operator [] (int index)
{
    return get_elem(index);
}

template<typename Type>
const Type &Vector<Type>::operator [] (int index) const
{
    return get_elem(index);
}

template<typename Type>
Vector<Type> &Vector<Type>::sum_equal(const Type &number)
{
    *this += number;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::sum_equal(const Vector<Type> &vec)
{
    *this += vec;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::sub_equal(const Type &number)
{
    *this -= number;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::sub_equal(const Vector<Type> &vec)
{
    *this -= vec;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::mult_equal(const Type &number)
{
    *this *= number;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::mult_equal(const Vector<Type> &vec)
{
    *this *= vec;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::div_equal(const Type &number)
{
    *this /= number;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::div_equal(const Vector<Type> &vec)
{
    *this /= vec;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::vec_mult_equal(const Vector<Type> &vec)
{
    *this ^= vec;

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::sum_number(const Type &number) const
{
    return *this + number;
}

template<typename Type>
Vector<Type> Vector<Type>::sum_vector(const Vector<Type> &vec) const
{
    return *this + vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::sum_number(const Type1 &number) const
{
    return *this + number;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::sum_vector(const Vector<Type1> &vec) const
{
    return *this + vec;
}

template<typename Type>
Vector<Type> Vector<Type>::sub_number(const Type &number) const
{
    return *this - number;
}

template<typename Type>
Vector<Type> Vector<Type>::sub_vector(const Vector<Type> &vec) const
{
    return *this - vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::sub_number(const Type1 &number) const
{
    return *this - number;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::sub_vector(const Vector<Type1> &vec) const
{
    return *this - vec;
}

template<typename Type>
Vector<Type> Vector<Type>::mult_number(const Type &number) const
{
    return *this * number;
}

template<typename Type>
Vector<Type> Vector<Type>::mult_vector(const Vector<Type> &vec) const
{
    return *this * vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::mult_number(const Type1 &number) const
{
    return *this * number;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::mult_vector(const Vector<Type1> &vec) const
{
    return *this * vec;
}

template<typename Type>
Vector<Type> Vector<Type>::div_number(const Type &number) const
{
    return *this / number;
}

template<typename Type>
Vector<Type> Vector<Type>::div_vector(const Vector<Type> &vec) const
{
    return *this / vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::div_number(const Type1 &number) const
{
    return *this / number;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::div_vector(const Vector<Type1> &vec) const
{
    return *this / vec;
}

template<typename Type>
Vector<Type> Vector<Type>::vec_mult(const Vector<Type> &vec) const
{
    return *this ^ vec;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator += (const Type &number)
{
    *this = *this + number;
    
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator += (const Vector<Type> &vec)
{
    *this = *this + vec;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator -= (const Type &number)
{
    *this = *this - number;
    
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator -= (const Vector<Type> &vec)
{
    *this = *this - vec;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator *= (const Type &number)
{
    *this = *this * number;
    
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator *= (const Vector<Type> &vec)
{
    *this = *this * vec;

    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator /= (const Type &number)
{
    *this = *this / number;
    
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator /= (const Vector<Type> &vec)
{
    *this = *this / vec;
    
    return *this;
}

template<typename Type>
Vector<Type> &Vector<Type>::operator ^= (const Vector<Type> &vec)
{
    check_size_for_vec_mul(this->size, __LINE__);
    check_size_for_vec_mul(vec.size, __LINE__);
    
    double x = (*this)[1] * vec[2] - (*this)[2] * vec[1];
    double y = (*this)[2] * vec[0] - (*this)[0] * vec[2];
    double z = (*this)[0] * vec[1] - (*this)[1] * vec[0];
    
    *this = Vector<Type>(3, x, y, z);

    return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator + (const Type &number) const
{
    check_vec_size(this->size, __LINE__);
    
    Vector<Type> res_vec(*this);
    Iterator<Type> iter = res_vec.begin();

    for (; iter; iter++)
        *iter += number;
    
    return res_vec;
}

template<typename Type>
Vector<Type> Vector<Type>::operator + (const Vector<Type> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.size, __LINE__);

    Vector<Type> res_vec(*this);
    Iterator<Type> res_iter = res_vec.begin();
    Const_Iterator<Type> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
        *res_iter += *iter;

    return res_vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator + (const Type1 &number) const
{
    check_vec_size(this->size, __LINE__);
    
    Vector<decltype((*this)[0] + number)> res_vec(*this);
    Iterator<decltype((*this)[0] + number)> iter = res_vec.begin();

    for (; iter; iter++)
        *iter += number;
    
    return res_vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator + (const Vector<Type1> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.get_size(), __LINE__);

    Vector<decltype((*this)[0] + vec[0])> res_vec(*this);
    Iterator<decltype((*this)[0] + vec[0])> res_iter = res_vec.begin();
    Const_Iterator<Type1> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
        *res_iter += *iter;
    
    return res_vec;
}

template<typename Type>
Vector<Type> Vector<Type>::operator - (const Type &number) const
{
    return *this + number * (-1);
}

template<typename Type>
Vector<Type> Vector<Type>::operator - (const Vector<Type> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.size, __LINE__);

    Vector<Type> res_vec(*this);
    Iterator<Type> res_iter = res_vec.begin();
    Const_Iterator<Type> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
        *res_iter -= *iter;

    return res_vec;
};

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator - (const Type1 &number) const
{
    return *this + number * (-1);
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator - (const Vector<Type1> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.get_size(), __LINE__);

    Vector<decltype((*this)[0] + vec[0])> res_vec(*this);
    Iterator<decltype((*this)[0] + vec[0])> res_iter = res_vec.begin();
    Const_Iterator<Type1> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
        *res_iter -= *iter;
    
    return res_vec;
};

template<typename Type>
Vector<Type> Vector<Type>::operator * (const Type &number) const
{
    check_vec_size(this->size, __LINE__);
    
    Vector<Type> res_vec(*this);
    Iterator<Type> iter = res_vec.begin();

    for (; iter; iter++)
        *iter *= number;
    
    return res_vec;
}

template<typename Type>
Vector<Type> Vector<Type>::operator * (const Vector<Type> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.size, __LINE__);

    Vector<Type> res_vec(*this);
    Iterator<Type> res_iter = res_vec.begin();
    Const_Iterator<Type> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
        *res_iter *= *iter;
    
    return res_vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator * (const Type1 &number) const
{
    check_vec_size(this->size, __LINE__);
    
    Vector<decltype((*this)[0] + number)> res_vec(*this);
    Iterator<decltype((*this)[0] + number)> iter = res_vec.begin();

    for (; iter; iter++)
        *iter *= number;
    
    return res_vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator * (const Vector<Type1> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.get_size(), __LINE__);

    Vector<decltype((*this)[0] + vec[0])> res_vec(*this);
    Iterator<decltype((*this)[0] + vec[0])> res_iter = res_vec.begin();
    Const_Iterator<Type1> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
        *res_iter *= *iter;
    
    return res_vec;
}

template<typename Type>
Vector<Type> Vector<Type>::operator / (const Type &number) const
{
    check_number_is_zero(number, __LINE__);
    check_vec_size(this->size, __LINE__);
    
    Vector<Type> res_vec(*this);
    Iterator<Type> iter = res_vec.begin();

    for (; iter; iter++)
        *iter /= number;
    
    return res_vec;
}

template<typename Type>
Vector<Type> Vector<Type>::operator / (const Vector<Type> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.size, __LINE__);

    Vector<Type> res_vec(*this);
    Iterator<Type> res_iter = res_vec.begin();
    Const_Iterator<Type> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
        *res_iter /= *iter;

    return res_vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator / (const Type1 &number) const
{
    check_number_is_zero(number, __LINE__);
    check_vec_size(this->size, __LINE__);
    
    Vector<decltype((*this)[0] + number)> res_vec(*this);
    Iterator<decltype((*this)[0] + number)> iter = res_vec.begin();

    for (; iter; iter++)
        *iter /= number;
    
    return res_vec;
}

template<typename Type>
template<typename Type1>
decltype(auto) Vector<Type>::operator / (const Vector<Type1> &vec) const
{
    check_vec_size(this->size, __LINE__);
    ckeck_sizes_are_equal(vec.get_size(), __LINE__);

    Vector<decltype((*this)[0] + vec[0])> res_vec(*this);
    Iterator<decltype((*this)[0] + vec[0])> res_iter = res_vec.begin();
    Const_Iterator<Type1> iter = vec.begin();

    for (; res_iter; res_iter++, iter++)
    {
        check_number_is_zero(*iter, __LINE__);
        *res_iter /= *iter;
    }
    
    return res_vec;
}

template<typename Type>
Vector<Type> Vector<Type>::operator ^ (const Vector<Type> &vec) const
{
    check_size_for_vec_mul(this->size, __LINE__);
    check_size_for_vec_mul(vec.size, __LINE__);
    
    double x = (*this)[1] * vec[2] - (*this)[2] * vec[1];
    double y = (*this)[2] * vec[0] - (*this)[0] * vec[2];
    double z = (*this)[0] * vec[1] - (*this)[1] * vec[0];
    
    Vector<Type> res_vec(3, x, y, z);

    return res_vec;
}

template <typename Type>
Vector<Type> Vector<Type>::operator - (void)
{
    check_vec_size(this->size, __LINE__);

    Vector<Type> res_vec(*this);
    Iterator<Type> iter = res_vec.begin();

    for (; iter; iter++)
        *iter = -*iter;
    
    return res_vec;
}

template<typename Type>
Vector<Type> Vector<Type>::negative(void)
{
    return -*this;
}

template<typename Type>
Type Vector<Type>::sum_elements(void) const
{
    check_vec_size(this->size, __LINE__);
    
    Const_Iterator<Type> iter = this->begin();
    Type sum = 0;

    for (; iter; iter++)
        sum += *iter;
    
    return sum;
}

template<typename Type>
Vector<Type> Vector<Type>::get_normalize_vector(void) const
{
    check_vec_size(this->size, __LINE__);

    Vector<Type> res_vec(*this);    
    Iterator<Type> iter = res_vec.begin();

    double len = this->length();
    check_number_is_zero(len, __LINE__);

    res_vec.div_equal(len);
    
    return res_vec;
}

template<typename Type>
double Vector<Type>::operator & (const Vector<Type> &vec) const
{
    return this->mult_vector(vec).sum_elements();
}

template<typename Type>
double Vector<Type>::scalar_mult(const Vector<Type> &vec) const
{
    return this->mult_vector(vec).sum_elements();
}

template<typename Type>
double Vector<Type>::length(void) const
{
    check_vec_size(this->size, __LINE__);
    
    Const_Iterator<Type> iter = this->begin();
    double sum = 0;
    
    for (; iter; iter++)
        sum += *iter * *iter;
    
    return sqrt(sum);
}

template<typename Type>
double Vector<Type>::angle(const Vector<Type> &vec) const
{
    check_vec_size(this->size, __LINE__);
    check_vec_size(vec.size, __LINE__);
    
    double angle = (*this & vec)/(this->length() * vec.length());

    return CONVERSION_TO_DEGREES(acos(angle));
}

template<typename Type>
bool Vector<Type>::is_collinearity(const Vector<Type> &vec) const
{
    if (this->angle(vec) < EPS)
        return true;
    else
        return false;
}

template<typename Type>
bool Vector<Type>::is_orthogonality(const Vector<Type> &vec) const
{
    if (abs(this->angle(vec)) < EPS + 90)
        return true;
    else
        return false;
}

template<typename Type>
bool Vector<Type>::is_normalized(void) const
{
    if (abs(this->length() - 1) < EPS)
        return true;
    else
        return false;
}

template <typename Type>
void Vector<Type>::mem_alloc(int size, int line)
{
    time_t time_ = time(NULL);

    try
    {
        this->vec_ptr.reset(new Type[size]);
    }
    catch (std::bad_alloc &exception)
    {
        throw memory_error(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
void Vector<Type>::check_vec_size(const int &vec_size, int line) const
{
    if (vec_size <= 0)
    {
        time_t time_ = time(NULL);
        throw neg_size_error(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
void Vector<Type>::check_array(const Type *arr, int line) const
{
    if (!arr)
    {
        time_t time_ = time(NULL);
        throw invalid_arr_error(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
void Vector<Type>::check_index(int index, int line) const
{
    if (index < 0 || index >= this->size)
    {
        time_t time_ = time(NULL);
        throw index_out_of_range(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
void Vector<Type>::check_number_is_zero(const Type &number, int line) const
{   
    if (!number)
    {
        time_t time_ = time(NULL);
        throw div_zero_error(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
void Vector<Type>::check_size_for_vec_mul(const int &vec_size, int line) const
{
    if (vec_size != 3)
    {
        time_t time_ = time(NULL);
        throw invalid_size_for_vec_mul(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
void Vector<Type>::ckeck_sizes_are_equal(const int &vec_size, int line) const
{
    if (this->size != vec_size)
    {
        time_t time_ = time(NULL);
        throw sizes_are_not_equal(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
std::ostream &operator << (std::ostream &ostr, const Vector<Type> &vec)
{    
    if (vec.is_empty())
    {
        ostr << "Пустой вектор.";
        return ostr;
    }
    
    Iterator<Type> iter(vec);

    ostr << '(' << *iter;
    for (iter++; iter; iter++)
        ostr << ", " << *iter;
    ostr << ')';
    
    return ostr;
}

#endif
