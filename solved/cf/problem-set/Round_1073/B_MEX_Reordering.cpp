#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int mex(int l , int r , vector<int>& a) {
    set<int> s;
    for (int i = l; i <= r; ++i) {
        s.insert(a[i]);
    }
    int mex = 0;
    while (s.count(mex)) ++mex;
    return mex;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    for (int i = 0; i < n - 1; ++i) {
        if (mex(0 , i, a) == mex(i + 1, n - 1, a)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
