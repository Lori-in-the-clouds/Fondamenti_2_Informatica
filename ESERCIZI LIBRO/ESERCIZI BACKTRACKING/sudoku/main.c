#include "sudoku.h"
#include <stdlib.h>
int main(void) {
	Matrix p;
	p.size = sizeMatrix;
	p.data = calloc(sizeMatrix,sizeof(int));
	p.data[0] = 8;
	p.data[1] = 7;
	p.data[12] = 9;
	p.data[17] = 4;
	p.data[19] = 2;
	p.data[21] = 7;
	p.data[24] = 1;
	p.data[26] = 5;
	p.data[29] = 9;
	p.data[30] = 6;
	p.data[34] = 3;
	p.data[44] = 9;
	p.data[47] = 6;
	p.data[48] = 5;
	p.data[49] = 4;
	p.data[54] = 6;
	p.data[55] = 9;
	p.data[60] = 7;
	p.data[63] = 2;
	p.data[68] = 7;
	p.data[69] = 4;
	p.data[75] = 3;
	p.data[79] = 1;
	ResolveSudoku(&p);
}
