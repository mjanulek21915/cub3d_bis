#include "cub3d.h"

void	print_pixmap(int *img, int size)
{
	while (size --)
		fprintf(stderr, "%d", *img++);
}