
#ifndef STACK_H
# define STACK_H

#include <string.h>
#include <stdlib.h>

typedef struct	s_stack {
	int		top;
	int		maxSize;
	int		*arr;
}				t_stack;

void			push(t_stack *stack, int data);
int				pop(t_stack *stack);
void			resize_stack(t_stack *stack);
int				is_full(t_stack *stack);
int				is_empty(t_stack *stack);
t_stack			*init_stack(int maxSize);
void			destroy_stack(t_stack *stack);
void			check_malloc(void *tmp);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			resize_stack(t_stack *stack);
int				peek(t_stack *stack);

# endif
