#ifndef CLASS_VECTOR_H
#define CLASS_VECTOR_H

#include <memory>

#include "base_vector.h"
#include "class_iterator.h"
#include "class_const_iterator.h"

template<typename Type>
class Vector: public base_Vector
{
public:
    friend class Iterator<Type>;
    friend class Const_Iterator<Type>;

    Vector();
    explicit Vector(int size);
    Vector(int size, Type elem, ...);
    Vector(int size, const Type *arr);
    Vector(std::initializer_list<Type> list);
    template <typename Type1>
    Vector(Type1 begin, Type1 end);
    
    explicit Vector(const Vector<Type> &vec);
    Vector(Vector<Type> &&vec) noexcept;
    virtual ~Vector() = default;
    
    Vector<Type> get_normalize_vector(void) const;
    double length(void) const;
    double angle(const Vector<Type> &vec) const;
    bool is_collinearity(const Vector<Type> &vec) const;
    bool is_orthogonality(const Vector<Type> &vec) const;
    bool is_normalized(void) const;

    Iterator<Type> begin(void) noexcept;
    Iterator<Type> end(void)   noexcept;
    Const_Iterator<Type> c_begin(void) const noexcept;
    Const_Iterator<Type> c_end(void)   const noexcept;
    Const_Iterator<Type> begin(void)   const noexcept;
    Const_Iterator<Type> end(void)     const noexcept;

    Vector<Type> operator - (void);
    Vector<Type> negative(void);

          Type &operator [] (int index);
    const Type &operator [] (int index) const;
          Type &get_elem(int index);
    const Type &get_elem(int index) const;
          void  set_elem(int index, const Type &number);

    bool operator == (const Vector<Type> &vec) const;
    bool operator != (const Vector<Type> &vec) const;
    bool is_equal(const Vector<Type> &vec) const;

    Vector<Type> &operator = (const Vector<Type> &vec);
    Vector<Type> &operator = (Vector<Type> &&vec) noexcept;
    Vector<Type> &operator = (std::initializer_list<Type> list);

    Vector<Type> &operator += (const Type &number);
    Vector<Type> &operator += (const Vector<Type> &vector);
    Vector<Type>  operator +  (const Type &number) const;
    Vector<Type>  operator +  (const Vector<Type> &vector) const;
    Vector<Type> &sum_equal   (const Type &number);
    Vector<Type> &sum_equal   (const Vector<Type> &vector);
    Vector<Type>  sum_number  (const Type &number) const;
    Vector<Type>  sum_vector  (const Vector<Type> &vector) const;

    template<typename Type1>
    decltype(auto) operator + (const Type1 &number) const;
    template<typename Type1>
    decltype(auto) operator + (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) sum_number (const Type1 &number) const;
    template<typename Type1>
    decltype(auto) sum_vector (const Vector<Type1> &vector) const;

    Vector<Type> &operator -= (const Type &number);
    Vector<Type> &operator -= (const Vector<Type> &vector);
    Vector<Type>  operator -  (const Type &number) const;
    Vector<Type>  operator -  (const Vector<Type> &vector) const;
    Vector<Type> &sub_equal   (const Type &number);
    Vector<Type> &sub_equal   (const Vector<Type> &vector);
    Vector<Type>  sub_number  (const Type &number) const;
    Vector<Type>  sub_vector  (const Vector<Type> &vector) const;

    template<typename Type1>
    decltype(auto) operator - (const Type1 &number) const;
    template<typename Type1>
    decltype(auto) operator - (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) sub_number (const Type1 &number) const;
    template<typename Type1>
    decltype(auto) sub_vector (const Vector<Type1> &vector) const;

    Vector<Type> &operator *= (const Type &number);
    Vector<Type> &operator *= (const Vector<Type> &vector);
    Vector<Type>  operator *  (const Type &number) const;
    Vector<Type>  operator *  (const Vector<Type> &vector) const;
    Vector<Type> &mult_equal  (const Type &number);
    Vector<Type> &mult_equal  (const Vector<Type> &vector);
    Vector<Type>  mult_number (const Type &number) const;
    Vector<Type>  mult_vector (const Vector<Type> &vector) const;

    template<typename Type1>
    decltype(auto) operator * (const Type1 &number) const;
    template<typename Type1>
    decltype(auto) operator * (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) mult_number(const Type1 &number) const;
    template<typename Type1>
    decltype(auto) mult_vector(const Vector<Type1> &vector) const;

    Vector<Type> &operator /= (const Type &number);
    Vector<Type> &operator /= (const Vector<Type> &vector);
    Vector<Type>  operator /  (const Type &number) const;
    Vector<Type>  operator /  (const Vector<Type> &vector) const;
    Vector<Type> &div_equal   (const Type &number);
    Vector<Type> &div_equal   (const Vector<Type> &vector);
    Vector<Type>  div_number  (const Type &number) const;
    Vector<Type>  div_vector  (const Vector<Type> &vector) const;

    template<typename Type1>
    decltype(auto) operator / (const Type1 &number) const;
    template<typename Type1>
    decltype(auto) operator / (const Vector<Type1> &vector) const;
    template<typename Type1>
    decltype(auto) div_number (const Type1 &number) const;
    template<typename Type1>
    decltype(auto) div_vector (const Vector<Type1> &vector) const;

    Vector<Type> &operator ^= (const Vector<Type> &vector);
    Vector<Type>  operator ^  (const Vector<Type> &vector) const;
    Vector<Type> &vec_mult_equal(const Vector<Type> &vector);
    Vector<Type>  vec_mult      (const Vector<Type> &vector) const;

    double operator & (const Vector<Type> &vec) const;
    double scalar_mult(const Vector<Type> &vec) const;

protected:
    void mem_alloc(int size, int line);
    Type sum_elements(void) const;

    void check_vec_size(const int &vec_size, int line) const;
    void check_array(const Type *arr, int line) const;
    void check_index(int index, int line) const;
    void check_number_is_zero(const Type &number, int line) const;
    void check_size_for_vec_mul(const int &vec_size, int line) const;
    void ckeck_sizes_are_equal(const int &vec_size, int line) const;

private:
    std::shared_ptr<Type> vec_ptr;
};

#include "vector.hpp"

#endif
