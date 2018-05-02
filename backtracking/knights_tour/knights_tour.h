#ifndef KNIGHTS_TOUR_H
# define KNIGHTS_TOUR_H

#include <stdio.h>
#include <stdlib.h>

# define N 8

int		**create_board(void);
void	draw(int **board);
void	check_malloc(void *ptr);
void	free_board(int **board);
int		is_safe(int **board,int possible_x, int possible_y);
int		solve(int **board, int x, int y, int *x_arr, int *y_arr, int next);
void	knights_tour(void);

#endif
