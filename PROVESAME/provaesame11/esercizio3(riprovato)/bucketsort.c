#include "elemtype.h"
#include "list.h" 
#include <stdlib.h>
//Item* ConcatenaN(Item** v, size_t v_size) {
//	Item* head = ListCreateEmpty();
//	Item* last = ListCreateEmpty();
//	for (int i = 0; i < v_size; i++) {
//		if (!ListIsEmpty(v[i])) {
//			if (ListIsEmpty(head)) {
//				head = v[i];
//			}
//			else {
//				last->next = v[i];
//			}
//
//			while (!ListIsEmpty(ListGetTail(v[i]))) {
//				v[i] = ListGetTail(v[i]);
//			}
//			last = v[i]; //collegamento con head, mantine il punto su quello procedente partendo dall'head
//		}
//	}
//	return head;
//}
Item* ConcatenaN(Item** v, size_t v_size) {
	Item *ris = ListCreateEmpty();
	for (int j = 0; j < v_size; j++) {
		for (Item* tmp = v[j]; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			ris = ListInsertBack(ris, ListGetHeadValue(tmp));
		}
	}
	return ris;
}
Item* BucketSort(Item* l) {
	if (ListIsEmpty(l)) return ListCreateEmpty();
	//CONTO QUANTI VALORI CI SONO E TROVO IL MAX E IL MIN
	if (ListIsEmpty(l)) return ListCreateEmpty();
	int cont1 = 0;
	int max = *ListGetHeadValue(l);
	int min = *ListGetHeadValue(l);
	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), &max) > 0) max = *ListGetHeadValue(tmp);
		if (ElemCompare(ListGetHeadValue(tmp), &min) < 0) min = *ListGetHeadValue(tmp);
		cont1++;
	}
	if (min == max) {
		return l;
	}
	//VETTORE DI LISTA
	Item** v = calloc(cont1, sizeof(Item));
	//INSERIAMO I VALORI NEL BUCKET GIUSTO
	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		int val = ((cont1 - 1) * ((*ListGetHeadValue(tmp)) - min)) / (max - min);
		v[val] = ListInsertBack(v[val], ListGetHeadValue(tmp));
	}
	for (int j = 0; j < cont1; j++) {
		v[j] = BucketSort(v[j]);
	}
	Item* ris = ConcatenaN(v, cont1);
	free(v);
	return ris;
}