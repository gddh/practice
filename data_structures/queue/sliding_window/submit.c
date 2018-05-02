/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_queue 
{
	int		*arr;
	size_t	size;
	int		front;
	int		back;
	size_t	num_elem;
}				t_queue;

void	check_malloc(void	*ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}

void	resize(t_queue *q)
{
	int		*new_arr;
	size_t	i;

	if (q->size == 0)
		q->size = 1;
	new_arr = (int *)malloc(sizeof(int) * q->size * 2);
	check_malloc(new_arr);
	i = 0;
	while (i < q->num_elem)
		new_arr[i++] = q->arr[q->front++ % q->size];
	free(q->arr);
	q->front = 0;
	q->back = q->num_elem;
	q->arr = new_arr;
	q->size = q->size * 2;
}

t_queue	*init_queue(size_t size)
{
	t_queue *q;
	int		*arr;
	
	q = (t_queue *)malloc(sizeof(t_queue));
	check_malloc(q);
	arr = (int *)malloc(sizeof(int) * size);
	check_malloc(arr);
	q->arr = arr;
	q->size = size;
	q->front = 0;
	q->back = 0;
	q->num_elem = 0;
	return (q);
}

void	enqueue(t_queue *q, int data)
{
	if (q->size == q->num_elem)
	{
		resize(q);
	}
	q->arr[q->back++ % q->size] = data;
	q->num_elem = q->num_elem + 1;
}

int		is_empty(t_queue *q)
{
	return (q->num_elem == 0);
}

int		dequeue(t_queue *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "Cannot dequeue from empty array.\n");
		exit(1);
	}
	q->num_elem--;
	return (q->arr[q->front++ % q->size]);
}

int		back_dequeue(t_queue *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "Cannot dequeue from empty array.\n");
		exit(1);
	}
	q->num_elem--;
	return (q->arr[--q->back % q->size]);
}

int		back_peek(t_queue *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "Cannot peek into empty array.\n");
		exit(1);
	}
	return (q->arr[(q->back - 1) % q->size]);

}

int		peek(t_queue *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "Cannot peek into empty array.\n");
		exit(1);
	}
	return (q->arr[q->front % q->size]);
}

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

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int		*sol;
	size_t	i;
	size_t	sol_i;
	size_t	trailing;
	int tmp;
	t_queue	*q;
	
	*returnSize = numsSize - k + 1;
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

int 	main(void)
{
	int *p;
	int numSize;
	int returnSize = 6;
	numSize = 8;
	int nums[8] = {1, 3, -1, -3, 5, 3, 6, 7};
	p = maxSlidingWindow(nums, numSize, 3, &returnSize);
}
