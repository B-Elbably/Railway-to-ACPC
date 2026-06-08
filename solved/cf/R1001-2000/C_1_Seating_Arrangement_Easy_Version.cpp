#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, x, s;
    cin >> n >> x >> s;
    queue<char> q;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        q.push(c);
    }
    while (q.front() == 'E') q.pop();
    int ans = 0;
    int magic = 0;
    int non = 0;
    int valid = 0;
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        if (c == 'A') {
            if (valid) {
                magic++; ans++; valid--;
            }else {
                if (!x) continue;
                x--; ans++; valid += (s - 1);
            }
        }else if (c == 'E') {
            if (valid) {
                valid--; ans++;
            }else if (magic && x) {
                valid += (s - 1);
                magic--; x--;
                ans++; non++;
            }
        }else if (c == 'I') {
            if (!x) continue;
            non++; x--;
            ans++;
            valid += (s - 1);
        }
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
