#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<int,int>> movies(n);

    for (auto &x : movies)
        cin >> x.second >> x.first; 
    sort(movies.begin(), movies.end());

    int ans = 0, last = 0;
    for (auto &x : movies) {
        if (x.second >= last) {
            ans++;
            last = x.first;
        }
    }
    cout << ans;
}
