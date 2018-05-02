#ifndef GRAPH_H
# define GRAPH_H

# include <stdlib.h>
# include <stdio.h>

typedef int		g_type;

# include "list.h"
# include "stack.h"

typedef struct	s_graph
{
	int		V;
	t_node	**arr;
}				t_graph;

# include "edges.h"

void			check_alloc(void *ptr);
void			fill_int_arr(int *arr, int filler, int size);
t_graph			*init_graph(size_t size);
int				count_vertices(t_graph *graph);
void			free_graph(t_graph **graph);
int				*dfs(t_graph *graph, int s, int d);

# endif 
