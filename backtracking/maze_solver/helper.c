#include "maze_solver.h"

void	draw(int **sol)
{
	int y;
	int x;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			printf("%d ", sol[y][x]);
			x = x + 1;
		}
		printf("\n");
		y = y + 1;
	}
}

int		is_safe(int maze[N][N], int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
	{
		return (maze[y][x] == 1);
	}
	return (0);
}

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		fprintf(stderr, "Insufficient space for malloc.\n");
		exit(1);
	}
}


