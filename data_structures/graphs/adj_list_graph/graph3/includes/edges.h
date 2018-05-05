#ifndef EDGES_H
# define EDGES_H

void	print_edges(t_graph *graph, int vertex);
void	add_edge(t_graph *graph, int dst, int src);
int		valid_edge(t_graph *graph, int dst, int src);
int		count_edges(t_graph *graph);
int		is_edge(t_graph *graph, int dst, int src);

#endif 
