#include "cub3d.h"


int				iz_it(char *needl, char *hayst)
{
	while (*needl && *needl == *hayst)
	{
		needl++;
		hayst++;
	}
	if (!*needl)
	{
		// fprintf(stderr, "///iz_it %s: 1\n", needl);
		return (1);
	}
	// fprintf(stderr, "///iz_it %s: 0\n", needl);
	return (0);
}