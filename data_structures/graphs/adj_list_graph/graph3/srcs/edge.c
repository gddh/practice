#include <graph.h>

int		valid_edge(t_graph *graph, int dst, int src)
{
	return (src >= 0 && src >= 0 &&
		   	dst < graph->V && src < graph->V);
}

void	add_edge(t_graph *graph, int dst, int src)
{
	if (valid_edge(graph, dst, src))
	{
		push_back(graph->arr + src, dst);
		push_back(graph->arr + dst, src);
	}
}

int		count_edges(t_graph *graph)
{
	int count;

	count = 0;
	for (int i = 0; i < graph->V; i++)
		count = count + count_list(graph->arr[i]);
	return (count / 2);
}

int		is_edge(t_graph *graph, int dst, int src)
{
	if (valid_edge(graph, dst, src))
		return (in_list(graph->arr[src], dst));
	return (0);
}
