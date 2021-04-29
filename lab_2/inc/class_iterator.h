#ifndef CLASS_ITERATOR_H
#define CLASS_ITERATOR_H

#include <memory>

#include "base_iter.h"

template<typename Type>
class Vector;

template<typename Type>
class Iterator : public base_iter
{
public:
    Iterator(const Iterator<Type> &iter);
    Iterator(const Vector<Type> &vec);
    
          Type &operator * ();
    const Type &operator * () const;
          Type *operator ->();
    const Type *operator ->() const;
    operator bool() const;
    
    bool operator == (const Iterator<Type> &comparator) const;
    bool operator != (const Iterator<Type> &comparator) const;
    bool operator <  (const Iterator<Type> &comparator) const;
    bool operator >  (const Iterator<Type> &comparator) const;
    bool operator <= (const Iterator<Type> &comparator) const;
    bool operator >= (const Iterator<Type> &comparator) const;

    Iterator<Type>  operator +  (int number) const;
    Iterator<Type> &operator += (int number);
    Iterator<Type>  operator -  (int number) const;
    Iterator<Type> &operator -= (int number);

    Iterator<Type> &operator ++ ();
    Iterator<Type>  operator ++ (int);
    Iterator<Type> &operator -- ();
    Iterator<Type>  operator -- (int);
    
    Iterator<Type> &operator = (const Iterator<Type> &iter);

protected:
    Type *get_current_ptr() const;

    void check_object(int line) const;
    void check_valid_iter(int line) const;

private:
    std::weak_ptr<Type> iter_ptr;
};

#include "iterator.hpp"

#endif 
