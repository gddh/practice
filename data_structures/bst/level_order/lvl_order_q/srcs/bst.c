#include <bst.h>

t_node	*create_node(int data)
{
	t_node *tmp;

	if(!(tmp = (t_node *)malloc(sizeof(t_node))))
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
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
		return create_node(data);
	if (data < node->data)
		node->left = insert(node->left, data);
	if (data > node->data)
		node->right = insert(node->right, data);
	return (node);
}

t_node	*find_min(t_node *node)
{
	if (node->left == NULL)
		return (node);
	return (find_min(node->left));
}

t_node	*remove_min(t_node *node)
{
	if (node->left == NULL)
		return node->right;
	node->left = remove_min(node->left);
	return (node->left);
}

t_node	*remove_node(t_node *node, int data)
{
	t_node *tmp;

	if (!node)
		return (NULL);
	if (data < node->data)
		node->left = remove_node(node->left, data);
	if (data > node->data)
		node->right = remove_node(node->right, data);
	else
	{
		tmp = node;
		if (node->right == NULL)
			node = node->left;
		else if (node->left == NULL)
			node = node->right;
		else
		{
			node = find_min(tmp->right);
			node->right = remove_min(tmp->right);
		}
		free(tmp);
	}
	return (node);
}
