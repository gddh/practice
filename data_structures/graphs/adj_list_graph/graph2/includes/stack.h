#ifndef STACK_H
# define STACK_H

#include "list.h"

t_node	*init_stack(void);
void	push(t_node **head, g_type vertex);
g_type	pop(t_node **head);
int		is_empty(t_node *head);
void	free_stack(t_node **stack);

# endif
