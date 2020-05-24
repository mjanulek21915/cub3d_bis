#include "cub3d.h"

void		solve_get_dist_cosy(t_solve *solve)
{
	solve->dist = cos(solve->azi) * solve->stepy;
}