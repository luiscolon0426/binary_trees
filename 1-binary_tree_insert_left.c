#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert node as left-child of other node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Description: If parent has left-child, the new node must take its
 * place, and old left-child must be set as left-child of new node.
 *
 * Return: pointer to created node or NULL if fails
 */


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (new);
	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;
	return (new);
}
