#include "search.h"

/**
 * linear_skip - Search an ordered linked list for value using skip algorithm
 * @list: List to search
 * @value: Value to search for
 * Return: Pointer to first node containing the value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *lo = list, *hi, *curr = list;

	if (list == NULL)
		return (NULL);
	hi = lo->express;

	for (hi = lo->express; hi != NULL; lo = hi, hi = hi->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", hi->index, hi->n);
		if (value <= hi->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				lo->index, hi->index);
			for (curr = lo; curr; curr = curr->next)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					curr->index, curr->n);
				if (curr->n == value)
					return (curr);
			}
		}
	}
	curr = lo;
	while (curr->next != NULL)
		curr = curr->next;
	printf("Value found between indexes [%lu] and [%lu]\n",
		lo->index, curr->index);
	for (curr = lo; curr; curr = curr->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			curr->index, curr->n);
		if (curr->n == value)
			return (curr);
	}
	return (NULL);
}
