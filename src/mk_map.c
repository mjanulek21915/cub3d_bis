#include "cub3d.h"

t_map			*mk_map_malloc(void)
{
	t_map *map;
	if(!(map = malloc(sizeof(t_map))))
		do_exit("mk_map map malloc fail");
	map->player_hdg = 90 * PI / 180;
	map->player_hdg_spd = 1 * PI / 180;
	map->player_posx_spd = 0.1;
	map->player_posy_spd = 0.1;
	map->h_res = SIZE_X;
	map->v_res = SIZE_Y;

}

t_map			*mk_map(char *path)
{
 fprintf(stderr, "mk_map\n");
	char *buff;
	t_map *map;
	int i;
	int j;
	char sky[4] = {0, 255, 0, 0};
	char dirt[4] = {0, 0, 255, 0};

	open_file(&buff, PATH);
	map = mk_map_malloc();
	mk_map_assets(map, &buff);
	mk_map_walls(map, &buff);
	mk_map_background(map, sky, dirt);
 fprintf(stderr, "mk_map done\n");
	return (map);
}

