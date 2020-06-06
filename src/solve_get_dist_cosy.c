#include "cub3d.h"

void		solve_get_dist_cosy(t_solve *solve)
{
	solve->dist =  solve->stepy / cos(solve->azi);
	if (solve->dist < 0)
		solve->dist = -(solve->dist);
}