#include "queue.h"
#include "stdio.h"

#define BUF_SIZE 1024

char	*read()
{
	char buf[BUF_SIZE];
	char *tmp;
	int len;

	if (!fgets(buf, sizeof(buf), stdin))
	{
		fprintf(stderr, "Error in fgets.\n");
		exit(1);
	}
	len = ft_strlen(buf) - 1;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	ft_memcpy(tmp, buf, len);
	tmp[len] = '\0';
	return (tmp);
}

void	print_list(t_queue *head)
{
	while (head)
	{
		printf("%c--> ", head->data);
		head = head->next;
	}
	printf("\n");
}

int		main(void)
{
	char *input = read();
	printf("|%s|\n", input);

	t_queue *q;
	
	q = init_queue();
	printf("INITIALIZED Q\n");
	printf("is empty: |%d| ",is_empty(q));
	printf("size of queue %d\n", size(q));
	for (int i = 0; i < ft_strlen(input); i++)
	{
		enqueue_back(&q, input[i]);
		printf("enqueue_back: |%c| size: |%d|\n", input[i], size(q));
	}
	for (int i = 0; i < ft_strlen(input)/2; i++)
	{
		printf("dequeue: |%c|", dequeue(&q));
		printf("size: |%d|\n", size(q));
	}
	for (int i = 0; i < ft_strlen(input)/2; i++)
	{
		enqueue_back(&q, i + '0');
		printf("enqueue_back: |%c| size: |%d|\n", i + '0', size(q));
	}
	for (int i = 0; i < ft_strlen(input); i++)
	{
		printf("dequeue: |%c|", dequeue(&q));
		printf("size: |%d|\n", size(q));
	}
}
