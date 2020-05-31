#include "cub3d.h"

void		print_mask(t_masks *masks, char *label, char *indent)
{
	int i = 0;

fprintf(stderr, "%s", label);

	while (i < masks->hcount)
	{
		fprintf(stderr, "%sh_mask [%d] = %f\n", indent, i, masks->h_mask[i]);
		i++;
	}
	i = 0;

	while (i < masks->vcount)
	{
		fprintf(stderr, "%sv_mask[%d] = %f\n", indent, i, masks->v_mask[i]);
		i++;
	}
}