---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Datastructure/2dbit.hpp
    title: Datastructure/2dbit.hpp
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
  bundledCode: "#line 1 \"verify/Datastructure_2dbit_imos.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n\
    \    io_setup() {\n        ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n\
    \        cout << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief\
    \ verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/2dbit.hpp\"\
    \nTT struct bit2d {\n    int h, w;\n    vec<vec<T>> dat;\n\n    bit2d(int H, int\
    \ W) : h(H), w(W) {\n        dat = vec<vec<T>>(h, vec<T>(w, 0));\n    }\n\n  \
    \  void add(int y, int x, T v) {\n        assert(0 <= y && y < h);\n        assert(0\
    \ <= x && x < w);\n        for( ; y < h; y |= y + 1) {\n            for(int b\
    \ = x; b < w; b |= b + 1) {\n                dat[y][b] += v;\n            }\n\
    \        }\n    }\n\n    T prod(int y, int x) const {\n        T res = 0;\n  \
    \      y--, x--;\n        for( ; y >= 0; y = (y & (y + 1)) - 1) {\n          \
    \  for(int b = x; b >= 0; b = (b & (b + 1)) - 1) {\n                res += dat[y][b];\n\
    \            }\n        }\n        return res;\n    }\n\n    T prod(int sy, int\
    \ ty, int sx, int tx) const {\n        assert(0 <= sy && sy <= ty && ty <= h);\n\
    \        assert(0 <= sx && sx <= tx && tx <= w);\n\n        T res = prod(ty, tx);\n\
    \        res -= prod(sy, tx);\n        res -= prod(ty, sx);\n        res += prod(sy,\
    \ sx);\n        return res;\n    }\n};\n#line 4 \"verify/Datastructure_2dbit_imos.test.cpp\"\
    \n\nint main() { \n    int n;\n    cin >> n;\n    bit2d<ll> sum(1001, 1001);\n\
    \n    rep(i, 0, n) {\n        int sx, sy, tx, ty;\n        cin >> sx >> sy >>\
    \ tx >> ty;\n        sum.imos_add(sy, ty, sx, tx, 1);\n    }\n\n\n    int ans\
    \ = 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001){ \n            chmax(ans,\
    \ sum.imos_get(i, j));\n        }\n    }\n\n    cout << ans << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/2dbit.hpp\"\
    \n\nint main() { \n    int n;\n    cin >> n;\n    bit2d<ll> sum(1001, 1001);\n\
    \n    rep(i, 0, n) {\n        int sx, sy, tx, ty;\n        cin >> sx >> sy >>\
    \ tx >> ty;\n        sum.imos_add(sy, ty, sx, tx, 1);\n    }\n\n\n    int ans\
    \ = 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001){ \n            chmax(ans,\
    \ sum.imos_get(i, j));\n        }\n    }\n\n    cout << ans << endl;\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/2dbit.hpp
  isVerificationFile: true
  path: verify/Datastructure_2dbit_imos.test.cpp
  requiredBy: []
  timestamp: '2025-02-19 12:40:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/Datastructure_2dbit_imos.test.cpp
layout: document
redirect_from:
- /verify/verify/Datastructure_2dbit_imos.test.cpp
- /verify/verify/Datastructure_2dbit_imos.test.cpp.html
title: verify/Datastructure_2dbit_imos.test.cpp
---
