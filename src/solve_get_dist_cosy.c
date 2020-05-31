#include "cub3d.h"

void		solve_get_dist_cosy(t_solve *solve)
{
	solve->dist =  solve->stepy / cos(solve->azi);
}