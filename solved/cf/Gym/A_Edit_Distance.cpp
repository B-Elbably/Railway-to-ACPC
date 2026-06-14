#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
const int N = 2e3 + 5;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = n - cnt0;
    if (cnt1 > cnt0) {
        cout << string(n, '0') << '\n';
    } 
    else if (cnt0 > cnt1) {
        cout << string(n, '1') << '\n';
    } 
    else {
        if (s[0] == '0') {
            cout << '1' << string(n - 1, '0') << '\n';
        } else {
            cout << '0' << string(n - 1, '1') << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
 
    int t = 1;
    // cin >> t;
    while (t--) solve();
}