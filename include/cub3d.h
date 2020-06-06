#ifndef __CUB3D_H__
#define __CUB3D_H__

#include "_cub3d_debug.h"


#define R_LEFT 100
#define R_RIGHT 103
#define LEFT 99
#define RIGHT 98
#define UP 102
#define DOWN 118

#define SIZE_X 20
#define SIZE_Y 20
#define TITLE "test"

#define PI 3.14159265359
#define PI14 0.785398
#define PI12 1.570796
#define PI32 4.712389
#define PATH "/home/aaa/cub3d_bis/maps/map_test"

#define FOV_V 60;
#define FOV_H 90;



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
	int hcount;
	float *h_mask;
	int vcount;
	float *v_mask;
}						t_masks;


typedef struct			s_block
{
	int size_x;
	int is_void;

	char *n_path;
	t_texture *n_texture;
	float mult_n_v;
	float mult_n_h;

	char *s_path;
	t_texture *s_texture;
	float mult_s_v;
	float mult_s_h;

	char *e_path;
	t_texture *e_texture;
	float mult_e_v;
	float mult_e_h;

	char *w_path;
	t_texture *w_texture;
	float mult_w_v;
	float mult_w_h;
}						t_block;




typedef struct			s_asset
{
	char type;
	void *data;
}						t_asset;

typedef struct			s_loop
{
	int h;
	int v;
	int hcount;
	int vcount;
}						t_loop;



struct s_solve;
typedef struct s_solve t_solve;
struct s_map;
typedef struct s_map t_map;

//////////////////////////////////////////////////////////////////////
typedef struct			s_map
{
	int size_x;
	int size_y;


	t_background *background;
	t_block ***walls;
	t_asset *asset;
	t_masks *masks;


	void (*f_draw)(t_map *);
	int (*f_expose)(void *, void *, void *, int, int);

 	void *mlx;
	void *win;
	t_img *img;
	float **d_grid;


	int hres;
	int vres;
	float hfov;
	float vfov;
	

	float azi;
	float ati;
	float posx;
	float posy;
	float posz;
	float p_spd;
	float r_spd;
	int (*wall_check[3][3])(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop);
	void (*solve_walls[9])(float ati, float azi, struct s_map *map, t_loop loop);
}						t_map;

//////////////////////////////////////////////////////////////////////


struct			s_solve
{
	t_block *block;
	int is_found;
	float posx;
	float posy;
	float posz;
	float azi;
	float c_azi;
	float ati;
	float stepx;
	float stepy;
	float stepz;
	float dist;
	float dirx;
	float diry;
	float sum_dist;
	void (*get_dist)(struct s_solve *solve);
	int (*draw)(t_map *map, t_block *wall, struct s_solve *solve, t_loop loop);
};


void	print_map(t_map* map);
void print_player(t_map *map, char *label, char *indent);
void	printout(t_texture *texture);
void	print_pixmap(int *img, int size);
void		print_solve(t_solve *solve, char *label, char *indent);
void 		print_loop(t_loop loop, char *label, char *indent);
void		print_mask(t_masks *masks, char *label, char *indent);




float		float_r_down(float x);
float		float_r_up(float x);




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
void				mk_map_masks(t_map *map);
void				mk_map_background(t_map *map, char *c_sky, char *c_dirt);


t_block				*mk_map_assets_block(char **buff);
t_block				*mk_map_assets_block_void(char **buff);
void				mk_map_assets_player(t_map *map, char **buff);


void				mv_up(t_map *map);
void				mv_down(t_map *map);
void				mv_left(t_map *map);
void				mv_right(t_map *map);
void				mv_r_left(t_map *map);
void				mv_r_right(t_map *map);

int					key_hook(int key, t_map *map);


void static		solve_wall(float ati, float azi, t_map *map, t_loop loop);

void		solve_get_dist_cosy(t_solve *solve);
void		solve_get_dist_sinx(t_solve *solve);



void		draw(t_map *map);
int		draw_wall_w(t_map *map, t_block *wall, t_solve *solve, t_loop loop);
int		draw_wall_s(t_map *map, t_block *wall, t_solve *solve, t_loop loop);
int		draw_wall_n(t_map *map, t_block *wall, t_solve *solve, t_loop loop);
int		draw_wall_e(t_map *map, t_block *wall, t_solve *solve, t_loop loop);
void		draw_walls(t_map *map);


// int		solve_wall_x_primer(t_solve *solve, t_map *map);
// int		solve_wall_x(t_solve *solve, t_map *map);
// int		solve_wall_y_primer(t_solve *solve, t_map *map);
// int		solve_wall_y(t_solve *solve, t_map *map);
// int		solve_wall_step(t_solve *solve, t_map *map);

void		solve_wall(float ati, float azi, t_map *map, t_loop loop);


void		solve_wall_0(float ati, float azi, t_map *map, t_loop loop);
void		solve_wall_1(float ati, float azi, t_map *map, t_loop loop);
void		solve_wall_2(float ati, float azi, t_map *map, t_loop loop);
void		solve_wall_3(float ati, float azi, t_map *map, t_loop loop);
void		solve_wall_4(float ati, float azi, t_map *map, t_loop loop);
void		solve_wall_5(float ati, float azi, t_map *map, t_loop loop);
void		solve_wall_6(float ati, float azi, t_map *map, t_loop loop);
void		solve_wall_7(float ati, float azi, t_map *map, t_loop loop);

int			solve_wall_check(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop);
void		solve_wall_set(t_solve *solve_x, t_solve *solve_y);
void		solve_wall_x(t_solve *solve, t_loop loop);
void		solve_wall_y(t_solve *solve, t_loop loop);
void solve_wall_step(t_solve *solve_x, t_solve *solve_y);

int		solve_wall_check_draw_compare(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop);
int		solve_wall_check_draw_x(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop);
int		solve_wall_check_draw_y(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop);
int		solve_wall_check_return_0(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop);
int		solve_wall_check_return_1(t_solve *solve_x, t_solve *solve_y, t_map *map, t_loop loop);




#endif