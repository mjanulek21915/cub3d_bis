#include "cub3d.h"

void				mk_map_assets_player(t_map *map, char **buff)
{
// fprintf(stderr, "mk_map_assets_player\n");
	while (!(iz_it("player end", *buff)) && **buff)
	{
		// fprintf(stderr, "aaa\n");
		if (iz_it("HDG:", *buff))
			map->player_hdg = get_value(buff) / 180 * PI;
		else if (iz_it("HDG_SPD:", *buff))
			map->player_hdg_spd = get_value(buff) / 180 * PI;
		else if (iz_it("POSX:", *buff))
			map->player_posx = get_value(buff);
		else if (iz_it("POSX_SPD:", *buff))
			map->player_posx_spd = get_value(buff);
		else if (iz_it("POSY:", *buff))
			map->player_posy = get_value(buff);
		else if (iz_it("POSY_SPD:", *buff))
			map->player_posy_spd = get_value(buff);
		(*buff)++;
	}
	next_line(buff);
// fprintf(stderr, "mk_map_assets_player done\n");
}