#include <stdbool.h>
#include <stdlib.h>
#include "list.h"
bool Verifica(Item** cont, Item* i,int i_size) {
	for (int j = 0; j < i_size; j++) {
		if (i == cont[j]) return true;
	}
	return false;
}
bool AnyLoop(const Item* i1) {
	Item** cont = malloc(1 * sizeof(Item));
	int i_size = 0;
	for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (Verifica(cont, tmp, i_size)) {
			free(cont);
			return true;
		}
		cont[i_size] = tmp;
		cont = realloc(cont, (++i_size) * sizeof(Item));
	}
	free(cont);
	return false;
}