#include <graph.h>

int		*create_arr(int size, int c)
{
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		tmp[i] = c;
	return (tmp);
}

int		*bfs(t_graph *graph, int s, int target)
{
	int		*sol;
	int		*visited;
	int		cur_i;
	t_list	*cur_elem;
	t_list	*q;

	sol = create_arr(graph->V, -1);
	visited = create_arr(graph->V, 0);
	q = init_queue();
	enqueue(&q, s);
   	while (!is_empty(q))
	{
		cur_i = dequeue(&q);
		if (!visited[cur_i])
		{
			visited[cur_i] = 1;
			if (cur_i == target)
			{
				free(visited);
				free_queue(&q);
				return (sol);
			}
			cur_elem = graph->arr[cur_i];
			while (cur_elem)
			{
				if (!visited[cur_elem->data])
				{
					sol[cur_elem->data] = cur_i;
					enqueue(&q, cur_elem->data);
				}
				cur_elem = cur_elem->next;
			}
		}
	}
	free_queue(&q);
	free(visited);
	return (sol);
}
