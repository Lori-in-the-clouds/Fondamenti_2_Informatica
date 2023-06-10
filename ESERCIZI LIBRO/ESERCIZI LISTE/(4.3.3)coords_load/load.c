#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>

Item* ListLoad(const char* filename) {
	Item* ris = ListCreateEmpty();
	if (filename == NULL)  return ris;
	FILE* f = fopen(filename, "r");
	if (f == NULL) return ris;
	size_t turn1 = 1;
	struct Coord p;
	while (1) {
		turn1 = fscanf(f, "%d %d", &p.x, &p.y);
		if (turn1 == EOF) break;
		ris = ListInsertHead(&p, ris);
	}
	return ris;
}
