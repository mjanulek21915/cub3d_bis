#include "cub3d.h"

void		solve_wall_set(t_solve *solve_x, t_solve *solve_y)
{
// fprintf(stderr, ">>>solve_wall_set :\n");

// print_solve(solve_x, " solve x :\n", "  ");
// print_solve(solve_y, " solve y :\n", "  ");
	solve_x->stepy = solve_x->diry;
	solve_x->stepx = tan(solve_x->azi) * solve_x->stepy * solve_x->dirx;
	solve_x->get_dist(solve_x);
	solve_x->stepz = tan(solve_x->ati) * solve_x->dist;

	solve_y->stepx = solve_y->dirx;
	solve_y->stepy = tan(solve_y->c_azi) * solve_y->stepx * solve_y->dirx;
	solve_y->get_dist(solve_y);
	solve_y->stepz = tan(solve_y->ati) * solve_y->dist;
// print_solve(solve_x, " solve x ok:\n", "  ");
// print_solve(solve_y, " solve y ok:\n", "  ");
// fprintf(stderr, "\n");
}