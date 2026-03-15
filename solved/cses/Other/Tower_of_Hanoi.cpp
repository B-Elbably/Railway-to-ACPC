#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;
    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    hanoi(n - 1, aux, to, from);
}

void solve() {
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << endl;
    hanoi(n, 1, 3, 2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}