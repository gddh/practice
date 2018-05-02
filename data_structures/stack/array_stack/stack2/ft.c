#include "stack.h"
#include <stdio.h>


void	check_malloc(void *tmp)
{
	if (!tmp)
	{
		fprintf(stderr, "Insufficient memory for malloc\n");
		exit(1);
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (void *)(dst);
}
