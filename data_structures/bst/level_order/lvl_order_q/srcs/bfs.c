#include <q.h>

void	levelorder(t_node *root)
{
	q_node	*q;
	q_type	cur_node;
	
	q = init_q();
	enqueue(&q, root);
	while (!is_empty(q))
	{
		cur_node = dequeue(&q);
		printf("%d ", cur_node->data);
		if (cur_node->left)
		{
			enqueue(&q, cur_node->left);
		}
		if (cur_node->right)
		{
			enqueue(&q, cur_node->right);
		}
	}
}
