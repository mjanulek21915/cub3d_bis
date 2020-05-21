#include "cub3d.h"

void		solve_wall_0_init_x(float ati, float azi, t_solve *solve_x)
{
	solve_x->posx = map->posx;
	solve_x->posy = map->posy;
	solve_x->posz = map->posz;
	solve_x->ati = ati;
	solve_x->azi = azi;
	solve_x->roundx = float_r_up(map->posx);
	solve_x->roundy = float_r_up(map->posy);
}

void		solve_wall_0_init_y(float ati, float azi, t_solve *solve_y)
{
	solve_y->posx = map->posx;
	solve_y->posy = map->posy;
	solve_y->posz = map->posz;
	solve_y->ati = ati;
	solve_y->azi = azi;
	solve_y->roundx = float_r_up(map->posx);
	solve_y->roundy = float_r_up(map->posy);
}

void		solve_wall_0(float ati, float azi, t_map *map)
{
	t_solve solve_x;
	t_solve solve_y;

	solve_wall_0_init_x(ati, azi, &solve_x);
	solve_wall_0_init_y(ati, azi, &solve_y);
	if (solve_wall_x(&solve_x, map) && solve_wall_y(&solve_y, map))
		if(solve_wall_x_primer(&solve_x, map)
		&& solve_wall_y_primer(&solve_y, map))
			while (solve_wall_x_step(&solve_x, map)
			&& (solve_wall_y_step(&solve_y, map)));
}