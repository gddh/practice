#include <stack.h>

t_stack	*init_stack(size_t size)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	check_malloc(stack);
	stack->arr = (stack_type *)malloc(sizeof(stack_type) * size);
	check_malloc(stack->arr);
	stack->top = -1;
	stack->size = size;
	return (stack);
}

void		push(t_stack *stack, stack_type data)
{
	if (is_full(stack))
		resize(stack);
	stack->arr[++stack->top] = data;
}

stack_type pop(t_stack *stack)
{
	if (!is_empty(stack))
		return (stack->arr[stack->top--]);
	fprintf(stderr, "Cannot pop from empty stack\n");
	exit(1);
}

stack_type	peek(t_stack *stack)
{
	if (!is_empty(stack))
		return (stack->arr[stack->top]);
	fprintf(stderr, "Cannot pop from empty stack\n");
	exit(1);
}

void		destroy_stack(t_stack **stack)
{
	free((*stack)->arr);
	free(*stack);
	*stack = NULL;
}
