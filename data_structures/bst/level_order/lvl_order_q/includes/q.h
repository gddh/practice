#ifndef Q_H
# define Q_H

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef t_node	*q_type; 

typedef	struct	s_qnode
{
	struct s_qnode	*next;
	q_type			data;
}				q_node;

q_node	*init_q(void);
void	enqueue(q_node **q, q_type data);
q_type	dequeue(q_node **q);
q_type	peek(q_node *q);
int		is_empty(q_node *q);
void	destroy_q(q_node **q);


#endif
