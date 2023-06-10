#include "tree.h"
#include <float.h>
enum type {
	pari,
	dispari
};
void ContNode(const Node* t,int *n) {
	if (TreeIsEmpty(t)) return;
	n[0]++;
	ContNode(TreeLeft(t),n);
	ContNode(TreeRight(t),n);
}
void MedianoRec(Node* t, int n,enum type p,int* i,double *ris) {
	if (p == dispari) {
		if (TreeIsEmpty(t)) return;
		MedianoRec(TreeLeft(t), n, p,i,ris);
		i[0]++;
		if (i[0] == n + 1) {
			ris[0] = t->value;
			return;
		}
		MedianoRec(TreeRight(t), n, p, i,ris);
	}
	else {
		if (TreeIsEmpty(t)) return;
		
		MedianoRec(TreeLeft(t), n, p, i,ris);
		i[0]++;
		if (i[0] == n) {
			ris[0] += t->value;
		}
		if (i[0] == n + 1) {
			ris[0] += t->value;
			ris[0] /= 2.0;
			return;
		}
		MedianoRec(TreeRight(t), n, p, i,ris);
	}
}
double Mediano(const Node* t) {
	if (TreeIsEmpty(t)) return DBL_MAX;
	int n = 0;
	ContNode(t, &n);
	int pos = 0;
	int i = 0;
	double ris = 0;
	if (n % 2 != 0) {
		pos = (n / 2);
		MedianoRec(t, pos,dispari,&i,&ris);
	}
	else {
		i = 0;
		pos = n / 2;
		MedianoRec(t, pos, pari,&i,&ris);
	}
	return ris;
}