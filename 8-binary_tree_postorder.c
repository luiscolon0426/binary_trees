#include "binary_trees.h"

/**
 * binary_tree_postorder - goes thru BT using postorder traversal
 * @tree: pointer to the root node
 * @func: function to call for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (tree)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
