#include <stdio.h>
#include <math.h>

unsigned int fr(unsigned int n)
{
    if (n <=1)
    {
        return n;
    }
    return n ? fr(n - 1u) + fr(n - 2u) : 1u;
}

unsigned int fl(unsigned int n)
{
  int f[n + 1];
  f[0] = 0;
  f[1] = 1;
  for(unsigned int i = 2; i <= n; i++)
  {
    f[i] = f[i - 1] + f[i -2];
  }
  return f[n];
}

int main ()
{
    unsigned int n;
    printf("Enter number n\nn -> ");
    scanf("%u", &n);
    printf("Cycle: n = %u\nRecursion: n = %u\n", fl(n), fr(n));
    return 0;
}
