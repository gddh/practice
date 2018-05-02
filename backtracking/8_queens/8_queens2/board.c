#include "queens.h"

void	draw(int **board, int n)
{
	int y;
	int x;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			printf("%d ",board[y][x]);
			x = x + 1;
		}
		printf("\n");
		y = y + 1;
	}
}

void	fill_board(int **board, int n)
{
	int i;
	int j;

	i = 0;
	while(i < n)
	{
		board[i] = (int *)malloc(sizeof(int) * n);
		check_malloc(board[i]);
		j = 0;
		while (j < n)
		{
			board[i][j] = 0;
			j = j + 1;
		}
		i = i + 1;
	}
}

int		**init_board(int n)
{
	int **board;

	board = (int **)malloc(sizeof(int *) * n);
	check_malloc(board);
	fill_board(board, n);
	return (board);
}
