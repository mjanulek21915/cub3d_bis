#include "cub3d.h"

int		solve_x_r_down(t_solve *solve_x, t_map *map, float ati, float hdg, )
{
	float temp;
	float delta_y;
	float temp_cos;

	temp = float_r_down(map->player_posy);
	delta = temp - map->player_posy;
	solve_x->pos_x += delta * tan(hdg);
	solve_x->pos_y = temp;

	solve_
	solve_x->pos_z += delta * tan(ati);
}