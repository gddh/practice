#include "stack.h"

t_stack	*init_stack(size_t size)
{
	t_stack *tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	check_malloc(tmp);
	tmp->arr = (int *)malloc(sizeof(int) * size);
	check_malloc(tmp->arr);
	tmp->max_size = size;
	tmp->top = -1;
	return (tmp);
}

void	push(t_stack *stack, int data)
{
	if (is_full(stack))
		resize(stack);
	stack->arr[++stack->top] = data;
}


int		pop(t_stack *stack)
{
	if (!is_empty(stack))
	{
		return (stack->arr[stack->top--]);
	}
	fprintf(stderr, "Cannot pop from empty stack!\n");
	exit(1);
}

int		peek(t_stack *stack)
{
	if (!is_empty(stack))
	{
		return stack->arr[stack->top];
	}
	fprintf(stderr, "Cannot peek into empty stack!\n");
	exit(1);
}

void	destroy_stack(t_stack **stack)
{
	free((*stack)->arr);
	free(*stack);
	*stack = NULL;
}
