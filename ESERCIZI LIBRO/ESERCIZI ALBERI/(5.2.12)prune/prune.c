#include "tree.h"
void TreePruneRec(Node** t, const ElemType* cut_value,Node *past) {
	if (TreeIsEmpty(*t)) return;
	if (ElemCompare(TreeGetRootValue(*t), cut_value) == 0) {
		Node* tmp = past;
		TreeDelete(tmp->left);
		TreeDelete(tmp->right);
		tmp->left = NULL;
		tmp->right = NULL;
		return;
	}
	past = *t;
	TreePruneRec(&(*t)->left, cut_value,past);
	TreePruneRec(&(*t)->right, cut_value,past);
}
Node* TreePrune(Node* t, const ElemType* cut_value) {
	if (ElemCompare(&t->value, cut_value) == 0 || TreeIsEmpty(t)) {
		return TreeCreateEmpty();
	}
	TreePruneRec(&t, cut_value,NULL);
	return t;
}