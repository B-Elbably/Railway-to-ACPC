#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
bool prime[N];
vector<int> primes;

void build() {
    for (int i = 2; i < N; ++i) {
        // cout << i << " " << prime[i] << "\n";
        if (prime[i]) continue;
        primes.push_back(i);
        for (int j = i * 2; j < N; j += i) {
            prime[j] = true;
        }
    }
}
vector<int> ans;
void build2() {
    
}
const int mx = 1e18;
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cout << primes[i] * primes[i + 1] << " ";
    cout << endl;
    // int ans = 0;
    
    // int ai = 1;
    // while (ai * primes[ans] <= mx) ai *= primes[ans++];
    // cout << ans << "\n";
    // cout << (1 << 14);
    // int j = 0;
    // vector<int> ans;
    // for (int i = 0; i < n;++i) {
    //     // cout << ai << " ";
    //     ans.push_back(ai);
    //     if (ai > mx / primes[j]) j++;
    //     while (ai > mx / primes[j]) ai /= primes[j - 1];
    //     ai *= primes[j];
    //     // cout << (ai > mx);
    // }  
    // // cout << endl;
    // set<int> st;
    // for (int i = 0; i < n - 1; ++i) {
    //     st.insert(gcd(ans[i], ans[i + 1]));

    // }
    // cout << (*st.rbegin() <= mx) << endl;
    // cout << st.size();

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    build2();
    int t = 1;
    cin >> t; 
    while (t--) solve();
}
