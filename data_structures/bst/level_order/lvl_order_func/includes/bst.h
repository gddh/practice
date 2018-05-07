#ifndef BST_H
# define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	struct s_node	*left;
	struct s_node	*right;
	int				data;
}				t_node;

t_node			*insert(t_node *node, int data);
t_node			*delete_node(t_node *node, int data);
t_node			*find_smallest(t_node *node);
int				height(t_node *node);

#endif
