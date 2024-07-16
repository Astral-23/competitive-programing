---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/static1dsum.test.cpp
    title: verify/static1dsum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Datastructure/static1dsum.hpp\"\nTT struct static1dsum {\n\
    \    int n;\n    vec<T> dat;\n    bool f = false;\n\n    static1dsum(int n = 0)\
    \ : static1dsum(vec<T>(n, T())) {}\n\n    static1dsum(vec<T> dat) : n(dat.size()),\
    \ dat(dat) {}\n\n    void add(int i, T x) {\n        assert(!f);\n        dat[i]\
    \ += x;\n    }\n\n    void imos_add(int i, T x) { add(i, x); }\n\n    void imos_add(int\
    \ l, int r, T x) {\n        assert(!f);\n        chmax(l, 0);\n        chmin(r,\
    \ n);\n        if (l >= r) return;\n        dat[l] += x;\n        if (r < n) dat[r]\
    \ -= x;\n        return;\n    }\n\n    void build() {\n        rep(i, 0, n - 1)\
    \ dat[i + 1] += dat[i];\n        f = true;\n    }\n\n    T get(int i) {\n    \
    \    assert(f);\n        assert(0 <= i && i < n);\n        return dat[i];\n  \
    \  }\n\n    T imos_get(int i) { return prod(0, i + 1); }\n\n    T prod(int l,\
    \ int r) {\n        assert(f);\n        assert(l >= 0);\n        assert(r <= n);\n\
    \        assert(l <= r);\n        T res = dat[r - 1];\n        if (l) res -= dat[l\
    \ - 1];\n        return res;\n    }\n};\n"
  code: "TT struct static1dsum {\n    int n;\n    vec<T> dat;\n    bool f = false;\n\
    \n    static1dsum(int n = 0) : static1dsum(vec<T>(n, T())) {}\n\n    static1dsum(vec<T>\
    \ dat) : n(dat.size()), dat(dat) {}\n\n    void add(int i, T x) {\n        assert(!f);\n\
    \        dat[i] += x;\n    }\n\n    void imos_add(int i, T x) { add(i, x); }\n\
    \n    void imos_add(int l, int r, T x) {\n        assert(!f);\n        chmax(l,\
    \ 0);\n        chmin(r, n);\n        if (l >= r) return;\n        dat[l] += x;\n\
    \        if (r < n) dat[r] -= x;\n        return;\n    }\n\n    void build() {\n\
    \        rep(i, 0, n - 1) dat[i + 1] += dat[i];\n        f = true;\n    }\n\n\
    \    T get(int i) {\n        assert(f);\n        assert(0 <= i && i < n);\n  \
    \      return dat[i];\n    }\n\n    T imos_get(int i) { return prod(0, i + 1);\
    \ }\n\n    T prod(int l, int r) {\n        assert(f);\n        assert(l >= 0);\n\
    \        assert(r <= n);\n        assert(l <= r);\n        T res = dat[r - 1];\n\
    \        if (l) res -= dat[l - 1];\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/static1dsum.hpp
  requiredBy: []
  timestamp: '2024-07-17 07:05:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/static1dsum.test.cpp
documentation_of: Datastructure/static1dsum.hpp
layout: document
redirect_from:
- /library/Datastructure/static1dsum.hpp
- /library/Datastructure/static1dsum.hpp.html
title: Datastructure/static1dsum.hpp
---
