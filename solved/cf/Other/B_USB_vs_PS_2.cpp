#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n1, n2, n3, m;
    cin >> n1 >> n2 >> n3 >> m;
    
    vector<int> usb, ps2, both;
    for (int i = 0; i < m; i++) {
        int ai; string type;
        cin >> ai >> type;
        if (type == "USB") usb.push_back(ai);
        else ps2.push_back(ai);
    }
    sort(all(usb));
    sort(all(ps2));
    int ans = 0, cost = 0;
    for (int i = 0; i < min(n1, (int)usb.size()); i++) {
        ans++;
        cost += usb[i];
    }
    for (int i = min(n1, (int)usb.size()); i < usb.size(); i++) {
        both.push_back(usb[i]);
    }
    for (int i = 0; i < min(n2, (int)ps2.size()); i++) {
        ans++;
        cost += ps2[i];
    }
    for (int i = min(n2, (int)ps2.size()); i < ps2.size(); i++) {
        both.push_back(ps2[i]);
    }
    sort(all(both));
    for (int i = 0; i < min(n3, (int)both.size()); i++) {
        ans++;
        cost += both[i];
    }    
    cout << ans << ' ' << cost << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
}
