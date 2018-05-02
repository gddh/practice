#include <graph.h>

int		main(void)
{
	int size;
	int *sol;

	size = 6;
	t_graph *graph = init_graph(size);
	add_edge(graph, 0, 1);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 2, 3);
	add_edge(graph, 2, 4);
	add_edge(graph, 3, 5);
	print_edges(graph);
	printf("vertex num: %d edge count %d\n", count_vertices(graph), count_edges(graph));
	
	sol = dfs(graph, 0, 4);
	printf("printing sol array\n");
	for (int i = 0; i < graph->V; i++)
		printf("%d to %d \n",sol[i], i);
}
