#include "stack.h"
#include <stdlib.h>
#include <string.h>

int		is_empty(t_list *top)
{
	return (!*top);
}

void	*peek(t_list *top)
{
	return top->data;
}

void	push(t_list **head, void *data)
{
	t_list *tmp;

	tmp = *head;
	*head = create_elem(data);
	head->next = tmp;
}

void	*pop(t_list **head)
{
	t_list	*tmp;
	void	*data;

	tmp = *head;
	*head = (*head)->next;
	data = tmp->data;
	free(tmp);
	return (data);
}

void	destroy_stack(t_list *head)
{
	t_list *tmp;

	tmp = head;
	while(head)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
