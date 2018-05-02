#include <stdio.h>
#include <stdlib.h>

int		factorial(int factorial, int i)
{
	return (factorial * i);
}

int		cum_sum(int sum, int i)
{
	return (sum + i);
}

int		cum_squares(int total, int i)
{
	return (total + (i * i));
}

int		sum_every_other(int sum, int i)
{
	return (sum + (i * 2 - 1));
}

int		cum_func(int n, int (*f) (int, int))
{
	int i;
	int cum;

	i = 1;
	cum = 1;
	while (i < n)
	{
		i = i + 1;
		cum = (*f)(cum, i);
	}
	return (cum);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int(*f)(int, int);
		f = &factorial;
		printf("factorial: %d\n", cum_func(atoi(argv[1]), f));
		printf("cum_sum: %d\n", cum_func(atoi(argv[1]), &cum_sum));
		printf("cum_square: %d\n", cum_func(atoi(argv[1]), &cum_squares));
		printf("sum_every_other: %d\n", cum_func(atoi(argv[1]), &sum_every_other));
	}
}
