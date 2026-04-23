#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int MOD = 998244353;
void brute() {
    int N = 100;
    vector<int> pref(N + 5);
    for (int i = 1; i < N; ++i){
        pref[i] = i ^ pref[i - 1];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; ++j){
            if (pref[j] - pref[i - 1]) continue;
            cout << i << " " << j << endl;
            break;
        }
    }
}

int n, x;
int calc(int l, int n, int md) {
    if (l > n) return 0;
    while (l % 4 != md) l++;
    if (l > n) return 0;
    return n - l / 4 + 1;
}
void solve() {
    cin >> n >> x;
    // int ans = 0;
    int L0 = (1 + x / 4) % MOD;
    int R0 = ((n + 1) / 4 - x / 4) % MOD;
    int L1 = ((x + 2) / 4) % MOD;
    int R1 = ((n + 3) / 4 - (x + 2) / 4) % MOD;
    int ans = (L0 * R0) % MOD;
    ans = (ans + L1 * R1) % MOD;
    
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // brute();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}

// 1 -> 3 (+= 4), next r%4= 3
// 2 -> 5 (+= 4), next r%4=1
// 4 -> 7 (+= 4)
// 6 -> 9 (+= 4)