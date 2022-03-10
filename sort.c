#include "sort.h"

// function to copy array so original array is not modified
int *getArrayCopy(int *array, int size)
{
    int *arrayCopy = (int *)malloc(size * sizeof(array[0]));
    for (int i = 0; i < size; i++)
    {
        arrayCopy[i] = array[i];
    }
    return arrayCopy;
}

// function to return sorted copy of array
int *sort(int *array, int size)
{
    int *arrayCopy = getArrayCopy(array, size); // copying array so orginal data is not modified
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arrayCopy[j] > arrayCopy[j + 1])
            {
                int temp = arrayCopy[j];
                arrayCopy[j] = arrayCopy[j + 1];
                arrayCopy[j + 1] = temp;
            }
        }
    }
    return arrayCopy;
}
