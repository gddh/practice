#include "bst.h"

t_node	*create_node(int data)
{
	t_node *tmp;
	
	if(!(tmp = (t_node *)malloc(sizeof(t_node))))
		fprintf(stderr, "Insufficient memory for malloc.\n");
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	printf("creating %d at %p\n", tmp->data, tmp);
	return(tmp);
}

t_node	*insert(t_node *node, int data)
{
	if (!node)
	{
		return create_node(data);
	}
	if (data < node->data)
		node->left = insert(node->left, data);
	if (data > node->data)
	{
		node->right = insert(node->right, data);
	}
	return (node);
}

t_node *find_smallest(t_node *node)
{
	if (!node)
		return (NULL);
	if (!node->left)
		return node;
	return find_smallest(node->left);
}

t_node	*deleteSmallest(t_node *node)
{
	t_node *tmp;

	if (node->left == NULL)
	{
		tmp = node->right;
		return tmp;
	}
	node->left = deleteSmallest(node->left);
	return (node);
}

t_node	*deleteNode(t_node *node, int data)
{
	t_node *tmp;

	if (!node)
		return (NULL);
	else if (data < node->data)
		node->left = deleteNode(node->left, data);
	else if (data > node->data)
		node->right = deleteNode(node->right, data);
	else 
	{
		if (node->left == NULL)
		{
			tmp = node->right;
			free(node);
			return tmp;
		}
		else if (node->right == NULL)
		{
			tmp = node->left;
			free(node);
			return tmp;
		}
		else
		{
			tmp = node;
			node = find_smallest(node->right);
			node->right = deleteSmallest(tmp->right);
			node->left = tmp->left;
		}
		free(tmp);
	}
	return (node);
}
