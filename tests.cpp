/*!
\file tests.cpp
Файл с функциями для тестирования
*/
#include <stdio.h>
#include <math.h>
#include "solver.h"
#include "tests.h"

static int do_one_test(const test_data* test);

/*!
Проводит тест функции solve_square
\param[in] test структура, содержащая данные для теста
\return 1 если тест пройден успешно; 0 иначе
*/
static int do_one_test(const test_data* test)
    {
    double coefs[] = {(*test).a, (*test).b, (*test).c};
    double roots[] = {NAN, NAN};
    int count = solve_square(coefs, roots);

    if (count == (*test).count_ref)
        if ((compare(roots[0], (*test).x1_ref) == 0 && compare(roots[1], (*test).x2_ref) == 0) ||
            (compare(roots[1], (*test).x1_ref) == 0 && compare(roots[0], (*test).x2_ref) == 0) ||
            (compare(roots[0], (*test).x1_ref) == 0 && isnan(roots[1]) && isnan((*test).x2_ref)) ||
            isnan(roots[0]) && isnan((*test).x1_ref) && isnan(roots[1]) && isnan((*test).x2_ref))
            {
            printf("ok\n");
            return 1;
            }

    printf("FAIL: при coefs[%lf, %lf, %lf] roots[%lf, %lf] count = %i; ожидалось roots[%lf, %lf] count = %i\n",
            coefs[0], coefs[1], coefs[2], roots[0], roots[1], count, (*test).x1_ref, (*test).x2_ref, (*test).count_ref);
    return 0;
    }


int do_all_tests()
    {
    const int num_tests = 8; ///< количество тестов
    test_data all_tests[num_tests] = {
        {         0,       0,         0,         NAN,            NAN, INF},
        {  12.33569, -0.2365, -69589.23, 75.11812179,   -75.09894977,   2},
        {0.00000001,       2,      46.6,       -23.3,            NAN,   1},
        {         0,       0,        10,         NAN,            NAN,   0},
        {         1,      -2,         1,           1,            NAN,   1},
        {         1,       1,         1,         NAN,            NAN,   0},
        {        12,      89,         0,           0, -7.41666666666,   2},
        {        12,       0,         0,           0,            NAN,   1}
        };

    int total = 0;
    for (int i = 0; i < num_tests; i++)
        total += do_one_test(&all_tests[i]);
    return total;
    }
