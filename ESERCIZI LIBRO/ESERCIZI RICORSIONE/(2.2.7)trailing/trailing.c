void TrailingZerosRec(int n, int i, int* ris) {
	int tmp = i;
	while (tmp % 2 == 0 && tmp!=0) {
		tmp /= 2;
		ris[0]++;
	}
	if (i == n) return;

	TrailingZerosRec(n, i + 1, ris);
}
int TrailingZeros(unsigned int n) {
	if (n <= 0) return 0;
	int ris = 0;
	TrailingZerosRec(n, 1,&ris);
	return ris;
}