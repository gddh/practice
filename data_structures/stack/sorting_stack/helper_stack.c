#include "stack.h"

void		resize(t_stack *stack)
{
	stack_type	*new_arr;

	new_arr = (stack_type *)malloc(sizeof(stack_type) * stack->arrSize);
	check_malloc(new_arr);
	ft_memcpy(new_arr, stack->arr, stack->arrSize);
	free(stack->arr);
	stack->arr = new_arr;
	stack->arrSize = stack->arrSize * 2;
}

int			is_full(t_stack *stack)
{
	return (stack->top >= (int) stack->arrSize);
}

int			is_empty(t_stack *stack)
{
	return (stack->top == 0);
}
