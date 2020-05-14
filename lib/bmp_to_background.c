// #include "cub3d.h"

// t_texture				*bmp_to_background(char *path)
// {
// 	t_background *rst;
// 	char *buff;
// 	int status;
// 	int i;
// 	int j;
// 	int bitmap_size;
// 	int *temp;

// fprintf(stderr, "bmp_to_background \n");


// 	i = 0;
// 	if (!(rst = malloc(sizeof(t_backround))))
// 		do_exit("bmp_to_background malloc fail");
// 	if ((rst->size = open_file(&buff, path)) <= 0)
// 		do_exit("bmp_to_background open_file fail");
// fprintf(stderr, "\tsize %d\n", rst->size);
// 	rst->offset = *((int *)(buff + 10));
// 	rst->size = (rst->size - rst->offset)/4;
// 	if (!(rst->bitmap = malloc(sizeof(int *) * rst->size)))
// 		do_exit("bmp_to_background malloc fail");


// fprintf(stderr, "bmp_to_background\tsize_x %d\n", rst->size_x);
// fprintf(stderr, "bmp_to_background\tsize_y %d\n", rst->size_y);
// fprintf(stderr, "bmp_to_background\tsize %d\n", rst->size);

// 	temp = (int *)(buff + rst->offset);

// 	i = 0;
// 	while (i < rst->size)
// 	{
// 		rst->bitmap[i] = *temp++;
// 		i++;
// 	}
// fprintf(stderr, "bmp_to_background done \n");
// 	return (rst);
// }