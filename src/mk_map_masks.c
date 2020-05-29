#include "cub3d.h"

void	mk_map_masks(t_map *map)
{
//  fprintf(stderr, "mk_map_masks\n");
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

// fprintf(stderr, "HFOVDEG = %f\n", map->hfov);
// fprintf(stderr, "VFOVDEG = %f\n", map->vfov);

	map->hfov = map->hfov * PI / 360;
	map->vfov = map->vfov * PI / 360;

	h_base = tan(PI12-map->hfov) * map->masks->hcount;
	v_base = tan(PI12-map->vfov) * map->masks->vcount;

// fprintf(stderr, "HVOV = %f\n", map->hfov);
// fprintf(stderr, "VBASE = %f\n", map->vfov);

// fprintf(stderr, "HBASE = %f\n", h_base);
// fprintf(stderr, "VBASE = %f\n", v_base);

	i = 0;
	while (i < map->masks->hcount)
	{
		map->masks->h_mask[i] = atan((float)i / h_base);
		i++;
	}
	i = 0;
	while (i < map->masks->vcount)
	{
		map->masks->v_mask[i] = atan((float)i / v_base);
		i++;
	}
	// print_mask(map->masks);
//  fprintf(stderr, "mk_map_masks done\n");
}