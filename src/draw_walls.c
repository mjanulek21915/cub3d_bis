#include "cub3d.h"

void static		solve_wall(float ati, float azi, t_map *map, t_loop loop)
{
 fprintf(stderr, "solve_wall\n");
	map->solve_walls[(int)(azi * PI4)](azi + map->azi, ati + map->ati, map, loop);
 fprintf(stderr, "solve_wall\n");

}

void static		init_loop(t_loop *loop, t_map *map)
{
 fprintf(stderr, "init_loop\n");

	loop->h = map->hres;
	loop->v = map->vres;
	loop->hcount = map->masks->hcount;
	loop->vcount = map->masks->vcount;
 fprintf(stderr, "init_loop ok\n");

}

void		draw_walls(t_map *map)
{
 fprintf(stderr, "draw_walls\n");

	t_loop loop;

	init_loop(&loop, map);
	while (loop.vcount--)
	{
		loop.hcount = map->masks->hcount;
		loop.h = map->hres;
		while (loop.hcount--)
			solve_wall(map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount], map, loop);
		while (loop.h--)
			solve_wall(map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount++], map, loop);
		loop.v--;
	}
	while (loop.v--)
	{
		loop.hcount = map->masks->hcount;
		loop.h = map->hres;
		while (loop.hcount--)
			solve_wall(map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount], map, loop);
		while (loop.h--)
			solve_wall(map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount++], map, loop);
		loop.vcount++;
 fprintf(stderr, "draw_walls ok\n");

	}
}