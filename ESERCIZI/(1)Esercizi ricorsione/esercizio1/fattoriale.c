static unsigned long long FattorialeRec(int n) {
	if (n == 1) {
		return n;
	}
	else {
		return FattorialeRec(n - 1) * n;
	}
}
unsigned long long Fattoriale(int n) {
	if (n ==0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	FattorialeRec(n);
}