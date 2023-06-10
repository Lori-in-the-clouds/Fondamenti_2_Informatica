#include "tree.h"
Node* DeleteBstNode(Node* n, const ElemType* key) {
	Node* tmp = n;
	while (1) {
		if (TreeIsEmpty(tmp)) {
			break;
		}
		if (ElemCompare(key, TreeGetRootValue(tmp)) > 0) {
			tmp = TreeRight(tmp);
		}
		if (ElemCompare(key, TreeGetRootValue(tmp)) < 0) {
			tmp = TreeLeft(tmp);
		}
		//Lo abbiamo trovato 
		if (ElemCompare(key, TreeGetRootValue(tmp)) == 0) {
			//se è una foglia 
			if (TreeIsLeaf(tmp)) {
				TreeDelete(tmp);
				break;
			}
			//se è un nodo con un solo figlio destro
			if ((!TreeLeft(tmp) && TreeRight(tmp) && TreeIsLeaf(TreeRight(tmp)))) {
				tmp->value = tmp->right->value;
				TreeDelete(tmp->right);
				tmp->right = NULL; //attenzione 
				break;

			}
			//se è un nuod con un solo figlio sinistro
			if ((TreeLeft(tmp) && !TreeRight(tmp) && TreeIsLeaf(TreeLeft(tmp)))) {
				tmp->value = tmp->left->value;
				TreeDelete(tmp->left);
				tmp->left = NULL; //attenzione 
				break;
			}
			//se è un nodo e ha due figli

			else {
				Node* s = tmp;
				if (!TreeIsEmpty(tmp->right)) {
					s = TreeRight(tmp);
				}
				
				while (1) {
					s = TreeLeft(s);
					if (TreeIsEmpty(s->left)) {
						tmp->value = s->value;
						TreeDelete(s->left);
						s->left = NULL;
						break;
						
					}
				}
				break;
			}
		}
	}
	return n;
}

