#include "tree.h"
void Tree2BstRec(const Node* t, Node** ris,bool *cont) {
	if (TreeIsEmpty(t)) return;
		
		Tree2BstRec(TreeLeft(t),ris,cont);
	//faccio quello ceh devo fare
		Node* tmp = *ris;
		
		while (true) {
			if (*cont == false) {
				*ris = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
				*cont = true;
				break;
			}
			if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(tmp)) <= 0) {
				if (TreeIsEmpty(tmp->left)) {
					tmp->left = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
					break;
				}
				else {
					tmp = TreeLeft(tmp);
				}
				continue;
			}
			if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(tmp)) > 0) {
				if (TreeIsEmpty(tmp->right)) {
					tmp->right = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
					break;
				}
				else {
					tmp = TreeRight(tmp);
				}
			}
			
		}
		Tree2BstRec(TreeRight(t),ris,cont);
}
Node* Tree2Bst(const Node* t) {
	if (TreeIsEmpty(t)) return TreeCreateEmpty();
	Node* ris = TreeCreateEmpty();
	bool cont = false;
	Tree2BstRec(t, &ris,&cont);
	return ris;
}