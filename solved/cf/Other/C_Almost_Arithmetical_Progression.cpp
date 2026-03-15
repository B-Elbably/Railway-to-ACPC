#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> a;
    for (int i = 0; i < n; ++i) { 
        cin >> arr[i]; 
        a.push_back(arr[i]);
    }
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    int m = a.size();
    vector<vector<int>> idx(m);
    for(int i = 0; i < n; ++i) {
        arr[i] = lower_bound(a.begin(), a.end(), arr[i]) - a.begin();
        idx[arr[i]].push_back(i);
    }

    int ans = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int ii = 0, jj = 0;
            int last = -1;
            int turn = 0;
            int res = 0;
            for(;;) {
                if (turn % 2 == 0) {
                    while (ii < idx[i].size() && idx[i][ii] <= last) ii++;
                    if (ii == idx[i].size()) break;
                    last = idx[i][ii];
                    ii++;
                } else {
                    while (jj < idx[j].size() && idx[j][jj] <= last) jj++;
                    if (jj == idx[j].size()) break;
                    last = idx[j][jj];
                    jj++;
                }
                res++;
                turn++;
            }
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}