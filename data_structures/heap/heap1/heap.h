#ifndef HEAP_H
# define HEAP_H

#include <stdlib.h>
#include <stdio.h>

typedef	struct	s_heap {
	int	*arr;
	int	size;
	int i;
}				t_heap;

void			check_malloc(void *ptr);
t_heap			*init_heap(int size);
int				parent(int i);
void			swap(int *a, int *b);
void			insert(t_heap *heap, int data);
int				min_i(int *arr, int i1, int i2, int max_i);
int				left_child(int cur, int i);
int				right_child(int cur, int i);
void			resize(t_heap *heap);
void			swim(int *arr, int i);
void			insert(t_heap * heap, int data);
int				peek(t_heap *heap);
void			sink(t_heap *heap);
int				removeMin(t_heap *heap);
void			*ft_memcpy(void *dst, void *src, size_t n);

#endif
