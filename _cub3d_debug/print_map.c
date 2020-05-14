#include "cub3d.h"

void print_map(t_map* map)
{
	int x;
	int y;

	x = 0;
	y = 0;

fprintf(stderr, "size_x : %d\n", map->size_x);
fprintf(stderr, "size_y : %d\n", map->size_y);

	while (x < map->size_x)
	{
		y = 0;
		while (y < map->size_y)
		{
			if (map->walls[x][y])
				fprintf(stderr, "x");
			else
				fprintf(stderr, "0");
			y++;
		}
		fprintf(stderr, "\n");
		x++;

	}
}