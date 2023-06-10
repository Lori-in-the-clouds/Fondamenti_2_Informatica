#include "colora.h"
#include <stdlib.h>
int main(void) {
	struct Matrix p;
	p.size = 3;
	p.data = calloc(p.size*p.size, sizeof(int));
	p.data[0] = true;
	p.data[1] = true;
	p.data[2] = true;
	p.data[3] = true;
	p.data[4] = true;
	p.data[5] = false;
	p.data[6] = true;
	p.data[7] = false;
	p.data[8] = true;
	char c[] = { 'r','v' };
	MappaColori(&p, c, 2);
}