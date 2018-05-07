#include "queue.h"
#include <stdio.h>

void	enqueue_back(t_queue **q_front, qType data)
{
	t_queue	*tmp;

	if (*q_front)
	{
		tmp = *q_front;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_node(data);
	}
	else
		*q_front = create_node(data);
}

void	enqueue_front(t_queue **q_front, qType data)
{
	t_queue *tmp;

	if (*q_front)
	{
		tmp = create_node(data);
		tmp->next = (*q_front);
		*q_front = tmp;
	}
	else
		*q_front = create_node(data);
}

qType	dequeue(t_queue **q_front)
{
	t_queue *tmp;
	qType 	data;

	if (*q_front)
	{
		tmp = *q_front;
		data = tmp->data;
		*q_front = (*q_front)->next;
		free(tmp);
		return (data);
	}
	else
	{
		fprintf(stderr, "Cannot dequeue from empty queue.\n");
		exit(1);
	}
}

void	destroy_q(t_queue **q)
{
	while (!is_empty(q))
		dequeue(q);
}
