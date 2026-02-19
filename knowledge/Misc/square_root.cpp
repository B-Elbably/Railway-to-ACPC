long long f(int x) { return (long long)x * x; }

int sqrt(int x) {
	int lo = 0;
	int hi = x;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid) <= x) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}