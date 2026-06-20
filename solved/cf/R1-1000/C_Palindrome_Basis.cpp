#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> palindromes;
const int MOD = 1e9 + 7;
const int N = 4e4 + 5; 
int dp[N];
void build() {
    for (int i = 1; i <= N; ++i) {
        string s = to_string(i);
        string t = s;
        reverse(all(t));
        if (s == t) {
            palindromes.push_back(i);
        }
    }
    dp[0] = 1;
    for (int p : palindromes) {
        for (int i = p; i <= N; ++i) {
            dp[i] = (dp[i] + dp[i - p]) % MOD;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << endl;
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
