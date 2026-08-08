#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 101;
int L[N], R[N];
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    int cnt = 0;
    cin >> s;
    for (int i = 0; i < k; ++i) cnt+= (s[i] == 'L');
    for (int i = n - 1; i >= n - k; --i) cnt+= s[i] != 'L';
    if (k * 2 > n) cnt = -1;
    cout << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
