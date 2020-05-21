#include "cub3d.h"

void		draw_background(int *background, int *img, int size)
{
	while (size--)
		*img++ = *background++;
}

float		draw_walls_get_x(float hdg, float posx, float posy, )
{
	
}

void		draw_walls(t_map *map, int *img)
{

}

void		draw(t_map *map, t_img *img)
{
	draw_background(map->background->bitmap, (int *)img->data, map->background->size);

}