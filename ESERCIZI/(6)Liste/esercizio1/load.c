#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

Item* ListLoad(const char* filename) {
	FILE* f = fopen(filename, "r");
	Item* l = ListCreateEmpty();
	if (f == NULL) {
		return l;
	}
	ElemType d = 0;
	while(1) {
		int turn1 = ElemRead(f, &d);
		if (turn1 == EOF) {
			break;
		}
		l = ListInsertHead(&d,l);
	}
	fclose(f);
	return l;
}