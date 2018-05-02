#include "graph.h"

int		main()
{
	int size;

	size = 5;
	t_graph *graph = init_graph(size);
	add_edge(graph, 0, 1);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 2, 3);
	add_edge(graph, 2, 4);
	for (int i = 0; i < size; i ++)
	{
		print_vertex_edges(graph, i);
	}
	printf("vertex num: %d edge count %d\n", vertex_count(graph), edge_count(graph));
	graph_destroy(graph, 3);
}
