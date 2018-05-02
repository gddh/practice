#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef int stack_type;

typedef struct	s_stack
{
	stack_type	*arr;
	int			top;
	size_t		arrSize;
}				t_stack;

t_stack			*init_stack(size_t size);
void			check_malloc(void *ptr);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				is_empty(t_stack *stack);
void			resize(t_stack *stack);
int				is_full(t_stack *stack);
void			push(t_stack *stack, stack_type data);
stack_type		pop(t_stack *stack);
stack_type		peek(t_stack *stack);
int				ft_strlen(char *str);
int				is_whitespace(char c);
int				ft_atoi(char *st);
int				is_num_start(char *str, int i);
int				get_num_int(char *str);
int				*split_str(char *str);
void			sort(t_stack *q);

#endif
