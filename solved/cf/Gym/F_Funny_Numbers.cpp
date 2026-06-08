#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'
const int N = 1e6 + 5;
const int M = 1e3 + 5;
int ans[N];

// using u64 = uint64_t;
// struct custom_hash {
//     static u64 splitmix64(u64 x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(u64 x) const {
//         static const u64 FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }

//     template<typename T, typename U>
//     size_t operator()(const pair<T, U>& p) const {
//         u64 h1 = (*this)(p.first);
//         u64 h2 = (*this)(p.second);
//         return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
//     }
// };


int f(int n) {
    int res = 0;
    while (n) {
        int d = n % 10;
        res += d * d;
        n /= 10;
    }
    return res;
}
int mx;

set<int> seen;
void build() {
    for (int i = 1; i < N; ++i) {
        // if(~ans[i]) continue;    
        // int x = i;
        // int cnt = 0;
        // while (ans[x] == -1 || ans[x] > i) {
        //     if (x >= N) {x = f(x); continue;}
        //     ans[x] = i;
        //     x = f(x);
        //     cnt++;
        // }mx = max(mx, cnt);
        // if (i > 10) continue;
        // cout << cnt << endl;
        if (i > M) {
            ans[i] = ans[f(i)];
            continue;
        }
        int cnt = 0;
        int x = i;
        while (seen.count(x) == 0) {
            seen.insert(x);
            x = f(x);
            cnt ++;
        }
        ans[i] = *seen.begin();
        mx = max(mx, cnt);
        seen.clear();
    }
}

void solve() {
    memset(ans, -1, sizeof ans);
    int a, b;
    cin >> a >> b;
    build();
    int sum = 0;
    for (int i = a; i <= b; ++i) {
        sum += ans[i];
        // cout << ans[i] << ' ';
    }
    // cout << mx << endl;
    cout << sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; 
    while (t--) solve();
    return 0;
}
