#ifndef CLASS_CONST_ITERATOR_H
#define CLASS_CONST_ITERATOR_H

#include <memory>

#include "base_iter.h"

template<typename Type>
class Vector;

template<typename Type>
class Const_Iterator : public base_iter
{
public:
    Const_Iterator(const Const_Iterator<Type> &iter);
    Const_Iterator(const Vector<Type> &vec);
    
    const Type &operator * () const;
    const Type *operator ->() const;
    operator bool() const;
    
    bool operator == (const Const_Iterator<Type> &comparator) const;
    bool operator != (const Const_Iterator<Type> &comparator) const;
    bool operator <  (const Const_Iterator<Type> &comparator) const;
    bool operator >  (const Const_Iterator<Type> &comparator) const;
    bool operator <= (const Const_Iterator<Type> &comparator) const;
    bool operator >= (const Const_Iterator<Type> &comparator) const;

    Const_Iterator<Type>  operator +  (int number) const;
    Const_Iterator<Type> &operator += (int number);
    Const_Iterator<Type>  operator -  (int number) const;
    Const_Iterator<Type> &operator -= (int number);

    Const_Iterator<Type> &operator ++ ();
    Const_Iterator<Type>  operator ++ (int);
    Const_Iterator<Type> &operator -- ();
    Const_Iterator<Type>  operator -- (int);
    
    Const_Iterator<Type> &operator = (const Const_Iterator<Type> &iter);

protected:
    Type *get_current_ptr() const;

    void check_object(int line) const;
    void check_valid_iter(int line) const;

private:
    std::weak_ptr<Type> iter_ptr;
};

#include "const_iterator.hpp"

#endif 
