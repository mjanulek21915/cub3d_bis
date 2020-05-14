#include "cub3d.h"

t_texture				*bmp_to_texture(char *path)
{
	t_texture *rst;
	char *buff;
	int status;
	int i;
	int j;
	int bitmap_size;

	int *temp;


	i = 0;
	if (!(rst = malloc(sizeof(t_texture))))
		return ((t_texture *)NULL);
	if ((rst->size = open_file(&buff, path)) <= 0)
		return ((t_texture *)NULL);
fprintf(stderr, "\tsize %d\n", rst->size);
	rst->offset = *((int *)(buff + 10));
	rst->size = (rst->size - rst->offset)/4;
	rst->size_x = *((int *)(buff + 18));
	rst->size_y = *((int *)(buff + 22));
	if (!(rst->bitmap = malloc(sizeof(int *) * rst->size_x)))
		return ((t_texture *)NULL);
	while (i < rst->size_x)
	{
		if (!(rst->bitmap[i] = malloc(sizeof(int) * rst->size_y)))
			return ((t_texture *)NULL);
		i++;
	}
fprintf(stderr, "\tsize_x %d\n", rst->size_x);
fprintf(stderr, "\tsize_y %d\n", rst->size_y);
fprintf(stderr, "\tsize %d\n", rst->size);

	temp = (int *)(buff + rst->offset);

	i = 0;
	while (i < rst->size_x)
	{
		j = 0;
		while (j < rst->size_y)
		{
			rst->bitmap[i][j] = *temp++;
			j++;
		}
		i++;
	}
fprintf(stderr, "bmp_to_texture done \n");
	return (rst);
}