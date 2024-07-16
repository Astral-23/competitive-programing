---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/static2dsum.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
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
  bundledCode: "#line 1 \"verify/static2dsum.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template<typename T>\nTT using vec = vector<T>;\n\
    template<class T1, class T2> bool chmin(T1 &x, T2 y) { return x > y ? (x = y,\
    \ true) : false; }\ntemplate<class T1, class T2> bool chmax(T1 &x, T2 y) { return\
    \ x < y ? (x = y, true) : false; }\n\n/*\n@brief verify\u7528\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/static2dsum.hpp\"\nTT struct static2dsum\
    \ {\n    int h, w;\n    vec<vec<T>> dat;\n    bool f = false;\n\n    static2dsum(int\
    \ h = 0, int w = 0)\n        : static2dsum(vec<vec<T>>(h, vec<T>(w, T()))) {}\n\
    \n    static2dsum(vec<vec<T>> dat) : dat(dat) {\n        h = dat.size();\n   \
    \     if (h)\n            w = dat[0].size();\n        else\n            w = 0;\n\
    \    }\n\n    void add(int i, int j, T x) {\n        assert(!f);\n        dat[i][j]\
    \ += x;\n    }\n\n    void imos_add(int i, int j, T x) { add(i, j, x); }\n\n \
    \   void imos_add(int sy, int ty, int sx, int tx, T x) {\n        assert(!f);\n\
    \        chmax(sx, 0);\n        chmax(sy, 0);\n        chmin(tx, w);\n       \
    \ chmin(ty, h);\n        if (sx >= tx || sy >= ty) return;\n        dat[sy][sx]\
    \ += x;\n        if (ty < h) dat[ty][sx] -= x;\n        if (tx < w) dat[sy][tx]\
    \ -= x;\n        if (tx < w && ty < h) dat[ty][tx] += x;\n        return;\n  \
    \  }\n\n    void build() {\n        rep(i, 0, h) {\n            rep(j, 0, w -\
    \ 1) { dat[i][j + 1] += dat[i][j]; }\n        }\n\n        rep(j, 0, w) {\n  \
    \          rep(i, 0, h - 1) { dat[i + 1][j] += dat[i][j]; }\n        }\n\n   \
    \     f = true;\n    }\n\n    T imos_get(int i, int j) { return prod(0, i + 1,\
    \ 0, j + 1); }\n\n    T get(int i, int j) {\n        assert(f);\n        assert(0\
    \ <= i && i < h);\n        assert(0 <= j && j < w);\n        return dat[i][j];\n\
    \    }\n\n    T prod(int sy, int ty, int sx, int tx) {\n        assert(f);\n \
    \       assert(sy >= 0);\n        assert(ty <= h);\n        assert(sx >= 0);\n\
    \        assert(tx <= w);\n        assert(sy <= ty);\n        assert(sx <= tx);\n\
    \        if (sx >= tx || sy >= ty) return 0;\n        tx--, ty--;\n        T res\
    \ = dat[ty][tx];\n        if (sx > 0) res -= dat[ty][sx - 1];\n        if (sy\
    \ > 0) res -= dat[sy - 1][tx];\n        if (sx > 0 && sy > 0) res += dat[sy -\
    \ 1][sx - 1];\n        return res;\n    }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\
    \u548C\n@doc docs/static2dsum.md\n*/\n#line 4 \"verify/static2dsum.test.cpp\"\n\
    \nint main() {\n    int h, w;\n    cin >> h >> w;\n    int k;\n    cin >> k;\n\
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
  path: verify/static2dsum.test.cpp
  requiredBy: []
  timestamp: '2024-07-17 07:05:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/static2dsum.test.cpp
layout: document
redirect_from:
- /verify/verify/static2dsum.test.cpp
- /verify/verify/static2dsum.test.cpp.html
title: verify/static2dsum.test.cpp
---
