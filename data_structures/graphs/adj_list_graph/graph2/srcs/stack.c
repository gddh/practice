#include <graph.h>

t_node	*init_stack(void)
{
	return (NULL);
}

void	push(t_node **head, g_type vertex)
{
	t_node *tmp;

	if (*head)
	{
		tmp = create_elem(vertex);
		tmp->next = *head;
		*head = tmp;
	}
	else
		*head = create_elem(vertex);
}

g_type	pop(t_node **head)
{
	t_node *tmp;
	g_type vertex;

	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		vertex = tmp->vertex;
		free(tmp);
		return (vertex);
	}
	return (-1);
}

int		is_empty(t_node *head)
{
	return (head == NULL);
}

void	free_stack(t_node **stack)
{
	free_list(stack);
}
