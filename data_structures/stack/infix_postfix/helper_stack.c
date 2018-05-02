#include "stack.h"

t_stack		*create_node(stack_type data)
{
	t_stack *tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	check_malloc(tmp);
	tmp->next = NULL;
	tmp->data = data;
	return (tmp);
}

size_t		size(t_stack *stack)
{
	size_t count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count = count + 1;
	}
	return (count);
}

stack_type	peek(t_stack *stack)
{
	if (!is_empty(stack))
		return (stack->data);
	else
	{
		fprintf(stderr, "Cannot peek into empty stack.\n");
		exit(1);
	}
}
