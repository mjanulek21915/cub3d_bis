#include "cub3d.h"

#define PATH "./img/test.bmp"



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

int main()
{
	t_texture *texture;
    texture = bmp_to_texture(PATH);
	printout(texture);
}