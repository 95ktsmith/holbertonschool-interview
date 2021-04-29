#include "search_algos.h"

/**
 * print_array - Prints the array currently being searched
 * @array: Array to print
 * @size: Number of elements in array
 */
void print_array(int *array, size_t size)
{
	size_t index;

	printf("Searching in array: ");
	for (index = 0; index < size; index++)
	{
		if (index == (size - 1))
			printf("%d\n", array[index]);
		else
			printf("%d, ", array[index]);
	}
}

/**
 * advanced_binary - Binary search through sorted array
 * @array: Pointer to start of the array
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index of the first matching instance of @value, or -1 if the array
 *         is empty, is NULL, or @value cannot be found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int mid, right;

	if (array == NULL || size == 0)
		return (-1);

	print_array(array, size);
	mid = (size - 1) / 2;

	if (size == 1)
		return (array[mid] == value ? (int)mid : -1);

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary(array, mid + 1, value));
	}

	if (array[mid] > value)
		return (advanced_binary(array, mid + 1, value));

	if (array[mid] < value)
	{
		right = advanced_binary(array + mid + 1, size - mid - 1, value);
		return (right < 0 ? -1 : mid + right + 1);
	}
	return (-1);
}
