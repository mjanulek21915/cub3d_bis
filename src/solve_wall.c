#include "cub3d.h"

void		solve_wall(float ati, float azi, t_map *map, t_loop loop)
{
//  fprintf(stderr, "solve_wall\n");
	map->solve_walls[(int)(azi * PI14)](azi, ati, map, loop);
//  fprintf(stderr, "solve_wall ok\n");
}