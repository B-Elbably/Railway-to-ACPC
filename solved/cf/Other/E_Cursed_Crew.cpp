#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int N = 2e5 + 5;
int vis[N];
int spf[N];
vector<int> idices[N];

void build (){
    for (int i = 1; i < N; ++i) spf[i] = i;
    for (int i = 2; i < N; ++i) {
        if (spf[i] != i) continue;
        for (int j = i; j < N; j += i) {
            if (spf[j] == j) spf[j] = i;
        }
    }
}

vector<int> factorize(int n) {
    vector<int> fac;
    while (n > 1) {
        fac.push_back(spf[n]);
        n /= spf[n];
    }
    if (n > 1) fac.push_back(n);
    return fac;
}

void solve() {
    // for (int i = 2; i <= 10; ++i) cout << spf[i]; cout << "\n";
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idices[a[i]].push_back(i);
    }
    sort(all(a));
    vector<vector<int>> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (vis[a[i]]) continue;
        vector<int> factors = factorize(a[i]);
        int m = factors.size();
        vector<int> res;
        for (int k = 0; k < (1LL << m); ++k) {
            int num = 1;
            for (int j = 0; j < m; ++j) {
                if ((k >> j) & 1) num *= factors[j];
            }
            if (idices[num].empty()) continue;
            vis[num] = 1;
            for (int idx: idices[num]){
                res.push_back(num);
            }
            idices[num].clear();
        }
        if (res.size()) ans.push_back(res);
    }
    cout << ans.size() << endl;
    for (vector<int> res: ans) {
        cout << res.size() << " ";
        for (int x: res) cout << x << " "; cout << endl;
    }
    // cout << (1 << 17) * 2e5;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
