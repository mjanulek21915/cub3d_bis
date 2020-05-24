#include "cub3d.h"

void		print_solve(t_solve *solve)
{
	fprintf(stderr, "\tprint_solve:\n");
	fprintf(stderr, "posx: %f\n", solve->posx);
	fprintf(stderr, "posy: %f\n", solve->posy);
	fprintf(stderr, "posz: %f\n", solve->posz);
	fprintf(stderr, "azi: %f\n", solve->azi);
	fprintf(stderr, "ati: %f\n", solve->ati);
	fprintf(stderr, "stepx: %f\n", solve->stepx);
	fprintf(stderr, "stepy: %f\n", solve->stepy);
	fprintf(stderr, "stepz: %f\n", solve->stepz);
	fprintf(stderr, "dist: %f\n", solve->dist);
	fprintf(stderr, "dirx: %f\n", solve->dirx);
	fprintf(stderr, "diry: %f\n", solve->diry);
	fprintf(stderr, "sum_dist: %f\n", solve->sum_dist);
	fprintf(stderr, "\tprint_solve end\n");

}