#include "cub3d.h"

void		solve_wall_y(t_solve *solve)
{
//  fprintf(stderr, "solve_wall_y\n");

	solve->stepy = tan(solve->c_azi) * solve->stepx;
	solve->posx = solve->posx + (solve->stepx * solve->dirx);
	solve->posy = solve->posy + (solve->stepy * solve->diry);
	solve->get_dist(solve);
	solve->stepz = tan(solve->ati) * solve->dist;
	solve->posz = solve->posz + solve->stepz;
	solve->sum_dist += solve->dist;
}