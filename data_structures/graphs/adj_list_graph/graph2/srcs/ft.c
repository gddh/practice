#include <graph.h>

void	check_alloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}

void	fill_int_arr(int *arr, int filler, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = filler;
}
