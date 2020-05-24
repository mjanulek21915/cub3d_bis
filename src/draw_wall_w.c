#include "cub3d.h"

int		draw_wall_w(t_map *map, t_block *wall, t_solve *solve, t_loop loop)
{
	float h;
	float v;

	h = (float)(solve->posx - (int)map->posx);
	v = (float)(solve->posz - (int)map->posz);
fprintf(stderr, "h : %f\n", h);
fprintf(stderr, "v : %f\n", v);

	((int *)map->img->data)[(loop.v * map->vres) + loop.h] =
	 wall->w_texture->bitmap[(int)(v * wall->mult_w_v)][(int)(h * wall->mult_w_v)];
	return (0);
}