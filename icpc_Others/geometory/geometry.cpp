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

// 直線 l に対する点 p の射影
Point projection(const Line l, const Point &p) {
    double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return Point(l.a.real() + t * (l.b - l.a).real(), l.a.imag() + t * (l.b - l.a).imag());
}

// 直線 l に対する点 p の反射
Point reflection(const Line l, const Point &p) {
    double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    Point q(l.a.real() + t * (l.b - l.a).real(), l.a.imag() + t * (l.b - l.a).imag());
    return Point(2 * q.real() - p.real(), 2 * q.imag() - p.imag());
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

// 平行判定
bool is_parallel(const Line &l1, const Line &l2) {
    return (cross(l1.b - l1.a, l2.b - l2.a) == 0);
}

// 垂直判定
bool is_orthogonal(const Line &l1, const Line &l2) {
    return (dot(l1.b - l1.a, l2.b - l2.a) == 0);
}

// 線分と線分の交差判定
bool is_intersection(const Segment &s1, const Segment &s2) {
    return (counter_clockwise(s2.a, s1.a, s1.b) * counter_clockwise(s2.b, s1.a, s1.b) <= 0 && counter_clockwise(s1.a, s2.a, s2.b) * counter_clockwise(s1.b, s2.a, s2.b) <= 0);
}

// 線分と線分の交点の座標
Point cross_point(const Segment &s1, const Segment &s2) {
    double d1 = cross(s1.a - s2.a, s1.b - s2.a);
    double d2 = cross(s1.a - s1.b, s2.b - s2.a);
    if (abs(d1) < EPS && abs(d2) < EPS) {
        if (counter_clockwise(s1.a, s2.a, s2.b) == 0) return s1.a;
        else return s1.b;
    }
    return s2.a + (s2.b - s2.a) * (d1 / d2);
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

// 直線と点の距離
double distance(const Line s, const Point &p) {
    double t = dot(p - s.a, s.b - s.a) / norm(s.b - s.a);
    Point proj = Point(s.a.real() + t * (s.b - s.a).real(), s.a.imag() + t * (s.b - s.a).imag());
    return abs(p - proj);
}

// 線分と点の距離
double distance(const Segment s, const Point &p) {
    double t = dot(p - s.a, s.b - s.a) / norm(s.b - s.a);
    if (t > -EPS && t < 1 + EPS) {
        Point proj = Point(s.a.real() + t * (s.b - s.a).real(), s.a.imag() + t * (s.b - s.a).imag());
        return abs(p - proj);
    } else {
        return min(abs(p - s.a), abs(p - s.b));
    }
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

// 凸性判定
bool is_convex(const Polygon &poly) {
    int N = poly.size();
    for (int i = 0; i < N; i++) {
        if (counter_clockwise(poly[i], poly[(i + 1) % N], poly[(i + 2) % N]) == -1) return false;
    }
    return true;
}

// 多角形と点の包含関係
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

// 円と直線の交点
vector<Point> cross_points(Circle c, Line l) {
    Point proj = projection(l, c.p);
    double d = abs(proj - c.p);
    if (d > c.r + EPS) {
        return {};
    } else if (abs(c.r - abs(proj - c.p)) < EPS) {
        return {proj};
    } else {
        double s = sqrt(c.r * c.r - norm(proj - c.p));
        return {proj - (s / abs(l.b - l.a)) * (l.b - l.a), proj + (s / abs(l.b - l.a)) * (l.b - l.a)};
    }
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
