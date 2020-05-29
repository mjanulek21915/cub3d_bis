#include "cub3d.h"

void 		print_loop(t_loop loop)
{
	fprintf(stderr, "PRINT LOOP");
	fprintf(stderr, "loop.h = %d", loop.h);
	fprintf(stderr, "loop.v = %d", loop.v);
	fprintf(stderr, "loop.hcount = %d", loop.hcount);
	fprintf(stderr, "loop.vcount = %d", loop.vcount);

}