#include "elemtype.h"
#include "tree.h"
void rec(Node** t, const ElemType* cut_value) {
	if (TreeIsEmpty(*t)) return;
	if (!TreeIsEmpty((*t)->left)) {
		if (ElemCompare(&(*t)->left->value, cut_value) == 0) {
			Node* tmp = *t;
			TreeDelete(tmp->left);
			tmp->left = NULL;
		}
	}
	if (!TreeIsEmpty((*t)->right)) {
		if (ElemCompare(&(*t)->right->value, cut_value) == 0) {
			Node* tmp = *t;
			TreeDelete(tmp->right);
			tmp->right = NULL;
		}
	}
	rec(&(*t)->left, cut_value);
	rec(&(*t)->right, cut_value);
}
Node* TreePrune(Node* t, const ElemType* cut_value) {
	if (TreeIsEmpty(t)) return TreeCreateEmpty();
	if (ElemCompare(TreeGetRootValue(t), cut_value) == 0) return TreeCreateEmpty();
	rec(&t, cut_value);
	return t;
}

//int main(void) {
//	int e[] = { 0,1,2,3,4,5,6,7,8};
//	Node* t = TreeCreateRoot(
//		e + 2,
//		TreeCreateRoot(e + 3, TreeCreateRoot(e+4,TreeCreateRoot(e+8,NULL,NULL),TreeCreateRoot(e+1,NULL,NULL)), NULL),
//		TreeCreateRoot(e + 7, TreeCreateRoot(e + 4, TreeCreateRoot(e, NULL, NULL), TreeCreateRoot(e + 1, NULL, NULL)), NULL)
//		);
//	ElemType cut_value = 3;
//	Node* ris = TreePrune(t, &cut_value);
//
//}