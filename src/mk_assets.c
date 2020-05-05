#include "cub3d.h"

int				mk_assets(char **buff, t_map *map)
{
	char temp;
	while (!(iz_it("assets:", *buff)))
		(*buff)++;
	next_line(buff);
	temp = **buff;
	while (!(iz_it("assets end")))
	{
		if (iz_it(":block"(*((*buff) + 1)))
		{
			map->asset[temp]->type = 'b';
			next_line(buff);
			map->asset[temp]->data = mk_block(buff);
		}
		if (iz_it(":player"(*((*buff) + 1)))
		{
			map->asset[temp]->type = 'p';
			next_line(buff);
			map->asset[temp]->data = mk_player(buff);
		}
		(*buff)++;
	}
}