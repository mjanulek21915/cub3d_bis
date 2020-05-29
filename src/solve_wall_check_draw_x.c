#include "cub3d.h"

int		solve_wall_check_draw_x(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop)
{

	solve_x->draw(map, map->walls[(int)solve_x->posx][(int)solve_x->posy], solve_x, loop);
	map->d_grid[(int)solve_x->posx][(int)solve_x->posy] = solve_x->sum_dist;
	return (1);

}