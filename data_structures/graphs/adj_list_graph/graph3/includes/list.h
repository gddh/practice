#ifndef LIST_H
# define LIST_H

#include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	int				data;
}				t_list;

void			push_back(t_list **lst, int data);
void			free_list(t_list **lst);
int				count_list(t_list *lst);
void			print_list(t_list *lst);
int				in_list(t_list *lst, int target);
void			check_malloc(void *ptr);

#endif
