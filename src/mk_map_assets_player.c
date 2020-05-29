#include "cub3d.h"

void				mk_map_assets_player(t_map *map, char **buff)
{
// fprintf(stderr, "mk_map_assets_player\n");
	while (!(iz_it("/player", *buff)) && **buff)
	{
		// fprintf(stderr, "aaa\n");
		if (iz_it("HDG:", *buff))
			map->ati = get_value(buff) / 180 * PI;
		else if (iz_it("HDG_SPD:", *buff))
			map->r_spd = get_value(buff) / 180 * PI;
		else if (iz_it("POSX:", *buff))
			map->posx = get_value(buff);
		else if (iz_it("POSY:", *buff))
			map->posy = get_value(buff);
		else if (iz_it("POSZ:", *buff))
			map->posz = get_value(buff);
		else if (iz_it("POS_SPD:", *buff))
			map->p_spd = get_value(buff);
		(*buff)++;
	}
	next_line(buff);
	// print_player(map);
// fprintf(stderr, "mk_map_assets_player done\n");
}