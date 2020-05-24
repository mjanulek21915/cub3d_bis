#include "cub3d.h"

void		mv_r_right(t_map *map)
{
	map->azi = map->azi - map->p_spd;
}