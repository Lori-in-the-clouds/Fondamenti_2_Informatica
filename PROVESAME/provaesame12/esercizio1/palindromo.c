#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool IsPalindromoRec(const char* str, int n,int i) {
	 if (n == -1) {
		return true;
	 }
	 if (str[n] != str[i]) return false;
	 IsPalindromoRec(str, n - 1, i + 1);
}

bool IsPalindromo(const char* str) {
	if (str == "" || str == NULL) return false;
	int n = (int)strlen(str);
	return IsPalindromoRec(str, n - 1, 0);
	
}
