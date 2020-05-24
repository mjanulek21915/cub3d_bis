#include "cub3d.h"

float		float_r_up(float x)
{
	if (x - (int)x)
		return ((float)((int)(x + 1)));
	return ((float)((int)x));
}