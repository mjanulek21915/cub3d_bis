#include "cub3d.h"

void		draw_background(int *background, int *img, int size)
{
	while (size--)
		*img++ = *background++;
}
void		draw(t_map *map, t_img *img)
{
	fprintf(stderr, "draw");
	fprintf(stderr, "draw map->background->size : %d\n", map->background->size);
	draw_background(map->background->bitmap, (int *)img->data, map->background->size);
}