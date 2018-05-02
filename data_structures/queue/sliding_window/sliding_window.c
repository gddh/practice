#include "sliding_window.h"

void	add_q(t_queue *q, int data)
{
	while (!is_empty(q) && data > back_peek(q))
	{
		back_dequeue(q);
	}
	enqueue(q, data);
}

int		remove_q(t_queue *q, int data)
{
	if (peek(q) == data)
		return (dequeue(q));
	return (peek(q));
}

int		*maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
	int		*sol;
	size_t	i;
	size_t	sol_i;
	size_t	trailing;
	int tmp;
	t_queue	*q;

	sol = (int *)malloc(sizeof(int) * (*returnSize));
	q = init_queue(k);
	i = 0;
	while (i < (size_t) k - 1)
		add_q(q, nums[i++]);
	sol_i = 0;
	trailing = 0;
	while (i < (size_t) numsSize)
	{
		add_q(q, nums[i++]);
		tmp = remove_q(q, nums[trailing++]);
		sol[sol_i++] = tmp;
	}
	return (sol);
}
