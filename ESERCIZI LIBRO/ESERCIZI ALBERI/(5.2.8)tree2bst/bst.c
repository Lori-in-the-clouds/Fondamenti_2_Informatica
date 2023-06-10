#include "tree.h"
void Tree2BstRec(const Node* t,Node **ris,int *cont) {
	if (TreeIsEmpty(t)) return;
	Tree2BstRec(TreeLeft(t),ris,cont);
	//inseriamo il primo elemento
	if (cont[0] == 0) {
		ElemType* e = TreeGetRootValue(t);
		*ris = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
		cont[0]++;
	}
	//inseriamo il restante dentro il BTS
	else {
		Node* tmp = *ris; // quello che c'è gia 
		while (true) {
			//sinistra 
			if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(tmp)) < 0) {
				if (TreeIsEmpty(tmp->left)) {
					tmp->left = TreeCreateRoot(TreeGetRootValue(t), TreeCreateEmpty(), TreeCreateEmpty());
					break;
				}
				else {
					tmp = TreeLeft(tmp);
					continue;
				}
			}
			//destra
			if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(tmp)) >= 0) {
				if (TreeIsEmpty(tmp->right)) {
					tmp->right = TreeCreateRoot(TreeGetRootValue(t), TreeCreateEmpty(t), TreeCreateEmpty(t));
					break;
				}
				else {
					tmp = TreeRight(tmp);
					continue;
				}
			}
		}
	}
	Tree2BstRec(TreeRight(t),ris,cont);
}
 Node* Tree2Bst(const Node* t) {
	 if (TreeIsEmpty(t)) return TreeCreateEmpty();
	 Node* ris = TreeCreateEmpty();
	 int cont = 0;
	 Tree2BstRec(t,&ris,&cont);
	 return ris;
 }