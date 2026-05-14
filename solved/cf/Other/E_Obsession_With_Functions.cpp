#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int s(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
int h(int n) {
    int sum = s(n);
    if (sum >= 10) return h(sum);
    return sum;
}
vector<int> pattern = {1, 4, 9, 7, 7, 9, 4, 1, 9};

int calc(int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        res += h(i * i);
    }
    return res;
}

void solve() {
    int l, r;
    cin >> l >> r;
    for (int i =1; i < 9; ++i) {
        // pattern[i] += pattern[i - 1];
    }
    // cout << calc(l, r) << endl; 
    // for (int i = 1; i <= 30; ++i) {
        // cout << i << ": " <<  h(i) << ", " << h(i * i) << endl;
        // if (i % 9 == 1) cout << "\n";
        // cout << h(i * i) << " ";
    // }
    int ans = (r / 9) * 51;
    for (int i = 0; i < (r % 9); ++i) {
        ans += pattern[i];
    }
    ans -= (--l / 9) * 51;
    for (int i = 0; i < (l % 9); ++i) {
        ans -= pattern[i];
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
