#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename K, typename V>
using HashMap = gp_hash_table<K, V, custom_hash>;

const int N = 1e5 + 5;
int spf[N];
int cache_get[N];

void build() {
    for (int i = 0; i < N; ++i) spf[i] = i;
    for (int i = 2; i < N; ++i) {
        if (spf[i] != i) continue;
        for (int j = i * i; j < N; j += i) {
            if (spf[j] == j)    
                spf[j] = i;
        }
    }
    for (int i = 2; i < N; ++i) {
        cache_get[i] = (int)(log2(100005) / log2(i)) + 2;
    }
}

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> factors;
    while (n > 1) {
        int p = spf[n];
        int cnt = 0;
        while (n % p == 0) {
            cnt++;
            n /= p;
        }
        factors.push_back({p, cnt});
    }
    return factors;
}

void solve() {
    int q;
    cin >> q;
    HashMap<int, int> factors;
    HashMap<int, bool> mx;
    vector<int> to_erase;
    while (q--) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            for (auto [k, v]: factorize(x)) {
                if (mx.find(k) != mx.end()) continue;
                if (factors[k] + v > cache_get[k]) {
                    mx[k] = true;
                    factors.erase(k);
                    continue;
                }
                factors[k] += v;
            }
        }
        else if (type == 2) {
            to_erase.clear();
            for (auto it = factors.begin(); it != factors.end(); ++it) {
                int k = it->first;
                if (mx.find(k) != mx.end()) {
                    to_erase.push_back(k);
                    continue;
                }
                if (x > cache_get[k] || it->second * x > cache_get[k]) {
                    mx[k] = true;
                    to_erase.push_back(k);
                    continue;
                } 
                it->second *= x;
            }
            for (int k: to_erase) {
                factors.erase(k);
            }
        }
        else {
            int ok = 1;
            for (auto [k, v]: factorize(x)) {
                if (mx.find(k) != mx.end()) continue;
                if (factors.find(k) == factors.end() || factors[k] < v){
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << "Yes\n";
            } else {
                cout << "No\n";            
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    solve();
    return 0;
}