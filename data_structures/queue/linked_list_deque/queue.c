#include "queue.h"
#include <stdio.h>

t_queue	*init_queue(void)
{
	return (NULL);
}

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

int		is_empty(t_queue *q)
{
	return (q == NULL);
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
