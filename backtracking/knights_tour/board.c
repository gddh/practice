#include "knights_tour.h"

int		**create_board(void)
{
	int **board;
	int *column;
	int x_i;
	int y_i;

	board = (int **)malloc(sizeof(int *) * N);
	check_malloc(board);
	y_i = 0;
	while (y_i < N)
	{
		board[y_i] = (int *)malloc(sizeof(int) * N);;
		check_malloc(board[y_i]);
		x_i = 0;
		while (x_i < N)
		{
			board[y_i][x_i] = -1;
			x_i = x_i + 1;
		}
		y_i = y_i + 1;
	}
	return (board);
}

void	draw(int **board)
{
	int x;
	int y;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			printf("%d ", board[x][y]);
			x = x + 1;
			if (x == N)
				printf("\n");
		}
		y = y + 1;
	}
	printf("\n");
}

void	free_board(int **board)
{
	int i;

	i = 0;
	while (i < N)
	{
		free(board[i]);
	}
	free(board);
	board = NULL;
}
