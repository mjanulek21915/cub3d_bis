#include "cub3d.h"


int				iz_it(char *needl, char *hayst)
{
	while (*needl && *needl == *hayst)
	{
		neeedl++;
		hayst++;
	}
	if (!*needl)
		return (1);
	return (0);
}