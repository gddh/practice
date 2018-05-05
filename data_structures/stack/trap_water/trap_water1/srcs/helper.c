#include "trap_rain.h"

void	resize(t_stack *stack)
{
	int *new_arr;

	if (stack->max_size == 0)
		stack->max_size = 1;
	new_arr = (int *)malloc(sizeof(int) * stack->max_size * 2);
	check_malloc(new_arr);
	ft_memcpy(new_arr, stack->arr, stack->max_size * sizeof(int));
	free(stack->arr);
	stack->arr = new_arr;
	stack->max_size = stack->max_size * 2;
}

int		is_full(t_stack *stack)
{
	return ((int)stack->max_size == stack->top + 1);
}

int		is_empty(t_stack *stack)
{
	return (stack->top == -1);
}
