#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1000;
vector<tuple<int, int, int>> triples;
vector<int> vals = {};
void brute() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1 ; j <= N; ++j) {
            int k1 = i * i + j * j;
            k1 = sqrt(k1);
            if (k1 * k1 != i * i + j * j) continue;
            int k2 = i * i - j;
            if (k1 != k2) continue;
            if (k1 > N) continue;
            triples.emplace_back(i, j, k1);
        }
    }
    sort(all(triples), [](auto &a, auto &b) {
        return get<2>(a) < get<2>(b);
    });
    for (auto [a, b, c] : triples) {
        cout << a << " " << b << " " << c << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    n = (n - 1) / 4; 
    int ans = sqrt(n);
    while ( (ans + 1) * (ans + 1) < n) ans++;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // brute();
    int t = 1;
    cin >> t; 
    while (t--) solve();
}
