int Rec(int m, int n) {
	if (n == 0) {
		return m;
	}
	Rec(n, m % n);
}
int MCD(int m, int n) {
	if (m < n) {
		int tmp = m;
		int m = n;
		int n = tmp;
	}
	return Rec(m, n);
}