// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all
// 5_A

#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;
using Polygon = vector<Point>;

struct Line {
    Point a, b;
    Line(Point a, Point b) : a(a), b(b) {}
};

struct Segment : Line {
    Segment(Point a, Point b) : Line(a, b) {}
};

const double EPS = 1e-12;

// 内積
double dot(const Point &a, const Point &b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積
double cross(const Point &a, const Point &b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

// 最も近い２点の距離を求める
double closest_pair(vector<Point> &ps) {
    auto dfs = [&](auto dfs, vector<Point> qs) -> double {
        int N = qs.size();
        if (N <= 1) return 1e18;
        sort(qs.begin(), qs.end(), [](const Point &p1, const Point &p2) {
            if (abs(p1.real() - p2.real()) < EPS) return p1.imag() < p2.imag();
            return p1.real() < p2.real();
        });
        vector<Point> P1, P2;
        for (int i = 0; i < N / 2; i++) P1.push_back(qs[i]);
        for (int i = N / 2; i < N; i++) P2.push_back(qs[i]);
        double d1 = dfs(dfs, P1), d2 = dfs(dfs, P2);
        double d = min(d1, d2), ans = d;
        double px = P1[N / 2 - 1].real(), py = P1[N / 2 - 1].imag();
        vector<pair<double, int>> V;
        for (int i = 0; i < N; i++) {
            if (qs[i].real() < px - d - EPS || qs[i].real() > px + d + EPS) continue;
            V.push_back(make_pair(qs[i].imag(), i));
        }
        sort(V.begin(), V.end());
        int r = 0;
        for (int l = 0; l < (int)V.size(); l++) {
            r = max(r, l);
            while (r < (int)V.size() && V[r].first < V[l].first + d + EPS) {
                if (l != r) ans = min(ans, abs(qs[V[l].second] - qs[V[r].second]));
                r++;
            }
        }
        return ans;
    };
    return dfs(dfs, ps);
}

int main() {
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    vector<Point> ps(N);
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        ps[i] = Point(x, y);
    }
    cout << closest_pair(ps) << "\n";
}
