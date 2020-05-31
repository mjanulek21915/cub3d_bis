#include "cub3d.h"

void print_map(t_map* map)
{
	int x;
	int y;

	x = 0;
	y = 0;
fprintf(stderr, "------------------------------------------------------------------------------------------------------------------------\n\n");

fprintf(stderr, "size_y : %d\n", map->size_y);
fprintf(stderr, "size_x : %d\n", map->size_x);
fprintf(stderr, "posy : %f\n", map->posy);
fprintf(stderr, "posx : %f\n", map->posx);
fprintf(stderr, "azi : %f\n", map->azi);
fprintf(stderr, "ati : %f\n", map->ati);
fprintf(stderr, "\n");
print_mask(map->masks, ">>>masks :\n", "  ");
fprintf(stderr, "\n");
 

	while (x < map->size_x)
	{
		y = 0;
		while (y < map->size_y)
		{
			if (!(map->walls[x][y]->is_void))
				fprintf(stderr, "x");
			else
				fprintf(stderr, "0");
			y++;
		}
		x++;
		fprintf(stderr, "\n");

	}
fprintf(stderr, "\n------------------------------------------------------------------------------------------------------------------------\n\n");

fprintf(stderr, "\n\n");
}