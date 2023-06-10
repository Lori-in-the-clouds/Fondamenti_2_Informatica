#include "list.h"
#include <stdlib.h>
Item* Intersect(const Item* i1, const Item* i2) {
	Item* ris = ListCreateEmpty();
	for ( const Item* tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			 const ElemType* e1 = ListGetHeadValue(tmp1);
		for ( const Item* tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			 const ElemType* e2 = ListGetHeadValue(tmp2);
			if (*e1 == *e2) {
				ris = ListInsertBack(ris,e1);
				break;
			}
		}
	
	}
	
	
	return ris;
	//se facessi free(l); libero solo il primo item 
	//quindi dovrei fare un ciclo, ma DOBBIAMO USARE LA LISTA ELEDELETE 
}