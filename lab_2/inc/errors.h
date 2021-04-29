#ifndef ERRORS_H
#define ERRORS_H

#include <string>
#include <ctime>

#include "base_errors.h"

#define OK 0

class memory_error : public base_error
{
public:
    memory_error(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Ошибка выделения памяти!\n") :

    base_error(filename, classname, line, time, info) {};
};

class neg_size_error : public base_error
{
public:
    neg_size_error(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Размер вектора должен быть больше 0!\n") :

    base_error(filename, classname, line, time, info) {};
};

class deleted_object : public base_error
{
public:
    deleted_object(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Попытка работы с удалённым объектом!\n") :

    base_error(filename, classname, line, time, info) {};
};

class invalid_iterator : public base_error
{
public:
    invalid_iterator(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Попытка использования недопустимого итератора!\n") :

    base_error(filename, classname, line, time, info) {};
};

class index_out_of_range : public base_error
{
public:
    index_out_of_range(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Попытка выхода за границы вектора!\n") :

    base_error(filename, classname, line, time, info) {};
};

class invalid_arr_error : public base_error
{
public:
    invalid_arr_error(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Передача нулевого указателя вместо указателя на массив!\n") :

    base_error(filename, classname, line, time, info) {};
};

class invalid_size_for_vec_mul : public base_error
{
public:
    invalid_size_for_vec_mul(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Размер вектора для векторного произведения должен быть равен 3!\n") :

    base_error(filename, classname, line, time, info) {};
};

class div_zero_error : public base_error
{
public:
    div_zero_error(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Попытка деления на 0!\n") :

    base_error(filename, classname, line, time, info) {};
};

class sizes_are_not_equal : public base_error
{
public:
    sizes_are_not_equal(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Размеры векторов не равны!\n") :

    base_error(filename, classname, line, time, info) {};
};

#endif
