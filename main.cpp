/**
\file main.cpp
\brief Программа для решения квадратных уравнений

Программа получает коэффициенты кв. уравнения вида a*x^2 + b*x + c = 0
и выводит приближенные решения
*/
#include <stdio.h>
#include <cstring>
#include "all.h"

/*!
Точка входа
\param[in] arg_count количество аргументов командной строки
\param[in] *argv[]
*/
int main(int arg_count, char *argv[])
    {
    if (arg_count > 1) ///< если есть аргументы командной строки кроме  имени файла
        {
        if (strcmp(argv[1], "--test") == 0) ///< если 1й аргумент равен "test"
            {
            printf("тестов пройдено: %i\n", do_all_tests());
            return 0;
            }
        else return 0;
        }
    else
        {
        double coefs[3] = {0};
        get_coefs(coefs);
        double roots[2] = {0};
        int count = solve_square(coefs, roots);
        print_roots(coefs, roots, count);
        return 0;
        }
    }
