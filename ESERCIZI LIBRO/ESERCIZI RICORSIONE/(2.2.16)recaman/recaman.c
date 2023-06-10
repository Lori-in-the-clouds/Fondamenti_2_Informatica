int rec(int n, int i, int m) {
	if (i == n) return m;
	if (m % i == 0) {
		rec(n, i + 1, m / i);
	}
	else {
		rec(n, i + 1, m * i);
	}
	}
	int Recaman(int n) {
		if (n < 1) return -1;
		return rec(n, 1, 1);
	}


