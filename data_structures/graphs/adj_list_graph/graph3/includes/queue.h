#ifndef QUEUE_H
# define QUEUE_H

t_list	*init_queue(void);
void	enqueue(t_list **lst, int data);
int		is_empty(t_list *lst);
int		dequeue(t_list **lst);
int		q_size(t_list *lst);
void	free_queue(t_list **lst);

# endif
