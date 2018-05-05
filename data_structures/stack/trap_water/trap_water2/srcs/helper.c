#include <stack.h>
#include <string.h>

void		resize(t_stack *stack)
{
	stack_type	*new_arr;

	if (stack->size == 0)
		stack->size = 2;
	new_arr = (stack_type *)malloc(sizeof(stack_type) * stack->size * 2);
	check_malloc(new_arr);
	memcpy(new_arr, stack->arr, stack->size * sizeof(stack_type));
	free(stack->arr);
	stack->arr = new_arr;
	stack->size = stack->size * 2;
}

int			is_full(t_stack *stack)
{
	return (stack->top + 1 == stack->size);
}

int			is_empty(t_stack *stack)
{
	return (stack->top == -1);
}
