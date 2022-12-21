#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n_rows, n_columns;
void fillRandom(int matrix[][n_columns], int n_rows, int n_cols)
{
    int i, j;
    for (i = 0; i < n_rows; ++i)
    {
        for (j = 0; j < n_cols; ++j)
        {
            matrix[i][j] = rand() % 101 - 50;
        }
    }
}

double averangeRowMatrix(int matrix[][n_columns], int n_columns, int i)
{
    int sum = 0, j;
    for (j = 0; j < n_columns; ++j)
    {
        sum += matrix[i][j];
    }
    return (double)sum / n_columns;
}

double averangeColumnMatrix(int matrix[][n_columns], int n_rows, int j)
{
    int sum = 0, i;
    for (i = 0; i < n_rows; ++i)
    {
        sum += matrix[i][j];
    }
    return (double)sum / n_rows;
}

int main()
{
    srand(time(0));
    printf("Enter number of rows -> ");
    scanf("%d", &n_rows);
    printf("Enter number of columns -> ");
    scanf("%d", &n_columns);
    
    int matrix[n_rows][n_columns];
    fillRandom(matrix, n_rows, n_columns);

    int i, j;
    for (i = 0; i < n_rows; ++i)
    {
        for (j = 0; j < n_columns; ++j)
        {
            printf("%7d", matrix[i][j]);
        }
        printf("|%7.2lf\n", averangeRowMatrix(matrix, n_columns, i));
    }
    for (j = 0; j < n_columns; ++j)
    {
        printf("-------");
    }
    printf(" -------\n");
    for (j = 0; j < n_columns; ++j)
    {
        printf("%7.2lf", averangeColumnMatrix(matrix, n_rows, j));
    }
    printf("|\n");
    return 0;
}
