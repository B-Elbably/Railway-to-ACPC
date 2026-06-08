#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 2e5 + 5;
int freq[1000001];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> nums;
    for (int i = 0; i <= N + 1; ++i) {
        nums.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] < N) 
            if (++freq[a[i]] == 1) nums.erase(a[i]);
        
        if (i >= k) {
            if (a[i - k] < N)
                if (--freq[a[i - k]] == 0) 
                    nums.insert(a[i - k]);
        }
        if (i >= k - 1) {
            cout << *nums.begin() << " ";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
