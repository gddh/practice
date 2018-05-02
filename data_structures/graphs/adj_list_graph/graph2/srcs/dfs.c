#include <graph.h>

int	*init_sol(t_graph *graph)
{
	int *arr;

	arr = (int *)malloc(sizeof(int) * graph->V);
	check_alloc(arr);
	fill_int_arr(arr, -1, graph->V);	
	return (arr);
}

int	*dfs(t_graph *graph, int s, int d)
{
	t_node	*stack;
	t_node	*cur_node;
	int		*sol;
	int		visited[graph->V];
	int		cur_vertex;

	stack = init_stack();
	sol = init_sol(graph);
	fill_int_arr(visited, 0, graph->V);
	push(&stack, s);
	while (!is_empty(stack))
	{
		cur_vertex = pop(&stack);
		if (!visited[cur_vertex])
		{
			visited[cur_vertex] = 1;
			if (cur_vertex == d)
			{
				free_stack(&stack);
				return (sol);
			}
			cur_node = graph->arr[cur_vertex];
			while (cur_node)
			{
				if (!visited[cur_node->vertex])
				{
					sol[cur_node->vertex] = cur_vertex;
					push(&stack, cur_node->vertex);
				}
				cur_node = cur_node->next;
			}
		}
	}
	return (NULL);
}
