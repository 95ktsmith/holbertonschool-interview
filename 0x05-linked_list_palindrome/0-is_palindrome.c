#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * is_palindrome - Check if sinkgly linked list is a palindrome
 * @head: Pointer to head of the linked list
 * Return: 1 if linked list is palindrome, 0 if not.
 */
int is_palindrome(listint_t **head)
{
	listint_t *hi, *lo;
	int length = 1, index = 0;

	if (head == NULL || *head == NULL)
		return (1);

	for (hi = *head; hi->next != NULL; hi = hi->next)
		length++;

	for (lo = *head; length > 1; length -= 2, lo = lo->next)
	{
		for (hi = lo, index = 0; index < length - 1; index++)
			hi = hi->next;
		if (lo->n != hi->n)
			return (0);
	}
	return (1);
}
