double FattorialeRec(int n) {
	if (n == 0) {
		return 1;
	}
	return FattorialeRec(n - 1) * n;
}

double Fattoriale(int n) {
	if (n < 0) {
		return -1;
	}
	FattorialeRec(n);
 }
