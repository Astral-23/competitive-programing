// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all
// 7_A, 7_B, 7_C, 7_D, 7_E, 7_F, 7_G, 7_H, 7_I

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

struct Circle {
    Point p;
    double r;
    Circle(Point p, double r) : p(p), r(r) {}
};

const double pi = acos(-1.0);
const double EPS = 1e-12;

// 内積
double dot(const Point &a, const Point &b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積
double cross(const Point &a, const Point &b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

// 円の交差判定
int intersection_of_circle(const Circle &c1, const Circle &c2) {
    double d = abs(c1.p - c2.p);
    // 分離
    if (d > c1.r + c2.r + EPS) {
        return 4;
    }
    // 外接
    if (abs(d - c1.r - c2.r) < EPS) {
        return 3;
    }
    // 交差
    if (d < c1.r + c2.r - EPS && d > abs(c1.r - c2.r) + EPS) {
        return 2;
    }
    // 内接
    if (abs(d - abs(c1.r - c2.r)) < EPS) {
        return 1;
    }
    // 包含
    return 0;
}

// 内接円
Circle incircle(const Point &p1, const Point &p2, const Point &p3) {
    double d = abs((p1 - p2)) + abs(p2 - p3) + abs(p3 - p1);
    Point p = p1 + (abs(p3 - p1) / d) * (p2 - p1) + (abs(p2 - p1) / d) * (p3 - p1);
    double r = abs(cross(p2 - p1, p3 - p1)) / d;
    return Circle(p, r);
}

// 外接円
Circle circumscribed_circle(const Point &p1, const Point &p2, const Point &p3) {
    double a = abs(p1 - p2), b = abs(p2 - p3), c = abs(p3 - p1), S = abs(cross(p2 - p1, p3 - p1)) * 0.5;
    double cx = norm(p2 - p1) * (p3 - p1).imag() - norm(p3 - p1) * (p2 - p1).imag(), cy = norm(p3 - p1) * (p2 - p1).real() - norm(p2 - p1) * (p3 - p1).real();
    cx /= 2.0 * cross(p2 - p1, p3 - p1);
    cy /= 2.0 * cross(p2 - p1, p3 - p1);
    Point p = p1 + Point(cx, cy);
    double r = a * b * c / (4.0 * S);
    return Circle(p, r);
}

// 直線と点の距離
double distance(const Line s, const Point &p) {
    double t = dot(p - s.a, s.b - s.a) / norm(s.b - s.a);
    Point proj = Point(s.a.real() + t * (s.b - s.a).real(), s.a.imag() + t * (s.b - s.a).imag());
    return abs(p - proj);
}

// 直線 l に対する点 p の射影
Point projection(const Line l, const Point &p) {
    double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return Point(l.a.real() + t * (l.b - l.a).real(), l.a.imag() + t * (l.b - l.a).imag());
}

// 円と直線の交点
vector<Point> cross_points(Circle c, Line l) {
    Point proj = projection(l, c.p);
    double d = abs(proj - c.p);
    if (d > c.r + EPS) {
        return {};
    }
    if (abs(c.r - abs(proj - c.p)) < EPS) {
        return {proj};
    }
    double s = sqrt(c.r * c.r - norm(proj - c.p));
    return {proj - (s / abs(l.b - l.a)) * (l.b - l.a), proj + (s / abs(l.b - l.a)) * (l.b - l.a)};
}

// 円と円の交点
vector<Point> cross_points(Circle c1, Circle c2) {
    int t = intersection_of_circle(c1, c2);
    if (t == 0 || t == 4) {
        return {};
    }
    if (t == 3) {
        return {c1.p + (c1.r / (c1.r + c2.r)) * (c2.p - c1.p)};
    }
    if (t == 1) {
        if (c1.r > c2.r) return {(-c2.r / abs(c1.r - c2.r)) * c1.p + (c1.r / abs(c1.r - c2.r)) * c2.p};
        return {(c2.r / abs(c1.r - c2.r)) * c1.p + (-c1.r / abs(c1.r - c2.r)) * c2.p};
    }
    double d = abs(c1.p - c2.p);
    double s = (c1.r * c1.r - c2.r * c2.r + d * d) / (2.0 * d);
    Point p = c1.p + (s / d) * (c2.p - c1.p);
    return {p - (sqrt(c1.r * c1.r - s * s) / d) * Point((c2.p - c1.p).imag(), -(c2.p - c1.p).real()), p + (sqrt(c1.r * c1.r - s * s) / d) * Point((c2.p - c1.p).imag(), -(c2.p - c1.p).real())};
}

// 円の接線
vector<Point> tangent(Circle c, Point p) {
    return cross_points(c, Circle(p, sqrt(norm(c.p - p) - c.r * c.r)));
}

// 円の共通接線
vector<Point> common_tangent(Circle c1, Circle c2) {
    double d = norm(c1.p - c2.p);
    double d1 = d - (c1.r + c2.r) * (c1.r + c2.r) + c2.r * c2.r;
    vector<Point> ps;
    if (d1 > -EPS) {
        d1 = sqrt(max(d1, 0.0));
        vector<Point> ps1 = cross_points(c1, Circle(c2.p, d1));
        for (auto p : ps1) ps.push_back(p);
    }
    double d2 = d - (c1.r - c2.r) * (c1.r - c2.r) + c2.r * c2.r;
    if (d2 > -EPS) {
        d2 = sqrt(max(d2, 0.0));
        vector<Point> ps2 = cross_points(c1, Circle(c2.p, d2));
        for (auto p : ps2) ps.push_back(p);
    }
    return ps;
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

// 円の共通部分の面積
double area_of_intersection(Circle c1, Circle c2) {
    int t = intersection_of_circle(c1, c2);
    if (t >= 3) {
        return 0;
    }
    if (t <= 1) {
        return pi * min(c1.r, c2.r) * min(c1.r, c2.r);
    }
    vector<Point> ps = cross_points(c1, c2);
    double a1 = arg(ps[0] - c1.p) - arg(ps[1] - c1.p), a2 = arg(ps[1] - c2.p) - arg(ps[0] - c2.p);
    if (a1 < -EPS) a1 += 2.0 * pi;
    if (a2 < -EPS) a2 += 2.0 * pi;
    return (a1 / 2) * c1.r * c1.r + (a2 / 2) * c2.r * c2.r - abs(area({ps[0], c1.p, ps[1], c2.p}));
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

int is_contained(const Point p, const Polygon poly) {
    int N = poly.size();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (counter_clockwise(p, poly[i], poly[(i + 1) % N]) == 0) {
            return 1;
        }
        Point a = poly[i], b = poly[(i + 1) % N];
        if (a.imag() > b.imag()) swap(a, b);
        if (p.imag() < b.imag() + EPS && p.imag() > a.imag() + EPS && counter_clockwise(p, a, b) < 0) {
            cnt++;
        }
    }
    if (cnt % 2 == 0) return 0;
    else return 2;
}

// 円と線分の交点
vector<Point> cross_points(Circle c, Line l) {
    Point proj = projection(l, c.p);
    double d = abs(proj - c.p);
    if (d > c.r + EPS) {
        return {};
    }
    if (abs(c.r - abs(proj - c.p)) < EPS) {
        if (counter_clockwise(proj, l.a, l.b) == 0) return {proj};
        else return {};
    }
    double s = sqrt(c.r * c.r - norm(proj - c.p));
    Point p1 = proj - (s / abs(l.b - l.a)) * (l.b - l.a), p2 = proj + (s / abs(l.b - l.a)) * (l.b - l.a);
    vector<Point> ps;
    if (counter_clockwise(p1, l.a, l.b)) ps.push_back(p1);
    if (counter_clockwise(p2, l.a, l.b)) ps.push_back(p2);
    return ps;
}

// 円と多角形の共通部分の面積
double area_of_intersection(Circle c, Polygon poly) {
    int N = poly.size();
}

int main() {
    cout << fixed << setprecision(15);
    int N, R;
    cin >> N >> R;
    Polygon poly(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        poly[i] = Point(x, y);
    }
    cout << area_of_intersection(Circle(Point(0, 0), R), poly) << "\n";
}
