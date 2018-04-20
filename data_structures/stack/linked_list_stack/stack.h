#ifndef STACK_H
# define STACK_H

typedef struct	s_list {
	struct s_list	*next;
	void			*data;
}				t_list;

void	check_malloc(t_list *node);
t_list	*create_elem(void *data);
int		is_empty(t_list *top);
void	*peek(t_list *top);
void	push(t_list **head, void *data);
void	*pop(t_list **head);
void	destroy_stack(t_list *head);

#endif
