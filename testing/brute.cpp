#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int> a) {
    long long sum = 0;
    for (int x : a) {
        sum += x;
        if (sum == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    do {
        if (valid(a)) {
            cout << "YES\n";
            for (int x : a) cout << x << " ";
            cout << "\n";
            // return 0;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "NO\n";
}
