#include "queens.h"

int		solve_queens(int **board, int col, int num_q, int n)
{
	int y;

	if (num_q == n)
		return (1);
	if(col >= 0 && col < n)
	{
		y = 0;
		while (y < n)
		{
			if (is_safe(board, col, y, n))
			{
				board[y][col] = 1;
				if (solve_queens(board, col + 1, num_q + 1, n))
					return (1);
				board[y][col] = 0;
			}
			y = y + 1;
		}
	}
	return (0);
}

void	solve(int n)
{
	int **board;

	if (n > 0)
	{
		board = init_board(n);
		if (solve_queens(board, 0, 0, n))
			draw(board, n);
		else
			printf("no solution found.\n");
	}
}
