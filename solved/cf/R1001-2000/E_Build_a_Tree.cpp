#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    if (k < 2 * (n - 1)) {
        cout << -1 << endl;
        return;
    }
    int mx = n * (n - 1) / 2 + n / 2;
    if (k > mx) {
        cout << -1 << endl;
        return;
    }
    if (k & 1) {
        cout << -1 << endl;
        return;
    }
    
    int sum = 2 * (n - 1);
    int l = 1, r = 1;
    for (int i = 2; i <= n; ++i) {
        int gain = 2 * ((i - 2) / 2);
        
        if (sum + gain > k) {
            int need = k - sum;
            int parent = (need == 0) ? 1 : ((i & 1) ? need + 1 : need);
            cout << parent << " " << i << endl;
            
            for (int j = i + 1; j <= n; ++j) {
                cout << 1 << " " << j << endl;
            }
            return;
        }
        else {
            sum += gain;
            if (i & 1) {
                cout << l << " " << i << endl;
                l = i;
            } else {
                cout << r << " " << i << endl;  
                r = i;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}