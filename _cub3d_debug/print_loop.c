#include "cub3d.h"

void 		print_loop(t_loop loop, char *label, char *indent)
{
	fprintf(stderr, "%s", label);
	fprintf(stderr, "%sh = %d ", indent, loop.h);
	fprintf(stderr, "%sv = %d ", indent, loop.v);
	fprintf(stderr, "%shcount = %d ", indent, loop.hcount);
	fprintf(stderr, "%svcount = %d\n", indent, loop.vcount);

}