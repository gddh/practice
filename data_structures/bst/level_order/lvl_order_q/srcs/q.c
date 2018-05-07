#include <q.h>

static q_node	*create_qnode(q_type data)
{
	q_node	*tmp;

	if(!(tmp = (q_node *)malloc(sizeof(q_node))))
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
	tmp->next = NULL;
	tmp->data = data;
	return (tmp);
}

void			enqueue(q_node **head, q_type data)
{
	q_node *tmp;

	if(*head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_qnode(data);
	}
	else
		*head = create_qnode(data);
}

q_type			dequeue(q_node **head)
{
	q_node 	*tmp;
	q_type	data;

	if (*head)
	{
		tmp = *head;
		data = (*head)->data;
		*head = (*head)->next;
		free(tmp);
		return (data);
	}
	else
	{
		fprintf(stderr, "Cannot dequeue from empty queue.\n");
		exit(1);
	}
}

void			destroy_q(q_node **q)
{
	while (!is_empty(*q))
		dequeue(q);
}
