#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of BT
 * @tree: pointer to the root node
 * Return: tree size
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->parent)
	{
		return (binary_tree_depth(tree->parent) + 1);
	}
	return (0);
}
