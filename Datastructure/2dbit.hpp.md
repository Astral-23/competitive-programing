---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Datastructure_2dbit.test.cpp
    title: verify/Datastructure_2dbit.test.cpp
  - icon: ':x:'
    path: verify/Datastructure_2dbit_imos.test.cpp
    title: verify/Datastructure_2dbit_imos.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Datastructure/2dbit.hpp\"\nTT struct bit2d {\n    int h,\
    \ w;\n    vec<vec<T>> dat;\n\n    bit2d(int H, int W) : h(H), w(W) {\n       \
    \ dat = vec<vec<T>>(h, vec<T>(w, 0));\n    }\n\n    void add(int y, int x, T v)\
    \ {\n        assert(0 <= y && y < h);\n        assert(0 <= x && x < w);\n    \
    \    for( ; y < h; y |= y + 1) {\n            for(int b = x; b < w; b |= b + 1)\
    \ {\n                dat[y][b] += v;\n            }\n        }\n    }\n\n    T\
    \ prod(int y, int x) const {\n        T res = 0;\n        y--, x--;\n        for(\
    \ ; y >= 0; y = (y & (y + 1)) - 1) {\n            for(int b = x; b >= 0; b = (b\
    \ & (b + 1)) - 1) {\n                res += dat[y][b];\n            }\n      \
    \  }\n        return res;\n    }\n\n    T prod(int sy, int ty, int sx, int tx)\
    \ const {\n        assert(0 <= sy && sy <= ty && ty <= h);\n        assert(0 <=\
    \ sx && sx <= tx && tx <= w);\n\n        T res = prod(ty, tx);\n        res -=\
    \ prod(sy, tx);\n        res -= prod(ty, sx);\n        res += prod(sy, sx);\n\
    \        return res;\n    }\n};\n"
  code: "TT struct bit2d {\n    int h, w;\n    vec<vec<T>> dat;\n\n    bit2d(int H,\
    \ int W) : h(H), w(W) {\n        dat = vec<vec<T>>(h, vec<T>(w, 0));\n    }\n\n\
    \    void add(int y, int x, T v) {\n        assert(0 <= y && y < h);\n       \
    \ assert(0 <= x && x < w);\n        for( ; y < h; y |= y + 1) {\n            for(int\
    \ b = x; b < w; b |= b + 1) {\n                dat[y][b] += v;\n            }\n\
    \        }\n    }\n\n    T prod(int y, int x) const {\n        T res = 0;\n  \
    \      y--, x--;\n        for( ; y >= 0; y = (y & (y + 1)) - 1) {\n          \
    \  for(int b = x; b >= 0; b = (b & (b + 1)) - 1) {\n                res += dat[y][b];\n\
    \            }\n        }\n        return res;\n    }\n\n    T prod(int sy, int\
    \ ty, int sx, int tx) const {\n        assert(0 <= sy && sy <= ty && ty <= h);\n\
    \        assert(0 <= sx && sx <= tx && tx <= w);\n\n        T res = prod(ty, tx);\n\
    \        res -= prod(sy, tx);\n        res -= prod(ty, sx);\n        res += prod(sy,\
    \ sx);\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/2dbit.hpp
  requiredBy: []
  timestamp: '2025-02-19 12:40:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/Datastructure_2dbit.test.cpp
  - verify/Datastructure_2dbit_imos.test.cpp
documentation_of: Datastructure/2dbit.hpp
layout: document
redirect_from:
- /library/Datastructure/2dbit.hpp
- /library/Datastructure/2dbit.hpp.html
title: Datastructure/2dbit.hpp
---
