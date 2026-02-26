#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

vector<int> get_divisors(int x) {
    vector<int> divisors;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divisors.push_back(i);
            if (i != x / i) divisors.push_back(x / i);
        }
    }
    return divisors;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m + 1);
    for (auto &x : a) cin >> x;
    sort(all(a));
    int ans = 1e9;
    int l = 0;
    int cnt = m;
    for (int r = 0; r < n; r++) {
        vector<int> divisors = get_divisors(a[r]);
        for (auto d : divisors) {
            if (d > m) continue;
            if (b[d] == 0) cnt--;
            b[d]++;
        }
        while (cnt == 0) {
            ans = min(ans, a[r] - a[l]);
            vector<int> ldivisors = get_divisors(a[l]);
            for (auto d : ldivisors) {  
                if (d > m) continue;
                b[d]--;
                if (b[d] == 0) cnt++;
            }
            l++;
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
// 3 4 5 6 7

// 1 2 3 4 5 6 7
