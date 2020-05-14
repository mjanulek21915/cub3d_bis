#include "cub3d.h"

void print_player(t_map *map)
{
	fprintf(stderr, "HDG : %f", map->player_hdg);
	fprintf(stderr, "POSX : %f", map->player_posx);
	fprintf(stderr, "POSY : %f", map->player_posy);
	fprintf(stderr, "\n");
}