---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/static1dsum.test.cpp
    title: verify/static1dsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/static2dsum.test.cpp
    title: verify/static2dsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/static2dsum_imos.test.cpp
    title: verify/static2dsum_imos.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/static2dsum.md
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"Datastructure/static2dsum.hpp\"\nTT struct static2dsum {\n\
    \    int h, w;\n    vec<vec<T>> dat;\n    bool f = false;\n\n    static2dsum(int\
    \ h = 0, int w = 0)\n        : static2dsum(vec<vec<T>>(h, vec<T>(w, T()))) {}\n\
    \n    static2dsum(vec<vec<T>> dat) : dat(dat) {\n        h = dat.size();\n   \
    \     if (h)\n            w = dat[0].size();\n        else\n            w = 0;\n\
    \    }\n\n    void add(int i, int j, T x) {\n        assert(!f);\n        dat[i][j]\
    \ += x;\n    }\n\n    void imos_add(int i, int j, T x) { add(i, j, x); }\n\n \
    \   void imos_add(int sy, int ty, int sx, int tx, T x) {\n        assert(!f);\n\
    \        chmax(sx, 0);\n        chmax(sy, 0);\n        chmin(tx, w);\n       \
    \ chmin(ty, h);\n        if (sx >= tx || sy >= ty) return;\n        dat[sy][sx]\
    \ += x;\n        if (ty < h) dat[ty][sx] -= x;\n        if (tx < w) dat[sy][tx]\
    \ -= x;\n        if (tx < w && ty < h) dat[ty][tx] += x;\n        return;\n  \
    \  }\n\n    void build() {\n        rep(i, 0, h) {\n            rep(j, 0, w -\
    \ 1) { dat[i][j + 1] += dat[i][j]; }\n        }\n\n        rep(j, 0, w) {\n  \
    \          rep(i, 0, h - 1) { dat[i + 1][j] += dat[i][j]; }\n        }\n\n   \
    \     f = true;\n    }\n\n    T imos_get(int i, int j) { return prod(0, i + 1,\
    \ 0, j + 1); }\n\n    T get(int i, int j) {\n        assert(f);\n        assert(0\
    \ <= i && i < h);\n        assert(0 <= j && j < w);\n        return dat[i][j];\n\
    \    }\n\n    T prod(int sy, int ty, int sx, int tx) {\n        assert(f);\n \
    \       assert(sy >= 0);\n        assert(ty <= h);\n        assert(sx >= 0);\n\
    \        assert(tx <= w);\n        assert(sy <= ty);\n        assert(sx <= tx);\n\
    \        if (sx >= tx || sy >= ty) return 0;\n        tx--, ty--;\n        T res\
    \ = dat[ty][tx];\n        if (sx > 0) res -= dat[ty][sx - 1];\n        if (sy\
    \ > 0) res -= dat[sy - 1][tx];\n        if (sx > 0 && sy > 0) res += dat[sy -\
    \ 1][sx - 1];\n        return res;\n    }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\
    \u548C\n@docs doc/static2dsum.md\n*/\n"
  code: "TT struct static2dsum {\n    int h, w;\n    vec<vec<T>> dat;\n    bool f\
    \ = false;\n\n    static2dsum(int h = 0, int w = 0)\n        : static2dsum(vec<vec<T>>(h,\
    \ vec<T>(w, T()))) {}\n\n    static2dsum(vec<vec<T>> dat) : dat(dat) {\n     \
    \   h = dat.size();\n        if (h)\n            w = dat[0].size();\n        else\n\
    \            w = 0;\n    }\n\n    void add(int i, int j, T x) {\n        assert(!f);\n\
    \        dat[i][j] += x;\n    }\n\n    void imos_add(int i, int j, T x) { add(i,\
    \ j, x); }\n\n    void imos_add(int sy, int ty, int sx, int tx, T x) {\n     \
    \   assert(!f);\n        chmax(sx, 0);\n        chmax(sy, 0);\n        chmin(tx,\
    \ w);\n        chmin(ty, h);\n        if (sx >= tx || sy >= ty) return;\n    \
    \    dat[sy][sx] += x;\n        if (ty < h) dat[ty][sx] -= x;\n        if (tx\
    \ < w) dat[sy][tx] -= x;\n        if (tx < w && ty < h) dat[ty][tx] += x;\n  \
    \      return;\n    }\n\n    void build() {\n        rep(i, 0, h) {\n        \
    \    rep(j, 0, w - 1) { dat[i][j + 1] += dat[i][j]; }\n        }\n\n        rep(j,\
    \ 0, w) {\n            rep(i, 0, h - 1) { dat[i + 1][j] += dat[i][j]; }\n    \
    \    }\n\n        f = true;\n    }\n\n    T imos_get(int i, int j) { return prod(0,\
    \ i + 1, 0, j + 1); }\n\n    T get(int i, int j) {\n        assert(f);\n     \
    \   assert(0 <= i && i < h);\n        assert(0 <= j && j < w);\n        return\
    \ dat[i][j];\n    }\n\n    T prod(int sy, int ty, int sx, int tx) {\n        assert(f);\n\
    \        assert(sy >= 0);\n        assert(ty <= h);\n        assert(sx >= 0);\n\
    \        assert(tx <= w);\n        assert(sy <= ty);\n        assert(sx <= tx);\n\
    \        if (sx >= tx || sy >= ty) return 0;\n        tx--, ty--;\n        T res\
    \ = dat[ty][tx];\n        if (sx > 0) res -= dat[ty][sx - 1];\n        if (sy\
    \ > 0) res -= dat[sy - 1][tx];\n        if (sx > 0 && sy > 0) res += dat[sy -\
    \ 1][sx - 1];\n        return res;\n    }\n};\n/*\n@brief 2\u6B21\u5143\u7D2F\u7A4D\
    \u548C\n@docs doc/static2dsum.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/static2dsum.hpp
  requiredBy: []
  timestamp: '2024-07-17 08:08:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/static2dsum_imos.test.cpp
  - verify/static2dsum.test.cpp
  - verify/static1dsum.test.cpp
documentation_of: Datastructure/static2dsum.hpp
layout: document
redirect_from:
- /library/Datastructure/static2dsum.hpp
- /library/Datastructure/static2dsum.hpp.html
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

