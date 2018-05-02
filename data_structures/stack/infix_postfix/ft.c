#include "stack.h"

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}

int		is_whitespace(char c)
{
	return ((c > 8 && c < 14) || c == ' ');
}

int		num_begins(char *str, int i)
{
	if (i == 0)
		return (!is_whitespace(str[i]));
	return (is_whitespace(str[i - 1]) && (!is_whitespace(str[i])));
}

int		num_ops(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (num_begins(str, i))
			count = count + 1;
		i = i + 1;
	}
	return (count);
}
