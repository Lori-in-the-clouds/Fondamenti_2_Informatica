#include "tree.h"
#include <stdlib.h>
void CountDominantRec(const Node* t,int *ris) {
	ElemType* e = calloc(1, sizeof(ElemType));
	ElemType* c = calloc(1, sizeof(ElemType));
	e[0] = 0;
	c[0] = 0;
	if (TreeIsLeaf(t)) {
		free(e);
		free(c);
		return;
	}
	 const ElemType* d = TreeGetRootValue(t);
	 if (!TreeIsEmpty(t->left)) {
		*e = *TreeGetRootValue(t->left);
	}
	 if (!TreeIsEmpty(t->right)) {
		*c = *TreeGetRootValue(t->right);
	}
	if (*d > *e + *c) {
			(*ris)++;
			free(e);
			free(c);
	}
	CountDominantRec(t->left, ris);
	CountDominantRec(t->right, ris);
}
int CountDominant(const Node* t) {
	int ris = 0;
	CountDominantRec(t, &ris);
	return ris;
}