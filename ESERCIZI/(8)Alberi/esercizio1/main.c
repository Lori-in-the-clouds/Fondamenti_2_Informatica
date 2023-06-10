#include "tree.h"
#include <stdlib.h>
extern Node* BstInsert(const ElemType* e, Node* n);
extern Node* BstInsertRec(const ElemType* e, Node* n);
int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* n = TreeCreateEmpty();
	n = TreeCreateRoot(
		e + 4,
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 1, TreeCreateRoot(e + 1, NULL, NULL), TreeCreateRoot(e + 2, NULL, NULL)), NULL),
		TreeCreateRoot(e + 7, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 8, NULL, NULL))
	);
	int* r = 6;
	Node* ris = TreeCreateEmpty();
	ris =BstInsertRec(&r, n);
			

}
//	     4              4        
//      / \            / \           
//     /   \          /   \        
//    3     7        10    7         
//   /     / \      /     / \       
//  1     5   8    1     5   8      
// / \            / \             
//1   2         1   2
