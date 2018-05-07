#ifndef QUEUE_H
# define QUEUE_H

#include <stdlib.h>

typedef char		qType;
typedef struct		s_queue
{
	struct s_queue	*next;
	qType			data;
}					t_queue;

t_queue				*init_queue();
void				enqueue_back(t_queue **q_front, qType data);
qType				dequeue(t_queue **q_front);
int					is_empty(t_queue *q);
int					size(t_queue *q);
t_queue				*create_node(qType data);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_strlen(char *str);
qType				peek(t_queue *q);
void				destroy_q(t_queue **q);

#endif
