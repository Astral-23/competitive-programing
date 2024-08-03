---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/imos2d.test.cpp
    title: verify/imos2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/static2dsum.md
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
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
    /*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n@docs doc/static2dsum.md\n*/\n"
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
    \ dat[i][j]; }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n@docs doc/static2dsum.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/imos2d.hpp
  requiredBy: []
  timestamp: '2024-08-03 19:07:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/imos2d.test.cpp
documentation_of: Datastructure/imos2d.hpp
layout: document
redirect_from:
- /library/Datastructure/imos2d.hpp
- /library/Datastructure/imos2d.hpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
## 概要
2次元累積和

## +演算を他の演算に変えたくなった時
逆元があれば良い。
add, prod(y, x), prod(sy, sx, ty, tx) の + , - , += , -= を全て変更する。

## コンストラクタ
`template<typename T> static2dsum(int h, int w)` ... T : 値の型。 [0, h) * [0, w)の配列を作る. 初期値は0。 
- 計算量 $O(HW)$

## 関数
基本、計算量は $O(1)$  

・1点加算/区間取得
- `void add(int y, int x, T v)` ... A[y][x] += v

- `void build()` ... 累積和を計算する。以降add不可能。また、buildを呼ぶ前はget.prod不可。(どちらも、assertが反応する) 
    - 計算量 $O(HW)$

- `void get(int y, int x)` ... A[y][x]を返す。

- `T prod(int sy, int ty, int sx, int tx)` ... [sy, ty) * [sx, tx)の矩形領域の和を返す。**半開区間**

<br>

・区間加算/1点取得(**上の関数と併用しないこと**)
- `void imos_add(int y, int x, T v)` ... A[y][x] += v

- `void imos_add(int sy, int ty, int sx, int tx, T v)` ... [sy, ty) * [sx, tx) の区間に一様に += v。**半開区間**

- `void build()` ... 累積和を計算する。以降add不可能。また、buildを呼ぶ前はget.prod不可。(どちらも、assertが反応する) 
    - 計算量 $O(HW)$

- `T imos_get(int y, int x, T v)` ... A[y][x]を返す。

