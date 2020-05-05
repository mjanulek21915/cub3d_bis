#include "cub3d.h"

t_map			*mk_map(char *path)
{
	char *buff;
	t_map *map;
	int i;
	int j;


	if ((open_file(&buff; path)) < 0 ||
	!(map = malloc(sizeof(t_map))))
		return (NULL);


	map->size_x = mini_atoi(&buff);
	map->size_y = mini_atoi(&buff);

	if (!(map->walls = malloc(sizeof(t_asset *) * map->size_x)))
		return (NULL);

	i = 0;
	while (i < map->size_x)
	{
		j = 0;
		if (!(map->walls[i] = malloc(sizeof(t_block) * map->size_y)))
			return (NULL);
		i++;
	}
	i = 0;
}