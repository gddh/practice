#include "queue.h"

t_q	*init_q(int size)
{
	t_q *q;
	qType	*arr;

	q = (t_q *)malloc(sizeof(t_q));
	check_malloc(q);
	arr = (qType *)malloc(sizeof(qType) * size);
	check_malloc(arr);
	q->arr = arr;
	q->front = 0;
	q->back = 0;
	q->num_elem = 0;
	q->size = size;
	return (q);
}

qType	peek(t_q *q)
{
	if (!is_empty(q))
		return (q->arr[q->front]);
	fprintf(stderr, "Cannot peek at an empty queue\n");
	exit(1);
}

void	push(t_q *q, qType data)
{
	if (q->num_elem >= q->size)
		resize(q);
	q->arr[q->back++] = data;
	q->num_elem++;
}

qType	pop(t_q *q)
{
	qType val;

	if (is_empty(q))
	{
		fprintf(stderr,"Cannot pop from an empty queue\n");
		exit(1);
	}
	val = q->arr[q->front++];
	if (q->front == q->size)
		q->front = 0;
	q->num_elem--;
	return (val);
}
