#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include <string.h>
# include <stdio.h>

typedef struct	s_list
{
	struct s_list	*next;
	int				data;
}				t_list;

void	print_list(t_list *head);
t_list	*create_elem(int data);
void	push_back(t_list **head, int data);
void	print_list_end(t_list *head, t_list *end);

#endif
