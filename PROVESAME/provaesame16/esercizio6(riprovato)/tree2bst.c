#include "elemtype.h"
#include "tree.h"

void rec(const Node* t, Node** ris,bool *control) {
	if (TreeIsEmpty(t)) {
		return;
	}
	rec(TreeLeft(t), ris,control);
	//facciamo quello che dobbiamo fare 
	Node* tmp = *ris;
	while (1) {
		if (control[0] == true) {
			*ris = TreeCreateRoot(TreeGetRootValue(t), TreeCreateEmpty(), TreeCreateEmpty());
			control[0] = false;
			break;
		}
		//vado a sinsitra
		if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(tmp)) <= 0) {
			if (TreeIsEmpty(tmp->left)) {
				tmp->left = TreeCreateRoot(TreeGetRootValue(t), TreeCreateEmpty(), TreeCreateEmpty());
				break;
			}
			else {
				tmp = TreeLeft(tmp);
			}
			continue;
		}
		//vado a destra
		if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(tmp)) > 0) {
			if (TreeIsEmpty(tmp->right)) {
				tmp->right = TreeCreateRoot(TreeGetRootValue(t), TreeCreateEmpty(), TreeCreateEmpty());
				break;
			}
			else {
				tmp = TreeRight(tmp);
			}
			continue;
		}
	}
	rec(TreeRight(t), ris,control);
}

Node* Tree2Bst(const Node* t) {
	if (TreeIsEmpty(t)) return TreeCreateEmpty();
	Node* ris = TreeCreateEmpty();
	bool control = true;
	rec(t, &ris, &control);
	return ris;
}