#include "cub3d.h"

t_block				*mk_map_assets_block_void(char **buff)
{
//  fprintf(stderr, "mk_map_assets_block_void\n");
	t_block *rst;
	if (!(rst = malloc(sizeof(t_block))))
		return (NULL);
	rst->is_void = 1;
	while (!(iz_it("/void", *buff)) && **buff)
		*(*buff++);
	next_line(buff);
//  fprintf(stderr, "mk_map_assets_block_void done\n");

	return (rst);
}