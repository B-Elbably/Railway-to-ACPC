#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int ans = 0;
vector<pair<int, int>> cows;

int search() {
    sort(cows.begin(), cows.end());

    vector<pair<int, int>> pref(n), suf(n);

    auto upd = [](pair<int,int> a, int b) {
        return make_pair(min(a.first, b), max(a.second, b));
    };

    pref[0] = {cows[0].second, cows[0].second};
    for (int i = 1; i < n; ++i)
        pref[i] = upd(pref[i - 1], cows[i].second);

    suf[n - 1] = {cows[n - 1].second, cows[n - 1].second};
    for (int i = n - 2; i >= 0; --i)
        suf[i] = upd(suf[i + 1], cows[i].second);

    int area = (cows.back().first - cows.front().first) *
               (pref.back().second - pref.back().first);

    int best = LLONG_MAX;

    for (int i = 0; i < n - 1; ++i) {
        if (cows[i].first == cows[i + 1].first) continue;

        int first_rect =
            (cows[i].first - cows[0].first) *
            (pref[i].second - pref[i].first);

        int second_rect =
            (cows.back().first - cows[i + 1].first) *
            (suf[i + 1].second - suf[i + 1].first);

        best = min(best, first_rect + second_rect);
    }

    return area - best;
}

int32_t main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    cin >> n;
    cows.resize(n);

    for (auto &x : cows)
        cin >> x.first >> x.second;

    ans = max(ans, search());

    for (auto &x : cows)
        swap(x.first, x.second);

    ans = max(ans, search());

    cout << ans << '\n';
}
