#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void putRandom(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 101 - 50;
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int findMin(int *array, int size)
{
    int index = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] < array[index])
        {
            index = i;
        }
    }
    return index;
}

int findMax(int *array, int size)
{
    int index = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[i] > array[index])
        {
            index = i;
        }
    }
    return index;
}

int abs(int number)
{
    return number >= 0 ? number : -number;
}

void putAt(int *array, int index, int value)
{
    array[index] = value;
}

void putZeroBetween(int *array, int left, int right)
{
    int i;
    if (left > right)
    {
        i = left;
        left = right;
        right = i;
    }
    for (i = left + 1; i < right; ++i)
    {
        array[i] = 0;
    }
}

int main()
{
    srand(time(0));

    int array_size, *array;
    int max_index, min_index, sum_index;

    printf("Enter array size: ");
    scanf("%d", &array_size);

    array = (int *)malloc(array_size * sizeof(int));
    putRandom(array, array_size);

    printf("Array: ");
    printArray(array, array_size);

    max_index = findMax(array, array_size);
    min_index = findMin(array, array_size);
    sum_index = max_index + min_index;

    printf("\nMax element: %d; index: %d\n", array[max_index], max_index);
    printf("Min element: %d; index: %d\n", array[min_index], min_index);
    printf("Index sum: %d\n", sum_index);

    if (sum_index < abs(array[min_index]) && sum_index > abs(array[max_index]))
    {
        putAt(array, min_index, sum_index);
        putAt(array, max_index, sum_index);
    }
    else
    {
        putZeroBetween(array, min_index, max_index);
    }

    printf("\nArray: ");
    printArray(array, array_size);

    free(array);
    return 0;
}
