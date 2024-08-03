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
    _deprecated_at_docs: doc/static1dsum.md
    document_title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"Datastructure/static1dsum.hpp\"\nTT struct static1dsum {\n\
    \    int n;\n    vec<T> dat;\n    bool built = false;\n\n    static1dsum(int n\
    \ = 0) : static1dsum(vec<T>(n, T())) {}\n\n    static1dsum(vec<T> dat) : n(dat.size()),\
    \ dat(dat) {}\n\n    void add(int i, T x) {\n        assert(!built);\n       \
    \ dat[i] += x;\n    }\n\n    void build() {\n        rep(i, 0, n - 1) dat[i +\
    \ 1] += dat[i];\n        built = true;\n    }\n\n    T operator[](int i) const\
    \ {\n        assert(built == true);\n        assert(0 <= i && i < n);\n      \
    \  return prod(i, i + 1);\n    }\n\n    T prod(int l, int r) {\n        assert(built);\n\
    \        assert(l >= 0);\n        assert(r <= n);\n        assert(l <= r);\n \
    \       T res = dat[r - 1];\n        if (l) res -= dat[l - 1];\n        return\
    \ res;\n    }\n};\n\n\n\n/*\n@brief 1\u6B21\u5143\u7D2F\u7A4D\u548C\n@docs doc/static1dsum.md\n\
    */\n"
  code: "TT struct static1dsum {\n    int n;\n    vec<T> dat;\n    bool built = false;\n\
    \n    static1dsum(int n = 0) : static1dsum(vec<T>(n, T())) {}\n\n    static1dsum(vec<T>\
    \ dat) : n(dat.size()), dat(dat) {}\n\n    void add(int i, T x) {\n        assert(!built);\n\
    \        dat[i] += x;\n    }\n\n    void build() {\n        rep(i, 0, n - 1) dat[i\
    \ + 1] += dat[i];\n        built = true;\n    }\n\n    T operator[](int i) const\
    \ {\n        assert(built == true);\n        assert(0 <= i && i < n);\n      \
    \  return prod(i, i + 1);\n    }\n\n    T prod(int l, int r) {\n        assert(built);\n\
    \        assert(l >= 0);\n        assert(r <= n);\n        assert(l <= r);\n \
    \       T res = dat[r - 1];\n        if (l) res -= dat[l - 1];\n        return\
    \ res;\n    }\n};\n\n\n\n/*\n@brief 1\u6B21\u5143\u7D2F\u7A4D\u548C\n@docs doc/static1dsum.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Datastructure/static1dsum.hpp
  requiredBy: []
  timestamp: '2024-08-03 18:57:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/static1dsum.test.cpp
documentation_of: Datastructure/static1dsum.hpp
layout: document
redirect_from:
- /library/Datastructure/static1dsum.hpp
- /library/Datastructure/static1dsum.hpp.html
title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
---
## 概要
1次元累積和

## +演算を他の演算に変えたくなった時
逆元があれば良い。
add, prod(y, x), prod(sy, sx, ty, tx) の + , - , += , -= を全て変更する。

## コンストラクタ
`template<typename T> static1dsum(int n)` ... T : 値の型。 [0, n) の配列を作る. 初期値は0
- 計算量 $O(n)$

## 関数
基本、計算量は $O(1)$  

・1点加算/区間取得
- `void add(int i, T v)` ... A[i] += v

- `void build()` ... 累積和を計算する。以降add不可能。また、buildを呼ぶ前はget.prod不可。(どちらも、assertが反応する) 
    - 計算量 $O(n)$

- `T get(int i)` ... A[i]を返す。

- `T prod(int l, int r)` ... [l, r)の範囲領域の和を返す。**半開区間**

<br>

・区間加算/1点取得(**上の関数と併用しないこと**)
- `void imos_add(int i, T v)` ... A[i] += v

- `void imos_add(int l, int r, T v)` ... [l, r) に一様にvを加算。**半開領域**

- `void build()` ... 累積和を計算する。以降add不可能。また、buildを呼ぶ前はget.prod不可。(どちらも、assertが反応する) 計算量 $O(n)$

- `T imos_get(int i)` ... A[i]を返す。

