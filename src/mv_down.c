#include "cub3d.h"

void		mv_down(t_map *map)
{
	map->player_posx = map->player_posx - map->player_posx_spd * sin(map->player_hdg);
	map->player_posy = map->player_posy - map->player_posy_spd * cos(map->player_hdg);
	print_player(map);
}