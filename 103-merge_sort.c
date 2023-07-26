#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 *
 * @array: The array containing the two subarrays to be merged.
 * @left: Pointer to the start of the left subarray.
 * @mid: Pointer to the end of the left subarray.
 * @right: Pointer to the end of the right subarray.
 */
void merge(int *array, int *left, int *mid, int *right)
{
int i, j, k;
int n1 = mid - left + 1;
int n2 = right - mid;

int *L = malloc(n1 * sizeof(int));
int *R = malloc(n2 * sizeof(int));
if (!L || !R)
{
free(L);
free(R);
return;
}

for (i = 0; i < n1; i++)
L[i] = left[i];
for (j = 0; j < n2; j++)
R[j] = mid[j + 1];

i = 0;
j = 0;
k = left - array;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
array[k++] = L[i++];
else
array[k++] = R[j++];
}

while (i < n1)
array[k++] = L[i++];

while (j < n2)
array[k++] = R[j++];

free(L);
free(R);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm (top-down approach).
 *
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
int *mid = array + (size / 2);
if (!array || size < 2)
return;

merge_sort(array, size / 2);
merge_sort(mid, size - (size / 2));

printf("Merging...\n[left]: ");
print_array(array, size / 2);
printf("[right]: ");
print_array(mid, size - (size / 2));

merge(array, array, mid - 1, array + size - 1);

printf("[Done]: ");
print_array(array, size);
}
