#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAX = 1e7 + 5;
int spf[MAX];
void sieve() {
    for (int i = 2; i < MAX; i++) spf[i] = i;
    for (int i = 2; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

const int N = 2e5 + 5;
const int M = 200;
int pref[N][M];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            pref[i + 1][j] = pref[i][j];
        }
        cin >> a[i];
        if (a[i] == 1) continue;
        int ai = a[i];
        while (spf[ai] != ai) ai--;
        a[i] -= ai;
        pref[i + 1][a[i]]++;
    }
    while (q--) {
        int l, r;
        long long k;
        cin >> l >> r >> k;
        int ans = 0;
        for (int i = 0; i < M; i++) {
            int cnt = pref[r][i] - pref[l - 1][i];
            if (cnt * i <= k) {
                ans += cnt;
                k -= cnt * i;
            }
            else {
                ans += k / i;
                break;
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
