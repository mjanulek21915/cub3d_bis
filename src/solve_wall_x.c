#include "cub3d.h"

int		solve_wall_x(t_solve *solve, t_map *map)
{
fprintf(stderr, "solve_wall_x\n");
	t_block *wall;
	solve->stepx = solve->stepy * tan(solve->azi);
	solve->posx =+ solve->stepx;
	solve->posy =+ solve->stepy;
fprintf(stderr, "solve_wall_x: ");
print_solve(solve);
	if (solve->posy >= map->size_y || solve->posx >= map->size_x ||
	 solve->posy < 0 || solve->posx < 0)
		return (0);
	solve->get_dist(solve);
	solve->sum_dist =+ solve->dist;
print_solve(solve);
	if (((solve->posz =+ (tan(solve->ati) * solve->dist)) <= 1 || solve->posz >= 0))
		return (0);
fprintf(stderr, "solve_wall_x test\n");
	solve->block = map->walls[(int)solve->posx][(int)solve->posy];
	if (!solve->block->is_void)
		solve->is_found = 1;
fprintf(stderr, "solve_wall_x ok\n");
	return (1);
}