#include <graph.h>

t_graph	*init_graph(int size)
{
	t_graph *graph;

	graph = (t_graph *)malloc(sizeof(t_graph));
	check_malloc(graph);
	graph->arr = (t_list **)malloc(sizeof(t_list) * size);
	check_malloc(graph->arr);
	for (int i = 0; i < size; i++)
		graph->arr[i] = NULL;
	graph->V = size;
	return (graph);
}

void	free_graph(t_graph **graph)
{
	if (*graph)
	{
		for (int i = 0; i < (*graph)->V; i++)
			free_list((*graph)->arr + i);
		free((*graph)->arr);
		(*graph)->arr = NULL;
		free(*graph);
		(*graph) = NULL;
	}
}

int		count_vertices(t_graph *graph)
{
	return (graph->V);
}
