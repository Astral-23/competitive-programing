// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all
// 3_A, 3_B, 3_C

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

int main() {
    cout << fixed << setprecision(1);
    int N;
    cin >> N;
    Polygon poly(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        poly[i] = Point(x, y);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        cout << is_contained(p, poly) << "\n";
    }
}
