/*!
\file tests.h
Заголовочный файл с прототипами функций для tests.cpp
*/
const int INF = 999999; ///< значение для бесконечности корней

struct test_data { ///< структура для 1 теста
    double a, b, c;
    double x1_ref, x2_ref;
    int count_ref;
    };

int solve_square(double coefs[], double roots[]);
int compare(double a, double b);

