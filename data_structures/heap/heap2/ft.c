#include "heap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (d);
}

void	swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}

int		min_i(char *arr, int i1, int i2)
{
	if (arr[i1] < arr[i2])
		return (i1);
	return (i2);
}
