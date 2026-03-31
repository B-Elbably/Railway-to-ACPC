#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    multiset<int> ms;
    int sumL = 0, sum = 0;
    for (int i = 0; i < k; ++i) {
        ms.insert(a[i]);
        sum += a[i];
    }
    auto it = ms.begin();
    for (int i = 0; i < (k - 1) / 2; ++i) {
        sumL += *it++;
    }
    int L = (k - 1) / 2;
    int R = k - 1 - L;
    auto get_cost = [&]() {
        int sumR = sum - sumL - *it;
        return sumR - sumL + (*it) * ((k % 2 - 1));
    };
    cout << get_cost() << ' ';
    for (int i = k; i < n; i++) {
        int add = a[i]; int rem = a[i - k];
        sum += add - rem;
        ms.insert(add);
        if (add < *it) {
            sumL += add;
            sumL -= *(--it);
        }
        if (rem <= *it) {
            sumL -= rem;
            sumL += *(it++);
        }
        ms.erase(ms.find(rem));
        cout << get_cost() << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
}