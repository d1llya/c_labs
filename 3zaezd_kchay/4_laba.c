#include <stdio.h>
#include <math.h>


double func(double x) 
{
    if (x <= 1) 
    {
        return cos(x + x * x * x);
    }
    return exp(-x*x) - x*x + 2*x;
}

double middleRectangleMethod(int nsegments, double xstart, double xend) 
{
    double dx = (xend - xstart) / nsegments;
    double x, sum = 0;
    int i;
    for (i = 0; i < nsegments; ++i) 
    {
        x = xstart + dx / 2 + i * dx;
        sum += func(x);
    }
    return sum * dx;
}

double countIntegral(double eps) 
{
    int n = 1;
    double previous_integral, integral;
    integral = middleRectangleMethod(n, 0.0, 2.0);
    do 
    {
        n *= 2;
        previous_integral = integral;
        integral = middleRectangleMethod(n, 0.0, 2.0);
    } while (fabs((integral - previous_integral) / 3.0) >= eps);
    return integral;
}

int main() 
{
    double eps, integral;
    printf("Precision -> ");
    scanf("%lf", &eps);
    integral = countIntegral(eps);
    printf("Integral  -> %lf\n", integral);
    return 0;
}
