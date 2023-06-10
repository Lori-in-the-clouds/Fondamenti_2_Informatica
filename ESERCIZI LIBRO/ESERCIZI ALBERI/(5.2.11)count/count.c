#include "tree.h"
#include <stdbool.h>
void TreeCountNodesRec(const Node* t, int* internal, int* external) {
	if (TreeIsEmpty(t)) return;
	if (TreeIsLeaf(t)) {
		external[0]++;
		return;
	}
	else {
		internal[0]++;
	}
	TreeCountNodesRec(TreeLeft(t), internal, external);
	TreeCountNodesRec(TreeRight(t), internal, external);
}
void TreeCountNodes(const Node* t, int* internal, int* external) {
	TreeCountNodesRec(t, &(*internal), &(*external));
	return;
}