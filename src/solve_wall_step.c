#include "cub3d.h"

int		solve_wall_step(t_solve *solve, t_map *map)
{
 fprintf(stderr, "solve_wall_step\n");

	solve->posx =+ solve->stepx;
	solve->posy =+ solve->stepy;
	solve->posz =+ solve->stepz;
		if (solve->posy >= map->size_y || solve->posx >= map->size_x ||
	 solve->posy < 0 || solve->posx < 0 || solve->posz >= 1 || solve->posz <= 0)
		return (0);
	solve->sum_dist =+ solve->dist;
	solve->block = map->walls[(int)solve->posx][(int)solve->posy];
 fprintf(stderr, "solve_wall_step ok\n");
	
	return (1);
}