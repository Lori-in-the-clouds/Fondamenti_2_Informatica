#include "differenza.h"
#include "list.h"
#include <math.h>
Item* Differenza(const Item* i1, const Item* i2) {
	int num1 = 0;
	int num2 = 0;
	int molt = 0;
	for (Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		num1 += (int)(*ListGetHeadValue(tmp)) * pow(10, molt);
		molt++;
	}
	molt = 0;
	for (Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		num2 += (int)(*ListGetHeadValue(tmp)) * pow(10, molt);
		molt++;
	}
	int numero = num1 - num2;
	int j = numero;
	int molt2 = 0;
	while (j > 0) {
		j /= 10;
		molt2++;
	}
	Item* ris = ListCreateEmpty();
	for (int i = 0; i < molt2; i++) {
		ElemType c = (numero / pow(10, i));
		ElemType e = (char)(c % 10) + 48;
		ris = ListInsertBack(ris,&e);
	}
	return ris;
}



////converto in int
//Item* ii1 = ListCreateEmpty();
//Item* ii2 = ListCreateEmpty();
//for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
//	 const ElemType e = (int)(*ListGetHeadValue(tmp));
//	ii1 = ListInsertBack(ii1,&e);
//}
//for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
//	const ElemType e = (int)(*ListGetHeadValue(tmp));
//	ii2 = ListInsertBack(ii2, &e);
//}
//Item* ris = ListCreateEmpty();
//if (ListIsEmpty(ii2)) {
//	for (const Item* tmp = ii1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
//		ris = ListInsertBack(ris,ListGetHeadValue(tmp));
//	}
//	return ris;
//}
//Item* tmp2 = ii2;
//ElemType rest = 0;//attenzione
//for (const Item* tmp1 = ii1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
//	if (ListIsEmpty(tmp2)) {
//		for (const Item* tmp3 = tmp1; !ListIsEmpty(tmp3); tmp3 = ListGetTail(tmp3)) {
//			if (rest != 0) {
//				ElemType som = (*ListGetHeadValue(tmp3)) - 1; //attenzioen
//				ris = ListInsertBack(ris,&som);
//				rest--;
//				continue;
//			}
//			ris = ListInsertBack(ris,ListGetHeadValue(tmp3));
//		}
//		break;
//	}
//	ElemType suv = *ListGetHeadValue(tmp1) - (*ListGetHeadValue(tmp2)); //attenzione
//	if (rest != 0) {
//		suv -= 1;
//		rest--;
//	}
//	if (suv < 0) {
//		suv += 10;
//		rest++;
//	}
//	ris = ListInsertBack(ris,&suv);
//	tmp2 = ListGetTail(tmp2);
//}
////riconverto in char 
//Item* ris2 = ListCreateEmpty();
//for (const Item* tmp = ris; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
//	char e = (char)(*ListGetHeadValue(tmp));
//	ris2 = ListInsertBack(ris2, &e);
//}
//return ris2;