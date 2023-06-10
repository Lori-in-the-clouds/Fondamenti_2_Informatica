#include "list.h"
#include <crtdbg.h>
#include <stdlib.h>
extern Item* InsertOrd(const ElemType* e, Item* i);
int main(void) {
	Item* p = ListCreateEmpty();
	int* v = malloc(4 * sizeof(int));
	v[0] = 1;
	v[1] = 2;
	v[2] = 4;
	v[3] = 5;

	for (int i = 0; i < 4; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	const ElemType e = 3;
	Item *ris = InsertOrdRec(&e, p);
	ListDelete(ris);
	
	free(v);
	_CrtDumpMemoryLeaks();
	return 0;

}