#include "tree.h"
#include <crtdbg.h>
#include <stdlib.h>
extern Node* DeleteBstNode(Node* n, const ElemType* key);
int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* n = TreeCreateEmpty();
	n = TreeCreateRoot(
		e + 4,
		TreeCreateRoot(e + 3, TreeCreateRoot(e + 1, TreeCreateRoot(e + 1, NULL, NULL), TreeCreateRoot(e + 2, NULL, NULL)), NULL),
		TreeCreateRoot(e + 7, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 8, NULL, NULL))
	);
	Node* t = TreeCreateEmpty();
	ElemType d[] = { 12,4,5 };
	t = TreeCreateRoot(
		d,
		TreeCreateRoot(d+1,NULL,TreeCreateRoot(d + 2, NULL, NULL)),
		NULL
	);
	const ElemType* c = 12;
	DeleteBstNode(t, &c);
	TreeDelete(n);
	_CrtDumpMemoryLeaks();
}
//	     4              4        
//      / \            / \           
//     /   \          /   \        
//    3     7        10    7         
//   /     / \      /     / \       
//  1     5   8    1     5   8      
// / \            / \             
//1   2         1   2