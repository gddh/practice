#include "queens.h"

int		row_safe(int **board, int y)
{
	int i;

	i = 0;
	while (i < N)
	{
		if (board[y][i] == 1)
			return (0);
		i = i + 1;
	}
	return (1);
}

int		col_safe(int **board, int x)
{
	int i;

	i = 0;
	while (i < N)
	{
		if (board[i][x] == 1)
			return (0);
		i = i + 1;
	}
	return (1);
}

int		asc_safe(int **board, int x, int y)
{
	int i;
	i = 0;
	while (x + i < N && y + i < N)
	{
		if (board[y + i][x + i] == 1)
			return (0);
		i = i + 1;
	}
	i = 0;
	while (x - i >= 0 && y - i >= 0)
	{
		if (board[y - i][x - i] == 1)
			return (0);
		i = i + 1;
	}
	return (1);
}

int		desc_safe(int **board, int x, int y)
{
	int i;
	i = 0;
	while (x + i < N && y - i >= 0)
	{
		if (board[y - i][x + i] == 1)
			return (0);
		i = i + 1;
	}
	i = 0;
	while (x - i >= 0 && y + i >= N)
	{
		if (board[y + i][x - i] == 1)
			return (0);
		i = i + 1;
	}
	return (1);
}

int		is_safe(int **board, int x, int y)
{
	int row;
	int col;
	int asc;
	int des;
	
	if (0 <= x && x < N && 0 <= y && y < N)
	{
		row = row_safe(board, y);
		col = col_safe(board, x);
		asc = asc_safe(board, x, y);
		des = desc_safe(board, x, y);
		return (board[y][x] == 0 && row && col && asc && des);
	}
	return (0);
}
