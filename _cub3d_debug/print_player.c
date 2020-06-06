#include "cub3d.h"

void print_player(t_map *map, char *label, char *indent)
{
	fprintf(stderr, "%s", label);
	fprintf(stderr, "%sHDG : %f\n", indent, map->azi);
	fprintf(stderr, "%sPOSX : %f\n", indent, map->posx);
	fprintf(stderr, "%sPOSY : %f\n", indent, map->posy);
	fprintf(stderr, "%sPOS_SPD : %f\n", indent, map->p_spd);
	fprintf(stderr, "%sHDG_SPD : %f\n", indent, map->r_spd);
}