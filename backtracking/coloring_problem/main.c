#include "coloring.h"

int	main(void)
{
	int graph[V][V] = {
		{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0}
	};
	int m = 3;
	graphColoring(graph, m);
}
