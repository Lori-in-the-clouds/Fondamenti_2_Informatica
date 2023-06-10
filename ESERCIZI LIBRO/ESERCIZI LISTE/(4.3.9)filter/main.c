#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "list.h"

extern Item* Filter(Item* i, ElemType* e);
int main(void) {
	Item* p = ListCreateEmpty();
	int* v = malloc(4 * sizeof(int));
	v[0] = 2;
	v[1] = 4;
	v[2] = 2;
	v[3] = 2;
	for (int i = 0; i < 4; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	ElemType e = 3;
	p = Filter(p, &e);
	ListDelete(p);
	free(v);
	_CrtDumpMemoryLeaks();
	return 0;
}