// Thanks for knowledge: dinkelbach
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n, k;
vector<int> v, w;

pair<int, int> dinkelbach() {
    vector<int> id(n);
    iota(all(id), 0);
    double lambda = 0;
    int a = 0, b = 1;

    while (true) {
        nth_element(id.begin(), id.begin() + k, id.end(), [&](int i, int j) {
            return v[i] - lambda * w[i] > v[j] - lambda * w[j];
        });

        int sv = 0, sw = 0;
        for (int i = 0; i < k; i++) {
            sv += v[id[i]];
            sw += w[id[i]];
        }
        if (sv == a && sw == b) break;
        a = sv; b = sw;
        lambda = (double)sv / sw;
    }

    return {a, b};
}
void solve() {
    cin >> n >> k;
    v.resize(n); w.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
    auto [a, b] = dinkelbach();
    int g = gcd(a, b);
    cout << a / g << " " << b / g << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
