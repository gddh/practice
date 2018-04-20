#include "stack.h"
#include "stdio.h"

t_stack	*init_stack(int maxSize)
{
	t_stack	*tmp;
	int		*arr;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	check_malloc(tmp);
	if (maxSize < 0)
		maxSize = 0;
	arr = (int *) malloc(sizeof(int) * maxSize);
	check_malloc(arr);
	tmp->arr = arr;
	tmp->maxSize = maxSize;
	tmp->top = -1;
	return (tmp);
}

int		peek(t_stack *stack)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "Cannot peek at empty stack.\n");
		exit(1);
	}
	return (stack->arr[(stack->top)]);
}

void	push(t_stack *stack, int data)
{
	if (is_full(stack))
		resize_stack(stack);
	stack->arr[++stack->top] = data;
}

int		pop(t_stack *stack)
{
	if (is_empty(stack))
	{
		fprintf(stderr, "Cannot pop from empty stack.\n");
		exit(1);
	}
	return (stack->arr[stack->top--]);
}

void	destroy_stack(t_stack *stack)
{
	free(stack->arr);
	free(stack);
}
