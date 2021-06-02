#include "lists.h"

/**
 * find_listint_loop - check a link list for a loop
 * @head: Pointer to the head of the list to check
 * Return: Pointer to the node where the loop begins if a loop is present,
 * or NULL if no loop is present.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL || head->next == NULL || head->next->next)
		return (NULL);

	slow = head->next;
	fast = slow->next;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		return (NULL);

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return (slow);
}
