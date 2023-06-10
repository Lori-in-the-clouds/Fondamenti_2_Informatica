#include "list.h"
#include <stdlib.h>
#include <crtdbg.h>
extern Item* Sum(const Item* i1, Item* i2);
int main(void) {
	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();
	int* v1 = malloc(4 * sizeof(int));
	v1[0] = 4;
	v1[1] = 5;
	v1[2] = 9;
	v1[3] = 1;
	int* v2 = malloc(3 * sizeof(int));
	v2[0] = 9;
	v2[1] = 2;
	v2[2] = 6;
	for (int i = 0; i < 4; i++) {
		i1 = ListInsertBack(i1, &v1[i]);
	}
	for (int i = 0; i < 3; i++) {
		i2 = ListInsertBack(i2, &v2[i]);
	}
	Item* ris = Sum(i1,i2);
	free(v1);
	free(v2);
	ListDelete(i1);
	ListDelete(i2);
	ListDelete(ris);

	_CrtDumpMemoryLeaks();
	return 0;
}