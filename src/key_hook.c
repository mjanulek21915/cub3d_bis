#include "cub3d.h"

int	key_hook(int key, t_map *map)
{
	struct timespec tms;
	struct timespec tms2;


	if (key==0xFF1B)
		exit(0);
	if (key == UP)
	{
		mv_up(map);
		print_player(map, "\t>key_hook\n", "  ");

	}
	if (key == DOWN)
	{
		mv_down(map);
		print_player(map, "\t>key_hook\n", "  ");

	}
	if (key == LEFT)
	{
		mv_left(map);
		print_player(map, "\t>key_hook\n", "  ");


	}
	if (key == RIGHT)
	{
		mv_right(map);
		print_player(map, "\t>key_hook\n", "  ");

	}
		if (key == R_LEFT)
	{
		mv_r_left(map);
		print_player(map, "\t>key_hook\n", "  ");

	}
	if (key == R_RIGHT)
	{
		mv_r_right(map);
		print_player(map, "\t>key_hook\n", "  ");

	}

	map->f_draw(map);
}