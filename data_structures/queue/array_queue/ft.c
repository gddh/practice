#include "queue.h"

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
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

int		ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}
