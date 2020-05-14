#include "cub3d.h"

void printout(t_texture *texture)
{
	int i = 0;
	int j = 0;
	
	while (i < texture->size_x)
	{
		j = 0;
		while (j < texture->size_y)
		{
			printf("|%d|", texture->bitmap[i][j]);
			j++;
		}
		i++;
	}
}