#include "concatena.h"
int main(void) {
	Item* p1 = ListCreateEmpty();
	Item* p2 = ListCreateEmpty();
	int v1[] = { 1,2,3,4 };
	int v2[] = { 5,6,7,8 };
	for (int i = 0; i < 4; i++) {
		p1 = ListInsertBack(p1, &v1[i]);
		p2 = ListInsertBack(p2, &v2[i]);
	}
	Concatena(p1, p2, kNoCopy);
	Concatena(p1, p2, kCopy);
	return 0;
}