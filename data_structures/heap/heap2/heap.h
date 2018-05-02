#ifndef HEAP_H
# define HEAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_heap
{
	char		*arr;
	size_t		size;
	int			i;
}				t_heap;

void	swap(char *a, char *b);
void	check_malloc(void *ptr);
void	*ft_memcpy(void *dst, const void *src, size_t n);
t_heap	*init_heap(size_t size);
int		parent(int i);
void	swim(char *arr, int i);
void	insert(t_heap *heap, char data);
void	resize(t_heap *heap);
int		min_i(char *arr, int i1, int i2);
int		get_child_i(char *arr, int i, int heap_i);
char	peek(t_heap *heap);
char	getMin(t_heap *heap);

#endif
