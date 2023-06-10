#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
void rec(int n, int* ris,bool *control,int som) {
	if (som == n) return;
	if (som > n) {
		*control = false;
		return;
	}
	ris[0]++;
	rec(n, ris, control, (int)pow(4, ris[0]));
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	int ris = -1;
	bool control = true;
	rec(n, &ris, &control,0);
	if (!control) {
		printf("!p4");
		return 0;
	}
	printf("4^%d = %d", ris,n);
	return 0;
}