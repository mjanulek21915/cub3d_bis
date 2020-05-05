#include "cub3d.h"

void				mk_block_get_paths(t_block *block, char **buff)
{
	while (!(iz_it("block end", *buff)) && **buff);
	{
		if (iz_it("N:", *buff))
			block->n_path = get_path(buff);
		else if (iz_it("S:", *buff))
			block->s_path = get_path(buff);
		else if (iz_it("E:", *buff))
			block->e_path = get_path(buff);
		else if (iz_it("W:", *buff))
			block->w_path = get_path(buff);
		(*buff)++;
	}
	next_line(buff);
}

void				mk_block_get_textures(t_block *block)
{
	block->n_texture = bmp_to_texture(block->n_path);
	block->s_texture = bmp_to_texture(block->s_path);
	block->e_texture = bmp_to_texture(block->e_path);
	block->w_texture = bmp_to_texture(block->w_path);
}

t_block				*mk_block(char **buff)
{
	t_block *rst;
	if (!(rst = malloc(sizeof(t_block))))
		return (NULL);
	mk_block_get_paths(block, buff);
	mk_block_get_textures(block);
	return (rst);
}