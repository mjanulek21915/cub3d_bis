#include "cub3d.h"

int					mk_map_walls_get_x_size(char *buff)
{
	int size;

	while (*buff && *buff == '\n')
		buff++;
	size = 0;
	while (*buff && *buff != '\n' && !(iz_it("walls end", buff)))
	{
		size++;
		next_line(&buff);
	}
	return (size);
}

int					mk_map_walls_get_y_size(char *buff)
{
	int size;
	int max_size;

	size = 0;
	max_size = 0;
	while (*buff && *buff == '\n')
		buff++;
	while (*buff && *buff != '\n' )
		// && !(iz_it("walls end", buff))
	{
		while (*buff && *buff != '\n')
		{
			size++;
			buff++;
		}
		if (size > max_size)
			max_size = size;
		size = 0;
		if (*buff == '\n')
			*buff++;
	}
	return (max_size);
}

void				mk_map_get_walls(t_map *map, char *buff)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (*buff == '\n')
		buff++;
	while (*buff && *buff != '\n' && !(iz_it("walls end", buff)))
	{
		while (*buff != '\n' && *buff)
		{
 fprintf(stderr, "mk_map_get_walls : %c\n", ((char)*buff));
			if (map->asset[*buff].type == 0)
				do_exit("mk_map_get_walls asset doesn't exist\n");
			if (map->asset[*buff].type = 'b')
				map->walls[x][y] = (t_block *)(map->asset[*buff].data);
			buff++;
			y++;
		}
		if (*buff)
			buff++;
		x++;
		y = 0;
	}
}

void				*mk_map_walls_malloc(t_map *map, char *buff)
{
	int x;
	int y;

	x = 0;
	y = 0;
	map->size_x = mk_map_walls_get_x_size(buff);
	map->size_y = mk_map_walls_get_y_size(buff);
	if (!(map->walls = malloc(sizeof(t_block **) * map->size_x)))
		do_exit("mk_map_wall malloc x fail\n");
	while (x < map->size_x)
	{
		if (!(map->walls[x] = malloc(sizeof(t_block*) * map->size_y)))
			do_exit("mk_map_wall malloc y fail\n");
		while (y < map->size_y)
		{
			map->walls[x][y] = NULL;
			y++;
		}
		y = 0;
		x++;
	}
}

void				mk_map_walls(t_map *map, char **buff)
{
 fprintf(stderr, "mk_map_walls\n");
	while (!(iz_it("walls:", *buff)))
		(*buff)++;
	next_line(buff);
	mk_map_walls_malloc(map, *buff);
	mk_map_get_walls(map, *buff);
 fprintf(stderr, "mk_map_walls done\n");
}