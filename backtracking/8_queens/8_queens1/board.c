#include "queens.h"

void	draw(int **board)
{
	int y;
	int x;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			printf("%d ", board[y][x]);
			x = x + 1;
		}
		printf("\n");
		y = y + 1;
	}
}

void	fill_board(int **board)
{
	int y;
	int x;

	y = 0;
	while (y < N)
	{
		board[y] = (int *)malloc(sizeof(int) * N);
		check_malloc(board[y]);
		x = 0;
		while (x < N)
		{
			board[y][x] = 0;
			x = x + 1;
		}
		y = y + 1;
	}

}

int		**init_board(void)
{
	int **board;

	board = (int **)malloc(sizeof(int *) * N);
	check_malloc(board);
	fill_board(board);
	return (board);
}
