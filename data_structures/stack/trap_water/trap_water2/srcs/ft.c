#include <stack.h>

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient memory for malloc.\n");
		exit(1);
	}
}


int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}