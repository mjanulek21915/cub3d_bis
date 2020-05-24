#include "cub3d.h"

void	mk_map_masks(t_map *map)
{
 fprintf(stderr, "mk_map_masks\n");
	float h_base;
	float v_base;
	int i;

	if (!(map->masks = malloc(sizeof(t_masks))))
		do_exit("mk_mask: malloc fail\n");

	map->masks->hcount = ((int)map->hres / 2) + ((int)map->hres % 2) + 1;
	map->masks->vcount = ((int)map->vres / 2) + ((int)map->vres % 2) + 1;
	if (!(map->masks->h_mask = malloc(sizeof(int) * map->masks->hcount)) || 
	!(map->masks->v_mask = malloc(sizeof(int) * map->masks->vcount)))
		do_exit("mk_mask: malloc fail\n");

	map->hfov = map->hfov * PI / 180;
	map->vfov = map->vfov * PI / 180;

	h_base = tan(map->hfov) * map->masks->hcount;
	v_base = tan(map->vfov) * map->masks->vcount;

	i = 0;
	while (i < map->masks->hcount)
	{
		map->masks->h_mask[i] = atan((float)i / h_base);
		i++;
	}
	i = 0;
	while (i < map->masks->vcount)
	{
//  fprintf(stderr, "mk_map_masks ok\n");
		map->masks->v_mask[i] = atan((float)i / v_base);
		i++;
	}
 fprintf(stderr, "mk_map_masks done\n");
}