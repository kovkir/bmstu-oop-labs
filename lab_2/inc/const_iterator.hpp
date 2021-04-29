#ifndef CONST_CLASS_ITERATOR_HPP
#define CONST_CLASS_ITERATOR_HPP

#include <iostream>
#include <ctime>

#include "class_vector.h"
#include "class_const_iterator.h"

template<class Type>
Const_Iterator<Type>::Const_Iterator(const Const_Iterator<Type> &iter)
{
    this->index    = iter.index;
    this->size     = iter.size;
    this->iter_ptr = iter.iter_ptr;
}

template<class Type>
Const_Iterator<Type>::Const_Iterator(const Vector<Type> &vec)
{
    this->index    = 0;
    this->size     = vec.size;
    this->iter_ptr = vec.vec_ptr;
}

template<class Type>
const Type &Const_Iterator<Type>::operator * () const
{
    check_object(__LINE__);
    check_valid_iter(__LINE__);

    return *get_current_ptr();
}

template<class Type>
const Type *Const_Iterator<Type>::operator -> () const
{
    check_object(__LINE__);
    check_valid_iter(__LINE__);
    
    return get_current_ptr();
}

template<class Type>
Const_Iterator<Type>::operator bool() const
{
    check_object(__LINE__);
    
    if (this->index >= this->size || this->size == 0)
        return false;
    else
        return true;
}

template<class Type>
bool Const_Iterator<Type>::operator == (const Const_Iterator<Type> &comparator) const
{   
    check_object(__LINE__);

    return this->index == comparator.index;
}

template<class Type>
bool Const_Iterator<Type>::operator != (const Const_Iterator<Type> &comparator) const
{
    check_object(__LINE__);
    
    return this->index != comparator.index;
}

template<class Type>
bool Const_Iterator<Type>::operator < (const Const_Iterator<Type> &comparator) const
{
    check_object(__LINE__);
    
    return this->index < comparator.index;
}

template<class Type>
bool Const_Iterator<Type>::operator > (const Const_Iterator<Type> &comparator) const
{
    check_object(__LINE__);
    
    return this->index > comparator.index;
}

template<class Type>
bool Const_Iterator<Type>::operator <= (const Const_Iterator<Type> &comparator) const
{
    check_object(__LINE__);
    
    return this->index <= comparator.index;
}

template<class Type>
bool Const_Iterator<Type>::operator >= (const Const_Iterator<Type> &comparator) const
{
    check_object(__LINE__);
    
    return this->index >= comparator.index;
}

template<class Type>
Const_Iterator<Type> &Const_Iterator<Type>::operator += (int number)
{
    check_object(__LINE__);
    
    this->index += number;
    
    return *this;
}

template<class Type>
Const_Iterator<Type> &Const_Iterator<Type>::operator -= (int number)
{
    check_object(__LINE__);

    this->index -= number;
    
    return *this;
}

template<class Type>
Const_Iterator<Type> Const_Iterator<Type>::operator + (int number) const
{
    check_object(__LINE__);

    Const_Iterator<Type> iter(*this);
    iter += number;
    
    return iter;
}

template<class Type>
Const_Iterator<Type> Const_Iterator<Type>::operator - (int number) const
{
    check_object(__LINE__);
    
    Const_Iterator<Type> iter(*this);
    iter -= number;
    
    return iter;
}

template<class Type>
Const_Iterator<Type> Const_Iterator<Type>::operator ++ (int)
{
    check_object(__LINE__);

    ++(*this);

    return *this;
}

template<class Type>
Const_Iterator<Type> &Const_Iterator<Type>::operator ++ ()
{
    check_object(__LINE__);

    (this->index)++;

    return *this;
}

template<class Type>
Const_Iterator<Type> Const_Iterator<Type>::operator -- (int)
{
    check_object(__LINE__);

    --(*this);

    return *this;
}

template<class Type>
Const_Iterator<Type> &Const_Iterator<Type>::operator -- ()
{
    check_object(__LINE__);

    (this->index)--;
    
    return *this;
}

template<class Type>
Const_Iterator<Type> &Const_Iterator<Type>::operator = (const Const_Iterator<Type> &iter)
{
    check_object(__LINE__);
    
    this->iter_ptr = iter.iter_ptr;

    return *this;
}

template<class Type>
Type *Const_Iterator<Type>::get_current_ptr() const
{
    std::shared_ptr<Type> copy_ptr = this->iter_ptr.lock();

    return copy_ptr.get() + this->index;
}

template<class Type>
void Const_Iterator<Type>::check_object(int line) const
{
    if (this->iter_ptr.expired())
    {
        time_t time_ = time(NULL);
        throw deleted_object(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

template<typename Type>
void Const_Iterator<Type>::check_valid_iter(int line) const
{
    if (this->index >= this->size)
    {
        time_t time_ = time(NULL);
        throw invalid_iterator(__FILE__, typeid(*this).name(), line, ctime(&time_));
    }
}

#endif
