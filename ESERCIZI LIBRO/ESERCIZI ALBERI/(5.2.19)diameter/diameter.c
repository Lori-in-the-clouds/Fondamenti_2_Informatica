#include "tree.h"
#define MAX(a,b) (((a)>(b))?(a):(b))
	/*     12
		  /  \
		 /    \
		4      21
	   / \    / \
	  /   \  5  18
	 0     2
	/ \   /
	77  8 9*/
void Rec(const Node* t, int ris, int* max) {
	if (TreeIsEmpty(t)) {
		if (ris > *max) {
			*max = ris;
		}
		return;
	}
	Rec(TreeLeft(t), ris+1, max);
	Rec(TreeRight(t), ris +1, max);
}
int TreeHight(const Node* t) {
	int max = 0;
	Rec(t, 0, &max);
	return max;
}
int Diameter(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	//calcoliamo i diametri
	int max = 0;
	int d_l = Diameter(TreeLeft(t));
	int d_r = Diameter(TreeRight(t));

	int h_l = TreeHight(TreeLeft(t));
	int h_r = TreeHight(TreeRight(t));

	return MAX(MAX(d_l,d_r), h_l + 1 + h_r);
}