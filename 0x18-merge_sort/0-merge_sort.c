#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - top-down merge sort
 * @array: Array of integerss to sort
 * @size: Number of integers in array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		exit(EXIT_FAILURE);

	split(array, size, tmp);
}

/**
 * split - top-down merge sort
 * @array: Array of integerss to sort
 * @size: Number of integers in array
 * @tmp: Temporary array to use for merging and swapping
 */
void split(int *array, size_t size, int *tmp)
{
	size_t middle;

	if (array == NULL || size < 2)
		return;

	middle = size / 2;

	/* Left */
	split(array, middle, tmp);

	/* Right */
	split(array + middle, size - middle, tmp);

	/* Merge */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, middle);
	printf("[right]: ");
	print_array(array + middle, size - middle);
	merge(array, middle, array + middle, size - middle, tmp);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - merge two arrays of integers together in ascending order
 * @left: Pointer to start of left array
 * @left_s: Number of integers in left array
 * @right: Pointer to start of right array
 * @right_s: Number of integers in right array
 * @tmp: Temporary array to use for merging and swapping
 */
void merge(int *left, size_t left_s, int *right, size_t right_s, int *tmp)
{
	size_t i = 0, j = 0;

	while (i + j < left_s + right_s)
	{
		if (i >= left_s)
		{
			tmp[i + j] = right[j];
			j++;
		}
		else if (j >= right_s)
		{
			tmp[i + j] = left[i];
			i++;
		}
		else
		{
			if (left[i] <= right[j])
			{
				tmp[i + j] = left[i];
				i++;
			}
			else
			{
				tmp[i + j] = right[j];
				j++;
			}
		}
	}

	for (i = 0; i < left_s + right_s; i++)
		left[i] = tmp[i];

}
