/**
\file main.cpp
\brief Программа для решения квадратных уравнений

Программа получает коэффициенты кв. уравнения вида a*x^2 + b*x + c = 0
и выводит приближенные решения
*/
#undef __SOLVER_H__
#undef __TESTS_H__

#include <stdio.h>
#include <cstring>
#include "tests.h"
#include "solver.h"

/*!
Точка входа
\param[in] arg_count количество аргументов командной строки
\param[in] *argv[] список указателей на аргументы командной строки
*/
int main(int arg_count, char *argv[])
    {
    if (arg_count > 1) ///< если есть аргументы командной строки кроме  имени файла
        {
        for (int i = 1; i < arg_count; i++)
            if (strcmp(argv[i], "--test") == 0)
                {
                printf("тестов пройдено: %i\n", do_all_tests());
                return 0;
                }
            else if (strcmp(argv[i], "--help") == 0)
                {
                printf("Usage: ./main [OPTION]...\nProgramm is the solver for square equation\nOptions:\n%s,\t%s\n%s,\t%s\n", "--test", "starts tests and exit", "--help", "display this help and exit");
                return 0;
                }
            else
                {
                printf("./main: unrecognized option '%s'\nTry './main --help' for more information.\n", argv[i]);
                return 0;
                }
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
