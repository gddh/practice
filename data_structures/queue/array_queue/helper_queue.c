#include "queue.h"

int		is_empty(t_q *q)
{
	return (q->num_elem == 0);
}

void	resize(t_q *q)
{
	qType *new_arr;

	new_arr = (qType *)malloc(sizeof(qType) * q->size * 2);
	check_malloc(new_arr);
	ft_memcpy(new_arr, q->arr, q->size);
	free(q->arr);
	q->arr = new_arr;
	q->size = q->size * 2;
}
