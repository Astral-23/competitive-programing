---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Datastructure/imos2d.hpp
    title: "2\u6B21\u5143imos\u6CD5"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja
  bundledCode: "#line 1 \"verify/imos2d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/imos2d.hpp\"\
    \nTT struct imos2d {\n    int h, w;\n    vec<vec<T>> dat;\n    bool f = false;\n\
    \n    imos2d(int h = 0, int w = 0) : h(h), w(w) {\n        dat = vec<vec<T>>(h,\
    \ vec<T>(w, T()));\n    }\n\n    void imos_add(int i, int j, T x) {\n        assert(f\
    \ == false);\n        dat[i][j] += x;\n    }\n\n    void imos_add(int sy, int\
    \ ty, int sx, int tx, T x) {\n        assert(f == false);\n        if (sx >= tx\
    \ || sy >= ty) return;\n        dat[sy][sx] += x;\n        if (ty < h) dat[ty][sx]\
    \ -= x;\n        if (tx < w) dat[sy][tx] -= x;\n        if (tx < w && ty < h)\
    \ dat[ty][tx] += x;\n    }\n\n    void build() {\n        rep(i, 0, h) {\n   \
    \         rep(j, 0, w - 1) { dat[i][j + 1] += dat[i][j]; }\n        }\n      \
    \  rep(j, 0, w) {\n            rep(i, 0, h - 1) { dat[i + 1][j] += dat[i][j];\
    \ }\n        }\n        f = true;\n    }\n\n    T imos_get(int i, int j) { return\
    \ dat[i][j]; }\n};\n/*\n@brief 2\u6B21\u5143imos\u6CD5\n\n*/\n#line 4 \"verify/imos2d.test.cpp\"\
    \n\nint main() { \n    int n;\n    cin >> n;\n    imos2d<ll> sum(1001, 1001);\n\
    \n    rep(i, 0, n) {\n        int sx, sy, tx, ty;\n        cin >> sx >> sy >>\
    \ tx >> ty;\n        sum.imos_add(sy, ty, sx, tx, 1);\n    }\n\n    sum.build();\n\
    \    int ans = 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001){ \n        \
    \    chmax(ans, sum.imos_get(i, j));\n        }\n    }\n\n    cout << ans << endl;\n\
    \n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/imos2d.hpp\"\
    \n\nint main() { \n    int n;\n    cin >> n;\n    imos2d<ll> sum(1001, 1001);\n\
    \n    rep(i, 0, n) {\n        int sx, sy, tx, ty;\n        cin >> sx >> sy >>\
    \ tx >> ty;\n        sum.imos_add(sy, ty, sx, tx, 1);\n    }\n\n    sum.build();\n\
    \    int ans = 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001){ \n        \
    \    chmax(ans, sum.imos_get(i, j));\n        }\n    }\n\n    cout << ans << endl;\n\
    \n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/imos2d.hpp
  isVerificationFile: true
  path: verify/imos2d.test.cpp
  requiredBy: []
  timestamp: '2024-08-16 18:32:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/imos2d.test.cpp
layout: document
redirect_from:
- /verify/verify/imos2d.test.cpp
- /verify/verify/imos2d.test.cpp.html
title: verify/imos2d.test.cpp
---
