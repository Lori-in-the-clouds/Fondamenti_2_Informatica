#include "remove.h"
#include <stdlib.h>
#include <crtdbg.h>
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = {4,6,6,6};
	for (int i = 0; i < 4; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	Item* ris = RemoveDuplicates(p, false);
	ListDelete(ris);
	free(v);
	_CrtDumpMemoryLeaks();
	return 0;
}