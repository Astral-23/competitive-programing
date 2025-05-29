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
  bundledCode: "#line 1 \"icpc_Others/geometory/closest_pair.cpp\"\n// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n\
    // 5_A\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing Point = complex<double>;\n\
    using Polygon = vector<Point>;\n\nstruct Line {\n    Point a, b;\n    Line(Point\
    \ a, Point b) : a(a), b(b) {}\n};\n\nstruct Segment : Line {\n    Segment(Point\
    \ a, Point b) : Line(a, b) {}\n};\n\nconst double EPS = 1e-12;\n\n// \u5185\u7A4D\
    \ndouble dot(const Point &a, const Point &b) {\n    return (a.real() * b.real()\
    \ + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const Point &a,\
    \ const Point &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n\
    }\n\n// \u6700\u3082\u8FD1\u3044\uFF12\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\ndouble closest_pair(vector<Point> &ps) {\n    auto dfs = [&](auto dfs,\
    \ vector<Point> qs) -> double {\n        int N = qs.size();\n        if (N <=\
    \ 1) return 1e18;\n        sort(qs.begin(), qs.end(), [](const Point &p1, const\
    \ Point &p2) {\n            if (abs(p1.real() - p2.real()) < EPS) return p1.imag()\
    \ < p2.imag();\n            return p1.real() < p2.real();\n        });\n     \
    \   vector<Point> P1, P2;\n        for (int i = 0; i < N / 2; i++) P1.push_back(qs[i]);\n\
    \        for (int i = N / 2; i < N; i++) P2.push_back(qs[i]);\n        double\
    \ d1 = dfs(dfs, P1), d2 = dfs(dfs, P2);\n        double d = min(d1, d2), ans =\
    \ d;\n        double px = P1[N / 2 - 1].real(), py = P1[N / 2 - 1].imag();\n \
    \       vector<pair<double, int>> V;\n        for (int i = 0; i < N; i++) {\n\
    \            if (qs[i].real() < px - d - EPS || qs[i].real() > px + d + EPS) continue;\n\
    \            V.push_back(make_pair(qs[i].imag(), i));\n        }\n        sort(V.begin(),\
    \ V.end());\n        int r = 0;\n        for (int l = 0; l < (int)V.size(); l++)\
    \ {\n            r = max(r, l);\n            while (r < (int)V.size() && V[r].first\
    \ < V[l].first + d + EPS) {\n                if (l != r) ans = min(ans, abs(qs[V[l].second]\
    \ - qs[V[r].second]));\n                r++;\n            }\n        }\n     \
    \   return ans;\n    };\n    return dfs(dfs, ps);\n}\n\nint main() {\n    cout\
    \ << fixed << setprecision(15);\n    int N;\n    cin >> N;\n    vector<Point>\
    \ ps(N);\n    for (int i = 0; i < N; i++) {\n        double x, y;\n        cin\
    \ >> x >> y;\n        ps[i] = Point(x, y);\n    }\n    cout << closest_pair(ps)\
    \ << \"\\n\";\n}\n"
  code: "// https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all\n// 5_A\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing Point = complex<double>;\n\
    using Polygon = vector<Point>;\n\nstruct Line {\n    Point a, b;\n    Line(Point\
    \ a, Point b) : a(a), b(b) {}\n};\n\nstruct Segment : Line {\n    Segment(Point\
    \ a, Point b) : Line(a, b) {}\n};\n\nconst double EPS = 1e-12;\n\n// \u5185\u7A4D\
    \ndouble dot(const Point &a, const Point &b) {\n    return (a.real() * b.real()\
    \ + a.imag() * b.imag());\n}\n\n// \u5916\u7A4D\ndouble cross(const Point &a,\
    \ const Point &b) {\n    return (a.real() * b.imag() - a.imag() * b.real());\n\
    }\n\n// \u6700\u3082\u8FD1\u3044\uFF12\u70B9\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\ndouble closest_pair(vector<Point> &ps) {\n    auto dfs = [&](auto dfs,\
    \ vector<Point> qs) -> double {\n        int N = qs.size();\n        if (N <=\
    \ 1) return 1e18;\n        sort(qs.begin(), qs.end(), [](const Point &p1, const\
    \ Point &p2) {\n            if (abs(p1.real() - p2.real()) < EPS) return p1.imag()\
    \ < p2.imag();\n            return p1.real() < p2.real();\n        });\n     \
    \   vector<Point> P1, P2;\n        for (int i = 0; i < N / 2; i++) P1.push_back(qs[i]);\n\
    \        for (int i = N / 2; i < N; i++) P2.push_back(qs[i]);\n        double\
    \ d1 = dfs(dfs, P1), d2 = dfs(dfs, P2);\n        double d = min(d1, d2), ans =\
    \ d;\n        double px = P1[N / 2 - 1].real(), py = P1[N / 2 - 1].imag();\n \
    \       vector<pair<double, int>> V;\n        for (int i = 0; i < N; i++) {\n\
    \            if (qs[i].real() < px - d - EPS || qs[i].real() > px + d + EPS) continue;\n\
    \            V.push_back(make_pair(qs[i].imag(), i));\n        }\n        sort(V.begin(),\
    \ V.end());\n        int r = 0;\n        for (int l = 0; l < (int)V.size(); l++)\
    \ {\n            r = max(r, l);\n            while (r < (int)V.size() && V[r].first\
    \ < V[l].first + d + EPS) {\n                if (l != r) ans = min(ans, abs(qs[V[l].second]\
    \ - qs[V[r].second]));\n                r++;\n            }\n        }\n     \
    \   return ans;\n    };\n    return dfs(dfs, ps);\n}\n\nint main() {\n    cout\
    \ << fixed << setprecision(15);\n    int N;\n    cin >> N;\n    vector<Point>\
    \ ps(N);\n    for (int i = 0; i < N; i++) {\n        double x, y;\n        cin\
    \ >> x >> y;\n        ps[i] = Point(x, y);\n    }\n    cout << closest_pair(ps)\
    \ << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: icpc_Others/geometory/closest_pair.cpp
  requiredBy: []
  timestamp: '2025-05-29 13:38:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc_Others/geometory/closest_pair.cpp
layout: document
redirect_from:
- /library/icpc_Others/geometory/closest_pair.cpp
- /library/icpc_Others/geometory/closest_pair.cpp.html
title: icpc_Others/geometory/closest_pair.cpp
---
