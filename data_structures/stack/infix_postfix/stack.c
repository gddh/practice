#include "stack.h"

t_stack		*init_stack(void)
{
	return (NULL);
}

void		push(t_stack **stack, stack_type data)
{
	t_stack *tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = create_node(data);
		(*stack)->next = tmp;
	}
	else
		(*stack) = create_node(data);
}

stack_type	pop(t_stack **stack)
{
	t_stack		*tmp;
	stack_type	data;

	tmp = *stack;
	*stack = (*stack)->next;
	data = tmp->data;
	free(tmp);
	return (data);
}

int			is_empty(t_stack *stack)
{
	return (stack == NULL);
}

void		destroy(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
