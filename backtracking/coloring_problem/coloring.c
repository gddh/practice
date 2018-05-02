#include "coloring.h"
#include <stdio.h>

int		is_safe(int graph[V][V], int cur_color, int sol[V], int vertex_i)
{
	int i;

	i = 0;
	while (i < vertex_i)
	{
		if (graph[vertex_i][i] && sol[i] == cur_color)
				return (0);
		i = i + 1;
	}
	return (1);
}

int	solve(int graph[V][V], int color, int sol[V], int vertex_i)
{
	int cur_color;

	if (vertex_i == V)
		return (1);
	cur_color = 0;
	while (cur_color < color)
	{
		if (is_safe(graph, cur_color, sol, vertex_i))
		{
			sol[vertex_i] = cur_color;
			if (solve(graph, color, sol, vertex_i + 1))
				return (1);
			sol[vertex_i] = -1;
		}
		cur_color = cur_color + 1;
	}
	return (0);
}

void	graphColoring(int graph[V][V], int color)
{
	int *sol;

	sol = create_sol_arr();
	if (solve(graph, color, sol, 0))
		print_arr(sol, V);
	else
		printf("no valid solution found.\n");
	free(sol);
}
