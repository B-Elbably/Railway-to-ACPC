#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
vector<int> a;
const int N = 5e3 + 5;
int cnt[N];
int memo[N];

int go(int mex) {
    if (mex == 0) return mex;
    int &ret = memo[mex];
    if (~ret) return ret;
    ret = 1e18;
    for (int i = 0; i < mex; i++) {
        int cost = (cnt[i] - 1) * mex + i;
        ret = min(ret, cost + go(i));
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    int mex = 0;
    int i = 0;
    for (; i < n; i++) {
        if (a[i] > mex) break;
        mex += (a[i] == mex);
        cnt[a[i]]++;
    }
    a.resize(i);
    n = a.size();
    // cout << mex << endl;
    cout << go(mex) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
