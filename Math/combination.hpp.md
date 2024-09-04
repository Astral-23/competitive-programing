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
  bundledCode: "#line 1 \"Math/combination.hpp\"\nTT struct CMB {  // must\u7D20\u6570\
    \n    ll mb;\n    vec<ll> fac, ifac, inv;\n\n    CMB(ll MAX_N, ll mod)\n     \
    \   :  mb(mod), fac(MAX_N + 1, 1), ifac(MAX_N + 1, 1), inv(MAX_N + 1, 1) {\n \
    \       for (ll i = 2; i <= MAX_N; i++) {\n            fac[i] = fac[i - 1] * i\
    \ % mb;\n            inv[i] = mb - inv[mb % i] * (mb / i) % mb;\n            ifac[i]\
    \ = ifac[i - 1] * inv[i] % mb;\n        }\n    }\n\n    T C(int n, int k) {\n\
    \        if (n < k) return 0LL;\n        if (n < 0 || k < 0) return 0LL;\n   \
    \     return fac[n] * (ifac[k] * ifac[n - k] % mb) % mb;\n    }\n\n    T B(int\
    \ n) { return (n < 0 ? 0 : fac[n]); }\n\n    T invB(int n) { return (n < 0 ? 0\
    \ : ifac[n]); }\n\n    T H(int n, int k) { return C(n + k - 1, k); }\n\n    T\
    \ Cn(int n) { return C(2 * n, n) * inv[n + 1] % mb; }\n};\n/*\n@brief \u30B3\u30F3\
    \u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n@docs doc/cmb.md\n*/\n"
  code: "TT struct CMB {  // must\u7D20\u6570\n    ll mb;\n    vec<ll> fac, ifac,\
    \ inv;\n\n    CMB(ll MAX_N, ll mod)\n        :  mb(mod), fac(MAX_N + 1, 1), ifac(MAX_N\
    \ + 1, 1), inv(MAX_N + 1, 1) {\n        for (ll i = 2; i <= MAX_N; i++) {\n  \
    \          fac[i] = fac[i - 1] * i % mb;\n            inv[i] = mb - inv[mb % i]\
    \ * (mb / i) % mb;\n            ifac[i] = ifac[i - 1] * inv[i] % mb;\n       \
    \ }\n    }\n\n    T C(int n, int k) {\n        if (n < k) return 0LL;\n      \
    \  if (n < 0 || k < 0) return 0LL;\n        return fac[n] * (ifac[k] * ifac[n\
    \ - k] % mb) % mb;\n    }\n\n    T B(int n) { return (n < 0 ? 0 : fac[n]); }\n\
    \n    T invB(int n) { return (n < 0 ? 0 : ifac[n]); }\n\n    T H(int n, int k)\
    \ { return C(n + k - 1, k); }\n\n    T Cn(int n) { return C(2 * n, n) * inv[n\
    \ + 1] % mb; }\n};\n/*\n@brief \u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\
    \n@docs doc/cmb.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/combination.hpp
  requiredBy: []
  timestamp: '2024-09-04 14:28:31+09:00'
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
  
