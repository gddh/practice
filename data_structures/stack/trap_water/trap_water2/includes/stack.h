#ifndef STACK_H
# define STACK_H

#include <stdio.h>
#include <jfj.h>
#include <stdlib.h>

typedef int		stack_type;

typedef struct	s_stack
{
	stack_type	*arr;
	int			top;
	int			size;
}				t_stack;

void		check_malloc(void *ptr);
void		*ft_memcpy(void *dst, const void *src, size_t n);
t_stack		*init_stack(size_t size);
void		push(t_stack *stack, stack_type data);
stack_type	pop(t_stack *stack);
int			is_empty(t_stack *stack);
stack_type	peek(t_stack *stack);
int			is_full(t_stack *stack);
void		resize(t_stack *stack);
void		destroy_stack(t_stack **stack);

#endif
