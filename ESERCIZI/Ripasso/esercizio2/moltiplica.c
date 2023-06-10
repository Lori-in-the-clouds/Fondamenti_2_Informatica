#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non è corretto. Sintassi del programma: \"mul <a> <b>\"");
		return 1;
	}
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int ris = a * b;
	fprintf(stdout,"%i", ris);
	return 0;



 }