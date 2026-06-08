#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;

void solve() {
    int x;
    cin >> x;
    vector<int> ans;
    for (int i = 1; i <= N; ++i) {
        int res = i * i;
        res += x;
        int d = sqrt(res);
        if (d * d == res) ans.push_back(d);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}


