/*!
\file solver.h
Заголовочный файл с прототипами функций для solver.cpp
*/

const double EPS = 0.0000001; ///< погрешность
const int INF = 999999; ///< значение для бесконечности корней
const int ERR = -1; ///< код ошибки

int solve_square(double coefs[], double roots[]);
void print_roots(double coefs[] ,double roots[], int count);
void get_coefs(double coefs[]);
void get_line(char line[]);
int compare(double a, double b);
