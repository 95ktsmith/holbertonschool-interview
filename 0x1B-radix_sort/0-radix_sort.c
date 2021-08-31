#include "sort.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * radix_sort - Perform radix sort algorithm
 * @array: Pointer to start of array to sort
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		exit(EXIT_FAILURE);

	recursive_radix(array, buffer, size, 1);

	free(buffer);
}

/**
 * recursive_radix - Recursively perform LSD radix sort
 * @array: Pointer to array to sort
 * @buffer: Pointer to temporary buffer
 * @size: Number of elements in array and buffer
 * @place: Significant digit to sort by
 */
void recursive_radix(int *array, int *buffer, size_t size, int place)
{
	int digit;
	size_t i, b = 0, done = 1;

	for (digit = 0; digit < 10; digit++)
	{
		for (i = 0; i < size; i++)
		{
			if (array[i] / place > 0)
				done = 0;

			if ((array[i] / place) % 10 == digit)
				buffer[b++] = array[i];
		}
	}

	for (i = 0; i < size; i++)
		array[i] = buffer[i];

	if (done)
		return;

	print_array(array, size);
	recursive_radix(array, buffer, size, place * 10);
}
