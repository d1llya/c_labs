#include <stdio.h>
#include <math.h>

double f(double x)
{
    double eps = 1e-6;
    if (x >= -eps && x <= 1 + eps)
    {
        return cos(x + x * x * x);
    }
    else
    {
        return pow(exp(1), -x * x) - x * x + 2 * x;
    }
    return 0;
}

double integrate(double x_left, double x_right, int n)
{
    double h = (x_right - x_left) / n;
    double x;
    double sum = 0;

    for (x = x_left; x + h / 2 < x_right; x += h)
    {
        sum += f(x + h / 2);
    }
    return sum * h;
}

int main()
{
    double x_start = 0;
    double x_end = 2;
    double eps;
    double intergal_n, integral_2n;
    int n = 4;
    printf("Введите точность: ");
    scanf("%lf", &eps);
    integral_2n = integrate(x_start, x_end, n);
    do
    {
        n *= 2;
        intergal_n = integral_2n;
        integral_2n = integrate(x_start, x_end, n);
    } while (fabs(integral_2n - intergal_n) / 3.0 >= eps);
    printf("Значение интеграла: %lf\n", integral_2n);
    return 0;
}
