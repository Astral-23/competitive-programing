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
  bundledCode: "#line 1 \"icpc_Others/geometory/segments_and_lines.cpp\"\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n\
    // 2_A, 2_B, 2_C, 2_D\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing\
    \ Point = complex<double>;\n\nstruct Line {\n    Point a, b;\n    Line(Point a,\
    \ Point b) : a(a), b(b) {}\n};\n\nstruct Segment : Line {\n    Segment(Point a,\
    \ Point b) : Line(a, b) {}\n};\n\nconst double EPS = 1e-12;\n\n// \u5185\u7A4D\
    \ndouble dot(const Point &a, const Point &b) {\n    return (a.real() * b.real()\
    \ + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const Point &a,\
    \ const Point &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n\
    }\n\n// \u5E73\u884C\u5224\u5B9A\nbool is_parallel(const Line &l1, const Line\
    \ &l2) {\n    return (cross(l1.b - l1.a, l2.b - l2.a) == 0);\n}\n\n// \u5782\u76F4\
    \u5224\u5B9A\nbool is_orthogonal(const Line &l1, const Line &l2) {\n    return\
    \ (dot(l1.b - l1.a, l2.b - l2.a) == 0);\n}\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\
    \u3093\u3060\u30D9\u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\
    \nint counter_clockwise(const Point &p2, Point p0, Point p1) {\n    // \u53CD\u6642\
    \u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) > EPS) {\n        return 1;\n\
    \    }\n    // \u6642\u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS)\
    \ {\n        return -1;\n    }\n    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\
    \u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0, p2 - p0) < -EPS) {\n        return 2;\n\
    \    }\n    // p0, p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n \
    \   if (dot(p1 - p0, p2 - p0) > norm(p1 - p0) + EPS) {\n        return -2;\n \
    \   }\n    // p2 \u306F p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n  \
    \  return 0;\n}\n\n// \u4EA4\u5DEE\u5224\u5B9A\nbool is_intersection(const Segment\
    \ &s1, const Segment &s2) {\n    return (counter_clockwise(s2.a, s1.a, s1.b) *\
    \ counter_clockwise(s2.b, s1.a, s1.b) <= 0 && counter_clockwise(s1.a, s2.a, s2.b)\
    \ * counter_clockwise(s1.b, s2.a, s2.b) <= 0);\n}\n\n// \u4EA4\u70B9\u306E\u5EA7\
    \u6A19\nPoint cross_point(const Segment &s1, const Segment &s2) {\n    double\
    \ d1 = cross(s1.a - s2.a, s1.b - s2.a);\n    double d2 = cross(s1.a - s1.b, s2.b\
    \ - s2.a);\n    if (abs(d1) < EPS && abs(d2) < EPS) {\n        if (counter_clockwise(s1.a,\
    \ s2.a, s2.b) == 0) return s1.a;\n        else return s1.b;\n    }\n    return\
    \ s2.a + (s2.b - s2.a) * (d1 / d2);\n}\n\n// \u7DDA\u5206 s \u3068 \u70B9 p \u306E\
    \u8DDD\u96E2\ndouble distance(const Segment s, const Point &p) {\n    double t\
    \ = dot(p - s.a, s.b - s.a) / norm(s.b - s.a);\n    if (t > -EPS && t < 1 + EPS)\
    \ {\n        Point proj = Point(s.a.real() + t * (s.b - s.a).real(), s.a.imag()\
    \ + t * (s.b - s.a).imag());\n        return abs(p - proj);\n    } else {\n  \
    \      return min(abs(p - s.a), abs(p - s.b));\n    }\n}\n\nint main() {\n   \
    \ cout << fixed << setprecision(15);\n}\n"
  code: "// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n// 2_A, 2_B,\
    \ 2_C, 2_D\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point =\
    \ complex<double>;\n\nstruct Line {\n    Point a, b;\n    Line(Point a, Point\
    \ b) : a(a), b(b) {}\n};\n\nstruct Segment : Line {\n    Segment(Point a, Point\
    \ b) : Line(a, b) {}\n};\n\nconst double EPS = 1e-12;\n\n// \u5185\u7A4D\ndouble\
    \ dot(const Point &a, const Point &b) {\n    return (a.real() * b.real() + a.imag()\
    \ * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const Point &a, const Point\
    \ &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n}\n\n// \u5E73\
    \u884C\u5224\u5B9A\nbool is_parallel(const Line &l1, const Line &l2) {\n    return\
    \ (cross(l1.b - l1.a, l2.b - l2.a) == 0);\n}\n\n// \u5782\u76F4\u5224\u5B9A\n\
    bool is_orthogonal(const Line &l1, const Line &l2) {\n    return (dot(l1.b - l1.a,\
    \ l2.b - l2.a) == 0);\n}\n\n// p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\u30D9\
    \u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\nint counter_clockwise(const\
    \ Point &p2, Point p0, Point p1) {\n    // \u53CD\u6642\u8A08\u56DE\u308A\n  \
    \  if (cross(p1 - p0, p2 - p0) > EPS) {\n        return 1;\n    }\n    // \u6642\
    \u8A08\u56DE\u308A\n    if (cross(p1 - p0, p2 - p0) < -EPS) {\n        return\
    \ -1;\n    }\n    // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \n    if (dot(p1 - p0, p2 - p0) < -EPS) {\n        return 2;\n    }\n    // p0,\
    \ p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n    if (dot(p1 - p0,\
    \ p2 - p0) > norm(p1 - p0) + EPS) {\n        return -2;\n    }\n    // p2 \u306F\
    \ p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\n    return 0;\n}\n\n// \u4EA4\
    \u5DEE\u5224\u5B9A\nbool is_intersection(const Segment &s1, const Segment &s2)\
    \ {\n    return (counter_clockwise(s2.a, s1.a, s1.b) * counter_clockwise(s2.b,\
    \ s1.a, s1.b) <= 0 && counter_clockwise(s1.a, s2.a, s2.b) * counter_clockwise(s1.b,\
    \ s2.a, s2.b) <= 0);\n}\n\n// \u4EA4\u70B9\u306E\u5EA7\u6A19\nPoint cross_point(const\
    \ Segment &s1, const Segment &s2) {\n    double d1 = cross(s1.a - s2.a, s1.b -\
    \ s2.a);\n    double d2 = cross(s1.a - s1.b, s2.b - s2.a);\n    if (abs(d1) <\
    \ EPS && abs(d2) < EPS) {\n        if (counter_clockwise(s1.a, s2.a, s2.b) ==\
    \ 0) return s1.a;\n        else return s1.b;\n    }\n    return s2.a + (s2.b -\
    \ s2.a) * (d1 / d2);\n}\n\n// \u7DDA\u5206 s \u3068 \u70B9 p \u306E\u8DDD\u96E2\
    \ndouble distance(const Segment s, const Point &p) {\n    double t = dot(p - s.a,\
    \ s.b - s.a) / norm(s.b - s.a);\n    if (t > -EPS && t < 1 + EPS) {\n        Point\
    \ proj = Point(s.a.real() + t * (s.b - s.a).real(), s.a.imag() + t * (s.b - s.a).imag());\n\
    \        return abs(p - proj);\n    } else {\n        return min(abs(p - s.a),\
    \ abs(p - s.b));\n    }\n}\n\nint main() {\n    cout << fixed << setprecision(15);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc_Others/geometory/segments_and_lines.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:38:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc_Others/geometory/segments_and_lines.cpp
layout: document
redirect_from:
- /library/icpc_Others/geometory/segments_and_lines.cpp
- /library/icpc_Others/geometory/segments_and_lines.cpp.html
title: icpc_Others/geometory/segments_and_lines.cpp
---
