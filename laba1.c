#include <stdio.h>

int main()
{
    int a, b, s;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    if (a < 0)
        a = -a;
    s = 0;
    while (a != 0)
    {
        s += a%10;
        a /= 10;
    }
    if (s>b)
    {
        printf("Sum digits = %d\n", s);
    }
    else if (s == b)
    {
        printf("Sum digits = b\n");
    }
    else
    {
        printf("Sum digits+b = %d\n", s+b);
    }
    return 0;
}
