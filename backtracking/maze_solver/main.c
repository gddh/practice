#include "maze_solver.h"

int		main(void)
{
	int maze[N][N] = {
		{1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
	solve(maze);
}
