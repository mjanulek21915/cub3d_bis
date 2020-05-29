#include "cub3d.h"

void		solve_wall_2_init_x(float ati, float azi, t_map *map, t_solve *solve)
{
//  fprintf(stderr, "solve_wall_2_init_x\n");

	solve->posx = map->posx;
	solve->posy = map->posy;
	solve->posz = map->posz;
	solve->ati = ati;
	solve->azi = azi - PI12;
	solve->c_azi = PI12 - azi;
	solve->stepy = solve->posy - floor(map->posy);
	if (!solve->stepy)
		solve->stepy = -1;	
	solve->get_dist = &solve_get_dist_sinx;
	solve->draw = &draw_wall_s;
	solve->dirx = 1;
	solve->diry = -1;
	solve->sum_dist = 0;
//  fprintf(stderr, "\tsolve_wall_2_init_x ok : ");
//  print_solve(solve);

}

void		solve_wall_2_init_y(float ati, float azi, t_map *map, t_solve *solve)
{
//  fprintf(stderr, "solve_wall_2_init_y\n");

	solve->posx = map->posx;
	solve->posy = map->posy;
	solve->posz = map->posz;
	solve->ati = ati;
	solve->azi = azi - PI12;
	solve->c_azi = PI12 - azi;
	solve->stepx = ceil(map->posx) - solve->posx;
	if (!solve->stepx)
		solve->stepx = 1;
	solve->get_dist = &solve_get_dist_sinx;
	solve->draw = &draw_wall_s;
	solve->dirx = 1;
	solve->diry = -1;
	solve->sum_dist = 0;

//  fprintf(stderr, "solve_wall_2_init_y ok : \n");
//  print_solve(solve);

}

void		solve_wall_2(float ati, float azi, t_map *map, t_loop loop)
{
//  fprintf(stderr, "solve_wall_2\n");

	t_solve solve_x;
	t_solve solve_y;

	solve_wall_2_init_x(ati, azi, map, &solve_x);
	solve_wall_2_init_y(ati, azi, map, &solve_y);
	solve_wall_x(&solve_x);
	solve_wall_y(&solve_y);
	if (solve_wall_check(&solve_x, &solve_x, map, loop))
		return ;
	solve_wall_set(&solve_x, &solve_y);
	// solve_wall_x(&solve_x);
	// solve_wall_y(&solve_y);
	while (!(solve_wall_check(&solve_x, &solve_x, map, loop)))
	{
		solve_wall_step(&solve_x, &solve_y);
	}
//  fprintf(stderr, "solve_wall_2 ok\n");
	
}