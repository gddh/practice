#include "stack.h"

#define BUF_SIZE 1024

char	*read()
{
	char 	buf[BUF_SIZE];
	char	*tmp;
	int		len;

	if (!fgets(buf, sizeof(buf), stdin))
		fprintf(stderr, "fgets returned NULL.\n");
	len = ft_strlen(buf);
	tmp = (char *)malloc(sizeof(char) * len);
	ft_memcpy(tmp, buf, len);
	tmp[len - 1] = '\0';
	return (tmp);
}

int		is_num_start(char *str, int i)
{
	if (i == 0)
		return ((str[i] >= '0' && str[i] <= '9') || str[i] == '-');
	else
		return (!((str[i-1] >= '0' && str[i-1] <= '9') ||
					str[i-1] == '-') && ((str[i] >= '0' &&
					str[i] <= '9') || str[i] == '-'));
}

int		get_num_int(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_num_start(str, i))
			count = count + 1;
		i = i + 1;
	}
	return (count);
}

int		*split_str(char *str)
{
	int i;
	int *arr;
	int arr_i;
	int num_int;

	num_int = get_num_int(str);
	arr = (int *)malloc(sizeof(int) * num_int);
	i = 0;
	arr_i = 0;
	while (str[i] != '\0')
	{
		if (is_num_start(str, i))
			arr[arr_i++] = ft_atoi(str + i);
		i = i + 1;
	}
	return (arr);
}

int		main(void)
{
	char	*str;
	int		*arr;
	int 	size;
	t_stack	*stack;

	str = read();
	printf("INPUT %s\n", str);
	size = get_num_int(str);
	arr = split_str(str);
	stack = init_stack(size);
	for (int i = 0; i < size; i ++)
		push(stack, arr[i]);
	sort(stack);
	printf("SORTED: ");
	for (int i = 0; i < size; i++)
		printf("%d ", pop(stack));
	printf("\n");
}
