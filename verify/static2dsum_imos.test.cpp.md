---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Datastructure/static2dsum.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: Utility/template.hpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
  bundledCode: "#line 1 \"verify/static2dsum_imos.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for(ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n#define rall(x) rbegin(x), rend(x)\n\n#define TT template<typename\
    \ T>\nTT using vec = vector<T>;\ntemplate<class T1, class T2> bool chmin(T1 &x,\
    \ T2 y) { return x > y ? (x = y, true) : false; }\ntemplate<class T1, class T2>\
    \ bool chmax(T1 &x, T2 y) { return x < y ? (x = y, true) : false; }\n\nstruct\
    \ io_setup {\n    io_setup() {\n        ios::sync_with_stdio(false);\n       \
    \ std::cin.tie(nullptr);\n        cout << fixed << setprecision(15);\n    }\n\
    } io_setup;\n\n/*\n@brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"\
    Datastructure/static2dsum.hpp\"\nTT struct static2dsum {\n    int h, w;\n    vec<vec<T>>\
    \ dat;\n    bool f = false;\n\n    static2dsum(int H, int W) : h(H), w(W) {\n\
    \        dat = vec<vec<T>>(h, vec<T>(w, 0));\n    }\n\n    void add(int i, int\
    \ j, T x) {\n        assert(!f);\n        dat[i][j] += x;\n    }\n\n    void imos_add(int\
    \ i, int j, T x) {\n        add(i, j, x);\n    }\n\n    void imos_add(int sy,\
    \ int ty,  int sx, int tx, T x) {\n        assert(!f);\n        chmax(sx, 0);\
    \ chmax(sy, 0);\n        chmin(tx, w); chmin(ty, h);\n        if(sx >= tx || sy\
    \ >= ty) return;\n        dat[sy][sx] += x;\n        if(ty < h) dat[ty][sx] -=\
    \ x;\n        if(tx < w) dat[sy][tx] -= x;\n        if(tx < w && ty < h) dat[ty][tx]\
    \ += x;\n        return;\n    }\n\n    void build() {\n        rep(i, 0, h) {\n\
    \            rep(j, 0, w-1) {\n                dat[i][j+1] += dat[i][j];\n   \
    \         }\n        }\n\n        rep(j, 0, w) {\n            rep(i, 0, h-1) {\n\
    \                dat[i+1][j] += dat[i][j];\n            }\n        }\n\n     \
    \   f = true;\n    }\n\n    T imos_get(int i, int j) {\n        return prod(0,\
    \ i+1, 0, j+1);\n    }\n\n    T get(int i, int j) {\n        assert(f);\n    \
    \    assert(0 <= i && i < h);\n        assert(0 <= j && j < w);\n        return\
    \ dat[i][j];\n    }\n\n    T prod(int sy, int ty, int sx, int tx) {\n        assert(f);\n\
    \        assert(sy >= 0); assert(ty <= h);\n        assert(sx >= 0); assert(tx\
    \ <= w);\n        assert(sy <= ty); assert(sx <= tx);\n        if(sx >= tx ||\
    \ sy >= ty) return 0;\n        tx--, ty--;\n        T res = dat[ty][tx];\n   \
    \     if(sx > 0) res -= dat[ty][sx-1];\n        if(sy > 0) res -= dat[sy-1][tx];\n\
    \        if(sx > 0 && sy > 0) res += dat[sy-1][sx-1];\n        return res;\n \
    \   }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n@doc docs/static2dsum.md\n\
    */\n#line 4 \"verify/static2dsum_imos.test.cpp\"\n\nint main() { \n    int n;\n\
    \    cin >> n;\n    static2dsum<ll> sum(1001, 1001);\n\n    rep(i, 0, n) {\n \
    \       int sx, sy, tx, ty;\n        cin >> sx >> sy >> tx >> ty;\n        sum.imos_add(sy,\
    \ ty, sx, tx, 1);\n    }\n\n    sum.build();\n    int ans = 0;\n    rep(i, 0,\
    \ 1001) {\n        rep(j, 0, 1001){ \n            chmax(ans, sum.imos_get(i, j));\n\
    \        }\n    }\n\n    cout << ans << endl;\n\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B&lang=ja\"\
    \n#include \"../Utility/template.hpp\"\n#include \"../Datastructure/static2dsum.hpp\"\
    \n\nint main() { \n    int n;\n    cin >> n;\n    static2dsum<ll> sum(1001, 1001);\n\
    \n    rep(i, 0, n) {\n        int sx, sy, tx, ty;\n        cin >> sx >> sy >>\
    \ tx >> ty;\n        sum.imos_add(sy, ty, sx, tx, 1);\n    }\n\n    sum.build();\n\
    \    int ans = 0;\n    rep(i, 0, 1001) {\n        rep(j, 0, 1001){ \n        \
    \    chmax(ans, sum.imos_get(i, j));\n        }\n    }\n\n    cout << ans << endl;\n\
    \n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/static2dsum.hpp
  isVerificationFile: true
  path: verify/static2dsum_imos.test.cpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/static2dsum_imos.test.cpp
layout: document
redirect_from:
- /verify/verify/static2dsum_imos.test.cpp
- /verify/verify/static2dsum_imos.test.cpp.html
title: verify/static2dsum_imos.test.cpp
---
