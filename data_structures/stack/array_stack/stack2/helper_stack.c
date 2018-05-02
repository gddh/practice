#include "stack.h"
#include <stdio.h>

int		is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

int		is_full(t_stack *stack)
{
	return (stack->top >= stack->maxSize - 1);
}

void	resize_stack(t_stack *stack)
{
	int		*new_arr;

	if (stack->maxSize == 0)
		stack->maxSize = 1;
	new_arr = (int *)malloc(sizeof(int) * (stack->maxSize * 2));
	check_malloc(new_arr);
	ft_memcpy(new_arr, stack->arr, sizeof(int) * stack->maxSize);
	free(stack->arr);
	stack->arr = new_arr;
	stack->maxSize = stack->maxSize * 2;
}
