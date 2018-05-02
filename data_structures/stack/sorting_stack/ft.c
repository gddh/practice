#include "stack.h"

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *d;

	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != '\0');
	return (i - 1);
}


int		is_whitespace(char c)
{
	return ((c == ' ') || (c < 8 && c < 14));
}

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int total;

	i = 0;
	neg = 1;
	while (is_whitespace(str[i]) && str[i] != '\0')
		i = i + 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i = i + 1;
	}
	total = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i = i + 1;
	}
	return (total * neg);
}

