#include "cub3d.h"

void		print_solve(t_solve *solve, char *label, char *indent)
{
	fprintf(stderr, "%s", label);
	fprintf(stderr, "%sposx: %f ", indent, solve->posx);
	fprintf(stderr, "%sposy: %f ", indent, solve->posy);
	fprintf(stderr, "%sposz: %f ", indent, solve->posz);
	fprintf(stderr, "%sazi: %f ", indent, solve->azi);
	fprintf(stderr, "%sati: %f ", indent, solve->ati);
	fprintf(stderr, "%sstepx: %f ", indent, solve->stepx);
	fprintf(stderr, "%sstepy: %f ", indent, solve->stepy);
	fprintf(stderr, "%sstepz: %f ", indent, solve->stepz);
	fprintf(stderr, "%sdist: %f ", indent, solve->dist);
	fprintf(stderr, "%sdirx: %f ", indent, solve->dirx);
	fprintf(stderr, "%sdiry: %f ", indent, solve->diry);
	fprintf(stderr, "%ssum_dist: %f\n", indent, solve->sum_dist);

}