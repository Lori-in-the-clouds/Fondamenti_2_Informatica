#include "list.h"
extern int ContaVette(const Item* i);
int main(void) {
	int v[] = { 7,2,5,4 };
	Item *i1 = ListCreateEmpty();
	for (int i = 0; i < sizeof(v) / sizeof(int); i++) {
		i1 = ListInsertBack(i1, v + i);
	}
	ContaVette(i1);
}