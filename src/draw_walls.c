#include "cub3d.h"

void		solve_wall(float ati, float azi, t_map *map, t_loop loop)
{

// print_loop(loop, ">>>loop:", "  ");
if (azi < 0)
	azi = azi + (2*PI);
if (azi >= (2 * PI))
	azi = azi - (2*PI);
// fprintf(stderr, "azi = %f, azi mult = %f,  solve nr. %d\n", azi,azi / PI14,  (int)(azi / PI14));
	map->solve_walls[(int)(azi / PI14)](ati, azi, map, loop);
}

void static		init_loop(t_loop *loop, t_map *map)
{

	loop->h = map->hres;
	loop->v = map->vres;
	loop->hcount = map->masks->hcount;
	loop->vcount = map->masks->vcount;
// print_loop(*loop);

}

void		draw_walls(t_map *map)
{

	t_loop loop;

	init_loop(&loop, map);


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
			solve_wall(map->ati - map->masks->v_mask[loop.vcount], map->azi + map->masks->h_mask[loop.hcount], map, loop);

		}


		while (loop.h--)
		{
			solve_wall(map->ati - map->masks->v_mask[loop.vcount], map->azi - map->masks->h_mask[loop.hcount], map, loop);

			loop.hcount++;
		}
	}


	while (loop.v)
	{
		loop.h = map->hres;
		loop.hcount = map->masks->hcount;
		loop.v--;

		while (loop.hcount)
		{
			loop.hcount--;
			loop.h--;
			solve_wall(map->ati + map->masks->v_mask[loop.vcount], map->azi + map->masks->h_mask[loop.hcount], map, loop);
		}


		while (loop.h--)
		{
			solve_wall(map->ati + map->masks->v_mask[loop.vcount], map->azi - map->masks->h_mask[loop.hcount], map, loop);
			loop.hcount++;
		}
		loop.vcount++;
	}
}