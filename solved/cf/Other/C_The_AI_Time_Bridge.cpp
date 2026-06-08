#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<int> ones; 
    int i = 0;
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if (s[j] == '1') ones.push_back(j);
        while (ones.size() >= 2) {
            int r = ones.back();
            int l = ones[ones.size() - 2];
            if (r - l - 1 >= k) break;
            i = l + 1;
            while (!ones.empty() && ones.front() < i) {
                ones.pop_front();
            }
        }
        ans += (j - i + 1);
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
