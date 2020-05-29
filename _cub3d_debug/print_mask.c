#include "cub3d.h"

void		print_mask(t_masks *masks)
{
	int i = 0;

	fprintf(stderr, "\tHMASK\n");
	while (i < masks->hcount)
	{
		fprintf(stderr, "%d = %f\n", i, masks->h_mask[i]);
		i++;
	}
	i = 0;

	fprintf(stderr, "\tVMASK\n");
	while (i < masks->hcount)
	{
		fprintf(stderr, "%d = %f\n", i, masks->v_mask[i]);
		i++;
	}
}