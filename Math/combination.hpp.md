---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/combination.test.cpp
    title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/cmb.md
    document_title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
    links: []
  bundledCode: "#line 1 \"Math/combination.hpp\"\nstruct CMB {//must\u7D20\u6570\n\
    \    using vl = vec<ll>;\n    vl fac;\n    vl ifac;\n    vl inv;\n    ll mb =\
    \ 0;\n    int N;\n  \n    CMB (int r, ll _mod) : mb(_mod), N(r+1), fac(r+1, 1),\
    \ ifac(r+1, 1), inv(r+1, 1) {\n        rep(i, 2, N) {\n            fac[i] = fac[i-1]\
    \ * i % mb;\n            inv[i] = mb - inv[mb%i]*(mb/i) % mb;\n            ifac[i]\
    \ = ifac[i-1] * inv[i] % mb;\n        }\n    }\n\n    ll C(int n, int k) { \n\
    \        if(n < k) return 0LL;\n        if(n < 0 || k < 0) return 0LL;\n     \
    \   return fac[n] * (ifac[k] * ifac[n-k]%mb)%mb;\n    }\n  \n\n    ll B(int n)\
    \ { \n      return fac[n];\n    }\n  \n    ll invB(int n) {\n        return ifac[n];\n\
    \    }\n  \n    ll H(int n, int k) { \n        return C(n+k-1, k);\n    }\n  \n\
    \    ll Cn(int n) { \n        return C(2*n, n) * inv[n+1] % mb;\n    }\n};\n\n\
    /*\n@brief \u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n@docs doc/cmb.md\n\
    */\n"
  code: "struct CMB {//must\u7D20\u6570\n    using vl = vec<ll>;\n    vl fac;\n  \
    \  vl ifac;\n    vl inv;\n    ll mb = 0;\n    int N;\n  \n    CMB (int r, ll _mod)\
    \ : mb(_mod), N(r+1), fac(r+1, 1), ifac(r+1, 1), inv(r+1, 1) {\n        rep(i,\
    \ 2, N) {\n            fac[i] = fac[i-1] * i % mb;\n            inv[i] = mb -\
    \ inv[mb%i]*(mb/i) % mb;\n            ifac[i] = ifac[i-1] * inv[i] % mb;\n   \
    \     }\n    }\n\n    ll C(int n, int k) { \n        if(n < k) return 0LL;\n \
    \       if(n < 0 || k < 0) return 0LL;\n        return fac[n] * (ifac[k] * ifac[n-k]%mb)%mb;\n\
    \    }\n  \n\n    ll B(int n) { \n      return fac[n];\n    }\n  \n    ll invB(int\
    \ n) {\n        return ifac[n];\n    }\n  \n    ll H(int n, int k) { \n      \
    \  return C(n+k-1, k);\n    }\n  \n    ll Cn(int n) { \n        return C(2*n,\
    \ n) * inv[n+1] % mb;\n    }\n};\n\n/*\n@brief \u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\
    \u30E7\u30F3\n@docs doc/cmb.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/combination.hpp
  requiredBy: []
  timestamp: '2024-07-06 20:37:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/combination.test.cpp
documentation_of: Math/combination.hpp
layout: document
redirect_from:
- /library/Math/combination.hpp
- /library/Math/combination.hpp.html
title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
---
## 概要
O(N)構築 combinationと付随する関数。
参考 : https://drken1215.hatenablog.com/entry/2018/06/08/210000

## 省略できるもの
コンストラクタとC(int n, int k)以外の関数はそれぞれ独立なので省略できます。及び、C(int n, int k)以外の関数のverifyはしていません。

## コンストラクタ
**CMB cmb(int r, int mod)** ... modを指定した上で、[0, r]の階乗や整数の逆元を求める  
- **計算量**
    $O(n)$

## 関数

- **ll C(int n, int k)**... $\binom{n}{r}$
    - **制約**
    $n, k \le r$

- **ll B(int n)**... $n!$
    - **制約**
    $0 \le n \le r$

- **ll invB(int n)**... $n!$ の逆元
    - **制約**
    $0 \le n \le r$

- **ll H(int n, int k)**... $\binom{n+k-1}{k}$ 重複あり組み合わせ
    - **制約**
    $n+k-1 \le r$

- **ll Cn(int u)**... $\binom{2n}{n} /(n+1)$ カタラン数
    - **制約**
    $2n \le r$
  
