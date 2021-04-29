#include <iostream>

#include "../inc/errors.h"
#include "../inc/class_vector.h"

int main()
{
    try
    {   
        std::cout << "\nТест конструкторов\n" << std::endl;

        double arr[3] = {9, 2, 5};

        Vector<double> v1;
        Vector<double> v2(1);
        Vector<double> v3(2, 1.2, 2.2);
        Vector<double> v4(3, arr);
        Vector<double> v5 = {1, 2, 3};
        Vector<double> v0(v5.begin(), v5.end());

        double double_numb = 5.5;

        std::cout << "Vector<double> v1                      : " << v1 << std::endl;
        std::cout << "Vector<double> v2(1)                   : " << v2 << std::endl;
        std::cout << "Vector<double> v3(2, 1.2, 2.2)         : " << v3 << std::endl;
        std::cout << "Vector<double> v4(3, arr)              : " << v4 << std::endl;
        std::cout << "Vector<double> v5 = {1, 2, 3}          : " << v5 << std::endl;
        std::cout << "Vector<double> v0(v5.begin(), v5.end()): " << v0 << std::endl;
        
        std::cout << "\nТест методов\n" << std::endl;

        std::cout << "Длина вектора " << v5 << " : " << v5.length() << std::endl;
        std::cout << "Размер вектора " << v5 << " : " << v5.get_size() << std::endl;
        std::cout << "Вектор пуст? " << v1 << " : " << v1.is_empty() << std::endl;
        std::cout << "Векторы равны? " << v3 << " и " << v5 << " : " 
                  << v3.is_equal(v5) << std::endl;
        std::cout << "2-ой элемент вектора " << v4 << " : " << v4.get_elem(1) << std::endl;
        std::cout << v4 << " [" << 1 << "] = " << (v4[1]) << std::endl;
        std::cout << "2-ой элемент вектора " << v4 << " = " << double_numb;
        v4.set_elem(1, double_numb);
        std::cout << " : " << v4 << std::endl;
        std::cout << "Получить нормированный вектор из " << v5 << " : " 
                  << v5.get_normalize_vector() << std::endl;
        std::cout << "Вектор нормированн? " << v5.get_normalize_vector() << " : " 
                  << v5.get_normalize_vector().is_normalized() << std::endl;

        Vector<int> v6(2, 2, 0);
        Vector<int> v7(2, 0, 3);

        std::cout << "Угол между векторами " << v6 << " и " << v7 << " : " 
                  << v6.angle(v7) << std::endl;
        std::cout << "Проверка коллинеарности " << v6 << " и " << v7 << " : " 
                  << v6.is_collinearity(v7) << std::endl;
        std::cout << "Проверка ортогональности " << v6 << " и " << v7 << " : " 
                  << v6.is_orthogonality(v7) << std::endl;

        std::cout << "\nТест арифметических операций\n" << std::endl;

        std::cout << "(Переменные одного типа)\n" << std::endl;

        std::cout << v4 << " + " << v5 << " = " << (v4 + v5) << std::endl;
        std::cout << v4 << " - " << v5 << " = " << (v4 - v5) << std::endl;
        std::cout << v4 << " * " << v5 << " = " << (v4 * v5) << std::endl;
        std::cout << v4 << " / " << v5 << " = " << (v4 / v5) << std::endl;
        std::cout << v4 << " & " << v5 << " = " << (v4 & v5) << std::endl;
        std::cout << v4 << " ^ " << v5 << " = " << (v4 ^ v5) << "\n" << std::endl;

        std::cout << v4 << " += " << double_numb << " = " << (v4 += double_numb) << std::endl;
        std::cout << v4 << " -= " << double_numb << " = " << (v4 -= double_numb) << std::endl;
        std::cout << v4 << " *= " << double_numb << " = " << (v4 *= double_numb) << std::endl;
        std::cout << v4 << " /= " << double_numb << " = " << (v4 /= double_numb) << "\n" << std::endl;

        std::cout << v4 << " += " << v5 << " = " << (v4 += v5) << std::endl;
        std::cout << v4 << " -= " << v5 << " = " << (v4 -= v5) << std::endl;
        std::cout << v4 << " *= " << v5 << " = " << (v4 *= v5) << std::endl;
        std::cout << v4 << " /= " << v5 << " = " << (v4 /= v5) << std::endl;
        std::cout << v4 << " ^= " << v5 << " = " << (v4 ^= v5) << "\n" << std::endl;

        std::cout << "(Переменные разных типов)\n" << std::endl;

        int int_numb = 4;

        std::cout << v4 << " + " << int_numb << " = " << (v4 + int_numb) << std::endl;
        std::cout << v4 << " - " << int_numb << " = " << (v4 - int_numb) << std::endl;
        std::cout << v4 << " * " << int_numb << " = " << (v4 * int_numb) << std::endl;
        std::cout << v4 << " / " << int_numb << " = " << (v4 / int_numb) << "\n" << std::endl;

        Vector<int> v8 = {10, 20, 30};

        std::cout << v4 << " + " << v8 << " = " << (v4 + v8) << std::endl;
        std::cout << v4 << " - " << v8 << " = " << (v4 - v8) << std::endl;
        std::cout << v4 << " * " << v8 << " = " << (v4 * v8) << std::endl;
        std::cout << v4 << " / " << v8 << " = " << (v4 / v8) << "\n" << std::endl;
    }
    catch (base_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    return OK;
}
