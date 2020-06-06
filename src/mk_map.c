#include "cub3d.h"

t_map			*mk_map_malloc(void)
{
	t_map *map;
	int i;

	i = 0;
	if(!(map = malloc(sizeof(t_map))))
		do_exit("mk_map map malloc fail\n");
	map->r_spd = 1 * PI / 180;
	map->p_spd = 0.1;
	map->hres = SIZE_X;
	map->vres = SIZE_Y;
	map->vfov = FOV_V;
	map->hfov = FOV_H;
	if (!(map->d_grid = malloc(sizeof(float *) * map->vres)))
		do_exit("mk_map float malloc fail\n");
	while (i < map->hres)
	{
		if (!(map->d_grid[i] = malloc(sizeof(float) * map->hres)))
			do_exit("mk_map float malloc fail\n");
		i++;
	}
	i = 0;
	return(map);
}

t_map			*mk_map(char *path)
{
//  fprintf(stderr, "mk_map\n");
	char *buff;
	t_map *map;
	int i;
	int j;
	char sky[4] = {118, 118, 92, 0};
	char dirt[4] = {5, 25, 50, 0};

	open_file(&buff, PATH);
	map = mk_map_malloc();
	mk_map_assets(map, &buff);
	mk_map_walls(map, &buff);
	mk_map_background(map, sky, dirt);
	map->f_draw = &draw;
	map->f_expose = &mlx_put_image_to_window;
	mk_map_masks(map);
	map->solve_walls[0] = &solve_wall_0;
	map->solve_walls[1] = &solve_wall_1;
	map->solve_walls[2] = &solve_wall_2;
	map->solve_walls[3] = &solve_wall_3;
	map->solve_walls[4] = &solve_wall_4;
	map->solve_walls[5] = &solve_wall_5;
	map->solve_walls[6] = &solve_wall_6;
	map->solve_walls[7] = &solve_wall_7;
	map->solve_walls[8] = map->solve_walls[0];
	map->wall_check[0][0] = &solve_wall_check_return_1;
	map->wall_check[0][1] = &solve_wall_check_draw_y;
	map->wall_check[0][2] = &solve_wall_check_return_0;
	map->wall_check[1][0] = &solve_wall_check_draw_x;
	map->wall_check[1][1] = &solve_wall_check_draw_compare;
	map->wall_check[1][2] = &solve_wall_check_draw_x;
	map->wall_check[2][0] = &solve_wall_check_return_0;
	map->wall_check[2][1] = &solve_wall_check_draw_y;
	map->wall_check[2][2] = &solve_wall_check_return_0;

// fprintf(stderr, "mk_map done\n");
	return (map);
}

