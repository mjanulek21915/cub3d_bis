#include "cub3d.h"

#include <stdio.h>
#include <stdlib.h>


int					get_path_strlen(char *buff)
{
	int i;

	i = 0;
	while (*buff++ != '\n')
		i++;
	return (i);
}


char			*get_path(char **buff)
{
	char *rst;
	int i;

	i = 0;
	next_line(buff);
	if (!(rst = malloc((sizeof(char) * ((get_path_strlen(*buff)) + 1)))))
		return (NULL);
	while (**buff && **buff != '\n')
		rst[i++] = *((*buff)++);
	return (rst);
}