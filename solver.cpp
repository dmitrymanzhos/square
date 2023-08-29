/*!
\file solver.cpp
Файл с функциями для получения коэффициентов, решения уравнения и вывода ответа
*/
#include <stdio.h>
#include <math.h>
#include <cassert>
#include "solver.h"

static void clear_buf();


int solve_square(data *all)
    {
    assert(all);
    assert(!isnan(all->a) && !isnan(all->b) && !isnan(all->c)); ///< проверяет, что изначально коэф. не NaN
    assert(isnan(all->x1) && isnan(all->x2)); ///< проверяет, что изначально корни NaN

    if (is_equal(all->a, 0) != 0) ///< при a = 0
        if (is_equal(all->b, 0) != 0 && is_equal(all->c, 0) == 0)
            return ZERO_ROOT; ///< нет корней
        else if (is_equal(all->b, 0) != 0 && is_equal(all->c, 0) != 0)
            return INF; ///< бесконечно много корней
        else
            {
            if (is_equal(-all->c / all->b, 0) != 0)
                all->x1 = 0;
            else
                all->x1 = -all->c / all->b;
            return ONE_ROOT; ///< 1 корень
            }
    else if (is_equal(all->c, 0) != 0) ///< при c = 0, a != 0
        {
        assert(is_equal(all->a, 0) == 0); ///< проверка на a != 0

        if (is_equal(all->b, 0) != 0)
            {
            all->x1 = 0;
            return ONE_ROOT; ///< если b = 0
            }
        else
            {
            all->x1 = 0;
            all->x2 = -all->b / all->a;
            return TWO_ROOTS; ///< если b != 0
            }
        }
    else
        {
        assert(is_equal(all->a, 0) == 0); ///< проверка на a != 0
        assert(is_equal(all->a, 0) == 0); ///< проверка на c != 0

        double d = all->b * all->b - 4 * all->a * all->c;
        if (d < 0)
            return ZERO_ROOT; ///< если дискриминант < 0
        else if (is_equal(d, 0) != 0)
            {
            all->x1 = -all->b / (2 * all->a);
            return ONE_ROOT; ///< если дискриминант = 0
            }
        else if (d > 0)
            {
            double root_of_d = sqrt(d);
            all->x1 = (-all->b + root_of_d) / (2 * all->a);
            all->x2 = (-all->b - root_of_d) / (2 * all->a);
            return TWO_ROOTS; ///< если дискриминант > 0
            }
        }
    return ERR; ///< код ошибки
    }


void print_roots(const data *all)
    {
    assert(all);
    assert(!isnan(all->a) && !isnan(all->b) && !isnan(all->c)); ///< проверяет, что изначально коэф. не NaN
    assert((ZERO_ROOT <= all->count && all->count <= TWO_ROOTS) || (all->count == INF)); ///< проверка количества корней

    if (is_equal(all->a, 0) != 0) ///< при a = 0
        printf("уравнение не квадратное;\n");

    switch (all->count)
        {
        case ZERO_ROOT:
            printf("нет решений\n");
            break;
        case ONE_ROOT:
            printf("1 корень:\n%.10lf\n", all->x1);
            break;
        case TWO_ROOTS:
            printf("2 корня:\n%.10lf\n%.10lf\n", all->x1, all->x2);
            break;
        case INF:
            printf("бесконечно много решений\n");
            break;
        default:
            printf("ошибка\n");
            break;
        }
    }


void get_coefs(data *all)
    {
    assert(all);
    assert(isnan(all->a) && isnan(all->b) && isnan(all->c)); ///< проверяет, что изначально коэф. NaN

    printf("введите коэффициенты через пробел\n");
    char c = 0;
    while (!(scanf("%lf%*[ \t]%lf%*[ \t]%lf%c", &(all->a), &(all->b), &(all->c), &c) == 4 && c == '\n'))
        {
        printf("-неверный формат ввода, повторите попытку\n");
        clear_buf();
        }
    return;
    }

/*!
Очищает буфер
*/
static void clear_buf()
    {
    int c = 0;
    while ((c = getchar()) != EOF && c != '\n')
        ;
    return;
    }


int is_equal(const double a, const double b)
    {
    return (fabs(a - b) < EPS);
    }
