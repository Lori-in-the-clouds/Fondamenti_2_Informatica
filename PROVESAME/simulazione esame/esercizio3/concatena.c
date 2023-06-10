#include "list.h"
Item* ConcatenaN(Item** v, size_t v_size) {
	int control = 0;
	for (int i = 0; i < v_size; i++) {
		if (ListIsEmpty(v[i])) control++;
	}
	if (control == v_size || v_size == 0) return ListCreateEmpty();
	int  i = 0;
	while (ListIsEmpty(v[i])) i++;
	v[0] = v[i];
	for (int j = i+1; j < v_size; j++) {
		for (Item* tmp = v[0]; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			if (ListIsEmpty(tmp->next)) {
				tmp->next = v[j];
				break;
			}
		}
	}
	return v[0];
}