#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ContaOccorrenze(const char* filename, const char* str) {
	FILE* f = fopen(filename, "rt");
	int ris = 0;
	int contatore = 0;
	// controllo f 
	if (f == NULL) {
		return 0;
	}
	//controllo str
	if (str == NULL) {
		return 0;
	}
	int num = strlen(str);
	int j = 0;
	while (1) {
		char s = 0;
		size_t turn1 = fscanf(f, "%c", &s);
		if (turn1 == EOF) {
			break;
		}
		if (s == str[0]) {
			//controlliamo tutte le altre lettere
			for (int i = 1; i < num; i++) {
				turn1 = fscanf(f, "%c", &s);
				if (turn1 == EOF) {
					break;
				}
				if (s == str[i]) {
					contatore++;
				}
				else {
					break;
				}

			}
			if (contatore == num-1) {
				ris++;
				contatore = 0;




			}
		}
		
	}
	fclose(f);
	return ris;
}