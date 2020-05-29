// #include "cub3d.h"

// int		solve_wall_y(t_solve *solve, t_map *map)
// {
// 	t_block *wall;
// 	solve->stepy = solve->stepx / tan(solve->azi);
// 	solve->posy += solve->stepy;
// 	solve->posx += solve->stepx;
// 	if (solve->posy >= map->size_y || solve->posx >= map->size_x ||
// 	 solve->posy < 0 || solve->posx < 0)
// 		return (0);
// 	solve->get_dist(solve);
// 	if (((solve->posz += (tan(solve->ati) * solve->dist)) >= 1 || solve->posz <= 0))
// 		return (0);
// 	solve->sum_dist += solve->dist;
// 	solve->block = map->walls[(int)solve->posx][(int)solve->posy];

// 	return (1);
// }