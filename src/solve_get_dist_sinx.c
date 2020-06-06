#include "cub3d.h"

void		solve_get_dist_sinx(t_solve *solve)
{
	solve->dist = solve->stepx / sin(solve->azi);
	if (solve->dist < 0)
		solve->dist = -(solve->dist);
}