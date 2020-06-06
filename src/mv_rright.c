#include "cub3d.h"

void		mv_r_right(t_map *map)
{
	map->azi = map->azi + map->r_spd;
	if (map->azi < 0)
		map->azi = map->azi + (2*PI);
	else if (map->azi >= (2 * PI))
		map->azi = map->azi - (2*PI);
}