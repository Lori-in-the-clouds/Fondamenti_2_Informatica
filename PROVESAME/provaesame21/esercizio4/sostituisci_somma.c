#include "tree.h"
void Rec2(Node* t, int *ris) {
	if (TreeIsEmpty(t)) return;
	(*ris) += (*TreeGetRootValue(t));
	Rec2(TreeLeft(t),ris);
	Rec2(TreeRight(t),ris);
}
void Rec1(Node* t) {
	if (TreeIsEmpty(t)) return;
	int ris = 0;
	Rec2(t, &ris);
	t->value = ris;
	Rec1(TreeLeft(t));
	Rec1(TreeRight(t));
}
void SostituisciSomma(Node* t) {
	if (TreeIsEmpty(t)) return;
	Rec1(t);
	return;
}