/*!
\file solver.h
Заголовочный файл с прототипами функций solver.cpp
*/
#ifndef __SOLVER_H__
#define __SOLVER_H__ 1

const double EPS = 0.0000001; ///< погрешность
const int INF = 999999; ///< значение для бесконечности корней
const int ERR = -1; ///< код ошибки

int solve_square(double coefs[], double roots[]);
void print_roots(double coefs[] ,double roots[], int count);
void get_coefs(double coefs[]);
int compare(double a, double b);

#endif
