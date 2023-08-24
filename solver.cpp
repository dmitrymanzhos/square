/*!
\file solver.cpp
Файл с функциями для получения коэффициентов, решения уравнения и вывода ответа
*/

/*!
Решает и записывает корни в roots[], если они есть
\param[in] coefs[] массив коэффицентов
\param[out] roots[] массив корней
\return количество корней
*/
int solve_square(double coefs[], double roots[])
    {

    if (compare(coefs[0], 0) == 0) ///< при a = 0
        if (compare(coefs[1], 0) == 0 && compare(coefs[2], 0) != 0)
            return 0; ///< нет корней
        else if (compare(coefs[1], 0) == 0 && compare(coefs[2], 0) == 0)
            return INF; ///< бесконечно много корней
        else
            {
            roots[0] = -coefs[2] / coefs[1];
            return 1; ///< 1 корень
            }
    else if (compare(coefs[2], 0) == 0) ///< при c = 0, a != 0
        {
        if (compare(coefs[1], 0) == 0)
            {
            roots[0] = 0;
            return 1; ///< если b = 0
            }
        else
            {
            roots[0] = 0;
            roots[1] = -coefs[1] / coefs[0];
            return 2; ///< если b != 0
            }
        }
    else
        {
        double d = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
        if (compare(d, 0) == -1)
            return 0; ///< если дискриминант < 0
        else if (compare(d, 0) == 0)
            {
            roots[0] = -coefs[1] / (2 * coefs[0]);
            return 1; ///< если дискриминант = 0
            }
        else if (compare(d, 0) == 1)
            {
            double root_of_d = sqrt(d);
            roots[0] = (-coefs[1] + root_of_d) / (2 * coefs[0]);
            roots[1] = (-coefs[1] - root_of_d) / (2 * coefs[0]);
            return 2; ///< если дискриминант > 0
            }
        }
    return ERR; ///< код ошибки
    }

/*!
Выводит ответ
\param[in] coefs[] массив коэффицентов
\param[in] roots[] массив корней
\param[in] count количество корней
*/
void print_roots(double coefs[] ,double roots[], int count)
    {
    if (compare(coefs[0], 0) == 0) ///< при a = 0
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
    else ///< при a != 0
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
\param[in] a число
\return -1 если < 0, 0 если равенство, 1 если > 0
*/
int compare(double a, double b)
    {
    if (a - b <= -EPS)
        return -1; ///< если a < b
    else if (fabs(a - b) < EPS)
        return 0; ///< если a = b
    else
        return 1; ///< если a > b
    }