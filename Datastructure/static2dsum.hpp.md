---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/static1dsum.test.cpp
    title: verify/static1dsum.test.cpp
  - icon: ':x:'
    path: verify/static2dsum.test.cpp
    title: verify/static2dsum.test.cpp
  - icon: ':x:'
    path: verify/static2dsum_imos.test.cpp
    title: verify/static2dsum_imos.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"Datastructure/static2dsum.hpp\"\nTT struct static2dsum {\n\
    \    int h, w;\n    vec<vec<T>> dat;\n    bool f = false;\n\n    static2dsum(int\
    \ H, int W) : h(H), w(W) {\n        dat = vec<vec<T>>(h, vec<T>(w, 0));\n    }\n\
    \n    void add(int i, int j, T x) {\n        assert(!f);\n        dat[i][j] +=\
    \ x;\n    }\n\n    void imos_add(int i, int j, T x) {\n        add(i, j, x);\n\
    \    }\n\n    void imos_add(int sy, int ty,  int sx, int tx, T x) {\n        assert(!f);\n\
    \        chmax(sx, 0); chmax(sy, 0);\n        chmin(tx, w); chmin(ty, h);\n  \
    \      if(sx >= tx || sy >= ty) return;\n        dat[sy][sx] += x;\n        if(ty\
    \ < h) dat[ty][sx] -= x;\n        if(tx < w) dat[sy][tx] -= x;\n        if(tx\
    \ < w && ty < h) dat[ty][tx] += x;\n        return;\n    }\n\n    void build()\
    \ {\n        rep(i, 0, h) {\n            rep(j, 0, w-1) {\n                dat[i][j+1]\
    \ += dat[i][j];\n            }\n        }\n\n        rep(j, 0, w) {\n        \
    \    rep(i, 0, h-1) {\n                dat[i+1][j] += dat[i][j];\n           \
    \ }\n        }\n\n        f = true;\n    }\n\n    T imos_get(int i, int j) {\n\
    \        return prod(0, i+1, 0, j+1);\n    }\n\n    T get(int i, int j) {\n  \
    \      assert(f);\n        assert(0 <= i && i < h);\n        assert(0 <= j &&\
    \ j < w);\n        return dat[i][j];\n    }\n\n    T prod(int sy, int ty, int\
    \ sx, int tx) {\n        assert(f);\n        assert(sy >= 0); assert(ty <= h);\n\
    \        assert(sx >= 0); assert(tx <= w);\n        assert(sy <= ty); assert(sx\
    \ <= tx);\n        if(sx >= tx || sy >= ty) return 0;\n        tx--, ty--;\n \
    \       T res = dat[ty][tx];\n        if(sx > 0) res -= dat[ty][sx-1];\n     \
    \   if(sy > 0) res -= dat[sy-1][tx];\n        if(sx > 0 && sy > 0) res += dat[sy-1][sx-1];\n\
    \        return res;\n    }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n\
    @doc docs/static2dsum.md\n*/\n"
  code: "TT struct static2dsum {\n    int h, w;\n    vec<vec<T>> dat;\n    bool f\
    \ = false;\n\n    static2dsum(int H, int W) : h(H), w(W) {\n        dat = vec<vec<T>>(h,\
    \ vec<T>(w, 0));\n    }\n\n    void add(int i, int j, T x) {\n        assert(!f);\n\
    \        dat[i][j] += x;\n    }\n\n    void imos_add(int i, int j, T x) {\n  \
    \      add(i, j, x);\n    }\n\n    void imos_add(int sy, int ty,  int sx, int\
    \ tx, T x) {\n        assert(!f);\n        chmax(sx, 0); chmax(sy, 0);\n     \
    \   chmin(tx, w); chmin(ty, h);\n        if(sx >= tx || sy >= ty) return;\n  \
    \      dat[sy][sx] += x;\n        if(ty < h) dat[ty][sx] -= x;\n        if(tx\
    \ < w) dat[sy][tx] -= x;\n        if(tx < w && ty < h) dat[ty][tx] += x;\n   \
    \     return;\n    }\n\n    void build() {\n        rep(i, 0, h) {\n         \
    \   rep(j, 0, w-1) {\n                dat[i][j+1] += dat[i][j];\n            }\n\
    \        }\n\n        rep(j, 0, w) {\n            rep(i, 0, h-1) {\n         \
    \       dat[i+1][j] += dat[i][j];\n            }\n        }\n\n        f = true;\n\
    \    }\n\n    T imos_get(int i, int j) {\n        return prod(0, i+1, 0, j+1);\n\
    \    }\n\n    T get(int i, int j) {\n        assert(f);\n        assert(0 <= i\
    \ && i < h);\n        assert(0 <= j && j < w);\n        return dat[i][j];\n  \
    \  }\n\n    T prod(int sy, int ty, int sx, int tx) {\n        assert(f);\n   \
    \     assert(sy >= 0); assert(ty <= h);\n        assert(sx >= 0); assert(tx <=\
    \ w);\n        assert(sy <= ty); assert(sx <= tx);\n        if(sx >= tx || sy\
    \ >= ty) return 0;\n        tx--, ty--;\n        T res = dat[ty][tx];\n      \
    \  if(sx > 0) res -= dat[ty][sx-1];\n        if(sy > 0) res -= dat[sy-1][tx];\n\
    \        if(sx > 0 && sy > 0) res += dat[sy-1][sx-1];\n        return res;\n \
    \   }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n@doc docs/static2dsum.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/static2dsum.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/static2dsum.test.cpp
  - verify/static1dsum.test.cpp
  - verify/static2dsum_imos.test.cpp
documentation_of: Datastructure/static2dsum.hpp
layout: document
redirect_from:
- /library/Datastructure/static2dsum.hpp
- /library/Datastructure/static2dsum.hpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
