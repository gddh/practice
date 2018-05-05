#include <trap_rain.h>

int		trap(int *height, int heightSize)
{
	t_stack *stack;
	int		total;
	int		cur_i;
	int		top_i;
	int		prev_i;
	int		dist;
	int		h;

	stack = init_stack(0);
	total = 0;
	cur_i = 0;
	while (cur_i < heightSize)
	{
		while (!is_empty(stack) && height[cur_i] > height[peek(stack)])
		{
			top_i = pop(stack);
			if (!is_empty(stack))
			{
				prev_i = peek(stack);
				dist = cur_i - prev_i - 1;
				h = min(height[cur_i], height[prev_i]) - height[top_i];
				total = total + dist * h;
			}
		}
		push(stack, cur_i);
		cur_i = cur_i + 1;
	}
	destroy_stack(&stack);
	return (total);
}
