#include "cub3d.h"

void static				mk_map_assets_block_get_paths(t_block *block, char **buff)
{
// fprintf(stderr, "mk_map_assets_block_get_paths\n");
//  fprintf(stderr, "/>>>mk_map_assets_block_get_paths : \n%s\n>>>end\n", *buff);
	while (!(iz_it("/block", *buff)) && **buff)
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

void static			mk_map_assets_block_get_mults(t_block *block)
{
	block->mult_n_v = block->n_texture->size_x;
	block->mult_n_h = block->n_texture->size_y;
	block->mult_s_v = block->s_texture->size_x;
	block->mult_s_h = block->s_texture->size_y;
	block->mult_e_v = block->e_texture->size_x;
	block->mult_e_h = block->e_texture->size_y;
	block->mult_w_v = block->w_texture->size_x;
	block->mult_w_h = block->w_texture->size_y;
}

void static			mk_map_assets_block_get_textures(t_block *block)
{
// fprintf(stderr, "mk_map_assets_block_get_textures\n");
	block->n_texture = bmp_to_texture(block->n_path);
	block->s_texture = bmp_to_texture(block->s_path);
	block->e_texture = bmp_to_texture(block->e_path);
	block->w_texture = bmp_to_texture(block->w_path);
	mk_map_assets_block_get_mults(block);
// fprintf(stderr, "mk_map_assets_block_get_textures done\n");
}

t_block				*mk_map_assets_block(char **buff)
{
// fprintf(stderr, "mk_map_assets_block\n");
	t_block *rst;
	if (!(rst = malloc(sizeof(t_block))))
		return (NULL);
	rst->is_void = 0;
	mk_map_assets_block_get_paths(rst, buff);
	mk_map_assets_block_get_textures(rst);
// fprintf(stderr, "mk_map_assets_block done\n");

	return (rst);
}