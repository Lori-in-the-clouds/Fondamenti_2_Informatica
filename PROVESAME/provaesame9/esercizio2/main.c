#include "colora.h"
#include <stdlib.h>
int main(void) {
	struct Matrix* p = malloc(1 * sizeof(struct Matrix));
	p->data = malloc(9 * sizeof(bool));	
	char c[] = { 'r','v','b'};
	p->size = 3;
	p->data[0] = true;
	p->data[1] = true;
	p->data[2] = true;
	p->data[3] = true;
	p->data[4] = true;
	p->data[5] = false;
	p->data[6] = true;
	p->data[7] = false;
	p->data[8] = true;
	MappaColori(p, c, 3);




	
}
