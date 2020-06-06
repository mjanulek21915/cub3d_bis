#include "cub3d.h"

int		solve_wall_check_draw_y(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop)
{
fprintf(stderr, "solve_wall_check_draw_y v=%d h=%d\n posx=%f posy=%f, azi=%f\n", loop.v, loop.h, map->posx, map->posy, map->azi);

	solve_y->draw(map, map->walls[(int)solve_y->posx][(int)solve_y->posy], solve_y, loop);
	map->d_grid[(int)solve_y->posx][(int)solve_y->posy] = solve_y->sum_dist;
print_solve(solve_y, "solve_y\n", "  ");
print_solve(solve_x, "solve_x\n", "  ");
fprintf(stderr, "\n\n");
	return (1);
}