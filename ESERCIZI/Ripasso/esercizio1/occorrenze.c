#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
	
	if (argc != 3) {
		printf("%s", "Il numero di parametri non è corretto. Sintassi del programma: \" occorrenze <s> <c>\"");
		return 1;
	}
	int ris = 0;
	size_t num = strlen(argv[1]);
	for (int i = 0; i < num; i++) {
		if (argv[1][i] == argv[2][0]) {
			ris++;
		
		}
	}
	printf("%i", ris);
	return 0;

}