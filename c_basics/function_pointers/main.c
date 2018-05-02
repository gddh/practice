#include <stdio.h>
#include <stdlib.h>

int		factorial(int n)
{
	int i;
	int factorial;

	i = 1;
	factorial = 1;
	while (i < n)
	{
		i = i + 1;
		factorial = factorial * i;
	}
	return (factorial);
}

int		cum_sum(int n)
{
	int i;
	int sum;

	i = 1;
	sum = 1;
	while (i < n)
	{
		i = i + 1;
		sum = sum + i;
	}
	return(sum);
}

int		cum_squares(int n)
{
	int i;
	int cum_sum;

	i = 1;
	cum_sum = 1;
	while (i < n)
	{
		i = i + 1;
		cum_sum = cum_sum + (i * i);
	}
	return (cum_sum);
}

int		sum_every_other(int n)
{
	int i;
	int sum;

	i = 1;
	sum = 1;
	while (i < n)
	{
		i = i + 1;
		sum = sum + (i * 2 - 1);
	}
	return (sum);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n", sum_every_other(atoi(argv[1])));
}


