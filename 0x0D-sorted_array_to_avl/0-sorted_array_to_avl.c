#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array of ints
 * @array: Array of integers
 * @size: Number of integers in array
 * Return: Pointer to the root of the tree if successful, NULL otherwise
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);

	return (insert_node(NULL, array, size));
}


/**
 * insert_node - Creates an avl_t node with any possible children
 * @parent: Pointer to the node to be used as inserted node's parent
 * @array: Array of integers to derive inserted node's n value from
 * @size: Number of integers in array
 * Return: Pointer to inserted node if successful, NULL otherwise
 */
avl_t *insert_node(avl_t *parent, int *array, size_t size)
{
	avl_t *node, *root = parent;
	size_t middle, left_size, right_size;

	if (size == 0)
		return (NULL);

	node = malloc(sizeof(avl_t));
	if (node == NULL)
	{
		while (root->parent != NULL)
			root = root->parent;
		free_tree(root);
		return (NULL);
	}

	middle = (size - 1) / 2;
	left_size = middle;
	right_size = size - middle - 1;

	node->n = array[middle];
	node->parent = parent;
	if (size == 1)
	{
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		node->left = insert_node(node, array, left_size);
		node->right = insert_node(node, array + middle + 1, right_size);
	}
	return (node);
}

/**
 * free_tree - Frees a binary tree from the given node down
 * @root: The node (and all of its children) to free
 */
void free_tree(avl_t *root)
{
	if (root == NULL)
		return;

	free_tree(root->left);
	free_tree(root->right);
	free(root);
}
