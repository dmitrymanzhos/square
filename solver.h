/*!
\file solver.h
Заголовочный файл с прототипами функций solver.cpp
*/
#ifndef __SOLVER_H__
#define __SOLVER_H__ 1
enum  ROOT_COUNT {ZERO_ROOT = 0, ONE_ROOT = 1 , TWO_ROOTS = 2 , INF = 999999 , ERR = -1};
const double EPS = 0.0000001; ///< погрешность
const int MAXSIZE = 1000; ///< максимальный размер для считываемой строки
// const int ERR = -1; ///< код ошибки

/*!
Решает и записывает корни в roots[], если они есть
\param[in] coefs[] массив коэффицентов
\param[out] roots[] массив корней
\return количество корней
*/
int solve_square(double coefs[], double roots[]);

/*!
Выводит ответ
\param[in] coefs[] массив коэффицентов
\param[in] roots[] массив корней
\param[in] count количество корней
*/
void print_roots(double coefs[] ,double roots[], int count);

/*!
Записывает введенные коэффициенты в coefs[]
\param coefs[] массив коэффициентов
*/
void get_coefs(double coefs[]);

/*!
сравнивает число с 0 в условиях double чисел
\param[in] a число
\param[in] a число
\return -1 если < 0, 0 если равенство, 1 если > 0
*/
int compare(double a, double b);

#endif
