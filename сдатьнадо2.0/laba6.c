#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int max=0,min=100,i_max=0,i_min=0;

int print_arr(int x[], int len) 
{
    int j;
    for(j = 0; j < len; j++) 
	{
        printf("%d ", x[j]);
    }
    printf("\n");
    return 0;
}

int find(int x[], int len) 
{
    int j;
    for(j = 0; j < len; j++) 
	{
        if (x[j]>=max)
        {
            max=x[j];
            i_max=j;
		}
		if (x[j]<min)
        {
            min=x[j];
            i_min=j;
		}
    }
    return 0;
}

int change(int x[], int len) 
{
    int j,k,m_m=i_max+i_min;
    if (abs(m_m)>abs(max) || abs(m_m)<abs(min))
    {
        x[i_max]=m_m;
        x[i_min]=m_m;
	}
	else
	{
		if (i_max<i_min)
		{
			k=i_min;
			i_min=i_max;
			i_max=k;
		}
		for(j = i_min+1; j < i_max; j++) 
		{
	        x[j]=0;
		}
	}
    return 0;
}

int main() 
{
	int i,n;
	printf("Write N: ");
	scanf("%d", &n);
	int mas[n];
	srand(time(NULL));
	for(i=0; i < n; i++)
	{
		mas[i]=rand()%10;
	}
	find(mas,n);
	printf("Old mass: ");
	print_arr(mas,n);
	printf("Max = %d, ", max);
	printf("Min = %d, ", min);
	printf("Number max = %d, ", i_max);
	printf("Number min = %d \n", i_min);
	printf("New mass: ");
	change(mas,n);
	print_arr(mas,n);
	return 0;
}
