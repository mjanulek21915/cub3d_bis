#include "cub3d.h"

int		draw_wall_s(t_map *map, t_block *wall, t_solve *solve, t_loop loop)
{
	float h;
	float v;

	h = (float)(solve->posy - (int)solve->posy);
	v = (float)(solve->posz - (int)solve->posz);
	((int *)map->img->data)[(loop.v * map->vres) + loop.h] =
	 wall->s_texture->bitmap[(int)(v * wall->mult_s_v)][(int)(h * wall->mult_s_v)];
	return (0);
}