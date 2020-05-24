#include "cub3d.h"

#include <stdio.h>
#include <stdlib.h>


int					get_path_strlen(char *buff)
{
//  fprintf(stderr, "get_path_strlen buff : \n%s\n", buff);

	int i;

	i = 0;
	while (*buff++ != '\n')
		i++;
//  fprintf(stderr, "get_path_strlen : %d\n", i);
	return (i);

}


char			*get_path(char **buff)
{
fprintf(stderr, "get_path\n");
	char *rst;
	int i;
	int len;

	i = 0;
	next_line(buff);
//  fprintf(stderr, "buff : \n%s\n", *buff);
	len = get_path_strlen(*buff);
	if (!(rst = malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	rst[len] = 0;
	while (**buff && **buff != '\n')
		rst[i++] = *((*buff)++);
	return (rst);
}