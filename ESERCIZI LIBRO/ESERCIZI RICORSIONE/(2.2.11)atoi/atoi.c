#include <string.h>
#include <math.h>
int atoiRec(const char* str,int i,int size,int res) {
	if (size == 0) {
		return res;
	}
	res += (str[i] - 48) * pow(10, size-1);
	atoiRec(str, i+1,size-1,res);
}
int atoi(const char* str) {
	int ris = 0;
	for (int i = 1; i < strlen(str); i++) {
		if ((str[i] < 48 || str[i]>57)) {
			return 0;
		}
	}
	if (str[0] != '+' && str[0] != '-' && str[0] != '0' && (str[0] < 48 || str[0]>57)) {
		return 0;
	}
	if (str[0] == '+' || str[0] == '0') {
		return atoiRec(str + 1, 0, strlen(str) - 1, ris);
	}
	if (str[0] == '-') {
		return -1 * atoiRec(str + 1, 0, strlen(str) - 1, ris);
	}
	
	
	return atoiRec(str, 0, strlen(str), ris);
}