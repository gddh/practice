#include <graph.h>

int		is_edge(t_graph *graph, int src, int dest)
{
	t_node *tmp;

	tmp = graph->arr[src];
	while (tmp)
	{
		if (tmp->vertex == dest)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		valid_edge(t_graph *graph, int src, int dest)
{
	return (0 <= src && src < graph->V && 0 <= dest && dest < graph->V);
}

void	add_edge(t_graph *graph, int src, int dest)
{
	if (!is_edge(graph, src, dest) && valid_edge(graph, src, dest))
	{
		push_back(&graph->arr[src], dest);
		push_back(&graph->arr[dest], src);
	}
}

void	print_edges(t_graph *graph)
{
	for (int i = 0; i < graph->V; i++)
	{
		printf("Edges for Vertex %d: ", i);
		print_list(graph->arr[i]);
	}
	printf("\n");
}

int		count_edges(t_graph *graph)
{
	int count;

	count = 0;
	for (int i = 0; i < graph->V; i++)
		count = count +	count_list(graph->arr[i]);
	return (count);
}
