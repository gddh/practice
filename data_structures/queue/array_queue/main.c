#include "queue.h"

#define BUF_SIZE 1024

char	*read()
{
	char	buf[BUF_SIZE];
	char	*tmp;
	int		len;

	if (!(fgets(buf, sizeof(buf), stdin)))
	{
		fprintf(stderr, "Error in fgets reading\n");
		exit(1);
	}
	len = ft_strlen(buf) - 1;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	ft_memcpy(tmp, buf, len);
	tmp[len] = '\0';
	return (tmp);
}

int		main(void)
{
	char	*input;
	t_q		*q;
	
	input = read();
	q = init_q(2);
	for (size_t i = 0; i < ft_strlen(input); i++)
	{
		push(q, input[i]);
		printf("%c ", peek(q));
	}
	printf("\n ARRAY STATE:");
	for (int i = 0; i < q->num_elem; i++)
		printf("%c ", q->arr[i]);
	printf("\n ARRAY SIZE: %d\nPOPPING: ", q->size);
	int tmp = q->num_elem;
	for (int i = 0; i < tmp / 2; i++)
		printf("%c ", pop(q));

	printf("\n ARRAY STATE:");
	for (int i = q->front; i < tmp; i++)
	{
		printf("%c ", q->arr[i % q->size]);
	}
	printf("\nenqueining: ");
	for (int i = 0; i < tmp / 2; i++)
	{
		push(q, i + '0');
		printf("%c ", i + '0');
	}
	printf("\n ARRAY STATE:");
	for (int i = 0; i < q->num_elem; i++)
		printf("%c ", q->arr[i]);

	printf("\ndequeueing: ");
	for (int i = 0; i < tmp; i++)
		printf("%c ", pop(q));

}
