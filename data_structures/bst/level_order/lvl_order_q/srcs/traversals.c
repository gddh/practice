#include "bst.h"

void	inorder(t_node *node)
{
	if (node)
	{
		inorder(node->left);
		printf("%d ", node->data);
		inorder(node->right);
	}
}

void	preorder(t_node *node)
{
	if (node)
	{
		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void	postorder(t_node *node)
{
	if (node)
	{
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->data);
	}
}
