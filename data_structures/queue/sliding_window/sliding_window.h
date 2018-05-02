#ifndef SLIDING_WINDOW_H
# define SLIDING_WINDOW_H

#include <stdlib.h>
#include <stdio.h>

typedef struct	s_queue 
{
	int		*arr;
	size_t	size;
	int		front;
	int		back;
	size_t	num_elem;
}				t_queue;

t_queue	*init_queue(size_t size);
void	enqueue(t_queue *q, int data);
int		dequeue(t_queue *q);
int		peek(t_queue *q);
int		is_empty(t_queue *q);
void	resize(t_queue *q);
void	check_malloc(void *ptr);
int		back_dequeue(t_queue *q);
int		back_peek(t_queue *q);
int		*maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize);

#endif
