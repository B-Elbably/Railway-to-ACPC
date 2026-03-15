#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int c, d, x;
const int N = 2e7 + 5;

vector<int> spf(N, 0);
void build() {
    // for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            for (int j = i; j < N; j += i) {
                spf[j]++;
            }
        }
    }
}

int calc(int g) {
    int res = x / g + d;
    if (res % c) return 0;
    res /= c;
    return 1LL << spf[res];
}

void solve() {
    cin >> c >> d >> x;
    int ans = 0;
    for (int g = 1; g * g <= x; g++) {
        if (x % g == 0) {
            ans += calc(g);
            if (g * g == x) continue;
            ans += calc(x / g);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
