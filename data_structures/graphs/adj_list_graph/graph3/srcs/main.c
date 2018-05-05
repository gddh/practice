#include <graph.h>
#include <stdio.h>

int		main(void)
{
	int size;
	int *sol;

	size = 6;
	t_graph *graph = init_graph(size);
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 0, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 4);
	add_edge(graph, 3, 4);
	add_edge(graph, 4, 5);
	print_graph(graph);
	printf("vertex num: %d edge count %d\n", count_vertices(graph), count_edges(graph));
	sol = bfs(graph, 0, 5);
	for (int i = 0; i < 6; i ++)
		printf("%d came from %d\n", i, sol[i]);
	free_graph(&graph);
	free(sol);
	leaks();
}
