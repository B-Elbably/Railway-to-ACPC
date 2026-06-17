#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<int> primes;
const int N = 1e6 + 5;
bool spf[N];
bool ans[N];
int l, r;

void build() {
    for (int i = 2; i < N; i++) spf[i] = true;
    for (int i = 2; i < N; i++) {
        if (!spf[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j < N; j += i) {
            spf[j] = false;
        }
    }
}

void solve() {
    cin >> l >> r;
    int len = r - l + 1;
    for (int i = 0; i < len; i++) ans[i] = true;
    if (l == 1) ans[0] = false;

    for (int p : primes) {
        if (p * p > r) break;
        int start = ((l + p - 1) / p) * p;
        if (start < p * p) start = p * p;
        for (int j = start; j <= r; j += p) {
            ans[j - l] = false;
        }
    }

    for (int i = 0; i < len; i++) {
        if (ans[i]) {
            cout << l + i << endl;
        }
    } cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1; cin >> t;
    while (t--) solve();
    return 0;
}