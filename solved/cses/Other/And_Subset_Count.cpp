#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 1 << 18;
int pw2[N];
void build() {
    pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> freq(N, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    for (int i = 0; i < 18; i++) {
        for (int mask = N - 1; mask >= 0; mask--) {
            if ((mask & (1 << i))) continue;
            freq[mask] += freq[mask | (1 << i)];    
        }
    }

    for (int i = 0; i < N; i++) {
        freq[i] = (pw2[freq[i]] - 1 + MOD) % MOD;
    }
    for (int i = 0; i < 18; i++) {
        for (int mask = N - 1; mask >= 0; mask--) {
            if ((mask & (1 << i))) continue;
            freq[mask] = (freq[mask] - freq[mask | (1 << i)] + MOD) % MOD;    
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << freq[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    while (t--) solve();
    return 0;
}