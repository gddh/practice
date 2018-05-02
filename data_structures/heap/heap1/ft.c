#include "heap.h"

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc\n");
		exit(1);
	}
}

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		min_i(int *arr, int i1, int i2, int max_i)
{
	if (i2 > max_i)
		return (i1);
	if (arr[i1] < arr[i2] && i1 < max_i)
		return (i1);
	return (i2);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while(n--)
		*d++ = *s++;
	return (d);
}
