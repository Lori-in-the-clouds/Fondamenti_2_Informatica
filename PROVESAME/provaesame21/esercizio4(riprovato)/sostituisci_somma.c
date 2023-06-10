#include "elemtype.h"
#include "tree.h"
void rec2(Node* t,int *ris) {
	if (TreeIsEmpty(t)) return;
	ris[0] += *TreeGetRootValue(t);
	rec2(TreeLeft(t),ris);
	rec2(TreeRight(t),ris);
}
void rec1(Node* t) {
	if (TreeIsEmpty(t)) return;
	int ris = 0;
	rec2(t,&ris);
	t->value = ris;
	rec1(TreeLeft(t));
	rec1(TreeRight(t));
}
void SostituisciSomma(Node* t) {
	if (TreeIsEmpty(t)) return;
	rec1(t);
	return;
}