---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Datastructure/static1dsum.hpp
    title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/static1dsum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#line 1 \"Utility/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n#define rep(i, s, t) for (ll i = s; i < (ll)(t);\
    \ i++)\n#define rrep(i, s, t) for (ll i = (ll)(t) - 1; i >= (ll)(s); i--)\n#define\
    \ all(x) begin(x), end(x)\n\n#define TT template <typename T>\nTT using vec =\
    \ vector<T>;\ntemplate <class T1, class T2> bool chmin(T1 &x, T2 y) {\n    return\
    \ x > y ? (x = y, true) : false;\n}\ntemplate <class T1, class T2> bool chmax(T1\
    \ &x, T2 y) {\n    return x < y ? (x = y, true) : false;\n}\n/*\n@brief verify\u7528\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n#line 1 \"Datastructure/static1dsum.hpp\"\
    \nTT struct static1dsum {\n    int n;\n    vec<T> dat;\n    bool built = false;\n\
    \n    static1dsum(int n = 0) : static1dsum(vec<T>(n, T())) {}\n\n    static1dsum(vec<T>\
    \ dat) : n(dat.size()), dat(dat) {}\n\n    void add(int i, T x) {\n        assert(!built);\n\
    \        dat[i] += x;\n    }\n\n    void build() {\n        rep(i, 0, n - 1) dat[i\
    \ + 1] += dat[i];\n        built = true;\n    }\n\n    T get(int p) const {\n\
    \        assert(built);\n        assert(0 <= p && p < n);\n        T res = dat[p];\n\
    \        if(p) res -= dat[p-1];\n        return res;\n    }\n\n    T prod(int\
    \ l, int r) const {\n        assert(built);\n        assert(0 <= l && r <= n);\n\
    \        assert(l <= r);\n        if(l == r) return 0;\n        T res = dat[r\
    \ - 1];\n        if (l) res -= dat[l - 1];\n        return res;\n    }\n\n   \
    \ T all_prod() const {\n        assert(built);\n        return dat[n-1];\n   \
    \ }\n};\n/*\n@brief 1\u6B21\u5143\u7D2F\u7A4D\u548C\n@docs doc/static1dsum.md\n\
    */\n#line 1 \"Datastructure/static2dsum.hpp\"\nTT struct static2dsum {\n    int\
    \ h, w;\n    vec<vec<T>> dat;\n    bool f = false;\n\n    static2dsum(int h =\
    \ 0, int w = 0)\n        : static2dsum(vec<vec<T>>(h, vec<T>(w, T()))) {}\n\n\
    \    static2dsum(vec<vec<T>> dat) : dat(dat) {\n        h = dat.size();\n    \
    \    if (h)\n            w = dat[0].size();\n        else\n            w = 0;\n\
    \    }\n\n    void add(int i, int j, T x) {\n        assert(!f);\n        dat[i][j]\
    \ += x;\n    }\n\n    void build() {\n        rep(i, 0, h) {\n            rep(j,\
    \ 0, w - 1) { dat[i][j + 1] += dat[i][j]; }\n        }\n\n        rep(j, 0, w)\
    \ {\n            rep(i, 0, h - 1) { dat[i + 1][j] += dat[i][j]; }\n        }\n\
    \n        f = true;\n    }\n\n    T prod(int sy, int ty, int sx, int tx) {\n \
    \       assert(f);\n        assert(0 <= sy && ty <= h);\n        assert(0 <= sx\
    \ && tx <= w);\n        assert(sy <= ty);\n        assert(sx <= tx);\n       \
    \ if(sy == ty || sx == tx) return 0;\n        tx--, ty--;\n        T res = dat[ty][tx];\n\
    \        if (sx > 0) res -= dat[ty][sx - 1];\n        if (sy > 0) res -= dat[sy\
    \ - 1][tx];\n        if (sx > 0 && sy > 0) res += dat[sy - 1][sx - 1];\n     \
    \   return res;\n    }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n@docs\
    \ doc/static2dsum.md\n*/\n#line 5 \"verify/static1dsum.test.cpp\"\n\n\nint main()\
    \ {\n    int n, q;\n    cin >> n >> q;\n    static1dsum<ll> sum1(n);\n    static2dsum<ll>\
    \ sum2(1, n);\n\n    rep(i, 0, n) {\n        ll a;\n        cin >> a;\n      \
    \  sum1.add(i, a);\n        sum2.add(0, i, a);\n    }\n\n    sum1.build();\n \
    \   sum2.build();\n\n    while(q--) {\n        int l, r;\n        cin >> l >>\
    \ r;\n        cout << sum1.prod(l, r) << endl;\n        assert(sum1.prod(l, r)\
    \ == sum2.prod(0, 1, l, r));\n    }\n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"../Utility/template.hpp\"\n#include \"../Datastructure/static1dsum.hpp\"\n\
    #include \"../Datastructure/static2dsum.hpp\"\n\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    static1dsum<ll> sum1(n);\n    static2dsum<ll> sum2(1,\
    \ n);\n\n    rep(i, 0, n) {\n        ll a;\n        cin >> a;\n        sum1.add(i,\
    \ a);\n        sum2.add(0, i, a);\n    }\n\n    sum1.build();\n    sum2.build();\n\
    \n    while(q--) {\n        int l, r;\n        cin >> l >> r;\n        cout <<\
    \ sum1.prod(l, r) << endl;\n        assert(sum1.prod(l, r) == sum2.prod(0, 1,\
    \ l, r));\n    }\n    \n}"
  dependsOn:
  - Utility/template.hpp
  - Datastructure/static1dsum.hpp
  - Datastructure/static2dsum.hpp
  isVerificationFile: true
  path: verify/static1dsum.test.cpp
  requiredBy: []
  timestamp: '2024-12-09 02:13:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/static1dsum.test.cpp
layout: document
redirect_from:
- /verify/verify/static1dsum.test.cpp
- /verify/verify/static1dsum.test.cpp.html
title: verify/static1dsum.test.cpp
---
