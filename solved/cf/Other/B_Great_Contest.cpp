#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

struct Solver {
    long long sum_x_pp = 0, sum_y_pp = 0;
    vector<Point> Q_pm, Q_mp;
    vector<long long> pref_x_pm, pref_y_pm;
    vector<long long> pref_x_mp, pref_y_mp;

    void init(const vector<long long>& a, const vector<long long>& b, const vector<long long>& c, const vector<long long>& d, int s1, int s2) {
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            long long x = s1 * (a[i] - b[i]);
            long long y = s2 * (c[i] - d[i]);
            if (x >= 0 && y >= 0) {
                sum_x_pp += x;
                sum_y_pp += y;
            } else if (x > 0 && y < 0) {
                Q_pm.push_back({x, y});
            } else if (x < 0 && y > 0) {
                Q_mp.push_back({x, y});
            }
        }

        sort(Q_pm.begin(), Q_pm.end(), [](const Point& A, const Point& B) {
            return (-A.y) * B.x < (-B.y) * A.x;
        });
        pref_x_pm.resize(Q_pm.size() + 1, 0);
        pref_y_pm.resize(Q_pm.size() + 1, 0);
        for (size_t i = 0; i < Q_pm.size(); ++i) {
            pref_x_pm[i + 1] = pref_x_pm[i] + Q_pm[i].x;
            pref_y_pm[i + 1] = pref_y_pm[i] + Q_pm[i].y;
        }

        sort(Q_mp.begin(), Q_mp.end(), [](const Point& A, const Point& B) {
            return (-A.x) * B.y < (-B.x) * A.y;
        });
        pref_x_mp.resize(Q_mp.size() + 1, 0);
        pref_y_mp.resize(Q_mp.size() + 1, 0);
        for (size_t i = 0; i < Q_mp.size(); ++i) {
            pref_x_mp[i + 1] = pref_x_mp[i] + Q_mp[i].x;
            pref_y_mp[i + 1] = pref_y_mp[i] + Q_mp[i].y;
        }
    }

    long long query(long long k, long long l) {
        long long ans = k * sum_x_pp + l * sum_y_pp;

        auto it_pm = lower_bound(Q_pm.begin(), Q_pm.end(), make_pair(k, l), [](const Point& pt, const pair<long long, long long>& q) {
            return (-pt.y) * q.second < q.first * pt.x;
        });
        size_t cnt_pm = it_pm - Q_pm.begin();
        ans += k * pref_x_pm[cnt_pm] + l * pref_y_pm[cnt_pm];

        auto it_mp = lower_bound(Q_mp.begin(), Q_mp.end(), make_pair(k, l), [](const Point& pt, const pair<long long, long long>& q) {
            return (-pt.x) * q.first < q.second * pt.y;
        });
        size_t cnt_mp = it_mp - Q_mp.begin();
        ans += k * pref_x_mp[cnt_mp] + l * pref_y_mp[cnt_mp];

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<long long> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    Solver solvers[4];
    solvers[0].init(a, b, c, d, 1, 1);
    solvers[1].init(a, b, c, d, 1, -1);
    solvers[2].init(a, b, c, d, -1, 1);
    solvers[3].init(a, b, c, d, -1, -1);

    for (int i = 0; i < q; ++i) {
        long long k, l;
        cin >> k >> l;
        long long max_penalty = 0;
        for (int j = 0; j < 4; ++j) {
            max_penalty = max(max_penalty, solvers[j].query(k, l));
        }
        cout << max_penalty << "\n";
    }

    return 0;
}