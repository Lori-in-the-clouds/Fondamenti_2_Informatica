#include <stdlib.h>
int QuozienteRec(size_t x, size_t y) {
	if (x / y == 0) {
		return 0;
	}
	return 1 + QuozienteRec(x - y, y);
}
int Quoziente(size_t x, size_t y) {
	if (y == 0) {
		return -1;
	} 
	return QuozienteRec(x, y);
}