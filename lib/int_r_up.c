#include "cub3d.h"

int		int_r_up(float x)
{
	if (x - (int)x)
		return ((int)(x + 1));
	return ((int)x);
}