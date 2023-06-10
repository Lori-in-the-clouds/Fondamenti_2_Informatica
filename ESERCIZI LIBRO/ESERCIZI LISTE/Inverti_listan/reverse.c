#include "list.h"
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

//metodo ricorsivo 
void ReverseRec(Item* head, Item** headRef) {
	Item* first = ListCreateEmpty();
	Item* rest = ListCreateEmpty();
	//CASO BASE
	if (ListIsEmpty(head)) {
		return;
	}
	first = head;
	rest = first->next;
	if (ListIsEmpty(rest)) {
		//CORREGGI IL PUNTATORE DELLA TESTA
		*headRef = first;
		return;
	}
	ReverseRec(rest, headRef);
	rest->next = first;
	first->next = NULL;
}
//Item* Reverse(Item* i) {
//	Item* curr = i;
//	Item* previous = ListCreateEmpty();
//	while (!ListIsEmpty(curr)) {
//		Item* next = curr->next;
//		curr->next = previous;
//		previous = curr;
//		curr = next;
//	}
//	return previous;
//}
	
