// #include "cub3d.h"

// int		solve_wall_x_primer(t_solve *solve, t_map *map)
// {
//  fprintf(stderr, "solve_wall_x_primer\n");

// 	solve->stepy = solve->diry;
// 	solve->stepx = tan(solve->azi);
// 	solve->posx += solve->stepx;
// 	solve->posy += solve->stepy;
// 	if (solve->posy >= map->size_y || solve->posx >= map->size_x ||
// 	 solve->posy < 0 || solve->posx < 0)
// 		return (0);
// 	solve->get_dist(solve);
// 	solve->stepz = tan(solve->ati) * solve->dist;
// 	if (((solve->posz += solve->stepz) >= 1 || solve->posz <= 0))
// 		return (0);
// 	solve->sum_dist += solve->dist;
// 	solve->block = map->walls[(int)solve->posx][(int)solve->posy];
//  fprintf(stderr, "solve_wall_x_primer ok\n");
	
// 	return (1);
// }