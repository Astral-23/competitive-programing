// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all
// 4_A, 4_B, 4_C

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

// 多角形の面積
double area(const Polygon &poly) {
    double ans = 0;
    int N = poly.size();
    for (int i = 0; i < N; i++) {
        ans += cross(poly[i], poly[(i + 1) % N]);
    }
    ans *= 0.5;
    return ans;
}

// p0 から p1 へ結んだベクトルから見た p2 の位置
int counter_clockwise(const Point &p2, Point p0, Point p1) {
    // 反時計回り
    if (cross(p1 - p0, p2 - p0) > EPS) {
        return 1;
    }
    // 時計回り
    if (cross(p1 - p0, p2 - p0) < -EPS) {
        return -1;
    }
    // p2, p0, p1 の順で同一直線上
    if (dot(p1 - p0, p2 - p0) < -EPS) {
        return 2;
    }
    // p0, p1, p2 の順で同一直線上
    if (dot(p1 - p0, p2 - p0) > norm(p1 - p0) + EPS) {
        return -2;
    }
    // p2 は p0 と p1 を結ぶ線分上
    return 0;
}

// 直線と線分の交差判定
bool is_intersection(const Line &l1, const Segment &s2) {
    return (counter_clockwise(s2.a, l1.a, l1.b) * counter_clockwise(s2.b, l1.a, l1.b) <= 0);
}

// 直線と線分の交点の座標
Point cross_point(const Line &s1, const Segment &s2) {
    double d1 = cross(s1.a - s2.a, s1.b - s2.a);
    double d2 = cross(s1.a - s1.b, s2.b - s2.a);
    if (abs(d1) < EPS && abs(d2) < EPS) {
        return s2.a;
    }
    return s2.a + (s2.b - s2.a) * (d1 / d2);
}

// 凸包
Polygon convex_hull(vector<Point> &ps) {
    int N = ps.size();
    auto compare = [](const Point &p1, const Point &p2) {
        if (p1.real() != p2.real()) return p1.real() < p2.real();
        return p1.imag() < p2.imag();
    };
    sort(ps.begin(), ps.end(), compare);
    int k = 0;
    Polygon qs(2 * N);
    // 下側凸包
    for (int i = 0; i < N; i++) {
        while (k > 1 && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS) k--;
        qs[k++] = ps[i];
    }
    // 上側凸包
    for (int i = N - 2, t = k; i >= 0; i--) {
        while (k > t && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

// 最も遠い２点の距離を求める
double farest_pair(vector<Point> &ps) {
    Polygon poly = convex_hull(ps);
    double ans = 0;
    for (int i = 0; i < (int)poly.size(); i++) {
        for (int j = 0; j < i; j++) {
            ans = max(ans, abs(poly[i] - poly[j]));
        }
    }
    return ans;
}

// 直線 l で凸多角形を切断する
Polygon convex_cut(const Polygon &poly, const Line &l) {
    int N = poly.size();
    vector<Point> ps;
    for (int i = 0; i < N; i++) {
        if (cross(l.b - l.a, poly[i] - l.a) > -EPS) {
            ps.push_back(poly[i]);
        }
        if (is_intersection(l, Segment(poly[i], poly[(i + 1) % N]))) {
            ps.push_back(cross_point(l, Segment(poly[i], poly[(i + 1) % N])));
        }
    }
    if (ps.size() <= 0) return {};
    Polygon ch = convex_hull(ps);
    return ch;
}

int main() {
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    Polygon poly(N);
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        poly[i] = Point(x, y);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1(x1, y1), p2(x2, y2);
        Line l(p1, p2);
        cout << area(convex_cut(poly, l)) << "\n";
    }
}
