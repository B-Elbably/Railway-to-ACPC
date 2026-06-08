#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> freq;
    map<int, set<int>> nums;
    for (int i = 0; i < n; ++i) {
        int now = a[i];
        if (freq[now] > 0) {
            nums[freq[now]].erase(now);
            if (nums[freq[now]].empty()) {
                nums.erase(freq[now]);
            }
        }
        freq[now]++;
        nums[freq[now]].insert(now);
        if (i >= k) {
            int x = a[i - k];
            nums[freq[x]].erase(x);
            if (nums[freq[x]].empty()) {
                nums.erase(freq[x]);
            }
            freq[x]--;
            if (freq[x] > 0) {
                nums[freq[x]].insert(x);
            }
        }
        if (i >= k - 1) {
            int mxFreq = nums.rbegin()->first;
            cout << *nums[mxFreq].begin() << " ";;
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
