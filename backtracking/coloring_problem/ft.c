#include "coloring.h"
#include <stdio.h>

void	print_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i] + 1);
		i = i + 1;
	}
	printf("\n");
}

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient space for malloc.\n");
		exit(1);
	}
}

int		*create_sol_arr(void)
{
	int *sol;

	sol = (int *)malloc(sizeof(int) * V);
	check_malloc(sol);
	for (int i = 0; i < V; i++)
		sol[i] = -1;
	return (sol);
}
