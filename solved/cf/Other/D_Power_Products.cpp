#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int fast_pow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

const int N = 1e5;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> target;
    for (int x = 1; x <= N; ++x) {
        target.push_back(fast_pow(x, k));
        if (target.back() >= N * N) break;
    }
    cout << target.size() << endl;

    int ans = 0;
    if (k >= 3) {
        map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            for (int t : target) {
                if (t % a[i] == 0) {
                    ans += freq[t / a[i]];
                }
            }
            freq[a[i]]++;
            cout << i << " " << ans << endl;
        }
    }else {
        sort(all(target));
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
