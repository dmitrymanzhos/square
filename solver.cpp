/*!
\file solver.cpp
Файл с функциями для получения коэффициентов, решения уравнения и вывода ответа
*/
#include <stdio.h>
#include <math.h>
#include <cassert>
#include "solver.h"

static void get_line(char line[]);


int solve_square(double coefs[], double roots[])
    {
    if (compare(coefs[0], 0) == 0) ///< при a = 0
        if (compare(coefs[1], 0) == 0 && compare(coefs[2], 0) != 0)
            return ZERO_ROOT; ///< нет корней
        else if (compare(coefs[1], 0) == 0 && compare(coefs[2], 0) == 0)
            return INF; ///< бесконечно много корней
        else
            {
            roots[0] = -coefs[2] / coefs[1];
            return ONE_ROOT; ///< 1 корень
            }
    else if (compare(coefs[2], 0) == 0) ///< при c = 0, a != 0
        {
        assert(compare(coefs[0], 0) != 0); ///< проверка на a != 0

        if (compare(coefs[1], 0) == 0)
            {
            roots[0] = 0;
            return ONE_ROOT; ///< если b = 0
            }
        else
            {
            roots[0] = 0;
            roots[1] = -coefs[1] / coefs[0];
            return TWO_ROOTS; ///< если b != 0
            }
        }
    else
        {
        assert(compare(coefs[0], 0) != 0); ///< проверка на a != 0
        assert(compare(coefs[0], 0) != 0); ///< проверка на c != 0

        double d = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
        if (compare(d, 0) == -1)
            return ZERO_ROOT; ///< если дискриминант < 0
        else if (compare(d, 0) == 0)
            {
            roots[0] = -coefs[1] / (2 * coefs[0]);
            return ONE_ROOT; ///< если дискриминант = 0
            }
        else if (compare(d, 0) == 1)
            {
            double root_of_d = sqrt(d);
            roots[0] = (-coefs[1] + root_of_d) / (2 * coefs[0]);
            roots[1] = (-coefs[1] - root_of_d) / (2 * coefs[0]);
            return TWO_ROOTS; ///< если дискриминант > 0
            }
        }
    return ERR; ///< код ошибки
    }


void print_roots(double coefs[] ,double roots[], int count)
    {
    assert((0 <= count && count <= 2) || (count == INF)); ///< проверка количества корней

    if (compare(coefs[0], 0) == 0) ///< при a = 0
        {
        switch (count)
            {
            case ZERO_ROOT:
                printf("Уравнение не квадратное; нет решений\n");
                break;
            case ONE_ROOT:
                printf("Уравнение не квадратное; 1 корень:\n%.10lf\n", roots[0]);
                break;
            case INF:
                printf("Уравнение не квадратное; бесконечно много решений\n");
                break;
            default:
                printf("ошибка\n");
                break;
            }
        }
    else ///< при a != 0
        {
        switch (count)
            {
            case ZERO_ROOT:
                printf("нет вещественных решений\n");
                break;
            case ONE_ROOT:
                printf("1 корень:\n%.10lf\n", roots[0]);
                break;
            case TWO_ROOTS:
                printf("2 корня:\n%.10lf\n%.10lf\n", roots[0], roots[1]);
                break;
            default:
                printf("Ошибка\n");
                break;
            }
        }
    }


void get_coefs(double coefs[])
    {
    printf("введите коэффициенты через пробел\n");
    char line[MAXSIZE] = {};
    get_line(line);
    while (sscanf(line, "%lf %lf %lf", &coefs[0], &coefs[1], &coefs[2]) != 3)
        {
        printf("неверный формат ввода, повторите попытку\n");
        get_line(line);
        }
    return;
    }

/*!
Записывает вводимую строку в line
\param[out] line[]
*/
static void get_line(char line[])
    {
    int c = 0;
    int i = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < (MAXSIZE - 1); i++)
        line[i] = char(c);
    if (char(c) == '\n')
        {
        line[i] = char(c);
        ++i;
        }
    line[i] = '\0';
    return;
    }


int compare(double a, double b)
    {
    if (a - b <= -EPS)
        return -1; ///< если a < b
    else if (fabs(a - b) < EPS)
        return 0; ///< если a = b
    else
        return 1; ///< если a > b
    }
