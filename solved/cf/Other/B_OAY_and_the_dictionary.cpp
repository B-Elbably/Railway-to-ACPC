#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int q = 0, cnt = 0; 
vector<int> freq(26, 0);

void add(char c) {
    if (c == '?') q++;
    else {
        if (freq[c - 'A'] == 0) cnt++;
        freq[c - 'A']++;
    }
}

void remove(char c) {
    if (c == '?') q--;
    else {
        freq[c - 'A']--;
        if (freq[c - 'A'] == 0) cnt--;
    }
}

void solve() {
    string s;
    if (!(cin >> s)) return;

    if (s.length() < 26) {
        cout << -1 << endl;
        return;
    }
    for (int k = 0; k < 26; k++) add(s[k]);

    int i = 0, j = 25;
    bool flag = false;
    while (true) {
        if (cnt + q == 26) {
            flag = true;
            break;
        }
        if (j + 1 == s.length()) break;
        remove(s[i]);
        i++; j++;
        add(s[j]);
    }

    if (!flag) {
        cout << -1;
        return;
    }
    string ref = s.substr(i, 26);
    vector<char> targets;
    vector<int> ref_freq(26, 0);
    for (char c : ref) if (c != '?') ref_freq[c - 'A']++;
    for (int k = 0; k < 26; k++) {
        if (ref_freq[k] == 0) targets.push_back((char)('A' + k));
    }

    int cnt2 = 0;
    for (int idx = 0; idx < 26; idx++) {
        if (ref[idx] == '?') {
            ref[idx] = targets[cnt2++];
        }
    }

    for (int k = 0; k < s.length(); k++) {
        if (k >= i && k <= j) {
            cout << ref[k - i];
        } else {
            cout << (s[k] == '?' ? 'A' : s[k]);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();
    return 0;
}