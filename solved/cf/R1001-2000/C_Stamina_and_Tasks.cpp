#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int n;
vector<pair<double,double>> a;
vector<int> memo; 

double go(int idx) {
    if(idx == n) return 0;
    if(memo[idx]) return memo[idx];
    double op1 = go(idx+1);
    double op2 = a[idx].first + go(idx+1) * a[idx].second;
    return memo[idx] = max(op1, op2);
}

void solve() {
    cin >> n;
    a.resize(n);
    memo.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    for(int i = 0; i < n; i++) a[i].second = (1.0 - a[i].second/100.0);
    cout << go(0) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--) solve();
}