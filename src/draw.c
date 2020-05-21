#include "cub3d.h"

void		draw_background(int *background, int *img, int size)
{
	while (size--)
		*img++ = *background++;
}


void		draw(t_map *map, t_img *img)
{
	draw_background(map->background->bitmap, (int *)img->data, map->background->size);

}