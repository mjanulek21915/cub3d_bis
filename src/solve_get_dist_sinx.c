#include "cub3d.h"

void		solve_get_dist_sinx(t_solve *solve)
{
	solve->dist = solve->stepx / sin(solve->azi);
}