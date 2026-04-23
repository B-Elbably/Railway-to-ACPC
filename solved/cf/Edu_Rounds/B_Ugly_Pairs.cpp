#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    set<int> od, ev;
    vector<int> freq(26, 0);
    for (char c : s) {
        if ((c - 'a') % 2) od.insert(c - 'a');
        else ev.insert(c - 'a');
        freq[c - 'a']++;
        if (freq[c - 'a'] == n) {
            cout << s << "\n";
            return;
        }
    }
    // for (int i = 0; i < 24; i++) {
    //     if (freq[i] + freq[i + 1] + freq[i + 2] == n) {
    //         cout << "No answer\n";
    //         return;
    //     }
    // }
    if (od.empty() || ev.empty()) {
        sort(all(s));
        cout << s << "\n";
        return;
    }
    if (abs(*od.begin() - *ev.rbegin()) != 1) {
        for (int e: ev) {
            for (int i = 0; i < freq[e]; i++) cout << (char)(e + 'a');
        }
        for (int o: od) {
            for (int i = 0; i < freq[o]; i++) cout << (char)(o + 'a');
        }
        cout << "\n";
        return;
    }
    if (abs(*od.rbegin() - *ev.begin()) != 1) {
        for (int o: od) {
            for (int i = 0; i < freq[o]; i++) cout << (char)(o + 'a');
        }
        for (int e: ev) {
            for (int i = 0; i < freq[e]; i++) cout << (char)(e + 'a');
        }
        cout << "\n";
        return;
    }
    // if (abs(*od.rbegin() - *ev.rbegin()) != 1) {
    //     vector<int> t1(od.begin(), od.end());
    //     vector<int> t2(ev.begin(), ev.end());
    //     sort(all(t1)); reverse(all(t1));
    //     for (int e: t1) {
    //         for (int i = 0; i < freq[e]; i++) cout << (char)(e + 'a');
    //     }
    //     for (int o: t2) {
    //         for (int i = 0; i < freq[o]; i++) cout << (char)(o + 'a');
    //     }
    //     cout << "\n";
    //     return;
    // }
    // if (abs(*od.begin() - *ev.begin()) != 1) {
    //     vector<int> t1(od.begin(), od.end());
    //     vector<int> t2(ev.begin(), ev.end());
    //     sort(all(t2)); reverse(all(t2));
    //     for (int e: t1) {
    //         for (int i = 0; i < freq[e]; i++) cout << (char)(e + 'a');
    //     }
    //     for (int o: t2) {
    //         for (int i = 0; i < freq[o]; i++) cout << (char)(o + 'a');
    //     }
    //     cout << "\n";
    //     return;
    // }
    cout << "No answer\n";
}   

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
