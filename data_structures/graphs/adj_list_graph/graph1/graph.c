#include "graph.h"

t_graph	*init_graph(size_t size)
{
	t_graph	*graph;
	t_lst	**arr;

	graph = (t_graph *)malloc(sizeof(t_graph));
	check_malloc(graph);
	arr = (t_lst **)malloc(sizeof(t_lst *) * size);
	check_malloc(arr);
	for(size_t i = 0; i < size; i++)
	{
		arr[i] = NULL;
	}
	graph->arr = arr;
	graph->V = size;
	return (graph);
}

void	graph_destroy(t_graph *graph, size_t size)
{
	for(size_t i = 0; i < size; i++)
		destroy_list(&graph->arr[i]);
	free(graph->arr);
	free(graph);
}

int		is_edge(t_graph *graph, int src, int end)
{
	t_lst *edges;

	edges = graph->arr[src];
	while (edges)
	{
		if (edges->data == end)
		{
			return (1);
		}
		edges = edges->next;
	}
	return (0);
}

void	add_edge(t_graph *graph, int src, int end)
{
	t_lst	**arr;

	if (src >= 0 && src <= graph->V &&
			end >= 0 && end <= graph->V &&
			!is_edge(graph, src, end))
	{
		arr = graph->arr;
		push_front(&arr[src], end);
		push_front(&arr[end], src);
	}
}

int		vertex_count(t_graph *graph)
{
	return (graph->V);
}

int		edge_count(t_graph *graph)
{
	int count;

	count = 0;
	for (int i = 0; i < graph->V; i++)
	{
		count = count + count_list(graph->arr[i]);
	}
	return (count / 2);
}
