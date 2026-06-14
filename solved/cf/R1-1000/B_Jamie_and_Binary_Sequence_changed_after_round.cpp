#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    map<int, int> mp;
    // vector<int> mp(64);
    for (int i = 60; i >= 0;--i) {
        if ((1LL << i) & n) {
            pq.push(i);
            mp[i]++;
        }
    }
    if (pq.size() > k) {
        cout << "No";
        return;
    }
    while (pq.size() < k) {
        int x = pq.top(); pq.pop();
        mp[x - 1] += 2;
        mp[x]--;
        pq.push(x - 1);
        pq.push(x - 1);
    }
    
    cout << "Yes\n";
    int mx = pq.top();
    int mn = 20;
    for (int i = -mn; i < mx; ++i) {
        mp[i + 1] += mp[i] / 2;
        mp[i] %= 2;
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> qq;
    for (int i = mx; i >= -mn; --i) {
        for (int j = 0; j < mp[i]; ++j) {
            qq.push(i);
        }
    }
    while (qq.size() < k) {
        int x = qq.top(); qq.pop();
        qq.push(x - 1);
        qq.push(x - 1);
    }
    while (!qq.empty()) {
        ans.push_back(qq.top());
        qq.pop();
    }
    reverse(all(ans));
    for (int x: ans) cout << x << " ";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
