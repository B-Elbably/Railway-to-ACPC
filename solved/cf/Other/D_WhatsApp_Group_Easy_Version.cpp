#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


int cnt;
map<int ,int> memo;
int brute(int n, int m) {
    cnt++;
    if (n <= m) return 1;
    if (memo.find(n) != memo.end()) return memo[n];
    return memo[n] = brute((n + 1) / 2, m) + brute(n / 2, m);
}


void solve() {
    int a, b;
    cnt = 0;
    cin >> a >> b;
    cout << brute(a, b) << endl;
    memo.clear();
    // cout << brute(a, b) << " " << cnt << " ";
    // cout << (a + b - 1) / b << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}

/*
1
100000 1
100000 55 100000

*/