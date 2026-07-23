#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 5;
int spf[N];
int ans[N];
int freq[N];
void build() {
    for (int i = 1; i < N; ++i) spf[i] = i;
    for (int i = 2; i * i < N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
void add(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans[i]++;
            if (i * i != n) ans[n / i]++;
        }
    }
}

void remove(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans[i]--;
            if (i * i != n) ans[n / i]--;
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x, freq[x]++;
    for (int i = 1; i < N; ++i) {
        if (freq[i]) add(freq[i]);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x;
            i--;
            if (a[i] == x) continue;
            remove(freq[a[i]]);
            remove(freq[x]);
            freq[a[i]]--;
            freq[x]++;
            add(freq[a[i]]);
            add(freq[x]);
            a[i] = x;
        } else {
            int p; cin >> p;
            cout << ans[p] << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
