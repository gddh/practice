#ifndef QUEENS_H
# define QUEENS_H

# define N 5
# include <stdlib.h>
# include <stdio.h>

void	check_malloc(void *ptr);
int		**init_board(void);
void	draw(int **board);
int		is_safe(int **board, int x, int y);
void	solve(void);

#endif
