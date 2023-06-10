#include "elemtype.h"
#include "tree.h"
#include <float.h>
#include <limits.h>
void Cont_Node(const Node* t, int* cont1) {
	if (TreeIsEmpty(t)) return;
	cont1[0]++;
	Cont_Node(TreeLeft(t), cont1);
	Cont_Node(TreeRight(t), cont1);
}
void Trov_val(const Node* t, int *i,int *ris,int j) {
	if (TreeIsEmpty(t)) return;
	Trov_val(TreeLeft(t), i,ris,j);
	i[0]++;
	if (i[0] == j) *ris = *TreeGetRootValue(t);
	Trov_val(TreeRight(t), i,ris,j);
}
double Mediano(const Node* t) {
	if (TreeIsEmpty(t)) return DBL_MAX;
	int cont1 = 0;
	Cont_Node(t, &cont1);
	int n = 0;
	int a = 0;
	int b = 0;
	int s = 0;
	if ((int)cont1 % 2 == 1) {
		n = cont1 / 2;
		Trov_val(t,&s, &a, n+1);
		return a;
	}
	else {
		n = cont1 / 2;
		Trov_val(t, &s, &a, n);
		n++;
		s = 0;
		Trov_val(t, &s, &b, n);
		return (double)(a + b) / 2.;
	}
}

//int main(void) {
//	//ALBERO BST
//  const ElemType e[] = { 0,1,2,3,4,5,6,7,8 };
//  Node* t = TreeCreateRoot(
//	  e + 4,
//	  TreeCreateRoot(e + 2, TreeCreateRoot(e + 1, NULL, NULL), TreeCreateRoot(e + 3, NULL, NULL)),
//	  TreeCreateRoot(e + 6, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 7, NULL, NULL))
//  );
//
//  Node* s = TreeCreateRoot(
//	  e + 7,
//	  TreeCreateRoot(e + 4, TreeCreateRoot(e + 2, TreeCreateRoot(e + 1, NULL, NULL), NULL), TreeCreateRoot(e + 5, NULL, NULL)),
//	  TreeCreateRoot(e + 8, NULL, NULL)
//  );
//  TreeWriteInOrder(s, stdout);
//  Mediano(s);
//
//}