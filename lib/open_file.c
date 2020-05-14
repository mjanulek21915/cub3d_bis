#include "cub3d.h"

int static		of_get_len(char *path)
{
	int fd;
	int rst;
	char buff;

	rst = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		do_exit("open_file get_len open error\n");
	while (read(fd, &buff, 1))
		rst ++;
	close(fd);
	return (rst);
}

int				open_file(char **buff, char *path)
{
	int size;
	int fd;

	if ((size = of_get_len(path)) < 0)
		do_exit("open_file get_len error\n");
	if (!(*buff = malloc(sizeof(char) * (size + 1))))
		do_exit("open_file buffer malloc error\n");
	if ((fd = open(path, O_RDONLY)) < 0)
		do_exit("open_file fd error\n");
	(*buff)[size] = 0;
	if ((read(fd, *buff, size))	!= size)
		do_exit("open_file buffer error\n");
	return (size);
}