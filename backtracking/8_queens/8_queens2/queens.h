#ifndef QUEENS_H
# define QUEENS_H

#include <stdio.h>
#include <stdlib.h>

void	draw(int **board, int n);
void	check_malloc(void *ptr);
int		**init_board(int n);
int		is_safe(int **board, int x, int y, int n);
void	solve(int n);

#endif
