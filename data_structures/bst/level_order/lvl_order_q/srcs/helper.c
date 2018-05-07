#include <q.h>

q_node			*init_q(void)
{
	return (NULL);
}

int				is_empty(q_node *head)
{
	return (head == NULL);
}

q_type			peek(q_node *q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "Cannot peek into empty queue.\n");
		exit(1);
	}
	return (q->data);
}
