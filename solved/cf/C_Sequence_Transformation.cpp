#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
int n;
void brute() {
    // int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    transform(a.begin(), a.end(), a.begin(),
        [](int x) { return 2 * x; });

    vector<pair<vector<int>, vector<int>>> res;
    do{
        vector<int> vec;
        for (int i = n; i; --i) {
            int g = 0;
            for (int j = 0; j < i; ++j) {
                g = __gcd(g, a[j]);
            }
            vec.push_back(g);
        }
        res.push_back({vec, a});
    }while(next_permutation(all(a)));

    sort(all(res));
    for (auto &x : res.back().first) {
        cout << x << ' ';
    }
    cout << endl;
    reverse(all(res.back().second));
    for (auto &x : res.back().second) {
        cout << x << ' ';
    }
    cout << endl;
}

void solve() {
    // int n;
    cin >> n;
    // n *= 2;
    vector<int> a(n);
    vector<int> ans;
    if (n == 3){
        ans = {1, 1, 3};
    }else if (n == 2){
        ans = {1, 2};
    }else {
        for (int i = 0; i < (n + 1) / 2; ++i) {
            ans.push_back(1);
        }
        int start = 2;
        int step = 4;
        
        while (ans.size() < n && start <= n)
        {   
            int cnt = 0;
            while (start + (cnt * step) <= n)
            {   
                ans.push_back(start);
                cnt++;
            }
            start <<= 1;
            step <<= 1;
        }
        int m = n;
        for (int i = 1; i * 4 < m ; i <<= 1) {
            if (m & i) {
                m -= i;
            }
        }
        ans[n - 1] = m;
    }
    for (int x: ans) cout << x << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) {
        // brute();
        solve();
    }
}

// 4 -> 4
// 5 -> 4

// 6 -> 6
// 7 -> 6

// 8 -> 8   
// 9 -> 8
// 10 -> 8
// 11 -> 8

// 12 -> 12
// 13 -> 12
// 14 -> 12
// 15 -> 12