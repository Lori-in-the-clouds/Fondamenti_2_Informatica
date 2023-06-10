#include "tree.h"
void rec(ElemType *fath,Node *tmp1,int a,int b,int i,int *l1,int *l2,int *cont,int *p1,int *p2,bool *ris) {
	if (TreeIsEmpty(tmp1)) {
		return;
	}
	if (a == *TreeGetRootValue(tmp1)) {
		*l1 = i;
		*p1 = *fath;
		cont[0]++;
	}
	if (b == *TreeGetRootValue(tmp1)) {
		*l2 = i;
		*p2 = *fath;
		cont[0]++;
	}
	if (*cont == 2) {
		if (*l1 == *l2) {
			if (*p1 != *p2) {
				*ris = true;
				return;
			}
		}
	}
	fath = TreeGetRootValue(tmp1);
	rec(fath,TreeLeft(tmp1), a, b,i+1,l1,l2,cont,p1,p2,ris);
	rec(fath,TreeRight(tmp1), a, b,i+1,l1,l2,cont,p1,p2,ris);
}
bool Cugini(const Node* t, int a, int b) {
	int l1 = 0;
	int l2 = 0;
	int p1 = 0;
	int p2 = 0;
	int cont = 0;
	ElemType fath = 0;
	bool ris = false;
	rec(&fath,t, a, b,0,&l1,&l2,&cont,&p1,&p2,&ris);
	return ris;
}