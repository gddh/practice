#include "graph.h"

void	print_vertex_edges(t_graph *graph, int vertex)
{
	t_lst *tmp;

	tmp = graph->arr[vertex];
	printf("Vertex %d: ", vertex);
	while (tmp)
	{
		printf("%d, ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int		count_list(t_lst *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count = count + 1;
		lst = lst->next;
	}
	return (count);
}
