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


void	print_level(t_node *node, int level)
{
	if (node)
	{
		if (level == 0)
			printf("%d ", node->data);
		else
		{
			print_level(node->left, level - 1);
			print_level(node->right, level - 1);
		}
	}
}

void	levelorder(t_node *root)
{
	printf("height is %d\n", height(root));
	for (int i = 0; i <= height(root); i++)
	{
		print_level(root, i);
	}
}
