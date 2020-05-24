#include "cub3d.h"

void print_player(t_map *map)
{
	fprintf(stderr, "HDG : %f", map->azi);
	fprintf(stderr, "\tPOSX : %f", map->posx);
	fprintf(stderr, "\tPOSY : %f", map->posy);
	fprintf(stderr, "\tPOS_SPD : %f", map->p_spd);
	fprintf(stderr, "\tHDG_SPD : %f", map->r_spd);
	fprintf(stderr, "\n");
}