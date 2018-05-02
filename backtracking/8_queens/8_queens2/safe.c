#include "queens.h"

int		check_row(int **board, int x, int y)
{
	int i;

	i = 0;
	while (i <= x)
	{
		if (board[y][i] == 1)
			return (0);
		i = i + 1;
	}
	return (1);
}

int		check_asc(int **board, int x, int y)
{
	int i;

	i = 0;
	while (x - i >= 0 && y - i >= 0)
	{
		if (board[y - i][x - i] == 1)
			return (0);
		i = i + 1;
	}
	return (1);
}

int		check_des(int **board, int x, int y, int n)
{
	int i;

	i = 0;
	while (x - i >= 0 && y + i < n)
	{
		if (board[y + i][x - i] == 1)
			return (0);
		i = i + 1;
	}
	return (1);
}


int		is_safe(int **board, int x, int y, int n)
{
	int row_safe;
	int asc_safe;
	int des_safe;

	row_safe = check_row(board, x, y);
	asc_safe = check_asc(board, x, y);
	des_safe = check_des(board, x, y, n);
	return (row_safe && asc_safe && des_safe);
}
