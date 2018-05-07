#include "queue.h"

t_queue	*create_node(qType data)
{
	t_queue	*tmp;
	if ((tmp = (t_queue *)malloc(sizeof(t_queue))))
	{
		tmp->next = NULL;
		tmp->data = data;
	}
	return (tmp);
}

int		size(t_queue *q)
{
	int count;

	count = 0;
	while (q)
	{
		q = q->next;
		count++;
	}
	return (count);
}

qType	peek(t_queue *q)
{
	if (!is_empty(q))
		return (q->data);
	else
	{
		fprintf(stderr, "Cannot peek into an empty queue.\n");
		exit(1);
	}
}

t_queue	*init_queue(void)
{
	return (NULL);
}

int		is_empty(t_queue *q)
{
	return (q == NULL);
}

