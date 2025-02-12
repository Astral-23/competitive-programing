---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/static2dsum.hpp
    title: Datastructure/static2dsum.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/template.hpp
    title: "verify\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560
  bundledCode: "#line 1 \"verify/Datastructure_static2dsum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560\"\n#line 1\
    \ \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t); i++)\n#define\
    \ rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define all(x) begin(x),\
    \ end(x)\n\n#define TT template <typename T>\nTT using vec = vector<T>;\ntemplate\
    \ <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return x > y ? (x = y, true)\
    \ : false;\n}\ntemplate <class T1, class T2> bool chmax(T1 &x, T2 y) {\n    return\
    \ x < y ? (x = y, true) : false;\n}\nstruct io_setup {\n    io_setup() {\n   \
    \     ios::sync_with_stdio(false);\n        std::cin.tie(nullptr);\n        cout\
    \ << fixed << setprecision(15);\n    }\n} io_setup;\n\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/static2dsum.hpp\"\
    \n\nTT struct static2dsum {\n    int id(int i, int j) const { return i * (w +\
    \ 1) + j; }\n    int h, w;\n    vector<T> d;\n    bool built = false;\n\n    static2dsum(int\
    \ h = 0, int w = 0)\n        : static2dsum(vector<vector<T>>(h, vector<T>(w, T())))\
    \ {}\n\n    static2dsum(vec<vec<T>> const &dat) {\n        h = dat.size();\n \
    \       if (h)\n            w = dat[0].size();\n        else\n            w =\
    \ 0;\n        d.resize((h + 1) * (w + 1), 0);\n        for (int i = 0; i < h;\
    \ ++i) {\n            for (int j = 0; j < w; ++j) {\n                d[id(i +\
    \ 1, j + 1)] = dat[i][j];\n            }\n        }\n    }\n    void add(int i,\
    \ int j, T x) {\n        assert(built == false);\n        d[id(i + 1, j + 1)]\
    \ += x;\n    }\n\n    void build() {\n        assert(built == false);\n      \
    \  for (int i = 0; i <= h; ++i) {\n            for (int j = 0; j < w; ++j) {\n\
    \                d[id(i, j + 1)] += d[id(i, j)];\n            }\n        }\n\n\
    \        for (int j = 0; j <= w; ++j) {\n            for (int i = 0; i < h; ++i)\
    \ {\n                d[id(i + 1, j)] += d[id(i, j)];\n            }\n        }\n\
    \n        built = true;\n    }\n\n    T get(int y, int x) const {\n        assert(built);\n\
    \        assert(0 <= y && y < h);\n        assert(0 <= x && x < w);\n        return\
    \ prod(y, y + 1, x, x + 1);\n    }\n\n    T prod(int sx, int tx, int sy, int ty)\
    \ const {\n        assert(built);\n        assert(0 <= sx && sx <= tx && tx <=\
    \ h);\n        assert(0 <= sy && sy <= ty && ty <= w);\n        T res = d[id(tx,\
    \ ty)];\n        res -= d[id(tx, sy)];\n        res -= d[id(sx, ty)];\n      \
    \  res += d[id(sx, sy)];\n        return res;\n    }\n};\n#line 4 \"verify/Datastructure_static2dsum.test.cpp\"\
    \n\nint main() {\n    int h, w;\n    cin >> h >> w;\n    int k;\n    cin >> k;\n\
    \    static2dsum<ll> J(h, w);\n    static2dsum<ll> O(h, w);\n    static2dsum<ll>\
    \ I(h, w);\n\n\n    rep(i, 0, h) rep(j, 0, w) {\n        char a;\n        cin\
    \ >> a;\n        if(a=='J') J.add(i, j, 1);\n        if(a=='O') O.add(i, j, 1);\n\
    \        if(a=='I') I.add(i, j, 1);\n    }\n\n    J.build();O.build();I.build();\n\
    \n\n    while(k--) {\n        int sy, sx, ty, tx;\n        cin >> sy >> sx >>\
    \ ty >> tx;\n        sy--, sx--;\n        cout << J.prod(sy, ty, sx, tx) << \"\
    \ \";\n        cout << O.prod(sy, ty, sx, tx) << \" \";\n        cout << I.prod(sy,\
    \ ty, sx, tx) << endl;\n\n    }\n\t\n\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/static2dsum.hpp\"\
    \n\nint main() {\n    int h, w;\n    cin >> h >> w;\n    int k;\n    cin >> k;\n\
    \    static2dsum<ll> J(h, w);\n    static2dsum<ll> O(h, w);\n    static2dsum<ll>\
    \ I(h, w);\n\n\n    rep(i, 0, h) rep(j, 0, w) {\n        char a;\n        cin\
    \ >> a;\n        if(a=='J') J.add(i, j, 1);\n        if(a=='O') O.add(i, j, 1);\n\
    \        if(a=='I') I.add(i, j, 1);\n    }\n\n    J.build();O.build();I.build();\n\
    \n\n    while(k--) {\n        int sy, sx, ty, tx;\n        cin >> sy >> sx >>\
    \ ty >> tx;\n        sy--, sx--;\n        cout << J.prod(sy, ty, sx, tx) << \"\
    \ \";\n        cout << O.prod(sy, ty, sx, tx) << \" \";\n        cout << I.prod(sy,\
    \ ty, sx, tx) << endl;\n\n    }\n\t\n\n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/static2dsum.hpp
  isVerificationFile: true
  path: verify/Datastructure_static2dsum.test.cpp
  requiredBy: []
  timestamp: '2025-02-13 07:41:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Datastructure_static2dsum.test.cpp
layout: document
redirect_from:
- /verify/verify/Datastructure_static2dsum.test.cpp
- /verify/verify/Datastructure_static2dsum.test.cpp.html
title: verify/Datastructure_static2dsum.test.cpp
---
