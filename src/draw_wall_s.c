#include "cub3d.h"

int		draw_wall_s(t_map *map, t_block *wall, t_solve *solve, t_loop loop)
{
// print_solve(solve);
	float h;
	float v;
	float hpixel;
	float vpixel;


// fprintf(stderr, ">>>draw_wall_s :\n  posh=%d posv=%d maskh=%d maskv=%d posx=%f posy=%f posz=%f\n",loop.h, loop.v, loop.hcount, loop.vcount, solve->posx, solve->posy, solve->posz);
// print_solve(solve, "" , "");

	h = (float)(solve->posx - (int)solve->posx);
	v = (float)(solve->posz - (int)solve->posz);
	hpixel = h * wall->mult_s_h;
	vpixel = v * wall->mult_s_v;

// fprintf(stderr, "  v :%f h:%f hpixel:%f vpixel:%f mult_h:%f mult_v:%f\n",
//  v, h, hpixel, vpixel, wall->mult_s_h, wall->mult_s_v);

	((int *)map->img->data)[(loop.v * map->hres) + loop.h] =
	 wall->s_texture->bitmap[(int)(v * wall->mult_s_v)][(int)(h * wall->mult_s_h)];
// fprintf(stderr, "\n");
	return (0);
}