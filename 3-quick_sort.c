#include "sort.h"

/**
 * swap - Swaps two integer values.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 *
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_partition(int *array, size_t low, size_t high)
{
int pivot = array[high];
size_t i = low - 1, j;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, high + 1);
}
}
}

if (array[i + 1] != array[high])
{
swap(&array[i + 1], &array[high]);
print_array(array, high + 1);
}

return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick sort.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the sub-array.
 * @high: The ending index of the sub-array.
 */
void quicksort(int *array, size_t low, size_t high)
{
if (low < high)
{
size_t pivot_idx = lomuto_partition(array, low, high);

quicksort(array, low, pivot_idx - 1);
quicksort(array, pivot_idx + 1, high);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *              sort algorithm (Lomuto partition scheme).
 *
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quicksort(array, 0, size - 1);
}

