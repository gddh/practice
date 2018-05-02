#include "knights_tour.h"

int		is_safe(int **board, int possible_x, int possible_y)
{
	return (possible_x >= 0 && possible_x < N && 
			possible_y >= 0 && possible_y < N &&
			board[possible_x][possible_y] == -1);
}

int		solve(int **board, int x, int y, int *x_arr, int *y_arr, int next)
{
	int i;
	int next_x;
	int next_y;

	if (next >= N * N)
		return (1);
	i = 0;

	while (i < 8)
	{
		next_x = x + x_arr[i];
		next_y = y + y_arr[i];
		if (is_safe(board, next_x, next_y))
		{
			board[next_x][next_y] = next;
			if (solve(board, next_x, next_y, x_arr, y_arr, next + 1))
				return (1);
			else
				board[x + x_arr[i]][y + y_arr[i]] = -1;
		}
		i  = i + 1;
	}
	return (0);
}

void	knights_tour(void)
{
	int **board;
	int x_movements[8] = {2,  2,  1,  1, -1, -1, -2, -2};
	int	y_movements[8] = {1, -1,  2, -2,  2, -2,  1, -1};

	board = create_board();
	board[0][0] = 0;
	if (solve(board, 0, 0, x_movements, y_movements, 1))
		draw(board);
}
