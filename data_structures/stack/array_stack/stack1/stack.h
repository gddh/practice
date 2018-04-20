
#ifndef STACK_H
# define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_stack {
	int *ptr;
	int maxSize;
	int top;
}				t_stack;

t_stack		*init_stack(int maxSize);
void		stack_destroy(t_stack *stack);
int			is_full(t_stack *stack);
int			is_empty(t_stack *stack);
void		stack_push(t_stack *stack, int data);
int			stack_pop(t_stack *stack);

#endif
