#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e7 + 5;
int spf[N];
void build() {
    for (int i = 1; i < N; ++i) spf[i] = i;
    for (int i = 2; i * i < N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > p) break;
        p += spf[a[i]];
        ans++;
    }
    cout << ans << " " << p << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
