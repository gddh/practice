#ifndef QUEUE_H
# define QUEUE_H

#include "stdlib.h"
#include "stdio.h"

typedef	char	qType;
typedef struct	s_queue
{
	qType	*arr;
	int		front;
	int		back;
	int		num_elem;
	int		size;
}				t_q;

void	check_malloc(void *ptr);
t_q		*init_q(int size);
void	*memcpy(void *dst, const void *src, size_t n);
int		is_empty(t_q *q);
qType	peek(t_q *q);
void	push(t_q *q, qType data);
qType	pop(t_q *q);
void	resize(t_q *q);
int		is_empty(t_q *q);
int		ft_strcmp(const char *str1, const char *str2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif
