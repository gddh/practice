#include <list.h>
#include <stdio.h>

t_list	*init_queue(void)
{
	return (NULL);
}

void	enqueue(t_list **lst, int data)
{
	push_back(lst, data);
}

int		is_empty(t_list *lst)
{
	return (lst == NULL);
}

int		dequeue(t_list **lst)
{
	t_list 	*tmp;
	int		data;

	if (!is_empty(*lst))
	{
		data = (*lst)->data;
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		return (data);
	}
	else
		fprintf(stderr, "Cannot dequeue from empty list\n");
	exit(1);
}

int		q_size(t_list *lst)
{
	return (count_list(lst));
}

void	free_queue(t_list **lst)
{
	free_list(lst);
}
