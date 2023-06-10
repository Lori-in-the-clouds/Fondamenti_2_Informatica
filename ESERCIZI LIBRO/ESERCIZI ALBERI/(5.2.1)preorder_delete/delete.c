#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
void TreePreOrderDelete(Node* t) {
	if (TreeIsEmpty(t)) return;

//facciamo quello che dobbiamo fare
	printf("%d ", t->value);
	Node* l = t->left;
	Node* r = t->right;
	free(t);
	TreePreOrderDelete(l);
	TreePreOrderDelete(r);
}
/*      12
          /  \
         /    \
        4      21
       / \    / \
      /   \  5  18
     0     2
    / \   /
   77  8 9*/