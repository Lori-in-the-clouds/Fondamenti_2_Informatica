#include "tree.h"
void Cont(Node* t, int* ris) {
	if (TreeIsEmpty(t))  return;
	ris[0]++;
	Cont(TreeLeft(t),ris);
	Cont(TreeRight(t),ris);
}
void PopulatingNextRec(Node** t,int n,int *i) {
	if (TreeIsEmpty(*t) && i[0] == n) {
		(*t)->next->value  = NULL;
		return;
	}
	if (TreeIsEmpty(*t))  return;
	PopulatingNextRec(&(*t)->left,n,i);
	i[0]++;
	(*t)->next = TreeGetRootValue(*t);
	PopulatingNextRec(&(*t)->right,n, i);
} 

void PopulatingNext(Node* t) {
	if (TreeIsEmpty(t)) return;
	int cont = 0;
	Cont(t, &cont);
	int i = 0;
	PopulatingNextRec(&t,cont,&i);
	return;
}
