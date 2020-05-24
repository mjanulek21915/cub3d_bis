#include "cub3d.h"

void		mv_right(t_map *map)
{
	map->posx = map->posx + map->p_spd * cos(map->azi);
	map->posy = map->posy - map->p_spd * sin(map->azi);
}