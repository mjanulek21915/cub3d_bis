#include "cub3d.h"

int		draw_wall_n(t_map *map, t_block *wall, t_solve *solve, t_loop loop)
{
	float h;
	float v;
	
fprintf(stderr, ">>>draw_wall_e :\nvalx=%f valy=%f valz=%f", solve->posx, solve->posx, solve->posz);

	h = (float)(solve->posy - (int)solve->posy);
	v = (float)(solve->posz - (int)solve->posz);
	((int *)map->img->data)[(loop.v * map->vres) + loop.h] =
	 wall->n_texture->bitmap[(int)(v * wall->mult_n_v)][(int)(h * wall->mult_n_v)];
	return (0);
}