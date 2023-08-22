/**
\file
\brief Программа для решения квадратных уравнений
Программа получает коэффициенты кв. уравнения и выводит приближенные решения
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define EPS 1e-20 // погрешность

void solve_sq(double, double, double);
void solve_not_sq(double, double);
void getline(char line[]);

/*!
Точка входа
*/
int main()
{
    double a, b, c;
    printf("введите коэффициенты через пробел\n");
    while (1)
    {
        char line[1000];
        getline(line);
        if (sscanf(line, "%lf %lf %lf", &a, &b, &c) != 3)
            printf("неверный формат ввода, повторитте попытку\n");
        else
            break;
    }
    if (fabs(a) < EPS) /// при a ~= 0
        solve_not_sq(b, c);
    else /// при a != 0
        solve_sq(a, b, c);
    return 0;
}

/*!
Записывает вводимую строку в line
\param line[] строка
*/
void getline(char line[])
{
    char c;
    for (int i = 0; (c = getchar()) != EOF && c != '\n' && i < 999; i++)
        line[i] = c;
    return;
}

/*!
Решает при a ~= 0
\param b,c коэффициенты
*/
void solve_not_sq(double b, double c)
{
    if (fabs(b) < EPS && fabs(c) < EPS)
        printf("уравнение не квадратное; бесконечно много решений\n");
    else if (fabs(b) < EPS && fabs(c) >= EPS)
        printf("уравнение не квадратное; нет решений\n");
    else
        printf("уравнение не квадратное; 1 корень:\n%lf\n", c / b);
}

/*!
Решает при a != 0
\param a,b,c коэффициенты
*/
void solve_sq(double a , double b, double c)
{
    double d = b * b - 4 * a * c;
    if (d <= -EPS)
        printf("нет вещественных решений\n");
    else if (fabs(d) < EPS)
        printf("1 решение:\n%.10lf\n", -b / (2 * a));
    else if (d>= EPS)
        printf("2 решения:\n%.10lf\n%.10lf\n", (-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    return;
}
