#include <graph.h>

t_node	*create_elem(g_type vertex)
{
	t_node *tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	check_alloc(tmp);
	tmp->vertex = vertex;
	tmp->next = NULL;
	return (tmp);
}

void	push_back(t_node **head, g_type vertex)
{
	t_node *tmp;

	if (*head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_elem(vertex);
	}
	else
		*head = create_elem(vertex);
}

void	free_list(t_node **head)
{
	t_node *tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void	print_list(t_node *head)
{
	while (head)
	{
		printf("%d --> ", head->vertex);
		head = head->next;
	}
	printf("\n");
}

int		count_list(t_node *head)
{
	int count;

	count = 0;
	while (head)
	{
		count = count + 1;
		head = head->next;
	}
	return (count);
}
