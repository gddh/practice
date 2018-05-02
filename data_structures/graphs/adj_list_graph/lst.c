#include "graph.h"

t_lst	*create_elem(lst_type data)
{
	t_lst *tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	check_malloc(tmp);
	tmp->next = NULL;
	tmp->data = data;
	return(tmp);
}

void	push_front(t_lst **head, lst_type data)
{
	t_lst *lst;

	if (*head)
	{
		lst = *head;
		*head = create_elem(data);
		(*head)->next = lst;
	}
	else
		*head = create_elem(data);
}

void	destroy_list(t_lst **head)
{
	t_lst *tmp;

	while(*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
