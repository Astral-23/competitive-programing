// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all
// 2_A, 2_B, 2_C, 2_D

#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;

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

// 平行判定
bool is_parallel(const Line &l1, const Line &l2) {
    return (cross(l1.b - l1.a, l2.b - l2.a) == 0);
}

// 垂直判定
bool is_orthogonal(const Line &l1, const Line &l2) {
    return (dot(l1.b - l1.a, l2.b - l2.a) == 0);
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

// 交差判定
bool is_intersection(const Segment &s1, const Segment &s2) {
    return (counter_clockwise(s2.a, s1.a, s1.b) * counter_clockwise(s2.b, s1.a, s1.b) <= 0 && counter_clockwise(s1.a, s2.a, s2.b) * counter_clockwise(s1.b, s2.a, s2.b) <= 0);
}

// 交点の座標
Point cross_point(const Segment &s1, const Segment &s2) {
    double d1 = cross(s1.a - s2.a, s1.b - s2.a);
    double d2 = cross(s1.a - s1.b, s2.b - s2.a);
    if (abs(d1) < EPS && abs(d2) < EPS) {
        if (counter_clockwise(s1.a, s2.a, s2.b) == 0) return s1.a;
        else return s1.b;
    }
    return s2.a + (s2.b - s2.a) * (d1 / d2);
}

// 線分 s と 点 p の距離
double distance(const Segment s, const Point &p) {
    double t = dot(p - s.a, s.b - s.a) / norm(s.b - s.a);
    if (t > -EPS && t < 1 + EPS) {
        Point proj = Point(s.a.real() + t * (s.b - s.a).real(), s.a.imag() + t * (s.b - s.a).imag());
        return abs(p - proj);
    } else {
        return min(abs(p - s.a), abs(p - s.b));
    }
}

int main() {
    cout << fixed << setprecision(15);
}
