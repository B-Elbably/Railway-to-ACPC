#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 1e6 + 1;
vector<int> phi(N + 1);
vector<bool> prime(N + 1);
void precompute() {
    for (int i = 0; i <= N; i++) {
        phi[i] = i;
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (int j = i; j <= N; j += i) {
                prime[j] = false;
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int pref[N + 1];
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<pair<int, int>>> res(n + 1);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int a = i * j;
            int b = j - i;
            if (a % b) continue;
            // cout << a << " " << b;
            ans++;
            res[j].push_back({i , j});
            pref[j]++;
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << res[i].size() << "\n--\n";
    //     for (auto [u, v]: res[i]) cout << u << " " << v << endl;
    //     cout << "--\n\n";
    // }

    // int sum = 0;
    // // for (int i = 2; i <= n; ++i) sum += n - phi[i];
    // for (int j = 2; j <= n; ++j) {
    //     int add = 0;
    //     for (int o: factors[j]) {
    //         int i = j - o;
    //         if (i == 0) continue;
    //         int a = i * j;
    //         int b = o;
    //         // if (a <= 0) continue;
    //         if (b <= 0) continue;
    //         if (a % b) continue;
    //         cout << i << " " << j << '\n';
    //         add++;
    //         sum++;
    //     }
    //     cout << j << " " << add << " *\n";
    // }
    // cout << ans << endl;
    // cout << sum << endl;
    for (int i = 1; i <= n; ++i) cout << i << " " << pref[i] << " " <<  i - phi[i] << " " << max(1LL, (i - phi[i]) / 4) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
