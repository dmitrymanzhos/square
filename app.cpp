// программа получает коэффициенты кв. уравнения и выводит приближенные решения
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define EPS 1e-20 // погрешность

void solve(double, double, double);

int main()
{
    double a, b, c;
    printf("введите коэффициенты через пробел\n");
    if (scanf("%lf %lf %lf", &a, &b, &c) == 3) // если все 3 числа получены
        if (fabs(a) < EPS) // при a ~= 0
            if (fabs(b) < EPS && fabs(c) < EPS)
                printf("уравнение не квадратное; бесконечно много решений\n");
            else if (fabs(b) < EPS && fabs(c) >= EPS)
                printf("уравнение не квадратное; нет решений\n");
            else
                printf("уравнение не квадратное; 1 корень %lf\n", c / b);
        else
            solve(a, b, c);
    else
        printf("неверный формат ввода\n");
    return 0;
}

void solve(double a , double b, double c) // решает и выводит ответ
{
    double d = pow(b, 2) - 4 * a * c;
    if (d <= -EPS)
        printf("нет вещественных решений\n");
    else if (fabs(d) < EPS)
        printf("1 решение: %.10lf\n", -b / (2 * a));
    else if (d>= EPS)
        printf("2 решения: %.10lf, %.10lf\n", (-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
    return;
}