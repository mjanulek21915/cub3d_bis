#include "cub3d.h"

void static		solve_wall(float ati, float azi, t_map *map)
{
	map->solve_walls[(int)(azi * PI4)](azi + map->azi, ati + map->ati, map);
}

void static		init_draw_walls(t_draw_walls *loop, t_map *map)
{
	loop->h = map->hres;
	loop->v = map->vres;
	loop->hcount = map->hcount;
	loop->v_count = map->vcount;
}

void		draw_walls(t_map *map)
{
	t_draw_walls loop;

	init_draw_walls(&loop, map);
	while (loop.v_count--)
	{
		loop.h_count = map->hcount;
		loop.h = map->hres;
		while (loop.h_count--)
			solve_wall(map->v_mask[loop.v_count], map->h_mask[loop.h_count], map);
		while (loop.h--)
			solve_wall(map->v_mask[loop.v_count], map->h_mask[loop.h_count++], map);
		loop.v--;
	}
	while (loop.v--)
	{
		loop.h_count = map->hcount;
		loop.h = map->hres;
		while (loop.h_count--)
			solve_wall(map->v_mask[loop.v_count], map->h_mask[loop.h_count], map);
		while (loop.h--)
			solve_wall(map->v_mask[loop.v_count], map->h_mask[loop.h_count++], map);
		loop.v_count++;
	}
}