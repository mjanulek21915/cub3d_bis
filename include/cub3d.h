#ifndef __CUB3D_H__
#define __CUB3D_H__

#include "debug.h"


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

typedef struct			s_block
{
	int size_x
	t_texture *texture_n;
	float mult_n_x;
	float mult_n_y;
	t_texture *texture_s;
	float mult_s_x;
	float mult_s_y;
	t_texture *texture_e;
	float mult_e_x;
	float mult_e_y;
	t_texture *texture_w;
	float mult_w_x;
	float mult_w_y;
}						t_block;

typedef struct			s_map
{
	s_block **walls;
	
}


int				open_file(char **buff, char *path);
t_texture				*bmp_to_texture(char *path);


#endif