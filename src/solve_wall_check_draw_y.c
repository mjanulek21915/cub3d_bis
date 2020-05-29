#include "cub3d.h"

int		solve_wall_check_draw_y(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop)
{

	solve_y->draw(map, map->walls[(int)solve_y->posx][(int)solve_y->posy], solve_y, loop);
	map->d_grid[(int)solve_y->posx][(int)solve_y->posy] = solve_y->sum_dist;
	return (1);
}