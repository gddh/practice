#include "heap.h"

void	resize(t_heap *heap)
{
	int *new_arr;

	if (heap->size < 1)
		heap->size = 1;
	new_arr = (int *)malloc(sizeof(heap->arr[0]) * heap->size * 2);
	check_malloc(new_arr);
	ft_memcpy(new_arr, heap->arr, sizeof(heap->arr[0]) * heap->size);
	free(heap->arr);
	heap->arr = new_arr;
	heap->size = heap->size * 2;
}

int		parent(int i)
{
	if (i < 1)
		fprintf(stderr, "i < 1 has no parent.\n");
	if (i == 1)
		return (1);
	return (i / 2);
}

int		left_child(int cur, int i)
{
	if (cur * 2  < i)
		return (cur * 2);
	return (i + 1);
}

int		right_child(int cur, int i)
{
	if (cur * 2 + 1 < i)
		return (cur * 2 + 1);
	return (i + 1);
}
