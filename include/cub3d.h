#ifndef __CUB3D_H__
#define __CUB3D_H__

#include "_cub3d_debug.h"


#define R_LEFT 113
#define R_RIGHT 100
#define LEFT 119
#define RIGHT 99
#define UP 115
#define DOWN 120

#define SIZE_X 200
#define SIZE_Y 200
#define TITLE "test"

#define PI 3.14159265359
#define PATH "/home/aaa/cub3d_bis/maps/map_test"


// typedef struct			s_map
// {
// 	t_background *background;
// 	t_block ***walls;
// 	int h_res;
// 	int v_res;
// 	int size_x;
// 	int size_y;
// 	float start_x;
// 	float start_y;
// 	t_asset *asset;
// 	float player_hdg;
// 	float player_hdg_spd;
// 	float player_posx;
// 	float player_posx_spd;
// 	float player_posy;
// 	float player_posy_spd;

// }						t_map;



typedef struct			s_background
{
	int *bitmap;
	int size;

}						t_background;

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


typedef struct			s_masks
{
	int h_mask_count;
	float *h_mask;
	int v_mask_count;
	float *v_mask;
}						t_masks;


typedef struct			s_block
{
	int size_x;

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




typedef struct			s_asset
{
	char type;
	void *data;
}						t_asset;

typedef struct			s_draw_walls
{
	int h;
	int v;
	int h_count;
	int v_count;
}						t_draw_walls;

typedef struct			s_solve
{
	float pos_x;
	float pos_y;
	float pos_z;
	float step_x;
	float step_y;
	float step_z;
	float sol_x;
	float sol_y;
	float sol_z;
	float round_x;
	float round_y;
	float azi;
	float ati;
	float dist;
}						t_solve;

typedef struct			s_request
{
	float ati;
	float azi;
}

// typedef struct			s_logic;
// {

// }


//////////////////////////////////////////////////////////////////////
typedef struct			s_map
{
	int size_x;
	int size_y;


	t_background *background;
	t_block ***walls;
	t_asset *asset;
	t_masks *


	void (*f_draw)(int *, int *, int);
	void (*f_expose)(void *, void *, int, int);

 	void *mlx;
	void *window;
	t_img *img;


	int h_res;
	int v_res;


	float player_hdg;
	float player_hdg_spd;
	float player_posx;
	float player_posx_spd;
	float player_posy;
	float player_posy_spd;
	void (*solve[9])(float ati, float azi, t_map *map)
}						t_map;



//////////////////////////////////////////////////////////////////////
void	print_map(t_map* map);
void	print_player(t_map *map);
void	printout(t_texture *texture);
void	print_pixmap(int *img, int size);



void				do_exit(char *msg);
int					open_file(char **buff, char *path);
t_texture			*bmp_to_texture(char *path);
void				next_line(char **buff);
void				end_line(char **buff);
int					iz_it(char *needl, char *hayst);
char				*get_path(char **buff);
float				get_value(char **buff);

t_map				*mk_map(char *path);
int					mk_map_assets(t_map *map, char **buff);
void				mk_map_walls(t_map *map, char **buff);
void				mk_map_background(t_map *map, char *c_sky, char *c_dirt);


t_block				*mk_map_assets_block(char **buff);
void				mk_map_assets_player(t_map *map, char **buff);

t_masks				*mk_mask(float fov_v, float v_res, float fov_h, float h_res);

void				mv_up(t_map *map);
void				mv_down(t_map *map);
void				mv_left(t_map *map);
void				mv_right(t_map *map);
void				mv_r_left(t_map *map);
void				mv_r_right(t_map *map);

int					key_hook(int key, t_map *map);

void		draw(t_map *map, t_img *img);



#endif