#include "list.h"
#include <stdlib.h>
#include <string.h>


/**
 * add_node_end - Adds a node to the end of the list
 * @list: Pointer to the address of the head of the list
 * @str: String to copy into the new node
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *node;

	if (list == NULL)
		return (NULL);

	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);
	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	if (*list == NULL)
	{
		*list = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}

	return (node);
}

/**
 * add_node_begin - Adds a node to the beginning of the list
 * @list: Pointer to the address of the head of the list
 * @str: String to copy into the new node
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *node;

	if (list == NULL)
		return (NULL);

	node = malloc(sizeof(List));
	if (node == NULL)
		return (NULL);
	node->str = str;
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}

	*list = node;

	return (node);
}
