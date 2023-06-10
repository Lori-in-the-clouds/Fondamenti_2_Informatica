#include "elemtype.h"
#include "tree.h"
void rec(const ElemType* v, size_t v_size, Node** ris) {
	for (int j = 0; j < v_size; j++) {
		Node* tmp = *ris;
		while (1) {
			//devo andare a sinistra
			if (ElemCompare(TreeGetRootValue(tmp), &v[j]) == 0) break;
			if (ElemCompare(TreeGetRootValue(tmp), &v[j]) > 0) {
				if (TreeIsEmpty(TreeLeft(tmp))) {
					tmp->left = TreeCreateRoot(&v[j], NULL, NULL);
					break;
				}
				else {
					tmp = TreeLeft(tmp);
				}
			} 
			//vado a destra
			else {
				if (TreeIsEmpty(TreeRight(tmp))) {
					tmp->right = TreeCreateRoot(&v[j], NULL, NULL);
					break;
				}
				else {
					tmp = TreeRight(tmp);
				}
			}
		}
	}
}
Node* Vector2Bst(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size <= 0) return TreeCreateEmpty();
	Node* ris = TreeCreateRoot(v, NULL, NULL);
	rec(v + 1, v_size-1, &ris);
	return ris;

}

int main(void) {
	ElemType v[] = { 8,2,4,5,2,1,9 };
	Node* ris = Vector2Bst(v, sizeof(v) / sizeof(ElemType));
	TreeWriteInOrder(ris, stdout);
}