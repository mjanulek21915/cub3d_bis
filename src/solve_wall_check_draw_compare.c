#include "cub3d.h"

int		solve_wall_check_draw_compare(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop)
{
fprintf(stderr, "solve_wall check compare v=%d h=%d\n posx=%f posy=%f, azi=%f\n", loop.v, loop.h, map->posx, map->posy, map->azi);

	if (solve_x->sum_dist <= solve_y->sum_dist)
	{
		solve_x->draw(map, map->walls[(int)solve_x->posx][(int)solve_x->posy], solve_x, loop);
		map->d_grid[(int)solve_x->posx][(int)solve_x->posy] = solve_x->sum_dist;
fprintf(stderr, "solve_x choisi\n");
print_solve(solve_x, "solve_x\n", "  ");
print_solve(solve_y, "solve_y\n", "  ");
fprintf(stderr, "\n\n");
		return (1);
	}
	solve_y->draw(map, map->walls[(int)solve_y->posx][(int)solve_y->posy], solve_y, loop);
	map->d_grid[(int)solve_y->posx][(int)solve_y->posy] = solve_y->sum_dist;
fprintf(stderr, "solve_y choisi\n");
print_solve(solve_x, "solve_x\n", "  ");
print_solve(solve_y, "solve_y\n", "  ");
fprintf(stderr, "\n\n");
	return (1);
}