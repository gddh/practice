#include  "maze_solver.h"

int		**init_sol(void)
{
	int **sol;
	int i;
	int j;

	sol = (int **)malloc(sizeof(int *) * N);
	check_malloc(sol);
	i = 0;
	while (i < N)
	{
		sol[i] = (int *)malloc(sizeof(int) * N);
		check_malloc(sol[i]);	
		j = 0;
		while (j < N)
			sol[i][j++] = 0;
		i = i + 1;
	}
	return (sol);
}

int		solve_maze(int maze[N][N], int **sol, int x, int y)
{
	draw(sol);

	if (x == N - 1 && y == N - 1)
	{
		sol[y][x] = 1;
		return (1);
	}
	if (is_safe(maze, x, y))
	{
		sol[y][x] = 1;
		if (solve_maze(maze, sol, x + 1, y))
			return (1);
		sol[y][x] = 0;
	}
	if (is_safe(maze, x, y))
	{
		sol[y][x] = 1;
		if (solve_maze(maze, sol, x, y + 1))
			return (1);
		sol[y][x] = 0;
	}
	return (0);
}

void	solve(int maze[N][N])
{
	int **sol = init_sol();
	if (solve_maze(maze, sol, 0, 0))
		draw(sol);
	else
		printf("No valid maze;");
}
