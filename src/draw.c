#include "cub3d.h"

void		draw_background(int *background, int *img, int size)
{
	while (size--)
	{
		*img++ = *background++;

	}
}


void		draw(t_map *map)
{
 fprintf(stderr, "draw\n");

	draw_background(map->background->bitmap, (int *)(map->img->data), map->background->size);
map->f_expose(map->mlx, map->win, map->img, 0, 0);
 fprintf(stderr, "draw_background ok\n");
	draw_walls(map);
 fprintf(stderr, "draw ok\n");

}