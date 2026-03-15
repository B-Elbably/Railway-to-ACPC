#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k, h;
    cin >> n >> k >> h;

    if (n < k) {
        cout << "impossible" << endl;
        return;
    }
    
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    int sz = 2;
    while (fib.back() < n) {
        fib.push_back(fib[sz - 1] + fib[sz - 2]);
        sz++;
    }
    priority_queue<int> pq;
    pq.push(n);
    while (pq.size() < k) {
        int x = pq.top();
        pq.pop();
        int idx = lower_bound(all(fib), x) - fib.begin();
        pq.push(fib[idx - 1]);
        pq.push(fib[idx - 2]);
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(all(ans));
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}