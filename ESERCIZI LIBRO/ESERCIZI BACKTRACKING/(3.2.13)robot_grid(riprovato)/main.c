#include "robot.h"
#include <stdlib.h>
int main(void) {
	struct Grid p;
	p.rows = 3;
	p.cols = 5;
	p.cell = malloc(15 * sizeof(int));
	p.cell[0] = 0;
	p.cell[1] = 'B';
	p.cell[2] = 0;
	p.cell[3] = 0;
	p.cell[4] = 0;
	p.cell[5] = 0;
	p.cell[6] = 'B';
	p.cell[7] = 0;
	p.cell[8] = 'B';
	p.cell[9] = 0;
	p.cell[10] = 0;
	p.cell[11] = 0;
	p.cell[12] = 0;
	p.cell[13] = 'B';
	p.cell[14] = 0;
	FindPaths(&p);
}