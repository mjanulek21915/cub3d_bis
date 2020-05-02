#include "cub3d.h"

int static		of_get_len(char *path)
{
	int fd;
	int rst;
	char buff;

	rst = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
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
		return (-1);
	if (!(*buff = malloc(sizeof(char) * (size + 1))))
		return (-2);
	if ((fd = open(path, O_RDONLY)) <= 0)
		return (-3);
	(*buff)[size] = 0;
	if ((read(fd, *buff, size))	!= size)
		return (-4);
	return (size);
}