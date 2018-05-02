#include "stack.h"

t_stack		*init_stack(size_t size)
{
	t_stack		*stack;
	stack_type	*arr;

	stack = (t_stack *)malloc(sizeof(t_stack));
	check_malloc(stack);
	arr = (stack_type *)malloc(sizeof(stack_type) * size);
	check_malloc(arr);
	stack->arr = arr;
	stack->top = 0;
	stack->arrSize = size;
	return (stack);
}

void		push(t_stack *stack, stack_type data)
{
	if (is_full(stack))
		resize(stack);
	stack->arr[stack->top++] = data;
}

stack_type	pop(t_stack *stack)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "Cannot pop from empty stack.\n");
		exit(1);
	}
	return (stack->arr[--stack->top]); 
}

stack_type	peek(t_stack *stack)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "Cannot peek at empty stack.\n");
		exit(1);
	}
	return (stack->arr[stack->top - 1]);
}

void		free_stack(t_stack **stack)
{
	if (stack && *stack)
	{
		free((*stack)->arr);
		(*stack)->arr = NULL;
		free(*stack);
		*stack = NULL;
	}
}
