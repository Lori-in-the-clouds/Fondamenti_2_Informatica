#include "tree.h"
#include <stdlib.h>
#include <crtdbg.h>
extern const Node* Predecessore(const Node* t, const ElemType* e);
extern const Node* Successore(const Node* t, const ElemType* e);
int main(void) {
    ElemType* e = malloc(8 * sizeof(int));
    for (int i = 0; i < 8; i++) {
        e[i] = i;
    }
    Node* t = TreeCreateRoot(
        e + 4,
        TreeCreateRoot(e + 2, TreeCreateRoot(e + 1, NULL, NULL), TreeCreateRoot(e + 3, NULL, NULL)),
        TreeCreateRoot(e + 6, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 7, NULL, NULL))
    );

  /*  Node* s = TreeCreateRoot(
        e + 7,
        TreeCreateRoot(e + 4, TreeCreateRoot(e + 2, TreeCreateRoot(e + 1, NULL, NULL), NULL), TreeCreateRoot(e + 5, NULL, NULL)),
        TreeCreateRoot(e + 8, NULL, NULL)
    );*/
    ElemType c = 4;
    //Node* ris = Predecessore(t, &c);
    Node* ris = Successore(t, &c);
    TreeDelete(ris);
    free(e);
    //TreeDelete(s);
    _CrtDumpMemoryLeaks();
    return 0;

}