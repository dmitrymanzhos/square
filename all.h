/*!
\file all.h
Заголовочный файл с прототипами функций для main.cpp
*/
struct test_data { ///< структура для 1 теста
    double a, b, c;
    double x1_ref, x2_ref;
    int count_ref;
    };

int solve_square(double coefs[], double roots[]);
void print_roots(double coefs[] ,double roots[], int count);
void get_coefs(double coefs[]);
void get_line(char line[]);
int compare(double a, double b);

int do_one_test(const test_data* test);
int do_all_tests();
