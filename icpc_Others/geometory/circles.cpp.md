---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all
  bundledCode: "#line 1 \"icpc_Others/geometory/circles.cpp\"\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n\
    // 7_A, 7_B, 7_C, 7_D, 7_E, 7_F, 7_G, 7_H, 7_I\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing Point = complex<double>;\nusing Polygon = vector<Point>;\n\
    \nstruct Line {\n    Point a, b;\n    Line(Point a, Point b) : a(a), b(b) {}\n\
    };\n\nstruct Segment : Line {\n    Segment(Point a, Point b) : Line(a, b) {}\n\
    };\n\nstruct Circle {\n    Point p;\n    double r;\n    Circle(Point p, double\
    \ r) : p(p), r(r) {}\n};\n\nconst double pi = acos(-1.0);\nconst double EPS =\
    \ 1e-12;\n\n// \u5185\u7A4D\ndouble dot(const Point &a, const Point &b) {\n  \
    \  return (a.real() * b.real() + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\n\
    double cross(const Point &a, const Point &b) {\n    return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n}\n\n// \u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\nint intersection_of_circle(const\
    \ Circle &c1, const Circle &c2) {\n    double d = abs(c1.p - c2.p);\n    // \u5206\
    \u96E2\n    if (d > c1.r + c2.r + EPS) {\n        return 4;\n    }\n    // \u5916\
    \u63A5\n    if (abs(d - c1.r - c2.r) < EPS) {\n        return 3;\n    }\n    //\
    \ \u4EA4\u5DEE\n    if (d < c1.r + c2.r - EPS && d > abs(c1.r - c2.r) + EPS) {\n\
    \        return 2;\n    }\n    // \u5185\u63A5\n    if (abs(d - abs(c1.r - c2.r))\
    \ < EPS) {\n        return 1;\n    }\n    // \u5305\u542B\n    return 0;\n}\n\n\
    // \u5185\u63A5\u5186\nCircle incircle(const Point &p1, const Point &p2, const\
    \ Point &p3) {\n    double d = abs((p1 - p2)) + abs(p2 - p3) + abs(p3 - p1);\n\
    \    Point p = p1 + (abs(p3 - p1) / d) * (p2 - p1) + (abs(p2 - p1) / d) * (p3\
    \ - p1);\n    double r = abs(cross(p2 - p1, p3 - p1)) / d;\n    return Circle(p,\
    \ r);\n}\n\n// \u5916\u63A5\u5186\nCircle circumscribed_circle(const Point &p1,\
    \ const Point &p2, const Point &p3) {\n    double a = abs(p1 - p2), b = abs(p2\
    \ - p3), c = abs(p3 - p1), S = abs(cross(p2 - p1, p3 - p1)) * 0.5;\n    double\
    \ cx = norm(p2 - p1) * (p3 - p1).imag() - norm(p3 - p1) * (p2 - p1).imag(), cy\
    \ = norm(p3 - p1) * (p2 - p1).real() - norm(p2 - p1) * (p3 - p1).real();\n   \
    \ cx /= 2.0 * cross(p2 - p1, p3 - p1);\n    cy /= 2.0 * cross(p2 - p1, p3 - p1);\n\
    \    Point p = p1 + Point(cx, cy);\n    double r = a * b * c / (4.0 * S);\n  \
    \  return Circle(p, r);\n}\n\n// \u76F4\u7DDA\u3068\u70B9\u306E\u8DDD\u96E2\n\
    double distance(const Line s, const Point &p) {\n    double t = dot(p - s.a, s.b\
    \ - s.a) / norm(s.b - s.a);\n    Point proj = Point(s.a.real() + t * (s.b - s.a).real(),\
    \ s.a.imag() + t * (s.b - s.a).imag());\n    return abs(p - proj);\n}\n\n// \u76F4\
    \u7DDA l \u306B\u5BFE\u3059\u308B\u70B9 p \u306E\u5C04\u5F71\nPoint projection(const\
    \ Line l, const Point &p) {\n    double t = dot(p - l.a, l.b - l.a) / norm(l.b\
    \ - l.a);\n    return Point(l.a.real() + t * (l.b - l.a).real(), l.a.imag() +\
    \ t * (l.b - l.a).imag());\n}\n\n// \u5186\u3068\u76F4\u7DDA\u306E\u4EA4\u70B9\
    \nvector<Point> cross_points(Circle c, Line l) {\n    Point proj = projection(l,\
    \ c.p);\n    double d = abs(proj - c.p);\n    if (d > c.r + EPS) {\n        return\
    \ {};\n    }\n    if (abs(c.r - abs(proj - c.p)) < EPS) {\n        return {proj};\n\
    \    }\n    double s = sqrt(c.r * c.r - norm(proj - c.p));\n    return {proj -\
    \ (s / abs(l.b - l.a)) * (l.b - l.a), proj + (s / abs(l.b - l.a)) * (l.b - l.a)};\n\
    }\n\n// \u5186\u3068\u5186\u306E\u4EA4\u70B9\nvector<Point> cross_points(Circle\
    \ c1, Circle c2) {\n    int t = intersection_of_circle(c1, c2);\n    if (t ==\
    \ 0 || t == 4) {\n        return {};\n    }\n    if (t == 3) {\n        return\
    \ {c1.p + (c1.r / (c1.r + c2.r)) * (c2.p - c1.p)};\n    }\n    if (t == 1) {\n\
    \        if (c1.r > c2.r) return {(-c2.r / abs(c1.r - c2.r)) * c1.p + (c1.r /\
    \ abs(c1.r - c2.r)) * c2.p};\n        return {(c2.r / abs(c1.r - c2.r)) * c1.p\
    \ + (-c1.r / abs(c1.r - c2.r)) * c2.p};\n    }\n    double d = abs(c1.p - c2.p);\n\
    \    double s = (c1.r * c1.r - c2.r * c2.r + d * d) / (2.0 * d);\n    Point p\
    \ = c1.p + (s / d) * (c2.p - c1.p);\n    return {p - (sqrt(c1.r * c1.r - s * s)\
    \ / d) * Point((c2.p - c1.p).imag(), -(c2.p - c1.p).real()), p + (sqrt(c1.r *\
    \ c1.r - s * s) / d) * Point((c2.p - c1.p).imag(), -(c2.p - c1.p).real())};\n\
    }\n\n// \u5186\u306E\u63A5\u7DDA\nvector<Point> tangent(Circle c, Point p) {\n\
    \    return cross_points(c, Circle(p, sqrt(norm(c.p - p) - c.r * c.r)));\n}\n\n\
    // \u5186\u306E\u5171\u901A\u63A5\u7DDA\nvector<Point> common_tangent(Circle c1,\
    \ Circle c2) {\n    double d = norm(c1.p - c2.p);\n    double d1 = d - (c1.r +\
    \ c2.r) * (c1.r + c2.r) + c2.r * c2.r;\n    vector<Point> ps;\n    if (d1 > -EPS)\
    \ {\n        d1 = sqrt(max(d1, 0.0));\n        vector<Point> ps1 = cross_points(c1,\
    \ Circle(c2.p, d1));\n        for (auto p : ps1) ps.push_back(p);\n    }\n   \
    \ double d2 = d - (c1.r - c2.r) * (c1.r - c2.r) + c2.r * c2.r;\n    if (d2 > -EPS)\
    \ {\n        d2 = sqrt(max(d2, 0.0));\n        vector<Point> ps2 = cross_points(c1,\
    \ Circle(c2.p, d2));\n        for (auto p : ps2) ps.push_back(p);\n    }\n   \
    \ return ps;\n}\n\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const\
    \ Polygon &poly) {\n    double ans = 0;\n    int N = poly.size();\n    for (int\
    \ i = 0; i < N; i++) {\n        ans += cross(poly[i], poly[(i + 1) % N]);\n  \
    \  }\n    ans *= 0.5;\n    return ans;\n}\n\n// \u5186\u306E\u5171\u901A\u90E8\
    \u5206\u306E\u9762\u7A4D\ndouble area_of_intersection(Circle c1, Circle c2) {\n\
    \    int t = intersection_of_circle(c1, c2);\n    if (t >= 3) {\n        return\
    \ 0;\n    }\n    if (t <= 1) {\n        return pi * min(c1.r, c2.r) * min(c1.r,\
    \ c2.r);\n    }\n    vector<Point> ps = cross_points(c1, c2);\n    double a1 =\
    \ arg(ps[0] - c1.p) - arg(ps[1] - c1.p), a2 = arg(ps[1] - c2.p) - arg(ps[0] -\
    \ c2.p);\n    if (a1 < -EPS) a1 += 2.0 * pi;\n    if (a2 < -EPS) a2 += 2.0 * pi;\n\
    \    return (a1 / 2) * c1.r * c1.r + (a2 / 2) * c2.r * c2.r - abs(area({ps[0],\
    \ c1.p, ps[1], c2.p}));\n}\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\u30D9\
    \u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\nint counter_clockwise(const\
    \ Point &p2, Point p0, Point p1) {\n    // \u53CD\u6642\u8A08\u56DE\u308A\n  \
    \  if (cross(p1 - p0, p2 - p0) > EPS) {\n        return 1;\n    }\n    // \u6642\
    \u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS) {\n        return\
    \ -1;\n    }\n    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \n    if (dot(p1 - p0, p2 - p0) < -EPS) {\n        return 2;\n    }\n    // p0,\
    \ p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0,\
    \ p2 - p0) > norm(p1 - p0) + EPS) {\n        return -2;\n    }\n    // p2 \u306F\
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\nint is_contained(const\
    \ Point p, const Polygon poly) {\n    int N = poly.size();\n    int cnt = 0;\n\
    \    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(p, poly[i],\
    \ poly[(i + 1) % N]) == 0) {\n            return 1;\n        }\n        Point\
    \ a = poly[i], b = poly[(i + 1) % N];\n        if (a.imag() > b.imag()) swap(a,\
    \ b);\n        if (p.imag() < b.imag() + EPS && p.imag() > a.imag() + EPS && counter_clockwise(p,\
    \ a, b) < 0) {\n            cnt++;\n        }\n    }\n    if (cnt % 2 == 0) return\
    \ 0;\n    else return 2;\n}\n\n// \u5186\u3068\u7DDA\u5206\u306E\u4EA4\u70B9\n\
    vector<Point> cross_points(Circle c, Line l) {\n    Point proj = projection(l,\
    \ c.p);\n    double d = abs(proj - c.p);\n    if (d > c.r + EPS) {\n        return\
    \ {};\n    }\n    if (abs(c.r - abs(proj - c.p)) < EPS) {\n        if (counter_clockwise(proj,\
    \ l.a, l.b) == 0) return {proj};\n        else return {};\n    }\n    double s\
    \ = sqrt(c.r * c.r - norm(proj - c.p));\n    Point p1 = proj - (s / abs(l.b -\
    \ l.a)) * (l.b - l.a), p2 = proj + (s / abs(l.b - l.a)) * (l.b - l.a);\n    vector<Point>\
    \ ps;\n    if (counter_clockwise(p1, l.a, l.b)) ps.push_back(p1);\n    if (counter_clockwise(p2,\
    \ l.a, l.b)) ps.push_back(p2);\n    return ps;\n}\n\n// \u5186\u3068\u591A\u89D2\
    \u5F62\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D\ndouble area_of_intersection(Circle\
    \ c, Polygon poly) {\n    int N = poly.size();\n}\n\nint main() {\n    cout <<\
    \ fixed << setprecision(15);\n    int N, R;\n    cin >> N >> R;\n    Polygon poly(N);\n\
    \    for (int i = 0; i < N; i++) {\n        int x, y;\n        cin >> x >> y;\n\
    \        poly[i] = Point(x, y);\n    }\n    cout << area_of_intersection(Circle(Point(0,\
    \ 0), R), poly) << \"\\n\";\n}\n"
  code: "// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n// 7_A, 7_B,\
    \ 7_C, 7_D, 7_E, 7_F, 7_G, 7_H, 7_I\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing Point = complex<double>;\nusing Polygon = vector<Point>;\n\nstruct\
    \ Line {\n    Point a, b;\n    Line(Point a, Point b) : a(a), b(b) {}\n};\n\n\
    struct Segment : Line {\n    Segment(Point a, Point b) : Line(a, b) {}\n};\n\n\
    struct Circle {\n    Point p;\n    double r;\n    Circle(Point p, double r) :\
    \ p(p), r(r) {}\n};\n\nconst double pi = acos(-1.0);\nconst double EPS = 1e-12;\n\
    \n// \u5185\u7A4D\ndouble dot(const Point &a, const Point &b) {\n    return (a.real()\
    \ * b.real() + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const\
    \ Point &a, const Point &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n\
    }\n\n// \u5186\u306E\u4EA4\u5DEE\u5224\u5B9A\nint intersection_of_circle(const\
    \ Circle &c1, const Circle &c2) {\n    double d = abs(c1.p - c2.p);\n    // \u5206\
    \u96E2\n    if (d > c1.r + c2.r + EPS) {\n        return 4;\n    }\n    // \u5916\
    \u63A5\n    if (abs(d - c1.r - c2.r) < EPS) {\n        return 3;\n    }\n    //\
    \ \u4EA4\u5DEE\n    if (d < c1.r + c2.r - EPS && d > abs(c1.r - c2.r) + EPS) {\n\
    \        return 2;\n    }\n    // \u5185\u63A5\n    if (abs(d - abs(c1.r - c2.r))\
    \ < EPS) {\n        return 1;\n    }\n    // \u5305\u542B\n    return 0;\n}\n\n\
    // \u5185\u63A5\u5186\nCircle incircle(const Point &p1, const Point &p2, const\
    \ Point &p3) {\n    double d = abs((p1 - p2)) + abs(p2 - p3) + abs(p3 - p1);\n\
    \    Point p = p1 + (abs(p3 - p1) / d) * (p2 - p1) + (abs(p2 - p1) / d) * (p3\
    \ - p1);\n    double r = abs(cross(p2 - p1, p3 - p1)) / d;\n    return Circle(p,\
    \ r);\n}\n\n// \u5916\u63A5\u5186\nCircle circumscribed_circle(const Point &p1,\
    \ const Point &p2, const Point &p3) {\n    double a = abs(p1 - p2), b = abs(p2\
    \ - p3), c = abs(p3 - p1), S = abs(cross(p2 - p1, p3 - p1)) * 0.5;\n    double\
    \ cx = norm(p2 - p1) * (p3 - p1).imag() - norm(p3 - p1) * (p2 - p1).imag(), cy\
    \ = norm(p3 - p1) * (p2 - p1).real() - norm(p2 - p1) * (p3 - p1).real();\n   \
    \ cx /= 2.0 * cross(p2 - p1, p3 - p1);\n    cy /= 2.0 * cross(p2 - p1, p3 - p1);\n\
    \    Point p = p1 + Point(cx, cy);\n    double r = a * b * c / (4.0 * S);\n  \
    \  return Circle(p, r);\n}\n\n// \u76F4\u7DDA\u3068\u70B9\u306E\u8DDD\u96E2\n\
    double distance(const Line s, const Point &p) {\n    double t = dot(p - s.a, s.b\
    \ - s.a) / norm(s.b - s.a);\n    Point proj = Point(s.a.real() + t * (s.b - s.a).real(),\
    \ s.a.imag() + t * (s.b - s.a).imag());\n    return abs(p - proj);\n}\n\n// \u76F4\
    \u7DDA l \u306B\u5BFE\u3059\u308B\u70B9 p \u306E\u5C04\u5F71\nPoint projection(const\
    \ Line l, const Point &p) {\n    double t = dot(p - l.a, l.b - l.a) / norm(l.b\
    \ - l.a);\n    return Point(l.a.real() + t * (l.b - l.a).real(), l.a.imag() +\
    \ t * (l.b - l.a).imag());\n}\n\n// \u5186\u3068\u76F4\u7DDA\u306E\u4EA4\u70B9\
    \nvector<Point> cross_points(Circle c, Line l) {\n    Point proj = projection(l,\
    \ c.p);\n    double d = abs(proj - c.p);\n    if (d > c.r + EPS) {\n        return\
    \ {};\n    }\n    if (abs(c.r - abs(proj - c.p)) < EPS) {\n        return {proj};\n\
    \    }\n    double s = sqrt(c.r * c.r - norm(proj - c.p));\n    return {proj -\
    \ (s / abs(l.b - l.a)) * (l.b - l.a), proj + (s / abs(l.b - l.a)) * (l.b - l.a)};\n\
    }\n\n// \u5186\u3068\u5186\u306E\u4EA4\u70B9\nvector<Point> cross_points(Circle\
    \ c1, Circle c2) {\n    int t = intersection_of_circle(c1, c2);\n    if (t ==\
    \ 0 || t == 4) {\n        return {};\n    }\n    if (t == 3) {\n        return\
    \ {c1.p + (c1.r / (c1.r + c2.r)) * (c2.p - c1.p)};\n    }\n    if (t == 1) {\n\
    \        if (c1.r > c2.r) return {(-c2.r / abs(c1.r - c2.r)) * c1.p + (c1.r /\
    \ abs(c1.r - c2.r)) * c2.p};\n        return {(c2.r / abs(c1.r - c2.r)) * c1.p\
    \ + (-c1.r / abs(c1.r - c2.r)) * c2.p};\n    }\n    double d = abs(c1.p - c2.p);\n\
    \    double s = (c1.r * c1.r - c2.r * c2.r + d * d) / (2.0 * d);\n    Point p\
    \ = c1.p + (s / d) * (c2.p - c1.p);\n    return {p - (sqrt(c1.r * c1.r - s * s)\
    \ / d) * Point((c2.p - c1.p).imag(), -(c2.p - c1.p).real()), p + (sqrt(c1.r *\
    \ c1.r - s * s) / d) * Point((c2.p - c1.p).imag(), -(c2.p - c1.p).real())};\n\
    }\n\n// \u5186\u306E\u63A5\u7DDA\nvector<Point> tangent(Circle c, Point p) {\n\
    \    return cross_points(c, Circle(p, sqrt(norm(c.p - p) - c.r * c.r)));\n}\n\n\
    // \u5186\u306E\u5171\u901A\u63A5\u7DDA\nvector<Point> common_tangent(Circle c1,\
    \ Circle c2) {\n    double d = norm(c1.p - c2.p);\n    double d1 = d - (c1.r +\
    \ c2.r) * (c1.r + c2.r) + c2.r * c2.r;\n    vector<Point> ps;\n    if (d1 > -EPS)\
    \ {\n        d1 = sqrt(max(d1, 0.0));\n        vector<Point> ps1 = cross_points(c1,\
    \ Circle(c2.p, d1));\n        for (auto p : ps1) ps.push_back(p);\n    }\n   \
    \ double d2 = d - (c1.r - c2.r) * (c1.r - c2.r) + c2.r * c2.r;\n    if (d2 > -EPS)\
    \ {\n        d2 = sqrt(max(d2, 0.0));\n        vector<Point> ps2 = cross_points(c1,\
    \ Circle(c2.p, d2));\n        for (auto p : ps2) ps.push_back(p);\n    }\n   \
    \ return ps;\n}\n\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const\
    \ Polygon &poly) {\n    double ans = 0;\n    int N = poly.size();\n    for (int\
    \ i = 0; i < N; i++) {\n        ans += cross(poly[i], poly[(i + 1) % N]);\n  \
    \  }\n    ans *= 0.5;\n    return ans;\n}\n\n// \u5186\u306E\u5171\u901A\u90E8\
    \u5206\u306E\u9762\u7A4D\ndouble area_of_intersection(Circle c1, Circle c2) {\n\
    \    int t = intersection_of_circle(c1, c2);\n    if (t >= 3) {\n        return\
    \ 0;\n    }\n    if (t <= 1) {\n        return pi * min(c1.r, c2.r) * min(c1.r,\
    \ c2.r);\n    }\n    vector<Point> ps = cross_points(c1, c2);\n    double a1 =\
    \ arg(ps[0] - c1.p) - arg(ps[1] - c1.p), a2 = arg(ps[1] - c2.p) - arg(ps[0] -\
    \ c2.p);\n    if (a1 < -EPS) a1 += 2.0 * pi;\n    if (a2 < -EPS) a2 += 2.0 * pi;\n\
    \    return (a1 / 2) * c1.r * c1.r + (a2 / 2) * c2.r * c2.r - abs(area({ps[0],\
    \ c1.p, ps[1], c2.p}));\n}\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\u30D9\
    \u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\nint counter_clockwise(const\
    \ Point &p2, Point p0, Point p1) {\n    // \u53CD\u6642\u8A08\u56DE\u308A\n  \
    \  if (cross(p1 - p0, p2 - p0) > EPS) {\n        return 1;\n    }\n    // \u6642\
    \u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS) {\n        return\
    \ -1;\n    }\n    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \n    if (dot(p1 - p0, p2 - p0) < -EPS) {\n        return 2;\n    }\n    // p0,\
    \ p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0,\
    \ p2 - p0) > norm(p1 - p0) + EPS) {\n        return -2;\n    }\n    // p2 \u306F\
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\nint is_contained(const\
    \ Point p, const Polygon poly) {\n    int N = poly.size();\n    int cnt = 0;\n\
    \    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(p, poly[i],\
    \ poly[(i + 1) % N]) == 0) {\n            return 1;\n        }\n        Point\
    \ a = poly[i], b = poly[(i + 1) % N];\n        if (a.imag() > b.imag()) swap(a,\
    \ b);\n        if (p.imag() < b.imag() + EPS && p.imag() > a.imag() + EPS && counter_clockwise(p,\
    \ a, b) < 0) {\n            cnt++;\n        }\n    }\n    if (cnt % 2 == 0) return\
    \ 0;\n    else return 2;\n}\n\n// \u5186\u3068\u7DDA\u5206\u306E\u4EA4\u70B9\n\
    vector<Point> cross_points(Circle c, Line l) {\n    Point proj = projection(l,\
    \ c.p);\n    double d = abs(proj - c.p);\n    if (d > c.r + EPS) {\n        return\
    \ {};\n    }\n    if (abs(c.r - abs(proj - c.p)) < EPS) {\n        if (counter_clockwise(proj,\
    \ l.a, l.b) == 0) return {proj};\n        else return {};\n    }\n    double s\
    \ = sqrt(c.r * c.r - norm(proj - c.p));\n    Point p1 = proj - (s / abs(l.b -\
    \ l.a)) * (l.b - l.a), p2 = proj + (s / abs(l.b - l.a)) * (l.b - l.a);\n    vector<Point>\
    \ ps;\n    if (counter_clockwise(p1, l.a, l.b)) ps.push_back(p1);\n    if (counter_clockwise(p2,\
    \ l.a, l.b)) ps.push_back(p2);\n    return ps;\n}\n\n// \u5186\u3068\u591A\u89D2\
    \u5F62\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D\ndouble area_of_intersection(Circle\
    \ c, Polygon poly) {\n    int N = poly.size();\n}\n\nint main() {\n    cout <<\
    \ fixed << setprecision(15);\n    int N, R;\n    cin >> N >> R;\n    Polygon poly(N);\n\
    \    for (int i = 0; i < N; i++) {\n        int x, y;\n        cin >> x >> y;\n\
    \        poly[i] = Point(x, y);\n    }\n    cout << area_of_intersection(Circle(Point(0,\
    \ 0), R), poly) << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc_Others/geometory/circles.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:38:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc_Others/geometory/circles.cpp
layout: document
redirect_from:
- /library/icpc_Others/geometory/circles.cpp
- /library/icpc_Others/geometory/circles.cpp.html
title: icpc_Others/geometory/circles.cpp
---
