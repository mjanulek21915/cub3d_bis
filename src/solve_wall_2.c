#include "cub3d.h"

void		solve_wall_2_init_x(float ati, float azi, t_map *map, t_solve *solve)
{
	solve->posx = map->posx;
	solve->posy = map->posy;
	solve->posz = map->posz;
	solve->ati = ati;
	solve->azi = azi;
	solve->stepy = float_r_down(map->posy) - solve->posy;
	solve->get_dist = &solve_get_dist_sinx;
	solve->draw = &draw_wall_s;
	solve->dirx = 1;
	solve->diry = -1;
	solve->sum_dist = 0;
}

void		solve_wall_2_init_y(float ati, float azi, t_map *map, t_solve *solve)
{
	solve->posx = map->posx;
	solve->posy = map->posy;
	solve->posz = map->posz;
	solve->ati = ati;
	solve->azi = azi;
	solve->stepx = float_r_up(map->posx) - solve->posx;
	solve->get_dist = &solve_get_dist_sinx;
	solve->draw = &draw_wall_s;
	solve->dirx = 1;
	solve->diry = -1;
	solve->sum_dist = 0;
}

void		solve_wall_2(float ati, float azi, t_map *map, t_loop loop)
{
	t_solve solve_x;
	t_solve solve_y;

	solve_wall_2_init_x(ati, azi, map, &solve_x);
	solve_wall_2_init_y(ati, azi, map, &solve_y);
	if (solve_wall_x(&solve_x, map) && solve_wall_y(&solve_y, map))
		if(solve_wall_x_primer(&solve_x, map)
		&& solve_wall_y_primer(&solve_y, map))
			while (solve_wall_step(&solve_x, map)
			&& (solve_wall_step(&solve_y, map)));
	if (solve_x.is_found && solve_y.is_found)
	{
		if (solve_x.sum_dist < solve_y.sum_dist)
			solve_x.draw(map, solve_x.block, &solve_x, loop);
		else
			solve_y.draw(map, solve_y.block, &solve_y, loop);
	}
	else if (solve_x.is_found && !(solve_y.is_found))
		solve_x.draw(map, solve_x.block, &solve_x, loop);
	else if (solve_y.is_found && !(solve_x.is_found))
		solve_y.draw(map, solve_y.block, &solve_y, loop);

}