#ifndef COLORING_H
# define COLORING_H

#define V 4
#include <stdlib.h>
void	graphColoring(int graph[V][V], int color);
void	print_arr(int *arr, int size);
void	check_malloc(void *ptr);
int		*create_sol_arr(void);
int		is_safe(int graph[V][V], int cur_color, int sol[V], int v_i);
void	graphColor(int graph[V][V], int color);

#endif
