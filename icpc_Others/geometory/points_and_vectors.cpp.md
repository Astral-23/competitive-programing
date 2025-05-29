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
  bundledCode: "#line 1 \"icpc_Others/geometory/points_and_vectors.cpp\"\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n\
    // 1_A, 1_B, 1_C\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point\
    \ = complex<double>;\n\nstruct Line {\n    Point a, b;\n    Line(Point a, Point\
    \ b) : a(a), b(b) {}\n};\n\nconst double EPS = 1e-12;\n\n// \u5185\u7A4D\ndouble\
    \ dot(const Point &a, const Point &b) {\n    return (a.real() * b.real() + a.imag()\
    \ * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const Point &a, const Point\
    \ &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n}\n\n// \u76F4\
    \u7DDA l \u306B\u5BFE\u3059\u308B\u70B9 p \u306E\u5C04\u5F71\nPoint projection(const\
    \ Line l, const Point &p) {\n    double t = dot(p - l.a, l.b - l.a) / norm(l.b\
    \ - l.a);\n    return Point(l.a.real() + t * (l.b - l.a).real(), l.a.imag() +\
    \ t * (l.b - l.a).imag());\n}\n\n// \u76F4\u7DDA l \u306B\u5BFE\u3059\u308B\u70B9\
    \ p \u306E\u53CD\u5C04\nPoint reflection(const Line l, const Point &p) {\n   \
    \ double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n    Point q(l.a.real()\
    \ + t * (l.b - l.a).real(), l.a.imag() + t * (l.b - l.a).imag());\n    return\
    \ Point(2 * q.real() - p.real(), 2 * q.imag() - p.imag());\n}\n\n// // p0 \u304B\
    \u3089 p1 \u3078\u7D50\u3093\u3060\u30D9\u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F\
    \ p2 \u306E\u4F4D\u7F6E\n// int counter_clockwise(const Point &p2, Point p0, Point\
    \ p1) {\n//     // \u53CD\u6642\u8A08\u56DE\u308A\n//     if (cross(p1 - p0, p2\
    \ - p0) > EPS) {\n//         return 0;\n//     }\n//     // \u6642\u8A08\u56DE\
    \u308A\n//     if (cross(p1 - p0, p2 - p0) < -EPS) {\n//         return 1;\n//\
    \     }\n//     // p2, p0, p1 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \n//     if (dot(p1 - p0, p2 - p0) < -EPS) {\n//         return 2;\n//     }\n\
    //     // p0, p1, p2 \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n//    \
    \ if (dot(p1 - p0, p2 - p0) > norm(p1 - p0) + EPS) {\n//         return 3;\n//\
    \     }\n//     // p2 \u306F p0 \u3068 p1 \u3092\u7D50\u3076\u7DDA\u5206\u4E0A\
    \n//     return 4;\n// }\n\nint main() {\n    cout << fixed << setprecision(15);\n\
    }\n"
  code: "// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n// 1_A, 1_B,\
    \ 1_C\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point = complex<double>;\n\
    \nstruct Line {\n    Point a, b;\n    Line(Point a, Point b) : a(a), b(b) {}\n\
    };\n\nconst double EPS = 1e-12;\n\n// \u5185\u7A4D\ndouble dot(const Point &a,\
    \ const Point &b) {\n    return (a.real() * b.real() + a.imag() * b.imag());\n\
    }\n\n// \u5916\u7A4D\ndouble cross(const Point &a, const Point &b) {\n    return\
    \ (a.real() * b.imag() - a.imag() * b.real());\n}\n\n// \u76F4\u7DDA l \u306B\u5BFE\
    \u3059\u308B\u70B9 p \u306E\u5C04\u5F71\nPoint projection(const Line l, const\
    \ Point &p) {\n    double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);\n   \
    \ return Point(l.a.real() + t * (l.b - l.a).real(), l.a.imag() + t * (l.b - l.a).imag());\n\
    }\n\n// \u76F4\u7DDA l \u306B\u5BFE\u3059\u308B\u70B9 p \u306E\u53CD\u5C04\nPoint\
    \ reflection(const Line l, const Point &p) {\n    double t = dot(p - l.a, l.b\
    \ - l.a) / norm(l.b - l.a);\n    Point q(l.a.real() + t * (l.b - l.a).real(),\
    \ l.a.imag() + t * (l.b - l.a).imag());\n    return Point(2 * q.real() - p.real(),\
    \ 2 * q.imag() - p.imag());\n}\n\n// // p0 \u304B\u3089 p1 \u3078\u7D50\u3093\u3060\
    \u30D9\u30AF\u30C8\u30EB\u304B\u3089\u898B\u305F p2 \u306E\u4F4D\u7F6E\n// int\
    \ counter_clockwise(const Point &p2, Point p0, Point p1) {\n//     // \u53CD\u6642\
    \u8A08\u56DE\u308A\n//     if (cross(p1 - p0, p2 - p0) > EPS) {\n//         return\
    \ 0;\n//     }\n//     // \u6642\u8A08\u56DE\u308A\n//     if (cross(p1 - p0,\
    \ p2 - p0) < -EPS) {\n//         return 1;\n//     }\n//     // p2, p0, p1 \u306E\
    \u9806\u3067\u540C\u4E00\u76F4\u7DDA\u4E0A\n//     if (dot(p1 - p0, p2 - p0) <\
    \ -EPS) {\n//         return 2;\n//     }\n//     // p0, p1, p2 \u306E\u9806\u3067\
    \u540C\u4E00\u76F4\u7DDA\u4E0A\n//     if (dot(p1 - p0, p2 - p0) > norm(p1 - p0)\
    \ + EPS) {\n//         return 3;\n//     }\n//     // p2 \u306F p0 \u3068 p1 \u3092\
    \u7D50\u3076\u7DDA\u5206\u4E0A\n//     return 4;\n// }\n\nint main() {\n    cout\
    \ << fixed << setprecision(15);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc_Others/geometory/points_and_vectors.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:38:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc_Others/geometory/points_and_vectors.cpp
layout: document
redirect_from:
- /library/icpc_Others/geometory/points_and_vectors.cpp
- /library/icpc_Others/geometory/points_and_vectors.cpp.html
title: icpc_Others/geometory/points_and_vectors.cpp
---
