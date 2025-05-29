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
  bundledCode: "#line 1 \"icpc_Others/geometory/convex_polygon.cpp\"\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n\
    // 4_A, 4_B, 4_C\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point\
    \ = complex<double>;\nusing Polygon = vector<Point>;\n\nstruct Line {\n    Point\
    \ a, b;\n    Line(Point a, Point b) : a(a), b(b) {}\n};\n\nstruct Segment : Line\
    \ {\n    Segment(Point a, Point b) : Line(a, b) {}\n};\n\nconst double EPS = 1e-12;\n\
    \n// \u5185\u7A4D\ndouble dot(const Point &a, const Point &b) {\n    return (a.real()\
    \ * b.real() + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const\
    \ Point &a, const Point &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n\
    }\n\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const Polygon &poly)\
    \ {\n    double ans = 0;\n    int N = poly.size();\n    for (int i = 0; i < N;\
    \ i++) {\n        ans += cross(poly[i], poly[(i + 1) % N]);\n    }\n    ans *=\
    \ 0.5;\n    return ans;\n}\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\u30D9\
    \u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\nint counter_clockwise(const\
    \ Point &p2, Point p0, Point p1) {\n    // \u53CD\u6642\u8A08\u56DE\u308A\n  \
    \  if (cross(p1 - p0, p2 - p0) > EPS) {\n        return 1;\n    }\n    // \u6642\
    \u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS) {\n        return\
    \ -1;\n    }\n    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \n    if (dot(p1 - p0, p2 - p0) < -EPS) {\n        return 2;\n    }\n    // p0,\
    \ p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0,\
    \ p2 - p0) > norm(p1 - p0) + EPS) {\n        return -2;\n    }\n    // p2 \u306F\
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\n// \u76F4\
    \u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool is_intersection(const\
    \ Line &l1, const Segment &s2) {\n    return (counter_clockwise(s2.a, l1.a, l1.b)\
    \ * counter_clockwise(s2.b, l1.a, l1.b) <= 0);\n}\n\n// \u76F4\u7DDA\u3068\u7DDA\
    \u5206\u306E\u4EA4\u70B9\u306E\u5EA7\u6A19\nPoint cross_point(const Line &s1,\
    \ const Segment &s2) {\n    double d1 = cross(s1.a - s2.a, s1.b - s2.a);\n   \
    \ double d2 = cross(s1.a - s1.b, s2.b - s2.a);\n    if (abs(d1) < EPS && abs(d2)\
    \ < EPS) {\n        return s2.a;\n    }\n    return s2.a + (s2.b - s2.a) * (d1\
    \ / d2);\n}\n\n// \u51F8\u5305\nPolygon convex_hull(vector<Point> &ps) {\n   \
    \ int N = ps.size();\n    auto compare = [](const Point &p1, const Point &p2)\
    \ {\n        if (p1.real() != p2.real()) return p1.real() < p2.real();\n     \
    \   return p1.imag() < p2.imag();\n    };\n    sort(ps.begin(), ps.end(), compare);\n\
    \    int k = 0;\n    Polygon qs(2 * N);\n    // \u4E0B\u5074\u51F8\u5305\n   \
    \ for (int i = 0; i < N; i++) {\n        while (k > 1 && cross(qs[k - 1] - qs[k\
    \ - 2], ps[i] - qs[k - 1]) < EPS) k--;\n        qs[k++] = ps[i];\n    }\n    //\
    \ \u4E0A\u5074\u51F8\u5305\n    for (int i = N - 2, t = k; i >= 0; i--) {\n  \
    \      while (k > t && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS)\
    \ k--;\n        qs[k++] = ps[i];\n    }\n    qs.resize(k - 1);\n    return qs;\n\
    }\n\n// \u6700\u3082\u9060\u3044\uFF12\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\ndouble farest_pair(vector<Point> &ps) {\n    Polygon poly = convex_hull(ps);\n\
    \    double ans = 0;\n    for (int i = 0; i < (int)poly.size(); i++) {\n     \
    \   for (int j = 0; j < i; j++) {\n            ans = max(ans, abs(poly[i] - poly[j]));\n\
    \        }\n    }\n    return ans;\n}\n\n// \u76F4\u7DDA l \u3067\u51F8\u591A\u89D2\
    \u5F62\u3092\u5207\u65AD\u3059\u308B\nPolygon convex_cut(const Polygon &poly,\
    \ const Line &l) {\n    int N = poly.size();\n    vector<Point> ps;\n    for (int\
    \ i = 0; i < N; i++) {\n        if (cross(l.b - l.a, poly[i] - l.a) > -EPS) {\n\
    \            ps.push_back(poly[i]);\n        }\n        if (is_intersection(l,\
    \ Segment(poly[i], poly[(i + 1) % N]))) {\n            ps.push_back(cross_point(l,\
    \ Segment(poly[i], poly[(i + 1) % N])));\n        }\n    }\n    if (ps.size()\
    \ <= 0) return {};\n    Polygon ch = convex_hull(ps);\n    return ch;\n}\n\nint\
    \ main() {\n    cout << fixed << setprecision(15);\n    int N;\n    cin >> N;\n\
    \    Polygon poly(N);\n    for (int i = 0; i < N; i++) {\n        double x, y;\n\
    \        cin >> x >> y;\n        poly[i] = Point(x, y);\n    }\n    int Q;\n \
    \   cin >> Q;\n    while (Q--) {\n        int x1, y1, x2, y2;\n        cin >>\
    \ x1 >> y1 >> x2 >> y2;\n        Point p1(x1, y1), p2(x2, y2);\n        Line l(p1,\
    \ p2);\n        cout << area(convex_cut(poly, l)) << \"\\n\";\n    }\n}\n"
  code: "// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n// 4_A, 4_B,\
    \ 4_C\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point = complex<double>;\n\
    using Polygon = vector<Point>;\n\nstruct Line {\n    Point a, b;\n    Line(Point\
    \ a, Point b) : a(a), b(b) {}\n};\n\nstruct Segment : Line {\n    Segment(Point\
    \ a, Point b) : Line(a, b) {}\n};\n\nconst double EPS = 1e-12;\n\n// \u5185\u7A4D\
    \ndouble dot(const Point &a, const Point &b) {\n    return (a.real() * b.real()\
    \ + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const Point &a,\
    \ const Point &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n\
    }\n\n// \u591A\u89D2\u5F62\u306E\u9762\u7A4D\ndouble area(const Polygon &poly)\
    \ {\n    double ans = 0;\n    int N = poly.size();\n    for (int i = 0; i < N;\
    \ i++) {\n        ans += cross(poly[i], poly[(i + 1) % N]);\n    }\n    ans *=\
    \ 0.5;\n    return ans;\n}\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\u30D9\
    \u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\nint counter_clockwise(const\
    \ Point &p2, Point p0, Point p1) {\n    // \u53CD\u6642\u8A08\u56DE\u308A\n  \
    \  if (cross(p1 - p0, p2 - p0) > EPS) {\n        return 1;\n    }\n    // \u6642\
    \u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS) {\n        return\
    \ -1;\n    }\n    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \n    if (dot(p1 - p0, p2 - p0) < -EPS) {\n        return 2;\n    }\n    // p0,\
    \ p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0,\
    \ p2 - p0) > norm(p1 - p0) + EPS) {\n        return -2;\n    }\n    // p2 \u306F\
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\n// \u76F4\
    \u7DDA\u3068\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\nbool is_intersection(const\
    \ Line &l1, const Segment &s2) {\n    return (counter_clockwise(s2.a, l1.a, l1.b)\
    \ * counter_clockwise(s2.b, l1.a, l1.b) <= 0);\n}\n\n// \u76F4\u7DDA\u3068\u7DDA\
    \u5206\u306E\u4EA4\u70B9\u306E\u5EA7\u6A19\nPoint cross_point(const Line &s1,\
    \ const Segment &s2) {\n    double d1 = cross(s1.a - s2.a, s1.b - s2.a);\n   \
    \ double d2 = cross(s1.a - s1.b, s2.b - s2.a);\n    if (abs(d1) < EPS && abs(d2)\
    \ < EPS) {\n        return s2.a;\n    }\n    return s2.a + (s2.b - s2.a) * (d1\
    \ / d2);\n}\n\n// \u51F8\u5305\nPolygon convex_hull(vector<Point> &ps) {\n   \
    \ int N = ps.size();\n    auto compare = [](const Point &p1, const Point &p2)\
    \ {\n        if (p1.real() != p2.real()) return p1.real() < p2.real();\n     \
    \   return p1.imag() < p2.imag();\n    };\n    sort(ps.begin(), ps.end(), compare);\n\
    \    int k = 0;\n    Polygon qs(2 * N);\n    // \u4E0B\u5074\u51F8\u5305\n   \
    \ for (int i = 0; i < N; i++) {\n        while (k > 1 && cross(qs[k - 1] - qs[k\
    \ - 2], ps[i] - qs[k - 1]) < EPS) k--;\n        qs[k++] = ps[i];\n    }\n    //\
    \ \u4E0A\u5074\u51F8\u5305\n    for (int i = N - 2, t = k; i >= 0; i--) {\n  \
    \      while (k > t && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < EPS)\
    \ k--;\n        qs[k++] = ps[i];\n    }\n    qs.resize(k - 1);\n    return qs;\n\
    }\n\n// \u6700\u3082\u9060\u3044\uFF12\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\ndouble farest_pair(vector<Point> &ps) {\n    Polygon poly = convex_hull(ps);\n\
    \    double ans = 0;\n    for (int i = 0; i < (int)poly.size(); i++) {\n     \
    \   for (int j = 0; j < i; j++) {\n            ans = max(ans, abs(poly[i] - poly[j]));\n\
    \        }\n    }\n    return ans;\n}\n\n// \u76F4\u7DDA l \u3067\u51F8\u591A\u89D2\
    \u5F62\u3092\u5207\u65AD\u3059\u308B\nPolygon convex_cut(const Polygon &poly,\
    \ const Line &l) {\n    int N = poly.size();\n    vector<Point> ps;\n    for (int\
    \ i = 0; i < N; i++) {\n        if (cross(l.b - l.a, poly[i] - l.a) > -EPS) {\n\
    \            ps.push_back(poly[i]);\n        }\n        if (is_intersection(l,\
    \ Segment(poly[i], poly[(i + 1) % N]))) {\n            ps.push_back(cross_point(l,\
    \ Segment(poly[i], poly[(i + 1) % N])));\n        }\n    }\n    if (ps.size()\
    \ <= 0) return {};\n    Polygon ch = convex_hull(ps);\n    return ch;\n}\n\nint\
    \ main() {\n    cout << fixed << setprecision(15);\n    int N;\n    cin >> N;\n\
    \    Polygon poly(N);\n    for (int i = 0; i < N; i++) {\n        double x, y;\n\
    \        cin >> x >> y;\n        poly[i] = Point(x, y);\n    }\n    int Q;\n \
    \   cin >> Q;\n    while (Q--) {\n        int x1, y1, x2, y2;\n        cin >>\
    \ x1 >> y1 >> x2 >> y2;\n        Point p1(x1, y1), p2(x2, y2);\n        Line l(p1,\
    \ p2);\n        cout << area(convex_cut(poly, l)) << \"\\n\";\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc_Others/geometory/convex_polygon.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:38:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc_Others/geometory/convex_polygon.cpp
layout: document
redirect_from:
- /library/icpc_Others/geometory/convex_polygon.cpp
- /library/icpc_Others/geometory/convex_polygon.cpp.html
title: icpc_Others/geometory/convex_polygon.cpp
---
