#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());  
    set<string> ans;
    do {
        ans.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    
    cout << ans.size() << "\n";
    for (auto &str : ans) cout << str << "\n";
}
