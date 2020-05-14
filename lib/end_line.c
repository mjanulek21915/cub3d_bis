#include "cub3d.h"

void			end_line(char **buff)
{
	while (**buff != '\n')
		(*buff)++;
}