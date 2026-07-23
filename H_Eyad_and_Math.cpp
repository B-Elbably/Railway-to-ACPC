    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define all(x) (x).begin(), (x).end()
    #define endl '\n'

    void solve() {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        double op1 = (double)(b * log(a));
        double op2 = (double)(d * log(c));
        if (op1 > op2) {
            cout << ">" << endl;
        } else {
            cout << "<" << endl;
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
