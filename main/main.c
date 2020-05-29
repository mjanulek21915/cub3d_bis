#include "cub3d.h"





int main()
{
    void *mlx;
    void *win;
	t_map *map;
	t_img *img;
	void *r_draw;

	map = mk_map(PATH);
	print_map(map);

	map->f_draw = &draw;

    if (!(mlx = mlx_init()))
		do_exit("mlx_init fail");

    if (!(win = mlx_new_window(mlx, SIZE_X, SIZE_Y, "test_window")))
		do_exit("mlx_new_window fail");


	if (!(img = mlx_new_image(mlx, SIZE_X, SIZE_Y)))
		do_exit("mlx_new_image fail");
	map->mlx = mlx;
	map->win = win;
	map->img = img;
	draw(map);
	// mlx_put_image_to_window(mlx, window, img, 0, 0);
    // mlx_key_hook(win, key_hook, map);
	// mlx_loop_hook(win,draw, mlx, window, 0);
    // mlx_loop(mlx);
}
































	// fprintf(stderr, "\n");
	// fprintf(stderr, "hdg : %f\n", map->player_hdg);
	// fprintf(stderr, "hdg : %f\n", map->player_posx);
	// fprintf(stderr, "hdg : %f\n", map->player_posy);