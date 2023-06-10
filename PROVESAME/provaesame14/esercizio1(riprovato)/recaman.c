void rec(int n,int i,int *an) {
	if (i == 1) {
		an[0] = 1;
	}
	if (i == n) {
		return;
	}
	else if (an[0] % i == 0) {
		an[0] = an[0] / i;
	}
	else {
		an[0] = i * an[0];
	}
	rec(n, i + 1, an);
}
int Recaman(int n) {
	if (n < 1) return -1;
	int an = 0;
	rec(n, 1,&an);
	return an;
}