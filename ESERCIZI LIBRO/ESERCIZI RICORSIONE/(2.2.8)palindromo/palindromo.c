#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool palindromoRec(const char* str,size_t i1,size_t i2) {
	if (str[i1] != str[i2]) {
		return false;
	}
	if (i1 == i2 || (i2 == strlen(str)-1 && i1 == 0)) {
		return true;
	}
	palindromoRec(str, i1 - 1, i2+1);
}
bool palindromo(const char* str) {
	if (str == NULL) {
		return false;
	}
	if (str == "") {
		return true;
	}
	return palindromoRec(str,strlen(str)-1,0);
}