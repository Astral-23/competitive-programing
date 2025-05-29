// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all
// 1_A, 1_B, 1_C

#include <bits/stdc++.h>
using namespace std;

using Point = complex<double>;

struct Line {
    Point a, b;
    Line(Point a, Point b) : a(a), b(b) {}
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

// // p0 から p1 へ結んだベクトルから見た p2 の位置
// int counter_clockwise(const Point &p2, Point p0, Point p1) {
//     // 反時計回り
//     if (cross(p1 - p0, p2 - p0) > EPS) {
//         return 0;
//     }
//     // 時計回り
//     if (cross(p1 - p0, p2 - p0) < -EPS) {
//         return 1;
//     }
//     // p2, p0, p1 の順で同一直線上
//     if (dot(p1 - p0, p2 - p0) < -EPS) {
//         return 2;
//     }
//     // p0, p1, p2 の順で同一直線上
//     if (dot(p1 - p0, p2 - p0) > norm(p1 - p0) + EPS) {
//         return 3;
//     }
//     // p2 は p0 と p1 を結ぶ線分上
//     return 4;
// }

int main() {
    cout << fixed << setprecision(15);
}
