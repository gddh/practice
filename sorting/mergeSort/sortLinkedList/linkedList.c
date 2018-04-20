#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*create_elem(int data)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->next = NULL;
		tmp->data = data;
	}
	return (tmp);
}

void	push_back(t_list **head, int data)
{
	t_list *tmp;
	
	if (*head)
	{
		tmp = *head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = create_elem(data);
	}
	else
		*head = create_elem(data);
}

void	print_list(t_list *head)
{
	while(head)
	{
		printf("%d --> ", head->data);
		head = head->next;
	}
	printf("\n");
}

void	print_list_end(t_list *head, t_list *tail)
{
	while(head && head != tail)
	{
		printf("%d --> ", head->data);
		head = head->next;
	}
	printf("\n");
}
