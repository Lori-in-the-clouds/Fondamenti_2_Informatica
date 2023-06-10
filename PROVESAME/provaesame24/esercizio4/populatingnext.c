#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

void Rec(Node* t, Node** prev) {
	if (TreeIsEmpty(t)) {
		return;
	}
	Rec(TreeLeft(t), prev);
	if (*prev != t) {
		(*prev)->next = t;
	}
	*prev = t;
	Rec(TreeRight(t), prev);
}
Node* Primo(Node* t) {
	if (TreeIsEmpty(TreeLeft(t))) return t;
	else return Primo(TreeLeft(t));
}
void PopulatingNext(Node* t) {
	Node* prev = Primo(t);
	Rec(t, &prev);
}