#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
const int N = 5e3 + 5;
int memo[N][N];
string s, t;

 
int dp(int i = 0, int j = 0) {
    if (i == s.size() && j == t.size()) 
        return max((int)s.size() - i, (int)t.size() - j);
    int& ret = memo[i][j];
    if (~ret) return ret;
    ret = 1e9;
    if (i < s.size()) {
        ret = min(ret, (s[i] - 'a' + 1) + dp(i + 1, j));
    }
    if (j < t.size()) {
        ret = min(ret, (t[j] - 'a' + 1) + dp(i, j + 1));
    }
    if (i < s.size() && j < t.size()) {
        ret = min(ret, abs(s[i] - t[j]) + dp(i + 1, j + 1));
    }     
    return ret;
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> s >> t;
    cout << dp() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}