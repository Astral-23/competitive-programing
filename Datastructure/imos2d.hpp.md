---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/imos2d.test.cpp
    title: verify/imos2d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "2\u6B21\u5143imos\u6CD5"
    links: []
  bundledCode: "#line 1 \"Datastructure/imos2d.hpp\"\nTT struct imos2d {\n    int\
    \ h, w;\n    vec<vec<T>> dat;\n    bool f = false;\n\n    imos2d(int h = 0, int\
    \ w = 0) : h(h), w(w) {\n        dat = vec<vec<T>>(h, vec<T>(w, T()));\n    }\n\
    \n    void imos_add(int i, int j, T x) {\n        assert(f == false);\n      \
    \  dat[i][j] += x;\n    }\n\n    void imos_add(int sy, int ty, int sx, int tx,\
    \ T x) {\n        assert(f == false);\n        if (sx >= tx || sy >= ty) return;\n\
    \        dat[sy][sx] += x;\n        if (ty < h) dat[ty][sx] -= x;\n        if\
    \ (tx < w) dat[sy][tx] -= x;\n        if (tx < w && ty < h) dat[ty][tx] += x;\n\
    \    }\n\n    void build() {\n        rep(i, 0, h) {\n            rep(j, 0, w\
    \ - 1) { dat[i][j + 1] += dat[i][j]; }\n        }\n        rep(j, 0, w) {\n  \
    \          rep(i, 0, h - 1) { dat[i + 1][j] += dat[i][j]; }\n        }\n     \
    \   f = true;\n    }\n\n    T imos_get(int i, int j) { return dat[i][j]; }\n};\n\
    /*\n@brief 2\u6B21\u5143imos\u6CD5\n\n*/\n"
  code: "TT struct imos2d {\n    int h, w;\n    vec<vec<T>> dat;\n    bool f = false;\n\
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
    \ dat[i][j]; }\n};\n/*\n@brief 2\u6B21\u5143imos\u6CD5\n\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/imos2d.hpp
  requiredBy: []
  timestamp: '2024-08-03 19:09:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/imos2d.test.cpp
documentation_of: Datastructure/imos2d.hpp
layout: document
redirect_from:
- /library/Datastructure/imos2d.hpp
- /library/Datastructure/imos2d.hpp.html
title: "2\u6B21\u5143imos\u6CD5"
---
