#include "cub3d.h"

void		solve_wall(float ati, float azi, t_map *map, t_loop loop)
{

fprintf(stderr, "------------------------------------------------------------------------------------------------------------------------\n");
//  fprintf(stderr, "solve_wall\n");
print_loop(loop, ">>>loop:", "  ");
fprintf(stderr, "\n");

	map->solve_walls[(int)(azi * PI14)](ati, azi, map, loop);
//  fprintf(stderr, "solve_wall ok\n");
fprintf(stderr, "------------------------------------------------------------------------------------------------------------------------\n");
fprintf(stderr, "\n");
}

void static		init_loop(t_loop *loop, t_map *map)
{
//  fprintf(stderr, "init_loop\n");

	loop->h = map->hres;
	loop->v = map->vres;
	loop->hcount = map->masks->hcount;
	loop->vcount = map->masks->vcount;
// print_loop(*loop);
//  fprintf(stderr, "init_loop ok\n");

}

void		draw_walls(t_map *map)
{
//  fprintf(stderr, "draw_walls\n");

	t_loop loop;

	init_loop(&loop, map);
	// fprintf(stderr, "start loop.vcount = %d\n", loop.vcount);
	// fprintf(stderr, "start loop.hcount = %d\n", loop.hcount);
	// fprintf(stderr, "start loop.h = %d\n", loop.h);
	// fprintf(stderr, "start loop.v = %d\n", loop.v);


	while (loop.vcount)
	{
		loop.v--;
		loop.h = map->hres;
		loop.hcount = map->masks->hcount;
		loop.vcount--;

		while (loop.hcount)
		{
			loop.hcount--;
			loop.h--;
// fprintf(stderr, "vcount = %d\tv = %d\thcount = %d\th = %d\n", loop.vcount, loop.v, loop.hcount, loop.h);
// fprintf(stderr, "vmask = %f\thmask = %f\n", map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount]);
			solve_wall(map->ati + map->masks->v_mask[loop.vcount], map->azi + map->masks->h_mask[loop.hcount], map, loop);

		}

		// fprintf(stderr, "\t\tloop.hcount end : %d\n", loop.hcount);

		while (loop.h--)
		{
// fprintf(stderr, "vcount = %d\tv = %d\thcount = %d\th = %d\n", loop.vcount, loop.v, loop.hcount, loop.h);
// fprintf(stderr, "vmask = %f\thmask = %f\n", map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount]);
			solve_wall(map->ati + map->masks->v_mask[loop.vcount], map->azi + map->masks->h_mask[loop.hcount], map, loop);

			loop.hcount++;
		}
	}

// fprintf(stderr, "\t\tend loop 1\n");

	while (loop.v--)
	{
		loop.h = map->hres;
		loop.hcount = map->masks->hcount;

		while (loop.hcount)
		{
			loop.hcount--;
			loop.h--;
	// fprintf(stderr, "vcount = %d\tv = %d\thcount = %d\th = %d\n", loop.vcount, loop.v, loop.hcount, loop.h);
	// fprintf(stderr, "vmask = %f\thmask = %f\n", map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount]);
	solve_wall(map->ati - map->masks->v_mask[loop.vcount], map->azi - map->masks->h_mask[loop.hcount], map, loop);
		}

	// fprintf(stderr, "\t\tloop.hcount end : %d\n", loop.hcount);

		while (loop.h--)
		{
	// fprintf(stderr, "vcount = %d\tv = %d\thcount = %d\th = %d\n", loop.vcount, loop.v, loop.hcount, loop.h);
	// fprintf(stderr, "vmask = %f\thmask = %f\n\n", map->masks->v_mask[loop.vcount], map->masks->h_mask[loop.hcount]);
	solve_wall(map->ati - map->masks->v_mask[loop.vcount], map->azi - map->masks->h_mask[loop.hcount], map, loop);
			loop.hcount++;
		}
		loop.vcount++;
	}
}