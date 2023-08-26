/**
\file main.cpp
\brief Программа для решения квадратных уравнений

Программа получает коэффициенты кв. уравнения вида a*x^2 + b*x + c = 0
и выводит приближенные решения
*/
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <cassert>
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
            // TODO: функции для аргументов
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
        // TODO: isnan isfinite -> assert ->
        double coefs[3] = {NAN, NAN, NAN};
        get_coefs(coefs);
        assert(!isnan(coefs[0]) && !isnan(coefs[1]) && !isnan(coefs[2])); ///< проверка на получение аргументов

        double roots[2] = {NAN, NAN};
        int count = solve_square(coefs, roots);
        assert((0 <= count && count <= 2) || (count == INF)); ///< проверка количества корней

        print_roots(coefs, roots, count);
        return 0;
        }
    }
