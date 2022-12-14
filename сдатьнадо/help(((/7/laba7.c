#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void fill(int n, int m, int matrix[n][m])
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            matrix[i][j] = rand()% 101 - 50;
}

void str(int n, int m, int matrix[n][m])
{ 
    for(int i = 0; i < n; i++)
    {
       int sum = 0;
    {
    for(int j = 0; j < n; j++)
    {
        sum+=matrix[i][j];
    }
    }
    printf("%.1f \n",(float)sum/m);
    printf("| ");
    }
}

void stl(int n, int m, int matrix[n][m], int sum)
{
    for(int j = 0; j < m; j++)
    {
        int sum=0;
    {
    for(int i = 0; i < n; i++)
    {
        sum+=matrix[i][j];
    }
    }
    printf(" %.1f ",(float)sum/n);  
    printf("_____");
    printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int n,m, matrix;
    printf("\nMatrix[%d,%d]:\n",n, m);
    printf("Enter size of matrix[n,m]");
    printf("\nEnter n = ");
    scanf("%d",&n);
    printf("\nEnter m = ");
    scanf("%d",&m);
    fill(n, m, matrix[n][m]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        printf("%4d ",matrix[i][j]);
    }
}
