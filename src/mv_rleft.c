#include "cub3d.h"

void		mv_r_left(t_map *map)
{
	map->azi = map->azi + map->r_spd;
}