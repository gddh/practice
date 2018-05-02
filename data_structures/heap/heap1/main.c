#include "heap.h"
#include <string.h>

char	*read()
{
	char	buff[512];
	size_t	len;
	char	*data = NULL;
	char	*tmp;
	size_t	size;
	int 	end = 0;
	while (!end)
	{	
		if (fgets(buff, sizeof(buff), stdin) == NULL) 
		{
			fprintf(stderr, "Error in reading the data.\n");
			exit(1);
		}
		if (strcmp(buff, "e\n") == 0)
			end = 1;
		if (!end)
		{
			len = strlen(buff);
			tmp = realloc(data, size + len + 1);
			if (tmp == NULL)
				fprintf(stderr, "Error in reallocation. \n");
			data = tmp;
			ft_memcpy(data + size, buff, len);
			size = size + len;
			data[size + 1] = '\0';
		}
	}
	return (data);
}

void basic_test()
{
	char *input;
	int input_size;
	t_heap *heap;

	input = read();
	input_size = strlen(input) - 1;
	for (int i = 0; i < input_size; i++)
		printf("%c ", input[i]);


	heap = init_heap(input_size);
	for (int i = 0; i < input_size; i++)
		insert(heap, input[i]);

	printf("Peeking: %c\n", peek(heap));
	printf("FINAL ARRAY IS : ");
	for (int i = 1; i <= input_size; i++)
		printf("%c ", heap->arr[i]);

	printf("REMOVING : \n");
	for (int i = 1; i <= input_size; i++)
		printf("%d smallest: %c\n",i, removeMin(heap));

	free(input);
}

int		main(void)
{	
	char *input;
	int input_size;
	t_heap *heap;

	input = read();
	input_size = strlen(input) - 1;
	for (int i = 0; i < input_size; i++)
		printf("%c ", input[i]);


	heap = init_heap(input_size);
	for (int i = 0; i < input_size; i++)
		insert(heap, input[i]);

	printf("FINAL ARRAY IS : ");
	for (int i = 1; i <= input_size; i++)
		printf("%c ", heap->arr[i]);

	printf("REMOVING : \n");
	for (int i = 1; i <= input_size / 2; i++)
		printf("%d smallest: %c\n",i, removeMin(heap));

	int i = 0;
	while (i < 10)
	{
		insert(heap, i + 'a');
		printf("inserting %c ", i + 'a');
		i = i + 2;
	}

	i = 1;
	while (i < 10)
	{
		insert(heap, i + 'a');
		printf("inserting %c ", i + 'a');
		i = i + 2;
	}

	printf("REMOVING : \n");
	for (int i = 1; i <= input_size / 2 + 10; i++)
		printf("%d smallest: %c\n",i, removeMin(heap));

	free(input);
}
