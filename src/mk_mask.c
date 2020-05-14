#include "cub3d.h"

t_masks			*mk_mask(float fov_v, float v_res, float fov_h, float h_res)
{
	t_masks *rst;

	float h_base;
	float v_base;
	int i;

	if (!(rst = malloc(sizeof(t_masks))))
		do_exit("mk_mask: malloc fail\n");
	rst->h_mask_count = ((int)h_res / 2) + ((int)h_res % 2) + 1;
	rst->v_mask_count = ((int)v_res / 2) + ((int)v_res % 2) + 1;
	if (!(rst->h_mask = malloc(sizeof(float) * rst->h_mask_count)) || 
	!(rst->h_mask = malloc(sizeof(float) * rst->h_mask_count)))
		do_exit("mk_mask: malloc fail\n");

	fov_h = fov_h * PI / 180;
	fov_v = fov_v * PI / 180;

	h_base = tan(fov_h) * rst->h_mask_count;
	v_base = tan(fov_v) * rst->v_mask_count;

	i = 0;
	while (i < rst->h_mask_count)
	{
		rst->h_mask[i] = atan((float)i / h_base);
		i++;
	}
	i = 0;
	while (i < rst->v_mask_count)
	{
		rst->v_mask[i] = atan((float)i / v_base);
		i++;
	}
	return (rst);
}