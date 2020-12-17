#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts node into a sorted singly linked list
 * @head: Address of head node
 * @number: Number to insert
 * Return: Address of the new node if successful, NULL otherwise
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current, *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;

	current = *head;
	while (current)
	{
		if (number < current->n)
		{
			new_node->next = *head;
			*head = new_node;
			return (new_node);
		}
		if (current->next)
		{
			if (number <= current->next->n)
			{
				new_node->next = current->next;
				current->next = new_node;
				return (new_node);
			}
			current = current->next;
		}
		else
		{
			new_node->next = NULL;
			current->next = new_node;
			return (new_node);
		}
	}
	new_node->next = NULL;
	*head = new_node;
	return (new_node);
}
