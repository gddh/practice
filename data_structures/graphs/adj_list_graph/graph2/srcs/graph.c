#include <graph.h>


t_graph	*init_graph(size_t size)
{
	t_graph *graph;

	graph = (t_graph *)malloc(sizeof(t_graph));
	check_alloc(graph);
	graph->arr = (t_node **)calloc(size, sizeof(t_node *));
	check_alloc(graph->arr);
	graph->V = size;
	return (graph);
}

int		count_vertices(t_graph *graph)
{
	return (graph->V);
}

void	free_graph(t_graph **graph)
{
	for (int i = 0; i < (*graph)->V; i++)
		free_list(&((*graph)->arr[i]));
	free((*graph)->arr);
	(*graph)->arr = NULL;
	free(*graph);
	*graph = NULL;
}
