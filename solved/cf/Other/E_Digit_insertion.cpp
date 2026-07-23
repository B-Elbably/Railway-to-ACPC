#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

string s;
vector<string> result;
int n;

void brute(int i, int j, string t) {
    if (i + (n - j) > 11) return;
    if (i == 11) {
        if (j == n) {
            result.push_back(t);
        }
        return;
    }
    brute(i + 1, j, t + '1');
    brute(i + 1, j, t + '9');
    if (j < n)
        brute(i + 1, j + 1, t + s[j]);
}

void solve() {
    cin >> s;
    n = s.size();
    if (n > 11) {
        cout << 0; 
        return;
    }
    set<string> ans;
    brute(0, 0, "");
    for (string x: result) {
        if (x[0] != '1') continue;
        if (x[1] == '0') continue;
        if (x[2] != '9') continue;
        ans.insert(x);
    }
    cout << ans.size() << "\n";
    // sort(all(ans));
    for (auto x: ans) cout << x << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}


// 23456789

// 17
// 11923456789
// 12913456789
// 12931456789
// 12934156789
// 12934516789
// 12934561789
// 12934567189
// 12934567819
// 12934567891
// 12934567899
// 12934567989
// 12934569789
// 12934596789
// 12934956789
// 12939456789
// 12993456789
// 19923456789
