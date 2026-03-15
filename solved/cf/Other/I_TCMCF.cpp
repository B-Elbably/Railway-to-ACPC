#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> positive, negative;
    int is_zero = 0;
    int mx = LLONG_MIN;
    for (int x : a) {
        if (x > 0) positive.push_back(x);
        else if (x < 0) {negative.push_back(x);mx = max(mx, x);}
        else is_zero = 1;
    }
    vector<int> ans;
    sort(all(positive));
    sort(all(negative));
    if (negative.size() & 1) negative.pop_back();
    for (int x: positive)  ans.push_back(x);
    for (int i = 0; i < negative.size(); i++){ 
        ans.push_back(negative[i]);
    }
    if (ans.size() == 0) {
        if (is_zero) ans.push_back(0);
        else if (mx != LLONG_MIN) ans.push_back(mx);
    }
    for (auto &x : ans) cout << x << " ";
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
