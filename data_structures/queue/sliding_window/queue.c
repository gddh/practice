#include "sliding_window.h"

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
		printf("resize?\n");
		resize(q);
	}
	q->arr[q->back++ % q->size] = data;
	q->num_elem = q->num_elem + 1;
	printf("enqeueud %d in %lu\n", data, (q->back - 1) % q->size);
}

int		dequeue(t_queue *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "Cannot dequeue from empty array.\n");
		exit(1);
	}
	q->num_elem--;
	printf("dequeue %d\n", q->arr[q->front %q->size]);
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
	printf("dequeue %d\n", q->arr[(q->back - 1) % q->size]);
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

int		is_empty(t_queue *q)
{
	return (q->num_elem == 0);
}
