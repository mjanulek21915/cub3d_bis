#include "cub3d.h"

void		solve_wall_x(t_solve *solve, t_loop loop)
{
print_loop(loop, "loop :\n", "  ");
print_solve(solve, "solve_wall_x\n", "  ");
	solve->stepx = tan(solve->azi) * solve->stepy;
	solve->posx = solve->posx + (solve->stepx * solve->dirx);
	solve->posy = solve->posy + (solve->stepy * solve->diry);
	solve->get_dist(solve);
	solve->stepz = tan(solve->ati) * solve->dist;
	solve->posz = solve->posz + solve->stepz;
	solve->sum_dist += solve->dist;
print_solve(solve, "solve_wall_x ok\n", "   ");

}