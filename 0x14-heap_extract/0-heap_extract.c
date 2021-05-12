#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * heap_extract - Extract the root from a binary heap
 * @root: Pointer to the address of the root of the heap
 * Return: Value of the extracted root, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *node;
	int extracted_value;

	if (root == NULL || *root == NULL)
		return (0);

	node = get_last_node(*root);
	extracted_value = (*root)->n;
	if (node != *root)
	{
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		node->parent = NULL;
		if ((*root)->left == node)
			node->left = NULL;
		else
			node->left = (*root)->left;
		if ((*root)->right == node)
			node->right = NULL;
		else
			node->right = (*root)->right;
		if (node->left != NULL)
			node->left->parent = node;
		if (node->right != NULL)
			node->right->parent = node;
		free(*root);
		*root = node;
		reorder(node);
	}
	else
	{
		free(*root);
		*root = NULL;
	}

	return (extracted_value);
}

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @root: Pointer to the root of the tree
 * Return: Number of nodes in the tree
 */
unsigned int count_nodes(heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * get_last_node - Gets the last node in a binary heap
 * @root: Pointer to the root of the tree
 * Return: Address of the last node
 */
heap_t *get_last_node(heap_t *root)
{
	unsigned int n_nodes, mask = 1;

	n_nodes = count_nodes(root);
	while (n_nodes / mask > 1)
		mask = mask << 1;
	mask = mask >> 1;

	while (mask)
	{
		if (n_nodes & mask)
			root = root->right;
		else
			root = root->left;
		mask = mask >> 1;
	}

	return (root);
}

/**
 * reorder - Reorders elements to follow max-heap rules
 * @root: Pointer to root of the tree to reorder
 */
void reorder(heap_t *root)
{
	int tmp;
	heap_t *swap_node = root;

	if (root->left && root->right)
	{
		if (root->left->n >= root->right->n)
		{
			if (root->left->n > root->n)
				swap_node = root->left;
		}
		else
		{
			if (root->right->n > root->n)
				swap_node = root->right;
		}
	}
	else if (root->left && root->left->n > root->n)
		swap_node = root->left;
	else if (root->right && root->right->n > root->n)
		swap_node = root->right;

	if (swap_node != root)
	{
		tmp = root->n;
		root->n = swap_node->n;
		swap_node->n = tmp;
		reorder(swap_node);
	}
}
