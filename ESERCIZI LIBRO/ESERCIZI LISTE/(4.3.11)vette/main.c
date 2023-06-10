#include "list.h"
extern int ContaVette(const Item* i);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = { 7,2,5,5,4 };
	for (int i = 0; i < 5; i++) {
		p = ListInsertBack(p, &v[i]);
	}
	ContaVette(p);
}