#include "cub3d.h"

void			next_line(char **buff)
{
	while (**buff != '\n' && **buff)
		(*buff)++;
	if (**buff)
		(*buff)++;
}