---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_1dimos.test.cpp
    title: verify/Datastructure_1dimos.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "1\u6B21\u5143imos\u6CD5"
    links: []
  bundledCode: "#line 1 \"Datastructure/imos1d.hpp\"\nTT struct imos1d {\n    int\
    \ n;\n    vec<T> dat;\n    bool built = false;\n\n    imos1d(int n = 0) : n(n)\
    \ { dat.resize(n, T()); }\n\n    void imos_add(int i, T x) {\n        assert(built\
    \ == false);\n        assert(0 <= i && i < n);\n        dat[i] += x;\n       \
    \ if(i + 1 < n) dat[i + 1] -= x;\n    }\n\n    void imos_add(int l, int r, T x)\
    \ {\n        assert(0 <= l && r <= n && l <= r);\n        dat[l] += x;\n     \
    \   if (r < n) dat[r] -= x;\n    }\n\n    void build() {\n        rep(i, 0, n\
    \ - 1) dat[i + 1] += dat[i];\n        built = true;\n    }\n\n    T operator[](int\
    \ i) const {\n        assert(built == true);\n        assert(0 <= i && i < n);\n\
    \        return dat[i];\n    }\n};\n\n/*\n@brief 1\u6B21\u5143imos\u6CD5\n*/\n"
  code: "TT struct imos1d {\n    int n;\n    vec<T> dat;\n    bool built = false;\n\
    \n    imos1d(int n = 0) : n(n) { dat.resize(n, T()); }\n\n    void imos_add(int\
    \ i, T x) {\n        assert(built == false);\n        assert(0 <= i && i < n);\n\
    \        dat[i] += x;\n        if(i + 1 < n) dat[i + 1] -= x;\n    }\n\n    void\
    \ imos_add(int l, int r, T x) {\n        assert(0 <= l && r <= n && l <= r);\n\
    \        dat[l] += x;\n        if (r < n) dat[r] -= x;\n    }\n\n    void build()\
    \ {\n        rep(i, 0, n - 1) dat[i + 1] += dat[i];\n        built = true;\n \
    \   }\n\n    T operator[](int i) const {\n        assert(built == true);\n   \
    \     assert(0 <= i && i < n);\n        return dat[i];\n    }\n};\n\n/*\n@brief\
    \ 1\u6B21\u5143imos\u6CD5\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/imos1d.hpp
  requiredBy: []
  timestamp: '2024-08-03 19:09:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_1dimos.test.cpp
documentation_of: Datastructure/imos1d.hpp
layout: document
redirect_from:
- /library/Datastructure/imos1d.hpp
- /library/Datastructure/imos1d.hpp.html
title: "1\u6B21\u5143imos\u6CD5"
---
