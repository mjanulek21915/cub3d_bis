#include "cub3d.h"


void print_asset(t_asset *asset)
{
	 fprintf(stderr, "type: %c", asset->type);
}



void			mk_map_assets_malloc(t_map *map)
{
 fprintf(stderr, "mk_map_assets_bzero\n");

	int i;

	i = 0;
	if (!(map->asset = malloc(sizeof(t_asset) * 128)))
		do_exit("mk_map_malloc phail");
 fprintf(stderr, "mk_map_assets_iteration\n");
	while (i < 128)
	{
 fprintf(stderr, "%d ", i);
		map->asset[i].data = NULL;
		map->asset[i].type = 0;
		i++;
	}
	fprintf(stderr, "\n");
 fprintf(stderr, "mk_map_assets_bzero done\n");
}




int				mk_map_assets( t_map *map, char **buff)
{
 fprintf(stderr, "mk_map_assets\n");
	
	char temp;

	mk_map_assets_malloc(map);




	while (!(iz_it("assets:", *buff)))
		(*buff)++;
	next_line(buff);
	while (**buff && !(iz_it("/assets", *buff)))
	{
		while (**buff == '\n')
			(*buff)++;
		temp = **buff;
		if (iz_it(":block", ((*buff) + 1)))
		{
			map->asset[temp].type = 'b';
			next_line(buff);
			map->asset[temp].data = mk_map_assets_block(buff);
		}
		else if (iz_it(":player", ((*buff) + 1)))
		{
			map->asset[temp].type = '0';
			next_line(buff);
			mk_map_assets_player(map, buff);
		}
		else if (iz_it(":void", ((*buff) + 1)))
		{
 fprintf(stderr, "mk_map_assets block void\n");
			map->asset[temp].type = 'b';
			next_line(buff);
			map->asset[temp].data = mk_map_assets_block_void(buff);
		}
	}
 fprintf(stderr, "mk_map_assets done\n");
}