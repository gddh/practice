#include <bst.h>

int		max(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		height(t_node *node)
{
	if (!node)
		return (0);
	return (max(height(node->left), height(node->right)) + 1);
}
