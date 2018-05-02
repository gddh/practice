#include "sliding_window.h"
#include "string.h"

#define BUF_SIZE 1024

char	*read()
{
	char	buf[BUF_SIZE];
	char	*tmp;
	size_t		len;

	if (!fgets(buf, sizeof(buf), stdin))
	{
		fprintf(stderr, "Error in fgets\n");
		exit(1);
	}
	len = strlen(buf);
	tmp = (char *)malloc(sizeof(char) * len);
	memcpy(tmp, buf, len);
	tmp[len - 1] = '\0';
	return (tmp);
}

void	parse_for_num(int *dst, char *src)
{
	int s_i;
	int atoi_f;
	int d_i;

	s_i = 0;
	while (src[s_i] == ' ' && src[s_i] != '\0')
		s_i = s_i + 1;
	d_i = 0;
	while (src[s_i] != '\0')
	{
		if (atoi_f)
		{
			dst[d_i++] = atoi(src + s_i);
			atoi_f = 0;
		}
		if (src[s_i] == ' ')
			atoi_f = 1;
		s_i = s_i + 1;
	}
}

int		is_num(char *src, size_t i)
{
	if (i == 0)
		return src[i] != ' ';
	return (src[i] != ' ' && src[i - 1] == ' ');
}

size_t	count_num(char *src)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (src[i] != '\0')
	{
		if (is_num(src, i))
			count = count + 1;
		i = i + 1;
	}
	return (count);
}

int		main(void)
{
	char	*input;
	size_t	arr_size;
	int		sol_size;
	int		*sol;
	int		k;

	input = read();
	printf("READ: %s\n", input);

	k = 3;
	arr_size = count_num(input);
	sol_size = arr_size - k + 1;
	int arr[arr_size];
	parse_for_num(arr, input);
	printf("PRINTING RESULTS:");
	for (size_t i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	sol = maxSlidingWindow(arr, arr_size, k, (int*)&arr_size);
	for (int i = 0; i < sol_size; i++)
		printf("%d ", sol[i]);
	printf("\n");
	free(sol);
}
