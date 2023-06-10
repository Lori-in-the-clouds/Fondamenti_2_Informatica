#include "tree.h"
#include <stdio.h>
void TreeMorrisInOrder(Node* t) {
	if (TreeIsEmpty(t)) return TreeCreateEmpty();
	Node* curr = t;
	while (!TreeIsEmpty(curr)) {
		//se ha figlio sinistro non NULL
		if (!TreeIsEmpty(TreeLeft(curr))) {
			//trovo il suo predecessore  
			Node* tmp = curr->left;				
			while (!TreeIsLeaf(tmp) && tmp->right != curr) {
				tmp = TreeRight(tmp);
			}
			//c'è gia il collegamento???
			if (tmp->right == curr) {			
				tmp->right = NULL;
				printf("%d ", *TreeGetRootValue(curr));
				curr = TreeRight(curr);
			}
			//altrimenti mettiamo il collegamento
			else {
				tmp->right = curr;
				curr = TreeLeft(curr);
			}
		}
		//ha il figlio sinistro NULL
		if (TreeIsEmpty(TreeLeft(curr))) {
			printf("%d ", *TreeGetRootValue(curr));
			curr = TreeRight(curr);
		}
	}
	return;
}
int main(void) {
	int e[] = { 0,1,2,3,4,5,6,7,8 };
	Node* t = TreeCreateRoot(
		e + 2,
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 4, TreeCreateRoot(e + 8, NULL, NULL), TreeCreateRoot(e + 1, NULL, NULL)), NULL),
		TreeCreateRoot(e + 7, TreeCreateRoot(e + 4, TreeCreateRoot(e, NULL, NULL), TreeCreateRoot(e + 1, NULL, NULL)), NULL)
	);
	TreeMorrisInOrder(t);

}