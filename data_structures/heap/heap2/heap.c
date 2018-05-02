#include "heap.h"

t_heap	*init_heap(size_t size)
{
	t_heap	*tmp;
	char	*arr;

	tmp = (t_heap *)malloc(sizeof(t_heap));
	check_malloc(tmp);
	arr = (char *)malloc(sizeof(arr[0]) * size);
	check_malloc(arr);
	tmp->arr = arr;
	tmp->i = 1;
	tmp->size = size;
	return (tmp);
}

void	swim(char *arr, int i)
{
	if(arr[parent(i)] > arr[i])
	{
		swap(arr + parent(i), arr + i);
		swim(arr, parent(i));
	}
}

void	insert(t_heap *heap, char data)
{
	if (heap->i + 1 >= (int)heap->size)
		resize(heap);
	heap->arr[heap->i] = data;
	swim(heap->arr, heap->i++);
}

char	peek(t_heap *heap)
{
	return (heap->arr[1]);
}

void	sink(t_heap *heap)
{
	int cur_i;
	int child_i;
	int valid_sink;

	child_i = 1;
	valid_sink = 1;
	while (valid_sink)
	{
		cur_i = child_i;
		child_i = get_child_i(heap->arr, cur_i, heap->i);
		if (child_i == -1 || heap->arr[child_i] > heap->arr[cur_i])
			valid_sink = 0;
		else
			swap(heap->arr + cur_i, heap->arr + child_i);
	}
}

char	getMin(t_heap *heap)
{
	char min;
	min = heap->arr[1];
	swap(heap->arr + 1, heap->arr + (--heap->i));
	sink(heap);
	return (min);
}
