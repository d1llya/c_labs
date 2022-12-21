#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fail()
{
    printf("Memory allocation failure!\n");
    exit(EXIT_FAILURE);
}

void fillRandom(int *matrix, int n_rows, int n_cols)
{
    int i, j;
    for (i = 0; i < n_rows; ++i)
    {
        for (j = 0; j < n_cols; ++j)
        {
            matrix[i * n_cols + j] = rand() % 101 - 50;
        }
    }
}

double averangeRowMatrix(int *matrix, int n_cols, int i)
{
    int sum = 0, j;
    for (j = 0; j < n_cols; ++j)
    {
        sum += matrix[i * n_cols + j];
    }
    return (double)sum / n_cols;
}

double averangeColumnMatrix(int *matrix, int n_rows, int n_cols, int j)
{
    int sum = 0, i;
    for (i = 0; i < n_rows; ++i)
    {
        sum += matrix[i * n_cols + j];
    }
    return (double)sum / n_rows;
}

int main()
{
    srand(time(0));
    int n_rows, n_columns, i, j, *matrix;

    printf("Enter number of rows -> ");
    scanf("%d", &n_rows);
    printf("Enter number of columns -> ");
    scanf("%d", &n_columns);

    if (!(matrix = (int *)malloc(n_rows * n_columns * sizeof(int))))
    {
        fail();
    }
    fillRandom(matrix, n_rows, n_columns);
    for (i = 0; i < n_rows; ++i)
    {
        for (j = 0; j < n_columns; ++j)
        {
            printf("%7d", matrix[i * n_columns + j]);
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
        printf("%7.2lf", averangeColumnMatrix(matrix, n_rows, n_columns, j));
    }
    printf("|\n");

    free(matrix);
    return 0;
}
