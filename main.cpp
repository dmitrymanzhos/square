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

void handle_arg_test();
void handle_arg_help();
void handle_unknown_arg(const char arg[]);


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
                handle_arg_test();
                return 0;
                }
            else if (strcmp(argv[i], "--help") == 0)
                {
                handle_arg_help();
                return 0;
                }
            else
                {
                handle_unknown_arg(argv[i]);
                return 0;
                }
        }
    else
        {
        data all = {NAN, NAN, NAN,
                    NAN, NAN,
                    ERR};
        get_coefs(&all);
        assert(!isnan(all.a) && !isnan(all.b) && !isnan(all.c)); ///< проверка на получение коэф.

        all.count = solve_square(&all);

        assert((ZERO_ROOT <= all.count && all.count <= TWO_ROOTS) || (all.count == INF)); ///< проверка количества корней
        print_roots(&all);
        return 0;
        }
    }


/*!
Регирует на аргумент --test
*/
void handle_arg_test()
    {
    printf("тестов пройдено: %i\n", do_all_tests());
    return;
    }


/*!
Регирует на аргумент --help
*/
void handle_arg_help()
    {
    printf("Usage: ./main [OPTION]...\nProgramm is the solver for square equation\nOptions:\n%s,\t%s\n%s,\t%s\n",
            "--test", "starts tests and exit", "--help", "display this help and exit");
    return;
    }


/*!
Реагирует на незнакомый аргумент
*/
void handle_unknown_arg(const char arg[])
    {
    printf("./main: unrecognized option '%s'\nTry './main --help' for more information.\n", arg);
    return;
    }
