#include <bits/stdc++.h>
using namespace std;

int randInt(int l, int r) {
    return l + rand() % (r - l + 1);
}

vector<int> generateUnique(int n, int maxVal, set<int>& banned) {
    vector<int> arr;
    set<int> used = banned;
    while ((int)arr.size() < n) {
        int x = randInt(0, maxVal);
        if (!used.count(x)) {
            arr.push_back(x);
            used.insert(x);
        }
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc < 2) { cerr << "Usage: ./gen <seed>\n"; return 1; }
    srand(atoi(argv[1]));

    int t = 1;
    printf("%d\n", t);

    int n = randInt(5, 6);  // robots
    int m = randInt(3, 6);  // spikes
    int k = randInt(2, 4);  // instructions
    int maxVal = 20;          // max position

    set<int> banned;
    vector<int> robots = generateUnique(n, maxVal, banned);
    for (int x : robots) banned.insert(x);
    vector<int> spikes = generateUnique(m, maxVal, banned);

    printf("%d %d %d\n", n, m, k);

    for (int i = 0; i < n; i++) printf("%d%c", robots[i], " \n"[i==n-1]);
    for (int i = 0; i < m; i++) printf("%d%c", spikes[i], " \n"[i==m-1]);

    string inst;
    for (int i = 0; i < k; i++) inst += (randInt(0,1) ? 'L' : 'R');
    printf("%s\n", inst.c_str());
}
