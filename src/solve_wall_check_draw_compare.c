#include "cub3d.h"

int		solve_wall_check_draw_compare(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop)
{

	if (solve_x->sum_dist <= solve_y->sum_dist)
	{
		solve_x->draw(map, map->walls[(int)solve_x->posx][(int)solve_x->posy], solve_x, loop);
		map->d_grid[(int)solve_x->posx][(int)solve_x->posy] = solve_x->sum_dist;
		return (1);
	}
	solve_y->draw(map, map->walls[(int)solve_y->posx][(int)solve_y->posy], solve_y, loop);
	map->d_grid[(int)solve_y->posx][(int)solve_y->posy] = solve_y->sum_dist;
	return (1);
}