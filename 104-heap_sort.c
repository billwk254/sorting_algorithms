#include "sort.h"

/**
 * sift_down - Helper function to perform the sift-down operation
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * @idx: Index of the element to sift down
 * @max_size: Max size of the heap
 */
void sift_down(int *array, size_t size, size_t idx, size_t max_size)
{
int temp;
size_t largest = idx;
size_t left = 2 * idx + 1;
size_t right = 2 * idx + 2;

if (left < max_size && array[left] > array[largest])
largest = left;

if (right < max_size && array[right] > array[largest])
largest = right;

if (largest != idx)
{
int temp = array[idx];
array[idx] = array[largest];
array[largest] = temp;
print_array(array, size);
sift_down(array, size, largest, max_size);
}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
int temp;
if (array == NULL || size <= 1)
return;

for (int i = size / 2 - 1; i >= 0; i--)
sift_down(array, size, i, size);

 for (int i = size - 1; i > 0; i--)
{
int temp = array[0];
array[0] = array[i];
array[i] = temp;
print_array(array, size);
sift_down(array, size, 0, i);
}
}

