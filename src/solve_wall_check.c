#include "cub3d.h"

int			solve_wall_check(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop)
{
//  fprintf(stderr, "solve_wall_check\n");

	int rst_x;
	int rst_y;
	int status;

	rst_x = 0;
	rst_y = 0;

	if (solve_x->posx < map->size_x  && solve_x->posy < map->size_y &&
	 solve_x->posx > 0 && solve_x->posy > 0 && solve_x->posz < 1 && solve_x->posz > 0)
	{
	rst_x = 2;
		if (!(map->walls[(int)solve_x->posx][(int)solve_x->posy]->is_void))
			rst_x = 1;
	}
	if (solve_y->posx < map->size_y  && solve_y->posy < map->size_y &&
	 solve_y->posx > 0 && solve_y->posy > 0 && solve_y->posz < 1 && solve_y->posz > 0)
	{
	rst_y = 2;

		if (!(map->walls[(int)solve_y->posx][(int)solve_y->posy]->is_void))
			rst_y = 1;
	}
 status = (map->wall_check[rst_x][rst_y](solve_x, solve_y, map, loop));
fprintf(stderr, ">>>solve_wall_check : %d\n", status);
	return (status);
}