#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is an avl tree
 * @tree: Pointer to root node
 * Return: 1 if tree is an avl tree, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (!is_bst(tree->left, tree->n, 0))
		return (0);

	if (!is_bst(tree->right, tree->n, 1))
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	if (abs(left - right) > 1)
		return (0);

	if (tree->left && tree->right)
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
	if (tree->left)
		return (binary_tree_is_avl(tree->left));
	return (binary_tree_is_avl(tree->right));
}

/**
 * height - Height of a binary tree
 * @tree: Pointer to root of the tree
 * Return: Height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_bst - Checks if a binary tree is a binary search tree
 * @tree: Pointer to root of the tree
 * @n: n value of the parent-most root
 * @side: Side of the tree being checked relative to the parent-most root.
 *        Value will be 0 for left and 1 for right.
 * Return: 1 if the tree is a BST, 0 if not.
 */
int is_bst(const binary_tree_t *tree, int n, int side)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->left->n > tree->n)
		return (0);

	if (tree->right && tree->right->n < tree->n)
		return (0);

	if (side == 0 && tree->n > n)
		return (0);

	if (side == 1 && tree->n < n)
		return (0);

	return (is_bst(tree->left, n, side) && is_bst(tree->right, n, side));
}
