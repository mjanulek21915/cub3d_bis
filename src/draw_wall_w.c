#include "cub3d.h"

int		draw_wall_w(t_map *map, t_block *wall, t_solve *solve, t_loop loop)
{
	float h;
	float v;
// print_solve(solve);

	h = (float)(solve->posx - (int)solve->posx);
	v = (float)(solve->posz - (int)solve->posz);
// fprintf(stderr, "h : %f\n", h);
// fprintf(stderr, "v : %f\n", v);
// fprintf(stderr, "loop.v : %d\n", loop.v);
// fprintf(stderr, "loop.h : %d\n", loop.h);

	((int *)map->img->data)[(loop.v * map->vres) + loop.h] =
	 wall->w_texture->bitmap[(int)(v * wall->mult_w_v)][(int)(h * wall->mult_w_h)];
	return (0);
}