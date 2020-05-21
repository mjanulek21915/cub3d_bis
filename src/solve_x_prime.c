#include "cub3d.h"

int		solve_x_r_down(t_solve *solve_x, t_map *map, float ati, float hdg)
{
	float temp;
	
	temp = solve->pos_y + 1;
	solve_x->pos_x += 1 * tan(hdg);
	solve_x->pos_y = temp;
	solve_x->pos_z += 1 * tan(ati);
}