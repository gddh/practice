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
