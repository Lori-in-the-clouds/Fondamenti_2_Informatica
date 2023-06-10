#include "vector_list.h"
#include <stdlib.h>
Item* Vector2List(const ElemType* v, size_t v_size, enum ConversionType c) {
	Item* ris = ListCreateEmpty();
	if (v == NULL) return ris;
	for (int i = 0; i < v_size; i++) {
		if (c == kInOrder) {
			ris = ListInsertBack(ris, v + i);
		}
		else ris = ListInsertHead(v + i, ris);
	}
	return ris;
}
ElemType* List2Vector(const Item* i, size_t* v_size, enum ConversionType c) {
	if (ListIsEmpty(i)) {
		*v_size = 0;
		return NULL;
	}
	int j = 0;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		(*v_size)++;
	}
	if (c == kReverse) j =(*v_size) - 1;
	ElemType* ris = malloc((v_size[0]) * sizeof(ElemType));
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (c == kInOrder) {
			ris[j] = *ListGetHeadValue(tmp);
			j++;
		}
		else {
			ris[j] = *ListGetHeadValue(tmp);
			j--;
		}
	}
	return ris;
}