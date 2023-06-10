#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
void rec(int n,int len) {
	int som = 0;
	for (int j = 0; j < len; j++) {
		som += (int)(n / pow(10, j)) % 10;
	}
	if (som / 10 == 0) {
		printf("%d", som);
		return;
	}
	int num = som;
	int j = 0;
	while (num > 0) {
		num /= 10;
		j++;
	}
	rec(som, j);
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	rec(n,strlen(argv[1]));
	return 0;

}