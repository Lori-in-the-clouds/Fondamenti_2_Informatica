#include "cc.h"
int main(void) {
	int v[] = { 1,2,4 };
	Item* i = ListCreateEmpty();
	int c[] = { 0,1,2,3,4 };
	for (int j = 0; j < sizeof(c) / sizeof(int); j++) {
		i = ListInsertBack(i, c + j);
	}
	ComponentiConnesse(i, v, 3);
}