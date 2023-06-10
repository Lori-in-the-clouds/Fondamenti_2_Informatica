#include "list.h"
#include <stdlib.h>
#include "minheap.h"
//FUNZIONE CHE INVERTE UNA LISTA 
Item* Reverse(Item* i) {
	Item* previous = NULL;
	Item* current = i;
	while (!ListIsEmpty(current)) {
		Item* next = current->next; //nota il nodo successivo
		current->next = previous; //corregge il nodo corrente 
		previous = current; //manda avanti di uno il puntatore previous
		current = next; //manda avanti di unao il puntatore current 
	}
	return previous; //previous che sarebbe il vecchio current (3 righe sopra)
}
//PROGRAMMA CHE CANCELLA UNA INTERA PARTE DI UNA LISTA 
Item* Taglia(Item* i, int n) {
	int j = 0;
	if (n < 0) return ListCreateEmpty();
	if (n == 0) return i;
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j + 1 == n) {
			ListDelete(ListGetTail(tmp)); //IMPORTANTE, devi cancellare la memoria della lista che viene dopo
			tmp->next = NULL; //IMPORTANTE, bisogna far puntatare a NULL
			break;
		}
		j++;
	}
	return i;
}
//INSERIMENTO DI UN ELEMENTO IN UNA LISTA ORDINATA 
Item* InsertOrd(const ElemType* e, Item* i) {
	//prev = idirizzo dell'elemento che dovrà prececederlo 
	Item* new_item = ListInsertHead(e, ListCreateEmpty());
	Item* suv = ListCreateEmpty();
	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp->next), e) > 0) {
			suv = ListGetTail(tmp);		//per trovare il pezzettino sopra, uso listgettail in modo tale da non dover fare copia incolla
			tmp->next = new_item;
			break;
		}
	}
	new_item->next = suv;
	return i;
}
//ELIMINAZIONE DI UN ELEMENTO IN UNA LISTA ORDINATA 
Item* DeleteNode(Item* i, ElemType* e) {
	while (ElemCompare(ListGetHeadValue(i), e) == 1) {
		Item* curr = i;
		i = ListGetTail(i);
		free(curr);
	}
	for (Item* tmp = i; !ListIsEmpty(tmp->next); tmp = ListGetTail(tmp)) {
		while (ElemCompare(ListGetHeadValue(tmp->next), e) == 0) {
			ElemDelete(&tmp->next->value);
			Item* curr = tmp->next;
			tmp->next = tmp->next->next;
			free(curr);
		}
	}
	return i;
}
//ELIMINAZIONE ELEMENTO DA UNA LISTA MA AL PRESENTE
Item* Taglia_al_presente(Item* i1, ElemType* e) {
	//NON PUò CANCELLARE IL PRIMO ELELMENTO DELLA LISTA
	Item* prev = i1;
	for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(tmp), e) == 0) {
			ElemDelete(&tmp->value);
			Item* curr = tmp;
			prev->next = tmp->next;
			free(curr);
			tmp = prev; // PARTE IMPORTANTE
		}
		prev = tmp;
	}
	return i1;
}


//COME NAVIGARE UN HEAP
void HeapNavigate(Heap* h, int i) {
	
	if (i >= h->size) return;
	
	HeapNavigate(h, HeapLeft(i));
	HeapNavigate(h, HeapRight(i));
}

//INSERTION SORT (PARTICOLARE ATTENZIONE A COME SHIFTARE DI UNO GLI ELEMENTTI DEL VETTORE)
void insMinore(int* v, int lastpos) {
	int i = 0;
	int x = v[lastpos];
	for (i = lastpos - 1; i >= 0 && x < v[i]; i--) { //PARTI SEMPRE DALL'INVERSO!!!!
		v[i + 1] = v[i];
	}
	v[i + 1] = x;
	return;
}
void InsertionSort(int* v, size_t v_size) {
	for (int i = 1; i < v_size; i++) {
		insMinore(v, i);
	}
}
