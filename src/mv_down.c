#include "cub3d.h"

void		mv_down(t_map *map)
{
	map->posx = map->posx - map->p_spd * sin(map->azi);
	map->posy = map->posy - map->p_spd * cos(map->azi);
}