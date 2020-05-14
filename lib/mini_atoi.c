#include "cub3d.h"

int static			mini_atoi(char **buff)
{
	int rst = 0;
	while (**buff >= '0' && **buff <= '9')
	{
		rst = (rst * 10) + **buff - '0';
		(*buff)++;
	}
	(*buff)++;
	return (rst);
}
