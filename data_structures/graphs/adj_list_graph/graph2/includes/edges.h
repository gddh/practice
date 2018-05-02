#ifndef EDGES_H
# define EDGES_H

int				is_edge(t_graph *graph, int src, int dest);
int				valid_edge(t_graph *graph, int src, int dest);
void			add_edge(t_graph *graph, int src, int dest);
void			print_edges(t_graph *graph);
int				count_edges(t_graph *graph);
# endif
