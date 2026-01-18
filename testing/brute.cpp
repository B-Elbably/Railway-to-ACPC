#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_set<long long> spikes;
        for (int i = 0; i < m; i++) {
            long long x;
            cin >> x;
            spikes.insert(x);
        }

        string s;
        cin >> s;

        vector<bool> alive(n, true);
        int alive_cnt = n;

        for (int step = 0; step < k; step++) {
            char c = s[step];
            for (int i = 0; i < n; i++) {
                if (!alive[i]) continue;
                if (c == 'L') a[i]--;
                else a[i]++;
                if (spikes.count(a[i])) {
                    alive[i] = false;
                    alive_cnt--;
                }
            }
            cout << alive_cnt;
            if (step + 1 < k) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
