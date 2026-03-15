#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = s;
    int k = 1;
    for (int i = 0; i < n; i++) {
        string right = s.substr(i);
        string left = s.substr(0, i);
        if ((n - i) & 1) reverse(left.begin(), left.end());
        string t = right + left;
        if (t < ans) {
            ans = t;
            k = i + 1;
        }
    }
    cout << ans << "\n" << k << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int right;
    cin >> right;
    while (right--) solve();
}