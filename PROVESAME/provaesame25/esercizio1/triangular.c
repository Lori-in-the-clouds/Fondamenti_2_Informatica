#include <stdio.h>
#include <stdlib.h>
int rec(int i) {
	if (i == 0) return 0;
	if (i == 1) return 1;
	if (i == 2) return 3;
	return 3 * rec(i - 1) - 3 * rec(i - 2) + rec(i - 3);
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	printf("%d",rec(n));
	return 0;

}