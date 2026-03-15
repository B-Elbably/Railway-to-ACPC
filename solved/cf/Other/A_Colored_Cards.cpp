#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

string ans[] = { "Pink", "Green","Yellow", "Blue"};

void solve() {
    int n;
    cin >> n;
    n %= 4;
    cout << ans[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
}
