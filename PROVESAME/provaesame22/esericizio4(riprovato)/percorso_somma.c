#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
void rec(Node* t, const ElemType* target,int som,bool *control) {
	if (TreeIsEmpty(t)) {
		if (som == *target) {
			control[0] = true;
		}
		return;
	}
	rec(TreeLeft(t), target,(*TreeGetRootValue(t))+ som,control);
	rec(TreeRight(t), target, (*TreeGetRootValue(t)) + som,control);
}
bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t) && *target == 0) return false;
	if (TreeIsEmpty(t)) return false;
	bool control = false;
	rec(t, target, 0, &control);
	return control;
}