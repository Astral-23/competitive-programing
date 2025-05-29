---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"icpc_Others/geometory/geometry.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing Point = complex<double>;\nusing Polygon = vector<Point>;\n\
    \nstruct Line {\n    Point a, b;\n    Line(Point a, Point b) : a(a), b(b) {}\n\
    };\n\nstruct Segment : Line {\n    Segment(Point a, Point b) : Line(a, b) {}\n\
    };\n\nstruct Circle {\n    Point p;\n    double r;\n    Circle(Point p, double\
    \ r) : p(p), r(r) {}\n};\n\nconst double pi = acos(-1.0);\nconst double EPS =\
    \ 1e-12;\n\n// \u5185\u7A4D\ndouble dot(const Point &a, const Point &b) {\n  \
    \  return (a.real() * b.real() + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\n\
    double cross(const Point &a, const Point &b) {\n    return (a.real() * b.imag()\
    \ - a.imag() * b.real());\n}\n\n// \u76F4\u7DDA l \u306B\u5BFE\u3059\u308B\u70B9\
    \ p \u306E\u5C04\u5F71\nPoint projection(const Line l, const Point &p) {\n   \
    \ double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n    return Point(l.a.real()\
    \ + t * (l.b - l.a).real(), l.a.imag() + t * (l.b - l.a).imag());\n}\n\n// \u76F4\
    \u7DDA l \u306B\u5BFE\u3059\u308B\u70B9 p \u306E\u53CD\u5C04\nPoint reflection(const\
    \ Line l, const Point &p) {\n    double t = dot(p - l.a, l.b - l.a) / norm(l.b\
    \ - l.a);\n    Point q(l.a.real() + t * (l.b - l.a).real(), l.a.imag() + t * (l.b\
    \ - l.a).imag());\n    return Point(2 * q.real() - p.real(), 2 * q.imag() - p.imag());\n\
    }\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\u30D9\u30AF\u30C8\u30EB\u304B\
    \u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\nint counter_clockwise(const Point &p2,\
    \ Point p0, Point p1) {\n    // \u53CD\u6642\u8A08\u56DE\u308A\n    if (cross(p1\
    \ - p0, p2 - p0) > EPS) {\n        return 1;\n    }\n    // \u6642\u8A08\u56DE\
    \u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS) {\n        return -1;\n    }\n\
    \    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1\
    \ - p0, p2 - p0) < -EPS) {\n        return 2;\n    }\n    // p0, p1, p2 \u306E\
    \u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0, p2 - p0) > norm(p1\
    \ - p0) + EPS) {\n        return -2;\n    }\n    // p2 \u306F p0 \u3068 p1 \u3092\
    \u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\n// \u5E73\u884C\u5224\u5B9A\
    \nbool is_parallel(const Line &l1, const Line &l2) {\n    return (cross(l1.b -\
    \ l1.a, l2.b - l2.a) == 0);\n}\n\n// \u5782\u76F4\u5224\u5B9A\nbool is_orthogonal(const\
    \ Line &l1, const Line &l2) {\n    return (dot(l1.b - l1.a, l2.b - l2.a) == 0);\n\
    }\n\n// \u7DDA\u5206\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool is_intersection(const\
    \ Segment &s1, const Segment &s2) {\n    return (counter_clockwise(s2.a, s1.a,\
    \ s1.b) * counter_clockwise(s2.b, s1.a, s1.b) <= 0 && counter_clockwise(s1.a,\
    \ s2.a, s2.b) * counter_clockwise(s1.b, s2.a, s2.b) <= 0);\n}\n\n// \u7DDA\u5206\
    \u3068\u7DDA\u5206\u306E\u4EA4\u70B9\u306E\u5EA7\u6A19\nPoint cross_point(const\
    \ Segment &s1, const Segment &s2) {\n    double d1 = cross(s1.a - s2.a, s1.b -\
    \ s2.a);\n    double d2 = cross(s1.a - s1.b, s2.b - s2.a);\n    if (abs(d1) <\
    \ EPS && abs(d2) < EPS) {\n        if (counter_clockwise(s1.a, s2.a, s2.b) ==\
    \ 0) return s1.a;\n        else return s1.b;\n    }\n    return s2.a + (s2.b -\
    \ s2.a) * (d1 / d2);\n}\n\n// \u76F4\u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\
    \u5224\u5B9A\nbool is_intersection(const Line &l1, const Segment &s2) {\n    return\
    \ (counter_clockwise(s2.a, l1.a, l1.b) * counter_clockwise(s2.b, l1.a, l1.b) <=\
    \ 0);\n}\n\n// \u76F4\u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u70B9\u306E\u5EA7\u6A19\
    \nPoint cross_point(const Line &s1, const Segment &s2) {\n    double d1 = cross(s1.a\
    \ - s2.a, s1.b - s2.a);\n    double d2 = cross(s1.a - s1.b, s2.b - s2.a);\n  \
    \  if (abs(d1) < EPS && abs(d2) < EPS) {\n        return s2.a;\n    }\n    return\
    \ s2.a + (s2.b - s2.a) * (d1 / d2);\n}\n\n// \u76F4\u7DDA\u3068\u70B9\u306E\u8DDD\
    \u96E2\ndouble distance(const Line s, const Point &p) {\n    double t = dot(p\
    \ - s.a, s.b - s.a) / norm(s.b - s.a);\n    Point proj = Point(s.a.real() + t\
    \ * (s.b - s.a).real(), s.a.imag() + t * (s.b - s.a).imag());\n    return abs(p\
    \ - proj);\n}\n\n// \u7DDA\u5206\u3068\u70B9\u306E\u8DDD\u96E2\ndouble distance(const\
    \ Segment s, const Point &p) {\n    double t = dot(p - s.a, s.b - s.a) / norm(s.b\
    \ - s.a);\n    if (t > -EPS && t < 1 + EPS) {\n        Point proj = Point(s.a.real()\
    \ + t * (s.b - s.a).real(), s.a.imag() + t * (s.b - s.a).imag());\n        return\
    \ abs(p - proj);\n    } else {\n        return min(abs(p - s.a), abs(p - s.b));\n\
    \    }\n}\n\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const Polygon\
    \ &poly) {\n    double ans = 0;\n    int N = poly.size();\n    for (int i = 0;\
    \ i < N; i++) {\n        ans += cross(poly[i], poly[(i + 1) % N]);\n    }\n  \
    \  ans *= 0.5;\n    return ans;\n}\n\n// \u51F8\u6027\u5224\u5B9A\nbool is_convex(const\
    \ Polygon &poly) {\n    int N = poly.size();\n    for (int i = 0; i < N; i++)\
    \ {\n        if (counter_clockwise(poly[i], poly[(i + 1) % N], poly[(i + 2) %\
    \ N]) == -1) return false;\n    }\n    return true;\n}\n\n// \u591A\u89D2\u5F62\
    \u3068\u70B9\u306E\u5305\u542B\u95A2\u4FC2\nint is_contained(const Point p, const\
    \ Polygon poly) {\n    int N = poly.size();\n    int cnt = 0;\n    for (int i\
    \ = 0; i < N; i++) {\n        if (counter_clockwise(p, poly[i], poly[(i + 1) %\
    \ N]) == 0) {\n            return 1;\n        }\n        Point a = poly[i], b\
    \ = poly[(i + 1) % N];\n        if (a.imag() > b.imag()) swap(a, b);\n       \
    \ if (p.imag() < b.imag() + EPS && p.imag() > a.imag() + EPS && counter_clockwise(p,\
    \ a, b) < 0) {\n            cnt++;\n        }\n    }\n    if (cnt % 2 == 0) return\
    \ 0;\n    else return 2;\n}\n\n// \u51F8\u5305\nPolygon convex_hull(vector<Point>\
    \ &ps) {\n    int N = ps.size();\n    auto compare = [](const Point &p1, const\
    \ Point &p2) {\n        if (p1.real() != p2.real()) return p1.real() < p2.real();\n\
    \        return p1.imag() < p2.imag();\n    };\n    sort(ps.begin(), ps.end(),\
    \ compare);\n    int k = 0;\n    Polygon qs(2 * N);\n    // \u4E0B\u5074\u51F8\
    \u5305\n    for (int i = 0; i < N; i++) {\n        while (k > 1 && cross(qs[k\
    \ - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS) k--;\n        qs[k++] = ps[i];\n\
    \    }\n    // \u4E0A\u5074\u51F8\u5305\n    for (int i = N - 2, t = k; i >= 0;\
    \ i--) {\n        while (k > t && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k -\
    \ 1]) < EPS) k--;\n        qs[k++] = ps[i];\n    }\n    qs.resize(k - 1);\n  \
    \  return qs;\n}\n\n// \u6700\u3082\u9060\u3044\uFF12\u70B9\u306E\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\ndouble farest_pair(vector<Point> &ps) {\n    Polygon poly\
    \ = convex_hull(ps);\n    double ans = 0;\n    for (int i = 0; i < (int)poly.size();\
    \ i++) {\n        for (int j = 0; j < i; j++) {\n            ans = max(ans, abs(poly[i]\
    \ - poly[j]));\n        }\n    }\n    return ans;\n}\n\n// \u76F4\u7DDA l \u3067\
    \u51F8\u591A\u89D2\u5F62\u3092\u5207\u65AD\u3059\u308B\nPolygon convex_cut(const\
    \ Polygon &poly, const Line &l) {\n    int N = poly.size();\n    vector<Point>\
    \ ps;\n    for (int i = 0; i < N; i++) {\n        if (cross(l.b - l.a, poly[i]\
    \ - l.a) > -EPS) {\n            ps.push_back(poly[i]);\n        }\n        if\
    \ (is_intersection(l, Segment(poly[i], poly[(i + 1) % N]))) {\n            ps.push_back(cross_point(l,\
    \ Segment(poly[i], poly[(i + 1) % N])));\n        }\n    }\n    if (ps.size()\
    \ <= 0) return {};\n    Polygon ch = convex_hull(ps);\n    return ch;\n}\n\n//\
    \ \u6700\u3082\u8FD1\u3044\uFF12\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\
    \ndouble closest_pair(vector<Point> &ps) {\n    auto dfs = [&](auto dfs, vector<Point>\
    \ qs) -> double {\n        int N = qs.size();\n        if (N <= 1) return 1e18;\n\
    \        sort(qs.begin(), qs.end(), [](const Point &p1, const Point &p2) {\n \
    \           if (abs(p1.real() - p2.real()) < EPS) return p1.imag() < p2.imag();\n\
    \            return p1.real() < p2.real();\n        });\n        vector<Point>\
    \ P1, P2;\n        for (int i = 0; i < N / 2; i++) P1.push_back(qs[i]);\n    \
    \    for (int i = N / 2; i < N; i++) P2.push_back(qs[i]);\n        double d1 =\
    \ dfs(dfs, P1), d2 = dfs(dfs, P2);\n        double d = min(d1, d2), ans = d;\n\
    \        double px = P1[N / 2 - 1].real(), py = P1[N / 2 - 1].imag();\n      \
    \  vector<pair<double, int>> V;\n        for (int i = 0; i < N; i++) {\n     \
    \       if (qs[i].real() < px - d - EPS || qs[i].real() > px + d + EPS) continue;\n\
    \            V.push_back(make_pair(qs[i].imag(), i));\n        }\n        sort(V.begin(),\
    \ V.end());\n        int r = 0;\n        for (int l = 0; l < (int)V.size(); l++)\
    \ {\n            r = max(r, l);\n            while (r < (int)V.size() && V[r].first\
    \ < V[l].first + d + EPS) {\n                if (l != r) ans = min(ans, abs(qs[V[l].second]\
    \ - qs[V[r].second]));\n                r++;\n            }\n        }\n     \
    \   return ans;\n    };\n    return dfs(dfs, ps);\n}\n\n// \u5186\u306E\u4EA4\u5DEE\
    \u5224\u5B9A\nint intersection_of_circle(const Circle &c1, const Circle &c2) {\n\
    \    double d = abs(c1.p - c2.p);\n    // \u5206\u96E2\n    if (d > c1.r + c2.r\
    \ + EPS) {\n        return 4;\n    }\n    // \u5916\u63A5\n    if (abs(d - c1.r\
    \ - c2.r) < EPS) {\n        return 3;\n    }\n    // \u4EA4\u5DEE\n    if (d <\
    \ c1.r + c2.r - EPS && d > abs(c1.r - c2.r) + EPS) {\n        return 2;\n    }\n\
    \    // \u5185\u63A5\n    if (abs(d - abs(c1.r - c2.r)) < EPS) {\n        return\
    \ 1;\n    }\n    // \u5305\u542B\n    return 0;\n}\n\n// \u5185\u63A5\u5186\n\
    Circle incircle(const Point &p1, const Point &p2, const Point &p3) {\n    double\
    \ d = abs((p1 - p2)) + abs(p2 - p3) + abs(p3 - p1);\n    Point p = p1 + (abs(p3\
    \ - p1) / d) * (p2 - p1) + (abs(p2 - p1) / d) * (p3 - p1);\n    double r = abs(cross(p2\
    \ - p1, p3 - p1)) / d;\n    return Circle(p, r);\n}\n\n// \u5916\u63A5\u5186\n\
    Circle circumscribed_circle(const Point &p1, const Point &p2, const Point &p3)\
    \ {\n    double a = abs(p1 - p2), b = abs(p2 - p3), c = abs(p3 - p1), S = abs(cross(p2\
    \ - p1, p3 - p1)) * 0.5;\n    double cx = norm(p2 - p1) * (p3 - p1).imag() - norm(p3\
    \ - p1) * (p2 - p1).imag(), cy = norm(p3 - p1) * (p2 - p1).real() - norm(p2 -\
    \ p1) * (p3 - p1).real();\n    cx /= 2.0 * cross(p2 - p1, p3 - p1);\n    cy /=\
    \ 2.0 * cross(p2 - p1, p3 - p1);\n    Point p = p1 + Point(cx, cy);\n    double\
    \ r = a * b * c / (4.0 * S);\n    return Circle(p, r);\n}\n\n// \u5186\u3068\u76F4\
    \u7DDA\u306E\u4EA4\u70B9\nvector<Point> cross_points(Circle c, Line l) {\n   \
    \ Point proj = projection(l, c.p);\n    double d = abs(proj - c.p);\n    if (d\
    \ > c.r + EPS) {\n        return {};\n    } else if (abs(c.r - abs(proj - c.p))\
    \ < EPS) {\n        return {proj};\n    } else {\n        double s = sqrt(c.r\
    \ * c.r - norm(proj - c.p));\n        return {proj - (s / abs(l.b - l.a)) * (l.b\
    \ - l.a), proj + (s / abs(l.b - l.a)) * (l.b - l.a)};\n    }\n}\n\n// \u5186\u3068\
    \u5186\u306E\u4EA4\u70B9\nvector<Point> cross_points(Circle c1, Circle c2) {\n\
    \    int t = intersection_of_circle(c1, c2);\n    if (t == 0 || t == 4) {\n  \
    \      return {};\n    }\n    if (t == 3) {\n        return {c1.p + (c1.r / (c1.r\
    \ + c2.r)) * (c2.p - c1.p)};\n    }\n    if (t == 1) {\n        if (c1.r > c2.r)\
    \ return {(-c2.r / abs(c1.r - c2.r)) * c1.p + (c1.r / abs(c1.r - c2.r)) * c2.p};\n\
    \        return {(c2.r / abs(c1.r - c2.r)) * c1.p + (-c1.r / abs(c1.r - c2.r))\
    \ * c2.p};\n    }\n    double d = abs(c1.p - c2.p);\n    double s = (c1.r * c1.r\
    \ - c2.r * c2.r + d * d) / (2.0 * d);\n    Point p = c1.p + (s / d) * (c2.p -\
    \ c1.p);\n    return {p - (sqrt(c1.r * c1.r - s * s) / d) * Point((c2.p - c1.p).imag(),\
    \ -(c2.p - c1.p).real()), p + (sqrt(c1.r * c1.r - s * s) / d) * Point((c2.p -\
    \ c1.p).imag(), -(c2.p - c1.p).real())};\n}\n\n// \u5186\u306E\u63A5\u7DDA\nvector<Point>\
    \ tangent(Circle c, Point p) {\n    return cross_points(c, Circle(p, sqrt(norm(c.p\
    \ - p) - c.r * c.r)));\n}\n\n// \u5186\u306E\u5171\u901A\u63A5\u7DDA\nvector<Point>\
    \ common_tangent(Circle c1, Circle c2) {\n    double d = norm(c1.p - c2.p);\n\
    \    double d1 = d - (c1.r + c2.r) * (c1.r + c2.r) + c2.r * c2.r;\n    vector<Point>\
    \ ps;\n    if (d1 > -EPS) {\n        d1 = sqrt(max(d1, 0.0));\n        vector<Point>\
    \ ps1 = cross_points(c1, Circle(c2.p, d1));\n        for (auto p : ps1) ps.push_back(p);\n\
    \    }\n    double d2 = d - (c1.r - c2.r) * (c1.r - c2.r) + c2.r * c2.r;\n   \
    \ if (d2 > -EPS) {\n        d2 = sqrt(max(d2, 0.0));\n        vector<Point> ps2\
    \ = cross_points(c1, Circle(c2.p, d2));\n        for (auto p : ps2) ps.push_back(p);\n\
    \    }\n    return ps;\n}\n\n// \u5186\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\
    \u7A4D\ndouble area_of_intersection(Circle c1, Circle c2) {\n    int t = intersection_of_circle(c1,\
    \ c2);\n    if (t >= 3) {\n        return 0;\n    }\n    if (t <= 1) {\n     \
    \   return pi * min(c1.r, c2.r) * min(c1.r, c2.r);\n    }\n    vector<Point> ps\
    \ = cross_points(c1, c2);\n    double a1 = arg(ps[0] - c1.p) - arg(ps[1] - c1.p),\
    \ a2 = arg(ps[1] - c2.p) - arg(ps[0] - c2.p);\n    if (a1 < -EPS) a1 += 2.0 *\
    \ pi;\n    if (a2 < -EPS) a2 += 2.0 * pi;\n    return (a1 / 2) * c1.r * c1.r +\
    \ (a2 / 2) * c2.r * c2.r - abs(area({ps[0], c1.p, ps[1], c2.p}));\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point = complex<double>;\n\
    using Polygon = vector<Point>;\n\nstruct Line {\n    Point a, b;\n    Line(Point\
    \ a, Point b) : a(a), b(b) {}\n};\n\nstruct Segment : Line {\n    Segment(Point\
    \ a, Point b) : Line(a, b) {}\n};\n\nstruct Circle {\n    Point p;\n    double\
    \ r;\n    Circle(Point p, double r) : p(p), r(r) {}\n};\n\nconst double pi = acos(-1.0);\n\
    const double EPS = 1e-12;\n\n// \u5185\u7A4D\ndouble dot(const Point &a, const\
    \ Point &b) {\n    return (a.real() * b.real() + a.imag() * b.imag());\n}\n\n\
    // \u5916\u7A4D\ndouble cross(const Point &a, const Point &b) {\n    return (a.real()\
    \ * b.imag() - a.imag() * b.real());\n}\n\n// \u76F4\u7DDA l \u306B\u5BFE\u3059\
    \u308B\u70B9 p \u306E\u5C04\u5F71\nPoint projection(const Line l, const Point\
    \ &p) {\n    double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n    return\
    \ Point(l.a.real() + t * (l.b - l.a).real(), l.a.imag() + t * (l.b - l.a).imag());\n\
    }\n\n// \u76F4\u7DDA l \u306B\u5BFE\u3059\u308B\u70B9 p \u306E\u53CD\u5C04\nPoint\
    \ reflection(const Line l, const Point &p) {\n    double t = dot(p - l.a, l.b\
    \ - l.a) / norm(l.b - l.a);\n    Point q(l.a.real() + t * (l.b - l.a).real(),\
    \ l.a.imag() + t * (l.b - l.a).imag());\n    return Point(2 * q.real() - p.real(),\
    \ 2 * q.imag() - p.imag());\n}\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\
    \u30D9\u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\nint counter_clockwise(const\
    \ Point &p2, Point p0, Point p1) {\n    // \u53CD\u6642\u8A08\u56DE\u308A\n  \
    \  if (cross(p1 - p0, p2 - p0) > EPS) {\n        return 1;\n    }\n    // \u6642\
    \u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS) {\n        return\
    \ -1;\n    }\n    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \n    if (dot(p1 - p0, p2 - p0) < -EPS) {\n        return 2;\n    }\n    // p0,\
    \ p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0,\
    \ p2 - p0) > norm(p1 - p0) + EPS) {\n        return -2;\n    }\n    // p2 \u306F\
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\n// \u5E73\
    \u884C\u5224\u5B9A\nbool is_parallel(const Line &l1, const Line &l2) {\n    return\
    \ (cross(l1.b - l1.a, l2.b - l2.a) == 0);\n}\n\n// \u5782\u76F4\u5224\u5B9A\n\
    bool is_orthogonal(const Line &l1, const Line &l2) {\n    return (dot(l1.b - l1.a,\
    \ l2.b - l2.a) == 0);\n}\n\n// \u7DDA\u5206\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\
    \u5224\u5B9A\nbool is_intersection(const Segment &s1, const Segment &s2) {\n \
    \   return (counter_clockwise(s2.a, s1.a, s1.b) * counter_clockwise(s2.b, s1.a,\
    \ s1.b) <= 0 && counter_clockwise(s1.a, s2.a, s2.b) * counter_clockwise(s1.b,\
    \ s2.a, s2.b) <= 0);\n}\n\n// \u7DDA\u5206\u3068\u7DDA\u5206\u306E\u4EA4\u70B9\
    \u306E\u5EA7\u6A19\nPoint cross_point(const Segment &s1, const Segment &s2) {\n\
    \    double d1 = cross(s1.a - s2.a, s1.b - s2.a);\n    double d2 = cross(s1.a\
    \ - s1.b, s2.b - s2.a);\n    if (abs(d1) < EPS && abs(d2) < EPS) {\n        if\
    \ (counter_clockwise(s1.a, s2.a, s2.b) == 0) return s1.a;\n        else return\
    \ s1.b;\n    }\n    return s2.a + (s2.b - s2.a) * (d1 / d2);\n}\n\n// \u76F4\u7DDA\
    \u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool is_intersection(const Line\
    \ &l1, const Segment &s2) {\n    return (counter_clockwise(s2.a, l1.a, l1.b) *\
    \ counter_clockwise(s2.b, l1.a, l1.b) <= 0);\n}\n\n// \u76F4\u7DDA\u3068\u7DDA\
    \u5206\u306E\u4EA4\u70B9\u306E\u5EA7\u6A19\nPoint cross_point(const Line &s1,\
    \ const Segment &s2) {\n    double d1 = cross(s1.a - s2.a, s1.b - s2.a);\n   \
    \ double d2 = cross(s1.a - s1.b, s2.b - s2.a);\n    if (abs(d1) < EPS && abs(d2)\
    \ < EPS) {\n        return s2.a;\n    }\n    return s2.a + (s2.b - s2.a) * (d1\
    \ / d2);\n}\n\n// \u76F4\u7DDA\u3068\u70B9\u306E\u8DDD\u96E2\ndouble distance(const\
    \ Line s, const Point &p) {\n    double t = dot(p - s.a, s.b - s.a) / norm(s.b\
    \ - s.a);\n    Point proj = Point(s.a.real() + t * (s.b - s.a).real(), s.a.imag()\
    \ + t * (s.b - s.a).imag());\n    return abs(p - proj);\n}\n\n// \u7DDA\u5206\u3068\
    \u70B9\u306E\u8DDD\u96E2\ndouble distance(const Segment s, const Point &p) {\n\
    \    double t = dot(p - s.a, s.b - s.a) / norm(s.b - s.a);\n    if (t > -EPS &&\
    \ t < 1 + EPS) {\n        Point proj = Point(s.a.real() + t * (s.b - s.a).real(),\
    \ s.a.imag() + t * (s.b - s.a).imag());\n        return abs(p - proj);\n    }\
    \ else {\n        return min(abs(p - s.a), abs(p - s.b));\n    }\n}\n\n// \u591A\
    \u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const Polygon &poly) {\n    double\
    \ ans = 0;\n    int N = poly.size();\n    for (int i = 0; i < N; i++) {\n    \
    \    ans += cross(poly[i], poly[(i + 1) % N]);\n    }\n    ans *= 0.5;\n    return\
    \ ans;\n}\n\n// \u51F8\u6027\u5224\u5B9A\nbool is_convex(const Polygon &poly)\
    \ {\n    int N = poly.size();\n    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(poly[i],\
    \ poly[(i + 1) % N], poly[(i + 2) % N]) == -1) return false;\n    }\n    return\
    \ true;\n}\n\n// \u591A\u89D2\u5F62\u3068\u70B9\u306E\u5305\u542B\u95A2\u4FC2\n\
    int is_contained(const Point p, const Polygon poly) {\n    int N = poly.size();\n\
    \    int cnt = 0;\n    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(p,\
    \ poly[i], poly[(i + 1) % N]) == 0) {\n            return 1;\n        }\n    \
    \    Point a = poly[i], b = poly[(i + 1) % N];\n        if (a.imag() > b.imag())\
    \ swap(a, b);\n        if (p.imag() < b.imag() + EPS && p.imag() > a.imag() +\
    \ EPS && counter_clockwise(p, a, b) < 0) {\n            cnt++;\n        }\n  \
    \  }\n    if (cnt % 2 == 0) return 0;\n    else return 2;\n}\n\n// \u51F8\u5305\
    \nPolygon convex_hull(vector<Point> &ps) {\n    int N = ps.size();\n    auto compare\
    \ = [](const Point &p1, const Point &p2) {\n        if (p1.real() != p2.real())\
    \ return p1.real() < p2.real();\n        return p1.imag() < p2.imag();\n    };\n\
    \    sort(ps.begin(), ps.end(), compare);\n    int k = 0;\n    Polygon qs(2 *\
    \ N);\n    // \u4E0B\u5074\u51F8\u5305\n    for (int i = 0; i < N; i++) {\n  \
    \      while (k > 1 && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS)\
    \ k--;\n        qs[k++] = ps[i];\n    }\n    // \u4E0A\u5074\u51F8\u5305\n   \
    \ for (int i = N - 2, t = k; i >= 0; i--) {\n        while (k > t && cross(qs[k\
    \ - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS) k--;\n        qs[k++] = ps[i];\n\
    \    }\n    qs.resize(k - 1);\n    return qs;\n}\n\n// \u6700\u3082\u9060\u3044\
    \uFF12\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B\ndouble farest_pair(vector<Point>\
    \ &ps) {\n    Polygon poly = convex_hull(ps);\n    double ans = 0;\n    for (int\
    \ i = 0; i < (int)poly.size(); i++) {\n        for (int j = 0; j < i; j++) {\n\
    \            ans = max(ans, abs(poly[i] - poly[j]));\n        }\n    }\n    return\
    \ ans;\n}\n\n// \u76F4\u7DDA l \u3067\u51F8\u591A\u89D2\u5F62\u3092\u5207\u65AD\
    \u3059\u308B\nPolygon convex_cut(const Polygon &poly, const Line &l) {\n    int\
    \ N = poly.size();\n    vector<Point> ps;\n    for (int i = 0; i < N; i++) {\n\
    \        if (cross(l.b - l.a, poly[i] - l.a) > -EPS) {\n            ps.push_back(poly[i]);\n\
    \        }\n        if (is_intersection(l, Segment(poly[i], poly[(i + 1) % N])))\
    \ {\n            ps.push_back(cross_point(l, Segment(poly[i], poly[(i + 1) % N])));\n\
    \        }\n    }\n    if (ps.size() <= 0) return {};\n    Polygon ch = convex_hull(ps);\n\
    \    return ch;\n}\n\n// \u6700\u3082\u8FD1\u3044\uFF12\u70B9\u306E\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\ndouble closest_pair(vector<Point> &ps) {\n    auto dfs\
    \ = [&](auto dfs, vector<Point> qs) -> double {\n        int N = qs.size();\n\
    \        if (N <= 1) return 1e18;\n        sort(qs.begin(), qs.end(), [](const\
    \ Point &p1, const Point &p2) {\n            if (abs(p1.real() - p2.real()) <\
    \ EPS) return p1.imag() < p2.imag();\n            return p1.real() < p2.real();\n\
    \        });\n        vector<Point> P1, P2;\n        for (int i = 0; i < N / 2;\
    \ i++) P1.push_back(qs[i]);\n        for (int i = N / 2; i < N; i++) P2.push_back(qs[i]);\n\
    \        double d1 = dfs(dfs, P1), d2 = dfs(dfs, P2);\n        double d = min(d1,\
    \ d2), ans = d;\n        double px = P1[N / 2 - 1].real(), py = P1[N / 2 - 1].imag();\n\
    \        vector<pair<double, int>> V;\n        for (int i = 0; i < N; i++) {\n\
    \            if (qs[i].real() < px - d - EPS || qs[i].real() > px + d + EPS) continue;\n\
    \            V.push_back(make_pair(qs[i].imag(), i));\n        }\n        sort(V.begin(),\
    \ V.end());\n        int r = 0;\n        for (int l = 0; l < (int)V.size(); l++)\
    \ {\n            r = max(r, l);\n            while (r < (int)V.size() && V[r].first\
    \ < V[l].first + d + EPS) {\n                if (l != r) ans = min(ans, abs(qs[V[l].second]\
    \ - qs[V[r].second]));\n                r++;\n            }\n        }\n     \
    \   return ans;\n    };\n    return dfs(dfs, ps);\n}\n\n// \u5186\u306E\u4EA4\u5DEE\
    \u5224\u5B9A\nint intersection_of_circle(const Circle &c1, const Circle &c2) {\n\
    \    double d = abs(c1.p - c2.p);\n    // \u5206\u96E2\n    if (d > c1.r + c2.r\
    \ + EPS) {\n        return 4;\n    }\n    // \u5916\u63A5\n    if (abs(d - c1.r\
    \ - c2.r) < EPS) {\n        return 3;\n    }\n    // \u4EA4\u5DEE\n    if (d <\
    \ c1.r + c2.r - EPS && d > abs(c1.r - c2.r) + EPS) {\n        return 2;\n    }\n\
    \    // \u5185\u63A5\n    if (abs(d - abs(c1.r - c2.r)) < EPS) {\n        return\
    \ 1;\n    }\n    // \u5305\u542B\n    return 0;\n}\n\n// \u5185\u63A5\u5186\n\
    Circle incircle(const Point &p1, const Point &p2, const Point &p3) {\n    double\
    \ d = abs((p1 - p2)) + abs(p2 - p3) + abs(p3 - p1);\n    Point p = p1 + (abs(p3\
    \ - p1) / d) * (p2 - p1) + (abs(p2 - p1) / d) * (p3 - p1);\n    double r = abs(cross(p2\
    \ - p1, p3 - p1)) / d;\n    return Circle(p, r);\n}\n\n// \u5916\u63A5\u5186\n\
    Circle circumscribed_circle(const Point &p1, const Point &p2, const Point &p3)\
    \ {\n    double a = abs(p1 - p2), b = abs(p2 - p3), c = abs(p3 - p1), S = abs(cross(p2\
    \ - p1, p3 - p1)) * 0.5;\n    double cx = norm(p2 - p1) * (p3 - p1).imag() - norm(p3\
    \ - p1) * (p2 - p1).imag(), cy = norm(p3 - p1) * (p2 - p1).real() - norm(p2 -\
    \ p1) * (p3 - p1).real();\n    cx /= 2.0 * cross(p2 - p1, p3 - p1);\n    cy /=\
    \ 2.0 * cross(p2 - p1, p3 - p1);\n    Point p = p1 + Point(cx, cy);\n    double\
    \ r = a * b * c / (4.0 * S);\n    return Circle(p, r);\n}\n\n// \u5186\u3068\u76F4\
    \u7DDA\u306E\u4EA4\u70B9\nvector<Point> cross_points(Circle c, Line l) {\n   \
    \ Point proj = projection(l, c.p);\n    double d = abs(proj - c.p);\n    if (d\
    \ > c.r + EPS) {\n        return {};\n    } else if (abs(c.r - abs(proj - c.p))\
    \ < EPS) {\n        return {proj};\n    } else {\n        double s = sqrt(c.r\
    \ * c.r - norm(proj - c.p));\n        return {proj - (s / abs(l.b - l.a)) * (l.b\
    \ - l.a), proj + (s / abs(l.b - l.a)) * (l.b - l.a)};\n    }\n}\n\n// \u5186\u3068\
    \u5186\u306E\u4EA4\u70B9\nvector<Point> cross_points(Circle c1, Circle c2) {\n\
    \    int t = intersection_of_circle(c1, c2);\n    if (t == 0 || t == 4) {\n  \
    \      return {};\n    }\n    if (t == 3) {\n        return {c1.p + (c1.r / (c1.r\
    \ + c2.r)) * (c2.p - c1.p)};\n    }\n    if (t == 1) {\n        if (c1.r > c2.r)\
    \ return {(-c2.r / abs(c1.r - c2.r)) * c1.p + (c1.r / abs(c1.r - c2.r)) * c2.p};\n\
    \        return {(c2.r / abs(c1.r - c2.r)) * c1.p + (-c1.r / abs(c1.r - c2.r))\
    \ * c2.p};\n    }\n    double d = abs(c1.p - c2.p);\n    double s = (c1.r * c1.r\
    \ - c2.r * c2.r + d * d) / (2.0 * d);\n    Point p = c1.p + (s / d) * (c2.p -\
    \ c1.p);\n    return {p - (sqrt(c1.r * c1.r - s * s) / d) * Point((c2.p - c1.p).imag(),\
    \ -(c2.p - c1.p).real()), p + (sqrt(c1.r * c1.r - s * s) / d) * Point((c2.p -\
    \ c1.p).imag(), -(c2.p - c1.p).real())};\n}\n\n// \u5186\u306E\u63A5\u7DDA\nvector<Point>\
    \ tangent(Circle c, Point p) {\n    return cross_points(c, Circle(p, sqrt(norm(c.p\
    \ - p) - c.r * c.r)));\n}\n\n// \u5186\u306E\u5171\u901A\u63A5\u7DDA\nvector<Point>\
    \ common_tangent(Circle c1, Circle c2) {\n    double d = norm(c1.p - c2.p);\n\
    \    double d1 = d - (c1.r + c2.r) * (c1.r + c2.r) + c2.r * c2.r;\n    vector<Point>\
    \ ps;\n    if (d1 > -EPS) {\n        d1 = sqrt(max(d1, 0.0));\n        vector<Point>\
    \ ps1 = cross_points(c1, Circle(c2.p, d1));\n        for (auto p : ps1) ps.push_back(p);\n\
    \    }\n    double d2 = d - (c1.r - c2.r) * (c1.r - c2.r) + c2.r * c2.r;\n   \
    \ if (d2 > -EPS) {\n        d2 = sqrt(max(d2, 0.0));\n        vector<Point> ps2\
    \ = cross_points(c1, Circle(c2.p, d2));\n        for (auto p : ps2) ps.push_back(p);\n\
    \    }\n    return ps;\n}\n\n// \u5186\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\
    \u7A4D\ndouble area_of_intersection(Circle c1, Circle c2) {\n    int t = intersection_of_circle(c1,\
    \ c2);\n    if (t >= 3) {\n        return 0;\n    }\n    if (t <= 1) {\n     \
    \   return pi * min(c1.r, c2.r) * min(c1.r, c2.r);\n    }\n    vector<Point> ps\
    \ = cross_points(c1, c2);\n    double a1 = arg(ps[0] - c1.p) - arg(ps[1] - c1.p),\
    \ a2 = arg(ps[1] - c2.p) - arg(ps[0] - c2.p);\n    if (a1 < -EPS) a1 += 2.0 *\
    \ pi;\n    if (a2 < -EPS) a2 += 2.0 * pi;\n    return (a1 / 2) * c1.r * c1.r +\
    \ (a2 / 2) * c2.r * c2.r - abs(area({ps[0], c1.p, ps[1], c2.p}));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc_Others/geometory/geometry.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:38:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc_Others/geometory/geometry.cpp
layout: document
redirect_from:
- /library/icpc_Others/geometory/geometry.cpp
- /library/icpc_Others/geometory/geometry.cpp.html
title: icpc_Others/geometory/geometry.cpp
---
