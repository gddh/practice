#ifndef STACK_H
# define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int		*arr;
	int		top;
	size_t	max_size;
}				t_stack;

void			check_malloc(void *ptr);
void			*ft_memcpy(void *dst, const void *src, size_t n);
t_stack			*init_stack(size_t size);
void			push(t_stack *stack, int data);
int				pop(t_stack *stack);
int				peek(t_stack *stack);
int				is_full(t_stack *stack);
int				is_empty(t_stack *stack);
void			resize(t_stack *stack);
void			destroy_stack(t_stack **stack);

# endif
