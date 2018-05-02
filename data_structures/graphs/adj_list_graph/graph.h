#ifndef GRAPH_H
# define GRAPH_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//#include "jfj.h"
typedef	int	lst_type;

typedef struct	s_lst
{
	struct s_lst	*next;
	lst_type	data;
}				t_lst;

typedef struct	s_graph
{
	int 		V;
	t_lst		**arr;
}				t_graph;

void	check_malloc(void *ptr);
t_lst	*create_elem(lst_type data);
void	push_front(t_lst **head, lst_type data);
t_graph	*init_graph(size_t size);
void	graph_destroy(t_graph *graph, size_t size);
void	add_edge(t_graph *graph, int src, int end);
void	print_vertex_edges(t_graph *graph, int vertex);
void	destroy_list(t_lst **head);
int		vertex_count(t_graph *graph);
int		count_list(t_lst *lst);
int		edge_count(t_graph *graph);

#endif
