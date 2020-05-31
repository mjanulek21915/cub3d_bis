#include "cub3d.h"

void		print_solve(t_solve *solve, char *label, char *indent)
{
	fprintf(stderr, "%s", label);
	fprintf(stderr, "%sposx: %f\n", indent, solve->posx);
	fprintf(stderr, "%sposy: %f\n", indent, solve->posy);
	fprintf(stderr, "%sposz: %f\n", indent, solve->posz);
	fprintf(stderr, "%sazi: %f\n", indent, solve->azi);
	fprintf(stderr, "%sati: %f\n", indent, solve->ati);
	fprintf(stderr, "%sstepx: %f\n", indent, solve->stepx);
	fprintf(stderr, "%sstepy: %f\n", indent, solve->stepy);
	fprintf(stderr, "%sstepz: %f\n", indent, solve->stepz);
	fprintf(stderr, "%sdist: %f\n", indent, solve->dist);
	fprintf(stderr, "%sdirx: %f\n", indent, solve->dirx);
	fprintf(stderr, "%sdiry: %f\n", indent, solve->diry);
	fprintf(stderr, "%ssum_dist: %f\n", indent, solve->sum_dist);

}