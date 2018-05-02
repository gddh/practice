#include "heap.h" 

t_heap	*init_heap(int size)
{
	int *arr;
	t_heap	*tmp;

	tmp = (t_heap *)malloc(sizeof(t_heap));
	check_malloc(tmp);
	if (size < 0)
		size = 1;
	arr = (int *)malloc(sizeof(int) * (size + 1));
	check_malloc(arr);
	tmp->arr = arr;
	tmp->size = size + 1;
	tmp->i = 1;
	return (tmp);
}

void	swim(int *arr, int i)
{
	if (arr[parent(i)] > arr[i])
	{
		swap(&arr[parent(i)], &arr[i]);
		swim(arr, parent(i));
	}
}

void	insert(t_heap *heap, int data)
{
	if (heap->i + 1 >= heap->size)
		resize(heap);
	heap->arr[heap->i] = data;
	swim(heap->arr, heap->i++);
}

int		peek(t_heap *heap)
{
	return (heap->arr[1]);
}

void	sink(t_heap *heap)
{
	int child_i;
	int cur_i;

	cur_i = 1;
	child_i = min_i(heap->arr, left_child(cur_i, heap->i),
		   			right_child(cur_i, heap->i), heap->i - 1);
	while (child_i < heap->i && child_i > 0 && heap->arr[cur_i] > heap->arr[child_i])
	{
		swap(&heap->arr[cur_i], &heap->arr[child_i]);
		cur_i = child_i;
		child_i = min_i(heap->arr, left_child(cur_i, heap->i), 
						right_child(cur_i, heap->i), heap->i);
	}
}

int		removeMin(t_heap *heap)
{
	int min;

	min = heap->arr[1];
	heap->i = heap->i - 1;
	swap(&(heap->arr[1]), &(heap->arr[heap->i]));
	sink(heap);
	return (min);
}
