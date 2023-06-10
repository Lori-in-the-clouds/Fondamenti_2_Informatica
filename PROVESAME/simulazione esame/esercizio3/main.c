#include "list.h"
#include <stdlib.h>
extern Item* ConcatenaN(Item** v, size_t v_size);
int main(void) {
	Item** p = malloc(3 * sizeof(Item));
	p[0] = ListCreateEmpty();
	p[1] = ListCreateEmpty();
	p[2] = ListCreateEmpty();
	int v[] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++) {
		p[2] = ListInsertBack(p[2], &v[i]);
	}
	
	ConcatenaN(p,3);
}