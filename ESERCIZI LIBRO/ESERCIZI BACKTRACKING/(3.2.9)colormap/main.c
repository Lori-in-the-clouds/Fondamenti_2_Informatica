#include "colormap.h"
#include <stdlib.h>
#include <stdbool.h>
int main(void) {
	struct SquareMatrix* p = malloc(sizeof(struct SquareMatrix));
	p->side = 9;
	p->data = malloc(p->side * sizeof(int));
	p->data[0] = 1;
	p->data[1] = 1;
	p->data[2] = 1;
	p->data[3] = 1;
	p->data[4] = 1;
	p->data[5] = 0;
	p->data[6] = 1;
	p->data[7] = 0;
	p->data[8] = 1;
	ColorMap(p, "rvb");
}