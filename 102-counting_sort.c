#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 Counting sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{

int max_val = array[0];
size_t i;
if (!array || size < 2)
return;
for (i = 1; i < size; i++)
{
if (array[i] > max_val)
max_val = array[i];
}

int *counting_array = malloc((max_val + 1) * sizeof(int));
if (!counting_array)
return;
for (i = 0; i <= (size_t)max_val; i++)
counting_array[i] = 0;

for (i = 0; i < size; i++)
counting_array[array[i]]++;

for (i = 1; i <= (size_t)max_val; i++)
counting_array[i] += counting_array[i - 1];
int *sorted_array = malloc(size * sizeof(int));
if (!sorted_array)
{
free(counting_array);
return;
}

for (i = 0; i < size; i++)
{
sorted_array[counting_array[array[i]] - 1] = array[i];
counting_array[array[i]]--;
}
for (i = 0; i < size; i++)
array[i] = sorted_array[i];

free(counting_array);
free(sorted_array);

print_array(array, size);
}
