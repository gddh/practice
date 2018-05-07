#include "bst.h"

t_node	*create_node(int data)
{
	t_node	*tmp;

	if(!(tmp = (t_node *)malloc(sizeof(t_node))))
	{
		fprintf(stderr, "Insufficient memory for malloc/\n");
		exit(1);
	}
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = data;
	return (tmp);
}

t_node	*insert(t_node *node, int data)
{
	if (!node)
		return (create_node(data));
	if (data < node->data)
		node->left = insert(node->left, data);
	if (data > node->data)
		node->right = insert(node->right, data);
	return (node);
}

t_node	*find_min(t_node *node)
{
	if (!node->left)
		return (node);
	return find_min(node->left);
}

t_node	*remove_min(t_node *node)
{
	if (!node->left)
		return (node->right);
	node->left = remove_min(node->left);
	return (node);
}

t_node	*delete_node(t_node *node, int data)
{
	t_node *tmp;

	if (!node)
		return (NULL);
	else if (data < node->data)
		node->left = delete_node(node->left, data);
	else if (data > node->data)
		node->right = delete_node(node->right, data);
	else
	{
		if (node->right == NULL)
			tmp = node->left;
		else if (node->left == NULL)
			tmp = node->right;
		else
		{
			tmp = find_min(node->right);
			tmp->right = remove_min(node->right);
			tmp->left = node->left;
		}
		free(node);
		return (tmp);
	}
	return (node);
}
