#include <trap.h>

int		trap(int *height, int heightSize)
{
	t_stack *stack;
	int		total;
	int		cur_i;
	int		top_i;
	int		prev_i;
	int		w;
	int		h;

	stack = init_stack(0);
	cur_i = 0;
	total = 0;
	while (cur_i < heightSize)
	{
		while (!is_empty(stack) && height[peek(stack)] < height[cur_i])
		{
			top_i = pop(stack);
			if (!is_empty(stack))
			{
				prev_i = peek(stack);
				w = cur_i - prev_i - 1;
				h = min(height[cur_i], height[prev_i]) - height[top_i];
				total = total + h * w;
			}
		}
		push(stack, cur_i++);
	}
	destroy_stack(&stack);
	return (total);
}
