#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'


int n, k;
vector<int> a;
int f(int n) {
    set<int> mex;
    for (int i = 0; i <= n; ++i) {
        mex.insert(a[i]);
    }
    for (int i = 0; i <= n; ++i) {
        if (mex.find(i) == mex.end()) {
            return i;
        }
    }
    return n + 1;
}

void solve() {
    cin >> n >> k;
    int ans = 0;
    // cout << "----- " << n << " " << k << " -------\n";
    a.resize(n);
    iota(all(a), 0);
    map<int, vector<vector<int>>> mp;
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum ^= f(i);
        }
        mp[sum].push_back(a);
        // cout << "Permutation: ";
        // for (int i = 0; i < n; ++i) {
        //     cout << a[i] << " ";
        // }
        // cout << " -> Sum: " << sum << endl;
    }while (next_permutation(all(a)));
    for (auto &[sum, permutations] : mp) {
        cout << sum << " ";
    } cout << endl;

    cout << endl;
    for (auto &[sum, permutations] : mp) {
        cout << "==============\n";
        cout << "Sum: " << sum << endl;
        for (int j = 0; j < min(10LL, (int)permutations.size()); ++j) {
            for (int i = 0; i < n; ++i) {
                cout << permutations[j][i] << " ";
            }
            cout << endl;
        }
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
