#include "cub3d.h"

void		mk_map_background(t_map *map, char *c_sky, char *c_dirt)
{
 fprintf(stderr, "mk_map_background\n");

	int i;
	int j;
	int k;
	int sky;
	int dirt;



	sky = *((int *)c_sky);
	dirt = *((int *)c_dirt);
	i = 0;
	k = 0;

	if (!(map->background = malloc(sizeof(t_background))))
		do_exit("mk_map_background malloc fail");
	map->background->size = map->hres * map->vres;
 fprintf(stderr, "mk_map_background : size %d\n", map->background->size);

	if (!(map->background->bitmap = malloc(sizeof(int) * map->background->size)))
		do_exit("mk_map_background malloc fail");
 fprintf(stderr, "mk_map_background test\n");
	
	while (i < map->hres / 2)
	{
		j = 0;
		while (j < map->vres)
		{
			map->background->bitmap[k] = sky;
			j++;
			k++;
		}
		i++;
	}
	while (i < map->hres)
	{
		j = 0;
		while (j < map->vres)
		{
			map->background->bitmap[k] = dirt;
			j++;
			k++;
		}
		i++;
	}
 fprintf(stderr, "mk_map_background done\n");

}