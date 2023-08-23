/**
\file
\brief Программа для решения квадратных уравнений

Программа получает коэффициенты кв. уравнения и выводит приближенные решения
*/
#include <stdio.h>
#include <math.h>
const double EPS = 1e-20; ///< погрешность
const int INF = 999999; ///< значение для бесконечности корней

int solve_square(double [], double []);
void print_roots(double [] ,double [], int count);
void getline(char []);
void get_coefs(double []);
int compare_to_0 (double a);


/*!
Точка входа
*/
int main()
{
    double coefs[3] = {0};
    get_coefs(coefs);
    double roots[2] = {0};
    int count = solve_square(coefs, roots);
    print_roots(coefs, roots, count);
    return 0;
}

/*!
Решает и записывает корни в roots[], если они есть
\param[in] coefs[] массив коэффицентов
\param[out] roots[] массив корней
\return количество корней
*/
int solve_square(double coefs[], double roots[])
{
    if (compare_to_0(coefs[0]))
        if (compare_to_0(coefs[1]) && !compare_to_0(coefs[2]))
            return 0; ///< нет корней
        else if (compare_to_0(coefs[1]) && compare_to_0(coefs[2]))
            return INF; ///< бесконечно много корней
        else {
            roots[0] = -coefs[2] / coefs[1];
            return 1;}
    else {
        double d = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
        if (d <= -EPS)
            return 0;
        else if (compare_to_0(d)) {
            roots[0] = -coefs[1] / (2 * coefs[0]);
            return 1;}
        else if (d >= EPS) {
            roots[0] = (-coefs[1] + sqrt(d)) / (2 * coefs[0]);
            roots[1] = (-coefs[1] - sqrt(d)) / (2 * coefs[0]);
            return 2;}
        }
    return -1;
}

/*!
Выводит ответ
\param[in] coefs[] массив коэффицентов
\param[in] roots[] массив корней
\param[in] count количество корней
*/
void print_roots(double coefs[] ,double roots[], int count)
{
    if (compare_to_0(coefs[0])) {
        switch (count) {
        case 0: printf("Уравнение не квадратное; нет решений\n");
                break;
        case 1: printf("Уравнение не квадратное; 1 корень:\n%.10lf\n", roots[0]);
                break;
        case INF: printf("Уравнение не квадратное; бесконечно много решений\n");
                break;
        default: printf("ошибка\n");
                break;}}
    else {
        switch (count) {
        case 0: printf("нет решений\n");
                break;
        case 1: printf("1 корень:\n%.10lf\n", roots[0]);
                break;
        case 2: printf("2 корня:\n%.10lf\n%.10lf\n", roots[0], roots[1]);
                break;
        default: printf("Ошибка\n");
                break;}}
}

/*!
Записывает введенные коэффициенты в coefs[]
\param coefs[] массив коэффициентов
*/
void get_coefs(double coefs[])
{
    printf("введите коэффициенты через пробел\n");
    char line[1000];
    getline(line);
    while (sscanf(line, "%lf %lf %lf", &coefs[0], &coefs[1], &coefs[2]) != 3)
    {
        printf("неверный формат ввода, повторите попытку\n");
        getline(line);
    }
    return;
}

/*!
Записывает вводимую строку в line
\param[out] line[]
*/
void getline(char line[])
{
    int c;
    int i;
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < 999; i++)
        line[i] = char(c);
    if (char(c) == '\n') {
        line[i] = char(c);
        ++i;
    }
    line[i] = '\0';
    return;
}

/*!
Проверяет на равенство 0 в условиях double чисел
\param a[in] число
\return 1 если равенство; 0 иначе
*/
int compare_to_0 (double a)
{
    if (fabs(a) < EPS)
        return 1;
    else return 0;
}
