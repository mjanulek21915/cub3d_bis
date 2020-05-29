#include "cub3d.h"

void solve_wall_step(t_solve *solve_x, t_solve *solve_y)
{
	solve_x->posx = solve_x->posx + solve_x->stepx;
	solve_y->posx = solve_y->posx + solve_y->stepx;
	solve_x->posy = solve_x->posy + solve_x->stepy;
	solve_y->posy = solve_y->posy + solve_y->stepy;
	solve_x->posz = solve_x->posz + solve_x->stepz;
	solve_y->posz = solve_y->posz + solve_y->stepz;
	solve_x->sum_dist += solve_x->dist;
	solve_y->sum_dist += solve_y->dist;
}