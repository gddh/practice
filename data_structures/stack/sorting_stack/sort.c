#include "stack.h"

void	pop_insert(t_stack *q, t_stack *tmp)
{
	size_t		count;
	stack_type	cur;

	count = 0;
	cur = pop(q);
	while (!is_empty(tmp) && cur < peek(tmp))
	{
		push(q, pop(tmp));
		count++;
	}
	push(tmp, cur);
	while (count--)
		push(tmp, pop(tmp));
}

void	sort(t_stack *q)
{
	t_stack		*tmp;
	stack_type	move;

	tmp = init_stack(q->arrSize);
	if (!is_empty(q))
	{
		push(tmp, pop(q));
		while (!is_empty(q))
			pop_insert(q, tmp);
		while(!is_empty(tmp))
		{
			move = pop(tmp);
			push(q, move);
		}
	}
}
