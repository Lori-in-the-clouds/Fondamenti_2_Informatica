#include "tree.h"
extern const ElemType* BstTreeMin(const Node* n);
extern const ElemType* TreeMin(const Node* n);
int main(void) {
	ElemType e[] = {0,1,2,3,4,-4,6,7,8,5};
	Node* n = TreeCreateEmpty();
	n = TreeCreateRoot(
		e + 4,
		TreeCreateRoot(e + 1, TreeCreateRoot(e + 5, TreeCreateRoot(e + 9, NULL, NULL), TreeCreateRoot(e, NULL, NULL)), TreeCreateRoot(e + 8, NULL, NULL)),
		TreeCreateRoot(e + 2, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 8, NULL, NULL))
			);
	TreeMin(n);
	return 0;
}
//	     4              4        
//      / \            / \           
//     /   \          /   \        
//    3     7        10    7         
//   /     / \      /     / \       
//  1     5   8    1     5   8      
// / \            / \             
//1   2         1   2