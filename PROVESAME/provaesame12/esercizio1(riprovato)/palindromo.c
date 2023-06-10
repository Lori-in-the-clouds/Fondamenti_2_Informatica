#include <stdbool.h>
#include <string.h>
void rec(const char* str, int starter, int finisher,bool *ris) {
	if (starter >= finisher) {
		return;
	}
	if (str[starter] != str[finisher]) {
		*ris = false;
		return;
	}
	return rec(str, starter + 1, finisher - 1,ris);
}
bool IsPalindromo(const char* str) {
	if (str == NULL) return false;
	int n = strlen(str);
	bool ris = true;
	rec(str, 0, n - 1,&ris);
	return ris;
}