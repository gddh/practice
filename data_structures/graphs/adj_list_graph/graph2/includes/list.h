#ifndef LIST_H
# define LIST_H

typedef struct	s_node	
{
	struct s_node	*next;
	g_type		vertex;
}				t_node;

t_node			*create_elem(g_type vertex);
void			push_back(t_node **head, g_type vertex);
void			free_list(t_node **head);
void			print_list(t_node *head);
int				count_list(t_node *head);

# endif
