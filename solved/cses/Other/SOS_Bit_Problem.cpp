#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

const int MAX_BITS = 20;
const int N = 1 << MAX_BITS;
int dp_sub[N], dp_sup[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp_sub[a[i]]++;
        dp_sup[a[i]]++;
    }

    // SOS DP: O(K * 2^K)
    for (int i = 0; i < MAX_BITS; ++i) {
        for (int mask = 0; mask < N; ++mask) {
            if (mask & (1 << i)) {
                dp_sub[mask] += dp_sub[mask ^ (1 << i)];
            } else {
                dp_sup[mask] += dp_sup[mask ^ (1 << i)];
            }
        }                                                                                  
    }

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        int ans1 = dp_sub[x];
        int ans2 = dp_sup[x];
        int ans3 = n - dp_sub[(N - 1) ^ x];
        
        cout << ans1 << " " << ans2 << " " << ans3 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}