---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/2dbit.test.cpp
    title: verify/2dbit.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/2dbit_imos.test.cpp
    title: verify/2dbit_imos.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/2dbit.md
    document_title: 2dbit
    links: []
  bundledCode: "#line 1 \"Datastructure/2dbit.hpp\"\nTT struct bit2d {\n    int h,\
    \ w;\n    vec<vec<T>> dat;\n\n    bit2d(int H, int W) : h(H), w(W) {\n       \
    \ dat = vec<vec<T>>(h, vec<T>(w, 0));\n    }\n\n    void add(int y, int x, T v)\
    \ {\n        assert(0 <= y && y < h);\n        assert(0 <= x && x < w);\n    \
    \    for( ; y < h; y |= y + 1) {\n            for(int b = x; b < w; b |= b + 1)\
    \ {\n                dat[y][b] += v;\n            }\n        }\n    }\n\n    void\
    \ imos_add(int y, int x, T v) {\n        add(y, x, v);\n    }\n\n    void imos_add(int\
    \ sy, int ty, int sx, int tx, T v) {\n        chmax(sy, 0);\n        chmax(sx,\
    \ 0); chmax(sy, 0);\n        chmin(tx, w); chmin(ty, h);\n        if(sx >= tx\
    \ || sy >= ty) return;\n        add(sy, sx, v);\n        if(ty < h && tx < w)\
    \ add(ty, tx, v);\n        if(ty < h) add(ty, sx, -v);\n        if(tx < w) add(sy,\
    \ tx, -v);\n    }\n\n    T prod(int y, int x) {\n        T res = 0;\n        y--,\
    \ x--;\n        for( ; y >= 0; y = (y & (y + 1)) - 1) {\n            for(int b\
    \ = x; b >= 0; b = (b & (b + 1)) - 1) {\n                res += dat[y][b];\n \
    \           }\n        }\n        return res;\n    }\n\n    T prod(int sy, int\
    \ ty, int sx, int tx) {\n        assert(sy >= 0); assert(sx >= 0);\n        assert(ty\
    \ <= h); assert(tx <= w);\n        T res = prod(ty, tx);\n        res -= prod(sy,\
    \ tx);\n        res -= prod(ty, sx);\n        res += prod(sy, sx);\n        return\
    \ res;\n    }\n\n    T imos_get(int y, int x) {\n        return prod(0, y+1, 0,\
    \ x+1);\n    }\n};\n/*\n@brief 2dbit\n@docs doc/2dbit.md\n*/\n"
  code: "TT struct bit2d {\n    int h, w;\n    vec<vec<T>> dat;\n\n    bit2d(int H,\
    \ int W) : h(H), w(W) {\n        dat = vec<vec<T>>(h, vec<T>(w, 0));\n    }\n\n\
    \    void add(int y, int x, T v) {\n        assert(0 <= y && y < h);\n       \
    \ assert(0 <= x && x < w);\n        for( ; y < h; y |= y + 1) {\n            for(int\
    \ b = x; b < w; b |= b + 1) {\n                dat[y][b] += v;\n            }\n\
    \        }\n    }\n\n    void imos_add(int y, int x, T v) {\n        add(y, x,\
    \ v);\n    }\n\n    void imos_add(int sy, int ty, int sx, int tx, T v) {\n   \
    \     chmax(sy, 0);\n        chmax(sx, 0); chmax(sy, 0);\n        chmin(tx, w);\
    \ chmin(ty, h);\n        if(sx >= tx || sy >= ty) return;\n        add(sy, sx,\
    \ v);\n        if(ty < h && tx < w) add(ty, tx, v);\n        if(ty < h) add(ty,\
    \ sx, -v);\n        if(tx < w) add(sy, tx, -v);\n    }\n\n    T prod(int y, int\
    \ x) {\n        T res = 0;\n        y--, x--;\n        for( ; y >= 0; y = (y &\
    \ (y + 1)) - 1) {\n            for(int b = x; b >= 0; b = (b & (b + 1)) - 1) {\n\
    \                res += dat[y][b];\n            }\n        }\n        return res;\n\
    \    }\n\n    T prod(int sy, int ty, int sx, int tx) {\n        assert(sy >= 0);\
    \ assert(sx >= 0);\n        assert(ty <= h); assert(tx <= w);\n        T res =\
    \ prod(ty, tx);\n        res -= prod(sy, tx);\n        res -= prod(ty, sx);\n\
    \        res += prod(sy, sx);\n        return res;\n    }\n\n    T imos_get(int\
    \ y, int x) {\n        return prod(0, y+1, 0, x+1);\n    }\n};\n/*\n@brief 2dbit\n\
    @docs doc/2dbit.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/2dbit.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/2dbit.test.cpp
  - verify/2dbit_imos.test.cpp
documentation_of: Datastructure/2dbit.hpp
layout: document
redirect_from:
- /library/Datastructure/2dbit.hpp
- /library/Datastructure/2dbit.hpp.html
title: 2dbit
---
## 概要
2dBit
参考 : https://hos.ac/slides/20140319_bit.pdf 

## +演算を他の演算に変えたくなった時
逆元があれば良い。
add, prod(y, x), prod(sy, sx, ty, tx) の + , - , += , -= を全て変更する。
**計算量$O(HW)$**
## コンストラクタ
**bit2d\<T\> bit (int h, int w)** ... T : 値の型。 [0, h) * [0, w)の配列を作る. 初期値は0。 計算量 $O(HW)$

## 関数
全て、計算量は $O(\log{h} \log{w})$
・1点加算/区間取得
- **add(int y, int x, T v)** ... A[y][x] += v
- **get(int y, int x)** ... A[y][x]を返す。
- **prod(int sy, int ty, int sx, int tx)** ... [sy, ty) * [sx, tx)の矩形領域の和を返す。**半開区間**

・区間加算/1点取得(**上の関数と併用しないこと**)
- **imos_add(int y, int x, T v)** ... A[y][x] += v
- **imos_add(int sy, int ty, int sx, int tx, T v)** ... [sy, ty) * [sx, tx) の区間に一様に += v。**半開区間**
- **imos_get(int y, int x, T v)** ... A[y][x]を返す。

