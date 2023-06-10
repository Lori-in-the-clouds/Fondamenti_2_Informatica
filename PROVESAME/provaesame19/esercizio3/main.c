#include "list.h"
#include <stdlib.h>
#include <crtdbg.h>
extern Item* PariDispari(Item* i);
int main(void) {
	int v[] = {1,3,5,4};
	Item* s = ListCreateEmpty();
	for (int j = 0; j < sizeof(v)/sizeof(int); j++) {
		s = ListInsertBack(s, &v[j]);
	}
	PariDispari(s);
	
	
	return 0;
	_CrtDumpMemoryLeaks();
}