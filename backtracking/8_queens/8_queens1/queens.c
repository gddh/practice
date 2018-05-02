#include "queens.h"

int		solve_queens(int **board, int x, int y, int num_q)
{
	if (num_q == N)
		return (1);

	while(y < N)
	{
		x = 0;
		while (x < N)
		{
			if (is_safe(board, x, y))
			{
				board[y][x] = 1;
				if (solve_queens(board, x, y, num_q + 1))
					return (1);
				board[y][x] = 0;
			}
			x = x + 1;
		}
		y = y + 1;
	}
	return (0);
}

void	solve(void)
{
	int **sol = init_board();
	if (solve_queens(sol, 0, 0, 0))
		draw(sol);
	else
		printf("no solution found\n");
}
