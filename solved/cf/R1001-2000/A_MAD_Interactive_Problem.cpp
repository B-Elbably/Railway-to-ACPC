#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int ask(vector<int>& q) {
    cout << "? " << q.size() << " "; cout.flush();
    for (int i : q) cout << i  << " "; cout << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> bad, good;
    vector<int> ans(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        a.push_back(i);
        int res = ask(a);
        if (res) {
            ans[i] = res;
            a.pop_back();
            bad.push_back(i);
        }else {
            good.push_back(i);
        }
    }
    a = bad;
    for (int i : good) {
        a.push_back(i);
        int res = ask(a);
        ans[i] = res;
        a.pop_back();
    }

    cout << "! ";
    for (int i = 1; i <= 2 * n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
