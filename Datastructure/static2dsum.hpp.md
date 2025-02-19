---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_static2dsum.test.cpp
    title: verify/Datastructure_static2dsum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Datastructure/static2dsum.hpp\"\nTT struct static2dsum {\n\
    \    int id(int i, int j) const {\n        return i * (w + 1) + j;\n    }\n  \
    \  int h, w;\n    vector<T> d;\n    bool built = false;\n\n    static2dsum(int\
    \ h = 0, int w = 0)\n        : static2dsum(vector<vector<T>>(h, vector<T>(w, T())))\
    \ {\n    }\n\n    static2dsum(vec<vec<T>> const &dat) {\n        h = dat.size();\n\
    \        if (h)\n            w = dat[0].size();\n        else\n            w =\
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
    \ prod(x, x + 1, y, y + 1);\n    }\n\n    T prod(int sx, int tx, int sy, int ty)\
    \ const {\n        assert(built);\n        assert(0 <= sy && sy <= ty && ty <=\
    \ h);\n        assert(0 <= sx && sx <= tx && tx <= w);\n\n        T res = d[id(ty,\
    \ tx)];\n        res -= d[id(sy, tx)];\n        res -= d[id(ty, sx)];\n      \
    \  res += d[id(sy, sx)];\n        return res;\n    }\n};\n"
  code: "TT struct static2dsum {\n    int id(int i, int j) const {\n        return\
    \ i * (w + 1) + j;\n    }\n    int h, w;\n    vector<T> d;\n    bool built = false;\n\
    \n    static2dsum(int h = 0, int w = 0)\n        : static2dsum(vector<vector<T>>(h,\
    \ vector<T>(w, T()))) {\n    }\n\n    static2dsum(vec<vec<T>> const &dat) {\n\
    \        h = dat.size();\n        if (h)\n            w = dat[0].size();\n   \
    \     else\n            w = 0;\n        d.resize((h + 1) * (w + 1), 0);\n    \
    \    for (int i = 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j) {\n\
    \                d[id(i + 1, j + 1)] = dat[i][j];\n            }\n        }\n\
    \    }\n    void add(int i, int j, T x) {\n        assert(built == false);\n \
    \       d[id(i + 1, j + 1)] += x;\n    }\n\n    void build() {\n        assert(built\
    \ == false);\n        for (int i = 0; i <= h; ++i) {\n            for (int j =\
    \ 0; j < w; ++j) {\n                d[id(i, j + 1)] += d[id(i, j)];\n        \
    \    }\n        }\n\n        for (int j = 0; j <= w; ++j) {\n            for (int\
    \ i = 0; i < h; ++i) {\n                d[id(i + 1, j)] += d[id(i, j)];\n    \
    \        }\n        }\n\n        built = true;\n    }\n\n    T get(int y, int\
    \ x) const {\n        assert(built);\n        assert(0 <= y && y < h);\n     \
    \   assert(0 <= x && x < w);\n        return prod(x, x + 1, y, y + 1);\n    }\n\
    \n    T prod(int sx, int tx, int sy, int ty) const {\n        assert(built);\n\
    \        assert(0 <= sy && sy <= ty && ty <= h);\n        assert(0 <= sx && sx\
    \ <= tx && tx <= w);\n\n        T res = d[id(ty, tx)];\n        res -= d[id(sy,\
    \ tx)];\n        res -= d[id(ty, sx)];\n        res += d[id(sy, sx)];\n      \
    \  return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/static2dsum.hpp
  requiredBy: []
  timestamp: '2025-02-19 12:40:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Datastructure_static2dsum.test.cpp
documentation_of: Datastructure/static2dsum.hpp
layout: document
redirect_from:
- /library/Datastructure/static2dsum.hpp
- /library/Datastructure/static2dsum.hpp.html
title: Datastructure/static2dsum.hpp
---
