#include "sliding_window.h"

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

void	check_malloc(void	*ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}
