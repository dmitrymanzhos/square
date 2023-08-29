/*!
\file solver.h
Заголовочный файл с прототипами функций solver.cpp
*/
#ifndef __SOLVER_H__
#define __SOLVER_H__
enum  ROOT_COUNT {ZERO_ROOT = 0, ONE_ROOT = 1 , TWO_ROOTS = 2 ,INF = 999999 , ERR = -1}; ///< константы для количества корней
const double EPS = 0.0000001; ///< погрешность

struct data {
    double a, b, c; ///< коэффициенты
    double x1, x2; ///< корни
    int count; ///< количество корней
    };

/*!
Решает и записывает корни в all, если они есть
\param[in, out] all общая структура для коэф., корней и количества корней
\return количество корней
*/
int solve_square(data *all);

/*!
Выводит ответ
\param[in] all общая структура для коэф., корней и количества корней
*/
void print_roots(const data *all);

/*!
Записывает введенные коэффициенты в all
\param[out] all общая структура для коэф., корней и количества корней
*/
void get_coefs(data *all);

/*!
сравнивает числа в условиях double чисел
\param[in] a число
\param[in] b число
\return 1 если равенство, 0 иначе
*/
int is_equal(double a, double b);

#endif
