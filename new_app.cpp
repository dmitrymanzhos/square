/**
\file
\brief Программа для решения квадратных уравнений

Программа получает коэффициенты кв. уравнения и выводит приближенные решения
*/
#include <stdio.h>
#include <math.h>
const double EPS = 0.0000001; ///< погрешность
const int INF = 999999; ///< значение для бесконечности корней

int solve_square(double coefs[], double roots[]);
void print_roots(double coefs[] ,double roots[], int count);
void get_coefs(double coefs[]);
void get_line(char line[]);
int compare (double a, double b);
int one_test(double a, double b, double c, double x1_ref, double x2_ref, int count_ref);
int all_tests();


/*!
Точка входа
*/
int main(int arg_count, char *argv[])
    {
    if (arg_count > 1)
        {
        if (argv[1][0] == 't' && argv[1][1] == 'e' && argv[1][2] == 's' && argv[1][3] == 't')
            {
            all_tests();
            return 0;
            }
        else return 0;
        }
    else
        {
        double coefs[3] = {0};
        get_coefs(coefs);
        double roots[2] = {0};
        int count = solve_square(coefs, roots);
        print_roots(coefs, roots, count);
        return 0;
        }
    }

/*!
Решает и записывает корни в roots[], если они есть
\param[in] coefs[] массив коэффицентов
\param[out] roots[] массив корней
\return количество корней
*/
int solve_square(double coefs[], double roots[])
    {
    if (compare(coefs[0], 0) == 0)
        if (compare(coefs[1], 0) == 0 && compare(coefs[2], 0) != 0)
            return 0; ///< нет корней
        else if (compare(coefs[1], 0) == 0 && compare(coefs[2], 0) == 0)
            return INF; ///< бесконечно много корней
        else
            {
            roots[0] = -coefs[2] / coefs[1];
            return 1;
            }
    else
        {
        double d = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
        if (compare(d, 0) == -1)
            return 0;
        else if (compare(d, 0) == 0)
            {
            roots[0] = -coefs[1] / (2 * coefs[0]);
            return 1;
            }
        else if (compare(d, 0) == 1)
            {
            roots[0] = (-coefs[1] + sqrt(d)) / (2 * coefs[0]);
            roots[1] = (-coefs[1] - sqrt(d)) / (2 * coefs[0]);
            return 2;
            }
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
    if (compare(coefs[0], 0) == 0)
        {
        switch (count)
            {
            case 0:
                printf("Уравнение не квадратное; нет решений\n");
                break;
            case 1:
                printf("Уравнение не квадратное; 1 корень:\n%.10lf\n", roots[0]);
                break;
            case INF:
                printf("Уравнение не квадратное; бесконечно много решений\n");
                break;
            default:
                printf("ошибка\n");
                break;
            }
        }
    else
        {
        switch (count)
            {
            case 0:
                printf("нет вещественных решений\n");
                break;
            case 1:
                printf("1 корень:\n%.10lf\n", roots[0]);
                break;
            case 2:
                printf("2 корня:\n%.10lf\n%.10lf\n", roots[0], roots[1]);
                break;
            default:
                printf("Ошибка\n");
                break;
            }
        }
    }

/*!
Записывает введенные коэффициенты в coefs[]
\param coefs[] массив коэффициентов
*/
void get_coefs(double coefs[])
    {
    printf("введите коэффициенты через пробел\n");
    char line[1000] = {};
    get_line(line);
    while (sscanf(line, "%lf %lf %lf", &coefs[0], &coefs[1], &coefs[2]) != 3)
        {
        printf("неверный формат ввода, повторите попытку\n");
        get_line(line);
        }
    return;
    }

/*!
Записывает вводимую строку в line
\param[out] line[]
*/
void get_line(char line[])
    {
    int c;
    int i;
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < 999; i++)
        line[i] = char(c);
    if (char(c) == '\n')
        {
        line[i] = char(c);
        ++i;
        }
    line[i] = '\0';
    return;
    }

/*!
сравнивает число с 0 в условиях double чисел
\param a[in] число
\return -1 если < 0, 0 если равенство, 1 если > 0
*/
int compare (double a, double b)
    {
    if (a - b <= -EPS)
        return -1;
    else if (fabs(a - b) < EPS)
        return 0;
    else
        return 1;
    }

int one_test(double a, double b, double c, double x1_ref, double x2_ref, int count_ref)
    {
    double coefs[] = {a, b, c};
    double roots[] = {0, 0};
    int count = solve_square(coefs, roots);

    if (count == count_ref)
        if ((compare(roots[0], x1_ref) == 0 && compare(roots[1], x2_ref) == 0) || (compare(roots[1], x1_ref) == 0 && compare(roots[0], x2_ref) == 0))
            {
            printf("ok\n");
            return 1;
            }

    printf("FAIL: при coefs[%lf, %lf, %lf] roots[%lf, %lf] count = %i; ожидалось roots[%lf, %lf] count = %i\n",
            coefs[0], coefs[1], coefs[2], roots[0], roots[1], count, x1_ref, x2_ref, count_ref);
    return 0;
    }

int all_tests()
    {
    int total = 0;
    total += one_test(0, 0, 0, 0, 0, INF);
    total += one_test(12.33569, -0.2365, -69589.23, 75.11812179, -75.09894977, 2);
    total += one_test(0, 0, 0, 0, 0, INF);
    total += one_test(0, 0, 0, 0, 0, INF);
    total += one_test(0, 0, 0, 0, 0, INF);
    return total;
    }
