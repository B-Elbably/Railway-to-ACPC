#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n;
    cin >> n;

    vector<tuple<int, string, int>> events;
    for (int i = 0; i < n; i++) {
        int day, change;
        string name;
        cin >> day >> name >> change;
        events.push_back({day, name, change});
    }

    sort(events.begin(), events.end());

    map<string, int> milk;
    milk["Bessie"] = 7;
    milk["Elsie"] = 7;
    milk["Mildred"] = 7;

    set<string> last = {"Bessie", "Elsie", "Mildred"};
    int ans = 0;

    for (int i = 0; i < n; ) {
        int day = get<0>(events[i]);
        while (i < n && get<0>(events[i]) == day) {
            milk[get<1>(events[i])] += get<2>(events[i]);
            i++;
        }

        int mx = 0;
        for (auto &p : milk) {
            mx = max(mx, p.second);
        }

        set<string> winner;
        for (auto &p : milk) 
            if (p.second == mx) 
                winner.insert(p.first);
        
        if (winner != last) ++ans;
        last = winner;
    }

    cout << ans << "\n";
    return 0;
}
