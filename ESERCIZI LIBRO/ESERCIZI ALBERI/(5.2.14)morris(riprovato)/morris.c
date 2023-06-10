#include "elemtype.h"
#include "tree.h"
//void TreeMorrisInOrder(Node* t) {
//	Node* curr = t;
//	while (!TreeIsEmpty(curr)) {
//		//HA IL FIGLIO SINISTRO NULL
//		if (TreeIsEmpty(TreeLeft(curr))) {
//			printf("%d", *TreeGetRootValue(curr));
//			curr = TreeRight(curr);
//			continue;
//		}
//		//HA IL FIGLIO SINISTRO
//		if (!TreeIsEmpty(TreeLeft(curr))) {
//			//trovo il suo predecessore
//			Node* tmp = curr->left;
//			while (!TreeIsEmpty(TreeRight(tmp)) && tmp->right != curr) {
//				tmp = TreeRight(tmp);
//			}
//			//c'è già un collegamento
//			if (tmp->right == curr) {
//				tmp->right = NULL;
//				printf("%d", *TreeGetRootValue(curr));
//				curr = TreeRight(curr);
//			}
//			//non c'è mai stato un collegamento
//			else {
//				tmp->right = curr;
//				curr = TreeLeft(curr);
//			}
//		}
//		
//	}
//	return;
//}

void TreeMorrisInOrder(Node* t) {
	Node* curr = t;
	while (!TreeIsEmpty(curr)) {
		if (TreeIsEmpty(TreeLeft(curr))) {
			printf("%d ", *TreeGetRootValue(curr));
			curr = TreeRight(curr);
			continue;
		}
		if (!TreeIsEmpty(TreeLeft(curr))) {
			Node* tmp = TreeLeft(curr);
			while (!TreeIsEmpty(TreeRight(tmp)) && tmp->right != curr) {
				tmp = TreeRight(tmp);
			}
			if (tmp->right == curr) {
				tmp->right = NULL;
				printf("%d ", *TreeGetRootValue(curr));
				curr = TreeRight(curr);
			}
			else {
				tmp->right = curr;
				curr = TreeLeft(curr);
			}
		}
	}
	return;
}

int main(void) {
	int e[] = { 0,1,2,3,4,5,6,7,8};
	Node* t = TreeCreateRoot(
		e + 2,
		TreeCreateRoot(e + 3, TreeCreateRoot(e+4,TreeCreateRoot(e+8,NULL,NULL),TreeCreateRoot(e+1,NULL,NULL)), NULL),
		TreeCreateRoot(e + 7, TreeCreateRoot(e + 4, TreeCreateRoot(e, NULL, NULL), TreeCreateRoot(e + 1, NULL, NULL)), NULL)
		);
	TreeMorrisInOrder(t);
	TreeWriteInOrder(t,stdout);

}