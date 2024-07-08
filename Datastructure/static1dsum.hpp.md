---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/static1dsum.test.cpp
    title: verify/static1dsum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"Datastructure/static1dsum.hpp\"\nTT struct static1dsum {\n\
    \    int n;\n    vec<T> dat;\n    bool f = false;\n\n    static1dsum(int N) :\
    \ n(N) {\n        dat = vec<T>(n, 0);\n    }\n\n    void add(int i, T x) {\n \
    \       assert(!f);\n        dat[i] += x;\n    }\n\n    void imos_add(int i, T\
    \ x) {\n        add(i, x);\n    }\n\n    void imos_add(int l, int r, T x) {\n\
    \        assert(!f);\n        chmax(l, 0); \n        chmin(r, n);\n        if(l\
    \ >= r) return;\n        dat[l] += x;\n        if(r < n) dat[r] -= x;\n      \
    \  return;\n    }\n\n    void build() {\n        rep(i, 0, n-1) dat[i+1] += dat[i];\n\
    \        f = true;\n    }\n\n    T get(int i) {\n        assert(f);\n        assert(0\
    \ <= i && i < n);\n        return dat[i];\n    }\n\n    T imos_get(int i) {\n\
    \        return prod(0, i+1);\n    }\n\n    T prod(int l, int r) {\n        assert(f);\n\
    \        assert(l >= 0);\n        assert(r <= n);\n        assert(l <= r);\n \
    \       T res = dat[r-1];\n        if(l) res -= dat[l-1];\n        return res;\n\
    \    }\n\n};\n\n/*\n@brief 1\u6B21\u5143\u7D2F\u7A4D\u548C\n@doc docs/static1dsum.md\n\
    \n\n*/\n"
  code: "TT struct static1dsum {\n    int n;\n    vec<T> dat;\n    bool f = false;\n\
    \n    static1dsum(int N) : n(N) {\n        dat = vec<T>(n, 0);\n    }\n\n    void\
    \ add(int i, T x) {\n        assert(!f);\n        dat[i] += x;\n    }\n\n    void\
    \ imos_add(int i, T x) {\n        add(i, x);\n    }\n\n    void imos_add(int l,\
    \ int r, T x) {\n        assert(!f);\n        chmax(l, 0); \n        chmin(r,\
    \ n);\n        if(l >= r) return;\n        dat[l] += x;\n        if(r < n) dat[r]\
    \ -= x;\n        return;\n    }\n\n    void build() {\n        rep(i, 0, n-1)\
    \ dat[i+1] += dat[i];\n        f = true;\n    }\n\n    T get(int i) {\n      \
    \  assert(f);\n        assert(0 <= i && i < n);\n        return dat[i];\n    }\n\
    \n    T imos_get(int i) {\n        return prod(0, i+1);\n    }\n\n    T prod(int\
    \ l, int r) {\n        assert(f);\n        assert(l >= 0);\n        assert(r <=\
    \ n);\n        assert(l <= r);\n        T res = dat[r-1];\n        if(l) res -=\
    \ dat[l-1];\n        return res;\n    }\n\n};\n\n/*\n@brief 1\u6B21\u5143\u7D2F\
    \u7A4D\u548C\n@doc docs/static1dsum.md\n\n\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/static1dsum.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/static1dsum.test.cpp
documentation_of: Datastructure/static1dsum.hpp
layout: document
redirect_from:
- /library/Datastructure/static1dsum.hpp
- /library/Datastructure/static1dsum.hpp.html
title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
---
