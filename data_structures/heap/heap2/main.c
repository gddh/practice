#include "heap.h"
#include <string.h>

char	*read()
{
	char buff[512];
	int end = 0;
	char *data = NULL;
	int len;
	char *tmp;
	int size;

	size = 0;
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

int		main(void)
{
	char	*res;
	int		len;
	t_heap	*heap;
   
	res = read();
	len = strlen(res) - 1;

	printf("input: %s", res);
	heap = init_heap(len);
	for (int i = 0; i < len; i++)
		insert(heap, res[i]);
	printf("Sorted array: ");
	for (int i = 1; i <= len; i++)
		printf("%c ", heap->arr[i]);
	printf("\nPEEKING: %c\n", peek(heap));
	printf("REMOVING: \n");
	for (int i = 0; i < len/2; i++)
		printf("removed %c", getMin(heap));
	printf("\nINSERTING:\n"); 
	for (int i = 0; i < len/2; i++)
	{
		insert(heap, 'a' + i);
		printf("%c ",'a' + i);
	}
	printf("\n");
	printf("REMOVING: \n");
	for (int i = 0; i < len; i++)
		printf("removed %c", getMin(heap));
	printf("\n");
	free(res);
}
