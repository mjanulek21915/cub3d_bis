#include "cub3d.h"

void				mk_player_get_values(t_block *block, char **buff)
{
	while (!(iz_it("player end", *buff)) && **buff);
	{
		if (iz_it("HDG:", *buff))
			player->hdg = get_value(buff);
		else if (iz_it("POSX:", *buff))
			player->pos_x = get_value(buff);
		else if (iz_it("POSY:", *buff))
			player->pos_y = get_value(buff);
		(*buff)++;
	}


}

void				mk_block_get_textures(t_block *block)
{
	block->n_texture = bmp_to_texture(block->n_path);
	block->s_texture = bmp_to_texture(block->s_path);
	block->e_texture = bmp_to_texture(block->e_path);
	block->w_texture = bmp_to_texture(block->w_path);
}

t_block				*mk_player(char **buff)
{
	t_player *player;
	if (!(rst = malloc(sizeof(t_player))))
		do_exit("mk_player malloc fail\n");
	player->hdg = -1;
	player->pos_x = -1;
	player->pos_y = -1;
	mk_player_get_values(player, buff);
	return (rst);
}