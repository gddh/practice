#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef char	stack_type;

typedef struct	s_stack
{
	struct s_stack	*next;
	stack_type		data;
}				t_stack;

void			check_malloc(void *ptr);
t_stack			*init_stack(void);
t_stack			*create_node(stack_type data);
void			push(t_stack **stack, stack_type data);
stack_type		peek(t_stack *stack);
stack_type		pop(t_stack **stack);
int				is_empty(t_stack *stack);
void			destroy(t_stack **stack);
size_t			size(t_stack *stack);
char			*infix_postfix(char *str);
int				num_ops(char *str);
int				num_begins(char *str, int i);

#endif
