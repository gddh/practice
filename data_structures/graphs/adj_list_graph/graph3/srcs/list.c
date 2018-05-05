#include <list.h>

t_list	*create_node(int data)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	check_malloc(tmp);
	tmp->next = NULL;
	tmp->data = data;
	return(tmp);
}

void	push_back(t_list **lst, int data)
{
	t_list *tmp;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_node(data);
	}
	else
		*lst = create_node(data);
}

void	free_list(t_list **lst)
{
	t_list *tmp;
	
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

int		count_list(t_list *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count = count + 1;
		lst = lst->next;
	}
	return (count);
}

int		in_list(t_list *lst, int target)
{
	while (lst)
	{
		if (lst->data == target)
			return (1);
		lst = lst->next;
	}
	return (0);
}
