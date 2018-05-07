#ifndef BST_H
# define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	int				data;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

t_node			*insert(t_node *node, int data);
t_node			*remove_node(t_node *node, int data);

# endif
