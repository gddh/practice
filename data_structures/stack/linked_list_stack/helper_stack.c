#include "stack.h"
#include <stdio.h>

void	check_malloc(t_list *node)
{
	if (!tmp)
	{
		fprintf(stderr, "Insufficient memory for malloc\n");
		exit(1);
	}	

}

t_list	*create_elem(void *data)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	check_malloc(tmp);
	tmp->next = NULL;
	tmp->data = data;
}
