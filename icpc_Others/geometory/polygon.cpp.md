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
  bundledCode: "#line 1 \"icpc_Others/geometory/polygon.cpp\"\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n\
    // 3_A, 3_B, 3_C\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point\
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
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\n// \u51F8\
    \u6027\u5224\u5B9A\nbool is_convex(const Polygon &poly) {\n    int N = poly.size();\n\
    \    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(poly[i], poly[(i\
    \ + 1) % N], poly[(i + 2) % N]) == -1) return false;\n    }\n    return true;\n\
    }\n\n// \u591A\u89D2\u5F62\u3068\u70B9\u306E\u5305\u542B\u95A2\u4FC2\nint is_contained(const\
    \ Point p, const Polygon poly) {\n    int N = poly.size();\n    int cnt = 0;\n\
    \    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(p, poly[i],\
    \ poly[(i + 1) % N]) == 0) {\n            return 1;\n        }\n        Point\
    \ a = poly[i], b = poly[(i + 1) % N];\n        if (a.imag() > b.imag()) swap(a,\
    \ b);\n        if (p.imag() < b.imag() + EPS && p.imag() > a.imag() + EPS && counter_clockwise(p,\
    \ a, b) < 0) {\n            cnt++;\n        }\n    }\n    if (cnt % 2 == 0) return\
    \ 0;\n    else return 2;\n}\n\nint main() {\n    cout << fixed << setprecision(1);\n\
    \    int N;\n    cin >> N;\n    Polygon poly(N);\n    for (int i = 0; i < N; i++)\
    \ {\n        int x, y;\n        cin >> x >> y;\n        poly[i] = Point(x, y);\n\
    \    }\n    int Q;\n    cin >> Q;\n    while (Q--) {\n        int x, y;\n    \
    \    cin >> x >> y;\n        Point p(x, y);\n        cout << is_contained(p, poly)\
    \ << \"\\n\";\n    }\n}\n"
  code: "// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n// 3_A, 3_B,\
    \ 3_C\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point = complex<double>;\n\
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
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\n// \u51F8\
    \u6027\u5224\u5B9A\nbool is_convex(const Polygon &poly) {\n    int N = poly.size();\n\
    \    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(poly[i], poly[(i\
    \ + 1) % N], poly[(i + 2) % N]) == -1) return false;\n    }\n    return true;\n\
    }\n\n// \u591A\u89D2\u5F62\u3068\u70B9\u306E\u5305\u542B\u95A2\u4FC2\nint is_contained(const\
    \ Point p, const Polygon poly) {\n    int N = poly.size();\n    int cnt = 0;\n\
    \    for (int i = 0; i < N; i++) {\n        if (counter_clockwise(p, poly[i],\
    \ poly[(i + 1) % N]) == 0) {\n            return 1;\n        }\n        Point\
    \ a = poly[i], b = poly[(i + 1) % N];\n        if (a.imag() > b.imag()) swap(a,\
    \ b);\n        if (p.imag() < b.imag() + EPS && p.imag() > a.imag() + EPS && counter_clockwise(p,\
    \ a, b) < 0) {\n            cnt++;\n        }\n    }\n    if (cnt % 2 == 0) return\
    \ 0;\n    else return 2;\n}\n\nint main() {\n    cout << fixed << setprecision(1);\n\
    \    int N;\n    cin >> N;\n    Polygon poly(N);\n    for (int i = 0; i < N; i++)\
    \ {\n        int x, y;\n        cin >> x >> y;\n        poly[i] = Point(x, y);\n\
    \    }\n    int Q;\n    cin >> Q;\n    while (Q--) {\n        int x, y;\n    \
    \    cin >> x >> y;\n        Point p(x, y);\n        cout << is_contained(p, poly)\
    \ << \"\\n\";\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc_Others/geometory/polygon.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:38:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc_Others/geometory/polygon.cpp
layout: document
redirect_from:
- /library/icpc_Others/geometory/polygon.cpp
- /library/icpc_Others/geometory/polygon.cpp.html
title: icpc_Others/geometory/polygon.cpp
---
