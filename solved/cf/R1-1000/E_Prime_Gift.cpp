#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
vector<int> ans1, ans2;
vector<int> one, two;
const int N = 1e18;
// vector<int> res;

void dfs1(int idx, int val) {
    ans1.push_back(val);
    for (int i = idx; i < one.size(); i++) {
        if (val <= N / one[i]) {
            dfs1(i, val * one[i]);
        }
    }
}

void dfs2(int idx, int val) {
    ans2.push_back(val);
    for (int i = idx; i < two.size(); i++) {
        if (val <= N / two[i]) {
            dfs2(i, val * two[i]);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(all(a));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) one.push_back(a[i]);
        else two.push_back(a[i]);
    }
    int k; cin >> k;
    dfs1(0, 1);
    dfs2(0, 1);
    sort(all(ans1));
    sort(all(ans2));
    // res.erase(unique(all(res)), res.end());
    // sort(all(res));
    // cout << res[--k] << endl;
    int l = 1, r = N, ans = N;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int cnt = 0;
        // for (int x : ans1) {
        //     if (x > mid) break;
        //     int need = mid / x;
        //     cnt += distance(ans2.begin(), upper_bound(all(ans2), need));
        // }
        int j = ans2.size() - 1;
        
        for (int i = 0; i < ans1.size(); i++) {
            if (ans1[i] > mid) break;
            while (j >= 0 && ans2[j] > mid / ans1[i]) {
                j--;
            }
            cnt += (j + 1);
        }
        if (cnt >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        } 
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
