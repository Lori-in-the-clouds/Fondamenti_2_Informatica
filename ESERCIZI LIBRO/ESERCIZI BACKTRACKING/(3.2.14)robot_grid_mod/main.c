#include "robot_mod.h"
#include <stdlib.h>
int main(void) {
	struct Grid p;
	p.rows = 3;
	p.cols = 5;
	p.cells = malloc(15 * sizeof(int));
	p.cells[0] = 0;
	p.cells[1] = 'B';
	p.cells[2] = 0;
	p.cells[3] = 0;
	p.cells[4] = 0;
	p.cells[5] = 0;
	p.cells[6] = 0;
	p.cells[7] = 0;
	p.cells[8] = 'B';
	p.cells[9] = 0;
	p.cells[10] = 0;
	p.cells[11] = 0;
	p.cells[12] = 0;
	p.cells[13] = 0;
	p.cells[14] = 0;
	FindPaths(&p, 9);
}