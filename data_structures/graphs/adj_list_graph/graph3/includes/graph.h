#ifndef GRAPH_H
# define GRAPH_H

#include <stdlib.h>
#include "list.h"
#include "jfj.h"
#include <stdio.h>

typedef struct	s_graph
{
	t_list	**arr;
	int		V;
}				t_graph;

#include "edges.h"
#include "queue.h"

t_graph			*init_graph(int size);
void			free_graph(t_graph **graph);
void			print_graph(t_graph *graph);
int				count_vertices(t_graph *graph);
int				*bfs(t_graph *graph, int s, int target);

#endif
