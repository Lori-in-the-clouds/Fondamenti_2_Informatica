#include "list.h"
extern Item* Reverse(Item* i);
extern void ReverseRec(Item* head, Item** headRef);
int main(void) {
	Item* p = ListCreateEmpty();
	int v[] = { 1,2,3 };
	for (int i = 0; i < sizeof(v)/sizeof(int); i++) {
		p = ListInsertBack(p, &v[i]);
	}
	Item* ris = ListCreateEmpty();
	Reverse(p);
	return 0;
}