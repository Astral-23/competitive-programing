---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Math_combination.test.cpp
    title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: doc/cmb.md
    document_title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
    links: []
  bundledCode: "#line 1 \"Math/combination.hpp\"\ntemplate <typename T, long long\
    \ mod> struct combination {\n    vector<long long> fac, ifac, inv;\n    long long\
    \ N;\n    combination() {\n        fac.resize(2, 1);\n        ifac.resize(2, 1);\n\
    \        inv.resize(2, 1);\n        N = 1;\n    }\n\n    void reserve(long long\
    \ n) { expand(n); }\n\n    T operator()(int n, int k) { return C(n, k); }\n\n\
    \    T C(int n, int k) {\n        if (n < k) return 0;\n        if (n < 0 || k\
    \ < 0) return 0;\n        if (N < n) expand(n);\n        return fac[n] * ifac[n\
    \ - k] % mod * ifac[k] % mod;\n    }\n\n    T P(int n, int k) {\n        if (n\
    \ < k) return 0;\n        if (n < 0 || k < 0) return 0;\n        if (N < n) expand(n);\n\
    \        return fac[n] * ifac[n - k] % mod;\n    }\n\n    T B(int n) {\n     \
    \   if (N < n) expand(n);\n        return (n < 0 ? 0 : fac[n]);\n    }\n    T\
    \ invB(int n) {\n        if (N < n) expand(n);\n        return (n < 0 ? 0 : ifac[n]);\n\
    \    }\n\n    T H(int n, int k) {\n        if (n < 0 || k < 0) return 0;\n   \
    \     if (k == 0) return 1;\n        return C(n + k - 1, k);\n    }\n\n    T Cn(int\
    \ n) { return C(2 * n, n) * inv[n + 1] % mod; }\n\n  private:\n    constexpr static\
    \ bool is_prime_constexpr(long long x) {\n        if (x <= 1) return false;\n\
    \        for (long long i = 2; i * i <= x; i++) {\n            if (x % i == 0)\
    \ return false;\n        }\n        return true;\n    }\n\n    static_assert(is_prime_constexpr(mod),\
    \ \"mod must be prime\");\n\n    long long extgcd(long long a, long long b, long\
    \ long &x, long long &y) {\n        if (b == 0) {\n            x = 1;\n      \
    \      y = 0;\n            return a;\n        }\n        auto d = extgcd(b, a\
    \ % b, y, x);\n        y -= a / b * x;\n        return d;\n    }\n\n    long long\
    \ modinv(long long a) {\n        long long x, y;\n        extgcd(a, mod, x, y);\n\
    \        x %= mod;\n        if (x < 0) x += mod;\n        return x;\n    }\n\n\
    \    void expand(long long new_max_n) {\n        if (new_max_n <= N) return;\n\
    \        long long nx = N;\n\n        // 2\u51AA\u3067\u5927\u304D\u304F\u3057\
    \u3066\u3044\u304F\u3002\n        while (nx < new_max_n) nx <<= 1;\n        new_max_n\
    \ = nx;\n\n        long long pre = N;\n        N = new_max_n;\n        fac.resize(N\
    \ + 1);\n        ifac.resize(N + 1);\n        inv.resize(N + 1);\n        for\
    \ (long long i = pre + 1; i <= N; i++) {\n            fac[i] = fac[i - 1] * i\
    \ % mod;\n        }\n        ifac[N] = modinv(fac[N]);\n        inv[N] = ifac[N]\
    \ * fac[N - 1] % mod;\n        for (long long i = N - 1; i >= pre + 1; i--) {\n\
    \            ifac[i] = ifac[i + 1] * (i + 1) % mod;\n            inv[i] = ifac[i]\
    \ * fac[i - 1] % mod;\n        }\n        return;\n    }\n};\n\nusing combination998244353\
    \ = combination<atcoder::modint998244353, 998244353>;\n/*\n@brief \u30B3\u30F3\
    \u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n@docs doc/cmb.md\n*/\n"
  code: "template <typename T, long long mod> struct combination {\n    vector<long\
    \ long> fac, ifac, inv;\n    long long N;\n    combination() {\n        fac.resize(2,\
    \ 1);\n        ifac.resize(2, 1);\n        inv.resize(2, 1);\n        N = 1;\n\
    \    }\n\n    void reserve(long long n) { expand(n); }\n\n    T operator()(int\
    \ n, int k) { return C(n, k); }\n\n    T C(int n, int k) {\n        if (n < k)\
    \ return 0;\n        if (n < 0 || k < 0) return 0;\n        if (N < n) expand(n);\n\
    \        return fac[n] * ifac[n - k] % mod * ifac[k] % mod;\n    }\n\n    T P(int\
    \ n, int k) {\n        if (n < k) return 0;\n        if (n < 0 || k < 0) return\
    \ 0;\n        if (N < n) expand(n);\n        return fac[n] * ifac[n - k] % mod;\n\
    \    }\n\n    T B(int n) {\n        if (N < n) expand(n);\n        return (n <\
    \ 0 ? 0 : fac[n]);\n    }\n    T invB(int n) {\n        if (N < n) expand(n);\n\
    \        return (n < 0 ? 0 : ifac[n]);\n    }\n\n    T H(int n, int k) {\n   \
    \     if (n < 0 || k < 0) return 0;\n        if (k == 0) return 1;\n        return\
    \ C(n + k - 1, k);\n    }\n\n    T Cn(int n) { return C(2 * n, n) * inv[n + 1]\
    \ % mod; }\n\n  private:\n    constexpr static bool is_prime_constexpr(long long\
    \ x) {\n        if (x <= 1) return false;\n        for (long long i = 2; i * i\
    \ <= x; i++) {\n            if (x % i == 0) return false;\n        }\n       \
    \ return true;\n    }\n\n    static_assert(is_prime_constexpr(mod), \"mod must\
    \ be prime\");\n\n    long long extgcd(long long a, long long b, long long &x,\
    \ long long &y) {\n        if (b == 0) {\n            x = 1;\n            y =\
    \ 0;\n            return a;\n        }\n        auto d = extgcd(b, a % b, y, x);\n\
    \        y -= a / b * x;\n        return d;\n    }\n\n    long long modinv(long\
    \ long a) {\n        long long x, y;\n        extgcd(a, mod, x, y);\n        x\
    \ %= mod;\n        if (x < 0) x += mod;\n        return x;\n    }\n\n    void\
    \ expand(long long new_max_n) {\n        if (new_max_n <= N) return;\n       \
    \ long long nx = N;\n\n        // 2\u51AA\u3067\u5927\u304D\u304F\u3057\u3066\u3044\
    \u304F\u3002\n        while (nx < new_max_n) nx <<= 1;\n        new_max_n = nx;\n\
    \n        long long pre = N;\n        N = new_max_n;\n        fac.resize(N + 1);\n\
    \        ifac.resize(N + 1);\n        inv.resize(N + 1);\n        for (long long\
    \ i = pre + 1; i <= N; i++) {\n            fac[i] = fac[i - 1] * i % mod;\n  \
    \      }\n        ifac[N] = modinv(fac[N]);\n        inv[N] = ifac[N] * fac[N\
    \ - 1] % mod;\n        for (long long i = N - 1; i >= pre + 1; i--) {\n      \
    \      ifac[i] = ifac[i + 1] * (i + 1) % mod;\n            inv[i] = ifac[i] *\
    \ fac[i - 1] % mod;\n        }\n        return;\n    }\n};\n\nusing combination998244353\
    \ = combination<atcoder::modint998244353, 998244353>;\n/*\n@brief \u30B3\u30F3\
    \u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n@docs doc/cmb.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/combination.hpp
  requiredBy: []
  timestamp: '2025-01-11 20:40:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Math_combination.test.cpp
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
  
