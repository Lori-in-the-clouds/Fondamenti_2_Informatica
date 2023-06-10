#include "tree.h"
bool Isomorfi(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) return true;
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) return false;
	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
		return false;
	}
	return (Isomorfi(TreeLeft(t1), TreeLeft(t2)) && Isomorfi(TreeRight(t1), TreeRight(t2))) || (Isomorfi(TreeLeft(t1), TreeRight(t2)) && Isomorfi(TreeRight(t1), TreeLeft(t2)));
}
//&& e || permettono di filtrare i true e false
//i primi due controllano che il caso in cui i nodi siano tutti uguali 
//i secondi controllano che ci siano dei nodi isomorfi
// se anche uno dei due gruppi è true, allora tutto è true