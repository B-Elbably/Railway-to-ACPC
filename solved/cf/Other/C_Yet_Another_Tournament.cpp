#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &i:a) cin >> i;
    auto b = a;
    sort(b.begin(),b.end());
    int win = 0;
    for(int i = 0; i < n && m >= b[i]; i++){
        m -= b[i];
        win++;
    }
    if(win != 0 && win != n)
        if(m + b[win - 1] >= a[win])
            win++;
    cout << n + 1 - win << endl;
}

int main() {
	int t; cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}