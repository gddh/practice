#include "heap.h"

int		parent(int i)
{
	if (i <= 1)
		return (1);
	return (i / 2);
}

void	resize(t_heap *heap)
{
	char *new_arr;

	new_arr = (char *)malloc(sizeof(char) * heap->size * 2);
	check_malloc(new_arr);
	ft_memcpy(new_arr, heap->arr, sizeof(char) * heap->size);
	free(heap->arr);
	heap->arr = new_arr;
	heap->size = heap->size * 2;
}

int		get_child_i(char *arr, int i, int heap_i)
{
	int left_child_i;
	int right_child_i;

	left_child_i = i * 2;
	right_child_i = i * 2 + 1;
	if (left_child_i < heap_i && right_child_i < heap_i)
		return (min_i(arr, left_child_i, right_child_i));
	if (left_child_i < heap_i)
		return (left_child_i);
	if (right_child_i < heap_i)
		return (right_child_i);
	return (-1);
}
