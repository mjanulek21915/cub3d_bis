#ifndef __CUB3D_H__
#define __CUB3D_H__

#include "debug.h"

#define PI 3.14159265359

typedef struct			s_asset
{
	int type;
	void *data;
}						t_asset;

typedef struct			s_texture
{
	int **bitmap;
	int size_x;
	int size_y;
	int offset;
	int size;
	int size_h;
	int size_w;
}						t_texture;

typedef struct			s_player;
{
	float pos_x;
	float pos_y;
	float hdg;
}						t_player;


typedef struct			s_masks
{
	int h_mask_count;
	float *h_mask;
	int v_mask_count;
	float *v_mask;
}						t_masks;


typedef struct			s_block
{
	int size_x

	char *n_path;
	t_texture *n_texture;
	float mult_n_x;
	float mult_n_y;

	char *s_path;
	t_texture *s_texture;
	float mult_s_x;
	float mult_s_y;

	char *e_path;
	t_texture *e_texture;
	float mult_e_x;
	float mult_e_y;

	char *w_path;
	t_texture *w_texture;
	float mult_w_x;
	float mult_w_y;
}						t_block;





typedef struct			s_map
{
	t_block **walls;
	int size_x;
	int size_y;
	float start_x;
	float start_y;
	char start_heading;
	t_asset asset[128];
}						t_map;





int				open_file(char **buff, char *path);
t_texture				*bmp_to_texture(char *path);


#endif