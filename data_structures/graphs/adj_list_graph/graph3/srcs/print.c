#include <stdio.h>
#include <graph.h>

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d-->", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

void	print_edges(t_graph *graph, int vertex)
{
	if (vertex >= 0 && vertex < graph->V)
	{
		printf("Vertex %d: ", vertex);
		print_list(graph->arr[vertex]);
	}
	else
		fprintf(stderr, "Invalid vertex.\n");
}

void	print_graph(t_graph *graph)
{
	if (graph)
	{
		for (int i = 0; i < graph->V; i++)
			print_edges(graph, i);
	}
	else
	{
		printf("No edges to print\n");
	}
}

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}
