/*!
\file tests.h
Заголовочный файл с прототипами функций tests.cpp
*/
#ifndef __TESTS_H__
#define __TESTS_H__ 1

/*!
Структура для данных одного теста
*/
struct test_data {
    double a, b, c; ///< коэффициенты
    double x1_ref, x2_ref; ///< эталонные корни
    int count_ref; ///< эталонное количество корней
    };

int do_all_tests();

#endif
