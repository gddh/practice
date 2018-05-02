#ifndef MAZE_SOLVER_H
# define MAZE_SOLVER_H

# define N 4
# include <stdio.h>
# include <stdlib.h>

void	draw(int **sol);
int		is_safe(int maze[N][N], int x, int y);
void	check_malloc(void *ptr);
int		**init_sol(void);
int		solve_maze(int maze[N][N], int **sol, int x, int y);
void	solve(int maze[N][N]);


# endif
