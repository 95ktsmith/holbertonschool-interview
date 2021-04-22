#include "sort.h"

/**
 * heap_sort - Sorts an array using heap sort algorithm
 * @array: Pointer to the beginning of the array to sort
 * @size: Number of ints in array
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, (int)size, size, i);

	for (i = (int)size - 1; i > 0; i--)
	{
		tmp = array[i];
		array[i] = array[0];
		array[0] = tmp;
		print_array(array, size);

		heapify(array, i, size, 0);
	}
}

/**
 * heapify - Heapify a subtree rooted with node i
 * @array: Pointer to beginning of array
 * @n: Number of ints in subtree
 * @size: Number of ints in array
 * @i: Index to use as root
 */
void heapify(int *array, int n, size_t size, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int tmp;

	if (l < n && array[l] > array[largest])
		largest = l;

	if (r < n && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		tmp = array[largest];
		array[largest] = array[i];
		array[i] = tmp;
		print_array(array, size);

		heapify(array, n, size, largest);
	}
}
