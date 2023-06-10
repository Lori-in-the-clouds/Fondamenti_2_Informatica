#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
int main(void) {
	struct Grid g;
	g.rows = 3;
	g.cols = 5;
	g.cells = calloc(g.rows * g.cols, sizeof(int));
	g.cells[0] = 0;
	g.cells[1] = -1;
	g.cells[2] = 0;
	g.cells[3] = 0;
	g.cells[4] = 0;
	g.cells[5] = 0;
	g.cells[6] = 0;
	g.cells[7] = 0;
	g.cells[8] = -1;
	g.cells[9] = 0;
	g.cells[10] = 0;
	g.cells[11] = 0;
	g.cells[12] = 0;
	g.cells[13] = 0;
	g.cells[14] = 0;
	FindPaths(&g);
	return 0;
}