#ifndef __SOLVER_H__
#define __SOLVER_H__ 1

/*!
\file solver.h
Заголовочный файл с прототипами функций solver.cpp
*/
int solve_square(double coefs[], double roots[]);
void print_roots(double coefs[] ,double roots[], int count);
void get_coefs(double coefs[]);
int compare(double a, double b);

#endif
