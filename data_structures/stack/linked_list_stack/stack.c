#include "stack.h"
#include <string.h>

t_list	*init_stack(void)
{
	return NULL;
}

int		is_empty(t_list *top)
{
	return (top == NULL);
}

void	*peek(t_list *top)
{
	if(is_empty(top))
	{
		fprintf(stderr, "Cannot peek at empty stack.\n");
		exit(1);
	}
	return top->data;
}

void	push(t_list **head, void *data)
{
	t_list *tmp;

	tmp = *head;
	*head = create_elem(data);
	(*head)->next = tmp;
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

void	destroy_stack(t_list **head)
{
	t_list *tmp;

	tmp = *head;
	while(tmp)
	{
		tmp = tmp->next;
		free(*head);
		*head = NULL;
		*head = tmp;
	}
}
