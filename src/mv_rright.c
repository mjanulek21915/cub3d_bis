#include "cub3d.h"

void		mv_r_right(t_map *map)
{
	map->player_hdg = map->player_hdg - map->player_hdg_spd;
	print_player(map);
}